#pragma once
#include "Check_du_lieu_nhap.h"
#include "Xu_li_do_hoa.h"

//-----------Load thông tin----------

void them_khachhang_vao_cay(TREE& t, KH data) {
	if (t == NULL) {
		node_kh* p = new node_kh;
		p->data = data;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else if (t != NULL) {
		if (stoi(data.maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4))) {
			them_khachhang_vao_cay(t->pLeft, data);
		}
		else if (stoi(data.maKh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4))) {
			them_khachhang_vao_cay(t->pRight, data);
		}
	}
}

node_hoa_don* KhoiTaoNodeHD(HoaDon a) {
	node_hoa_don* p = new node_hoa_don;
	p->data = a;
	p->pNext = NULL;
	return p;
}

void them_HoaDonNhap_vao_ds(DS_HOA_DON& dshd, HoaDon& a) {
	node_hoa_don* p = KhoiTaoNodeHD(a);
	if (dshd.pHead == NULL) {
		dshd.pHead = dshd.pTail = p;
	}
	else {
		dshd.pTail->pNext = p;
		dshd.pTail = p;
	}
}

// ================== Hàng Hóa =====================
void nhapHangHoa(HangHoa& a, DS_Hang_Hoa b)
{

	cout << "Nhap ma hang hoa (Q/A): "; getline(cin, a.ma_hh);// mã : Q,A
	while_ma_hh(a.ma_hh);
	a.ma_hh = a.ma_hh + tao_ma_hang_hoa(b);//mã hh = mã + số random

	cout << "Nhap ten hang hoa: "; getline(cin, a.ten_hh);
	while_ten(a.ten_hh);

	cout << "Nhap size: "; getline(cin, a.size);
	if (a.ma_hh[0] == 'A')
	{
		while_size_ao(a.size);
	}
	else
	{
		while_size_quan(a.size);
	}

	string tam;
	cout << "Gia: "; getline(cin, tam);
	while_so(tam);
	a.gia = stoll(tam);

	cout << "Nhap mo ta san pham: "; getline(cin, a.mo_ta_sp);// mô tả k cần nhập kích thước chi tiết vì đã kẻ bảng
	while_ten(a.mo_ta_sp);

	cout << "Nhap so luong trong kho: "; getline(cin, tam);
	while_so(tam);
	a.soLuongTonKho = stoi(tam);

	// thời  gian nhập hàng : lấy thời gian máy tính
	a.thoi_gian_nhap_hang = thoiGianThuc(a.thoi_gian_nhap_hang);
}

void xuat_tt_hh_ngan_gon(HangHoa a)
{
	cout << "Ma hang hoa: " << a.ma_hh << endl;
	cout << "Ten hang hoa: " << a.ten_hh << endl;
	cout << "Gia: " << a.gia << endl;
	cout << "Size: " << a.size << endl;
	cout << "So luong con trong kho: " << a.soLuongTonKho << endl;
}

void xuat_thong_tin_quan(DS_Hang_Hoa dshh)
{
	for (int i = 0; i < dshh.ds_quan.size(); i++)
	{
		xuat_tt_hh_ngan_gon(dshh.ds_quan.at(i));
	}
}

void xuat_thong_tin_ao(DS_Hang_Hoa dshh)
{
	for (int i = 0; i < dshh.ds_ao.size(); i++)
	{
		xuat_tt_hh_ngan_gon(dshh.ds_ao.at(i));
	}
}

//=================== Hóa Đơn =========================
void nhapHoaDon(HoaDon& a, ds_hoa_don b, DS_Hang_Hoa c, ds_khach_hang d)
{
	string loai_hd;
	cout << "Nhap loai hoa don (Xuat/Nhap) : "; getline(cin, loai_hd); // cho nhập Xuat / Nhap
	while_loai_hd(loai_hd);
	if (loai_hd == "Xuat")
	{
		a.ma_hoa_don = 'X';
	}
	else
	{
		a.ma_hoa_don = 'N';
	}
	a.ma_hoa_don = a.ma_hoa_don + tao_ma_hoa_don(b);
	if (loai_hd == "Xuat")
	{
		long long tien;
		cout << "Nhap ma khach hang: ";
		getline(cin, a.ma_kh);
		while_ma_kh(a.ma_kh);
		// ktra mã khách hàng xem có tồn tại không
		while (true)
		{
			if (check_ma_kh(a.ma_kh, d.t) == -1)
			{
				cout << "Khach hang khong ton tai!";
				cout << "\nNhap ma khach hang: ";
				getline(cin, a.ma_kh);
				while_ma_kh(a.ma_kh);
			}
			else
			{
				break;
			}
		}

		cout << "Nhap ma hang hoa: "; getline(cin, a.ma_hang_hoa);
		while_full_ma_hh(a.ma_hang_hoa);
		// ktra hh có tồn tại hay không 
		while (true)
		{
			if (check_ma_hh(a.ma_hang_hoa, c) == -1)
			{
				cout << "Hang hao khong ton tai!";
				cout << "\nNhap ma hang hoa: ";
				getline(cin, a.ma_hang_hoa);
				while_full_ma_hh(a.ma_hang_hoa);
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < c.ds_ao.size(); i++)
		{
			if (a.ma_hang_hoa == c.ds_ao.at(i).ma_hh)
			{
				tien = c.ds_ao.at(i).gia;
				break;
			}
		}
		for (int i = 0; i < c.ds_quan.size(); i++)
		{
			if (a.ma_hang_hoa == c.ds_quan.at(i).ma_hh)
			{
				tien = c.ds_quan.at(i).gia;
				break;
			}
		}
		if (a.ma_kh.substr(0, 2) == "DO")
		{
			a.tong_tien = (tien * a.sl_mua) * 0, 01;
			a.giam_gia_theo_hang = 0, 01;
		}
		else if (a.ma_kh.substr(0, 2) == "BA")
		{
			a.tong_tien = (tien * a.sl_mua) * 0, 03;
			a.giam_gia_theo_hang = 0, 03;
		}
		else if (a.ma_kh.substr(0, 2) == "VA")
		{
			a.tong_tien = (tien * a.sl_mua) * 0, 05;
			a.giam_gia_theo_hang = 0, 05;
		}
		else if (a.ma_kh.substr(0, 2) == "KC")
		{
			a.tong_tien = (tien * a.sl_mua) * 0, 1;
			a.giam_gia_theo_hang = 0, 1;
		}
		else
		{
			a.tong_tien = tien * a.sl_mua;
			a.giam_gia_theo_hang = 0;
		}
	}
	else
	{
		cout << "Nhap ma hang hoa (Q/A): "; getline(cin, a.ma_hang_hoa);
		while_ma_hh(a.ma_hang_hoa);
		a.ma_hang_hoa = a.ma_hang_hoa + tao_ma_hang_hoa(c);

		cout << "Nhap ten hang hoa: ";
		getline(cin, a.thong_tin_hang.ten_hh);
		while_ten(a.thong_tin_hang.ten_hh);

		cout << "Nhap size: ";
		getline(cin, a.thong_tin_hang.size);
		if (a.thong_tin_hang.ma_hh[0] == 'A')
		{
			while_size_ao(a.thong_tin_hang.size);
		}
		else
		{
			while_size_quan(a.thong_tin_hang.size);
		}

		string gia;
		cout << "Nhap gia: ";
		cin >> gia;
		while_so(gia);
		a.gia_nhap = stoll(gia);
	}
	string tam;
	cout << "Nhap so luong mua: "; getline(cin, tam);
	while_so(tam);
	a.sl_mua = stoi(tam);

	cout << "Nhap phuong thuc thanh toan( Cod/Bank ): "; getline(cin, a.pptt);
	while_pttt(a.pptt);

	// ngày lập hóa đơn : lấy thời gian máy tính
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);

	cout << "Trang thai: ";
	getline(cin, a.trang_thai);
	while_trang_thai(a.trang_thai);
}

void taoHoaDonKhiKhachDatHang(HoaDon& a, ds_hoa_don b, HangHoa c)
{
	a.ma_hoa_don = 'X' + tao_ma_hoa_don(b);
	a.ma_hang_hoa = c.ma_hh;

	string tam;
	cout << "Nhap so luong mua: ";
	getline(cin, tam);
	while_so(tam);
	a.sl_mua = stoi(tam);

	cout << "Nhap phuong thuc thanh toan( COD/Bank ): "; getline(cin, a.pptt);
	chuanHoa(a.pptt);
	while_pttt(a.pptt);

	// ngày lập hóa đơn : lấy thời gian máy tính
	thoiGianThuc(a.ngay_lap_hd);
}

void xuatHoaDonBanHang(HoaDon a)
{
	cout << "Ma khach hang: " << a.ma_kh << endl;
	cout << "Ma hoa don: " << a.ma_hoa_don << endl;
	cout << "\tThong tin hang hoa: " << endl;
	cout << "Ma hang hoa: " << a.thong_tin_hang.ma_hh << endl;
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh << endl;
	cout << "Gia: " << a.thong_tin_hang.gia << endl;
	cout << "Size: " << a.thong_tin_hang.size << endl;
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang << endl;
	cout << "Tong tien: " << a.tong_tien << endl;
	cout << "Trang thai: " << a.trang_thai << endl;
	cout << "\n\t\t=============\n";
}

void xuat_ds_hoa_don_ban_hang(DS_HOA_DON a)
{
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		xuatHoaDonBanHang(k->data);
	}
}

void xuatHoaDonNhapHang(HoaDon a)
{
	cout << "Ma hoa don: " << a.ma_hoa_don << endl;
	cout << "Thong tin hang hoa: " << endl;
	cout << "Ma hang hoa: " << a.thong_tin_hang.ma_hh << endl;
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh << endl;
	cout << "Gia: " << a.thong_tin_hang.gia << endl;
	cout << "Size: " << a.thong_tin_hang.size << endl;
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
	a.tong_tien = (a.thong_tin_hang.gia * a.sl_mua);
	cout << "Tong tien: " << a.tong_tien << endl;
	cout << "Trang thai: " << a.trang_thai << endl;
	cout << "==========================" << endl;
}

void xuat_ds_hoa_don_nhap_hang(DS_HOA_DON a)
{
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		xuatHoaDonNhapHang(k->data);
	}
}

node_hoa_don* khoi_tao_node_hoa_don(HoaDon a)
{
	node_hoa_don* p = new node_hoa_don;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = a;
	p->pNext = NULL;
	return p;
}

void xuat_hoa_don_mua_hang_kh(TREE t)
{
	if (t != NULL)
	{

		for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
		{

			xuatHoaDonBanHang(k->data);
		}
		xuat_hoa_don_mua_hang_kh(t->pLeft);
		xuat_hoa_don_mua_hang_kh(t->pRight);

	}
}

void them_cuoi_ds_hoa_don(DS_HOA_DON& a, HoaDon x)
{
	node_hoa_don* p = khoi_tao_node_hoa_don(x);
	if (a.pHead == NULL)
	{
		a.pHead = a.pTail = p;
	}
	else
	{
		a.pTail->pNext = p;
		a.pTail = p;
	}
}

void xoa_hd_xuat_theo_ma(DS_HOA_DON& a, string b)
{
	node_hoa_don* h = NULL;
	for (node_hoa_don* k = a.pHead; k != NULL;)
	{
		// vt nằm ở đầu danh sách
		if (k->data.ma_hoa_don == b && k == a.pHead)
		{
			a.pHead = a.pHead->pNext;
			delete k;
			k = a.pHead;
		}
		else
		{
			// xoá vị trí bất kì(ko ở đầu)
			if (k->data.ma_hoa_don == b)
			{
				h->pNext = k->pNext;
				delete k;
				k = h;
				// sau khi xoá vt nằm ở cuối
				if (h->pNext == NULL)
				{
					a.pTail = h;
					return;
				}
			}
			h = k;
			k = k->pNext;
		}
	}
	a.sl--;
}

// ============== Sửa thông tin hóa đơn ==================

void duyet_cay_sua_thong_tin(TREE& t, string ma_hd_sua, string ma_kh, string a)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.ma_hoa_don == ma_hd_sua)
				{
					k->data.ma_hang_hoa = a;
					break;
				}
			}
		}
		if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin(t->pLeft, ma_hd_sua, ma_kh, a);
		}
		else if (stoi(ma_kh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin(t->pRight, ma_hd_sua, ma_kh, a);
		}
	}
}

void duyet_cay_xoa_hd_theo_ma(TREE& t, string ma_kh_cu, string ma_hoa_don)
{
	if (t != NULL)
	{
		if (t->data.maKh == ma_kh_cu)
		{
			xoa_hd_xuat_theo_ma(t->data.don_mua_hang, ma_hoa_don);
		}
		if (stoi(ma_kh_cu.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_xoa_hd_theo_ma(t->pLeft, ma_kh_cu, ma_hoa_don);
		}
		else if (stoi(ma_kh_cu.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_xoa_hd_theo_ma(t->pRight, ma_kh_cu, ma_hoa_don);
		}
	}
}

void duyet_cay_them_hd(TREE& t, string ma_moi, HoaDon a)
{
	if (t != NULL)
	{
		if (t->data.maKh == ma_moi)
		{
			them_cuoi_ds_hoa_don(t->data.don_mua_hang, a);
			t->data.don_mua_hang.sl++;
		}
		if (stoi(ma_moi.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_them_hd(t->pLeft, ma_moi, a);
		}
		else if (stoi(ma_moi.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_them_hd(t->pRight, ma_moi, a);
		}
	}
}

void xep_hang_khach_hang_theo_tien(TREE& t)
{
	long long tong_tien_da_tieu = 0;
	if (t != NULL)
	{
		for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
		{
			tong_tien_da_tieu = tong_tien_da_tieu + k->data.tong_tien;
			cout << tong_tien_da_tieu << endl;
		}
		if (tong_tien_da_tieu <= 500000)
		{
			t->data.maKh.replace(0, 2, "SA");
			tong_tien_da_tieu = 0;
		}
		else if (tong_tien_da_tieu > 500000 && tong_tien_da_tieu <= 1000000) {
			t->data.maKh.replace(0, 2, "DO");
			tong_tien_da_tieu = 0;
		}
		else if (tong_tien_da_tieu > 1000000 && tong_tien_da_tieu <= 2000000) {
			t->data.maKh.replace(0, 2, "BA");
			tong_tien_da_tieu = 0;
		}
		else if (tong_tien_da_tieu > 2000000 && tong_tien_da_tieu <= 5000000) {
			t->data.maKh.replace(0, 2, "VA");
			tong_tien_da_tieu = 0;
		}
		else
		{
			t->data.maKh.replace(0, 2, "KC");
			tong_tien_da_tieu = 0;
		}

		xep_hang_khach_hang_theo_tien(t->pLeft);
		xep_hang_khach_hang_theo_tien(t->pRight);
	}

}

void sua_thong_tin_hoa_don(Admin& ad)
{
	string b;
	int c;
	bool check = true;
	cout << "Nhap ma hoa don muon sua: ";
	getline(cin, b);
	b[0] = toupper(b[0]);
	while (check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_nhap) > -1 || check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_xuat) > -1)
	{
		cout << "Ma hoa don khong ton tai!";
		cout << "Nhap ma hoa don muon sua: ";
		getline(cin, b);
		b[0] = toupper(b[0]);
	}
	if (b[0] == 'N')
	{
		while (check == true)
		{
			cout << "\n1.Sua ngay lap hoa don";
			cout << "\n2.Sua trang thai cua hoa don";
			cout << "\n0.Thoat";
			do
			{
				cout << "Chon loai thong tin muon sua: ";
				cin >> c;
				string k = to_string(c);
				while_so(k);
				c = stoi(k);
			} while (c < 0 || c>2);

			switch (c)
			{
			case 1:
			{
				string str;
				cout << "Nhap ngay lap hoa don: ";
				cin >> str;
				do
				{
					if (check_date(str) == false)
					{
						cout << "Ngay thang nhap khong hop le!\n";
						cout << "Nhap ngay lap hoa don: ";
						cin >> str;
					}
					else
					{
						break;
					}
				} while (true);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						k->data.ngay_lap_hd = str;
						break;
					}
				}
				break;
			}
			case 2:
			{
				string str;
				cout << "Nhap trang thai moi cua hoa don: ";
				getline(cin, str);
				while_trang_thai(str);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						k->data.trang_thai = str;
						break;
					}
				}
				break;
			}
			case 0:
			{
				check = false;
				break;
			}
			}

		}

	}
	else
	{
		while (check == true)
		{
			cout << "\n1.Sua ma hang hoa" << endl;
			cout << "2.Sua ma hang Khach hang" << endl;
			cout << "3.Sua ngay lap hoa don" << endl;
			cout << "4.Sua trang thai cua hoa don" << endl;
			cout << "\n0.Thoat";
			do
			{
				cout << "Chon loai thong tin muon sua: ";
				cin >> c;
				string k = to_string(c);
				while_so(k);
				c = stoi(k);

			} while (c < 0 || c>4);

			switch (c)
			{
			case 1:
			{
				string str, tam;
				cout << "Nhap ma hang hoa : ";
				getline(cin, str);
				while_full_ma_hh(str);
				do
				{
					if (check_ma_hh(str, ad.quan_li_ds_hang_hoa) == -1)
					{
						cout << "Hang hoa khong ton tai!\n";
						cout << "Nhap ma hang hoa: ";
						getline(cin, str);
						while_full_ma_hh(str);
					}
					else
					{
						break;
					}
				} while (true);

				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_sua_thong_tin(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						k->data.ma_hang_hoa = str;
						break;
					}
				}
				break;
			}
			case 2:
			{
				string str, ma_cu;
				cout << "Nhap ma khach hang muon sua: ";
				getline(cin, str);
				while_ma_kh(str);
				int asd = 0;
				do
				{
					if (check_ma_kh(str, ad.quan_li_ds_kh.t) == false)
					{
						cout << "Khach hang khong ton tai!" << endl;
						cout << "Nhap ma khach hang muon sua: ";
						getline(cin, str);
						while_ma_kh(str);
					}
					else
					{
						break;
					}
				} while (true);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_xoa_hd_theo_ma(ad.quan_li_ds_kh.t, k->data.ma_kh, b);
						k->data.ma_kh = str;
						duyet_cay_them_hd(ad.quan_li_ds_kh.t, str, k->data);
						break;
					}
				}
				xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
				break;
			}
			case 3:
			{
				string str, tam;
				cout << "Nhap ngay lap hoa don: ";
				cin >> str;
				do
				{
					if (check_date(str) == false)
					{
						cout << "Ngay thang nhap khong hop le!\n";
						cout << "Nhap ngay lap hoa don: ";
						cin >> str;
					}
					else
					{
						break;
					}
				} while (true);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						k->data.ngay_lap_hd = str;
						duyet_cay_sua_thong_tin(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						break;
					}
				}
				break;
			}
			case 4:
			{
				string str, tam;
				cout << "Nhap trang thai moi cua hoa don: ";
				getline(cin, str);
				while_trang_thai(str);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_sua_thong_tin(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						k->data.trang_thai = str;
						break;
					}
				}
				break;
			}
			case 0:
			{
				check = false;
				break;
			}

			}

		}
	}
}

// ================== Khách Hàng =====================

istream& operator >> (istream& in, KhachHang& a)
{
	// mã : SA (mặc định nếu là acc mới tạo) DO / BA / VA / KC
	/*ds_kh b;
	a.maKh = "SA";
	a.maKh = a.maKh + tao_ma_khach_hang(b);*/ // sai r ddcm m BARO
	// mã kh = mã + số random (tách chuỗi số thành số)
	cout << "Nhap ten: "; getline(in, a.ten);
	while_ten(a.ten);
	cout << "Nhap dia chi: "; getline(in, a.diaChi);
	//while_ten(a.diaChi);
	cout << "Nhap so dien thoai: "; getline(in, a.sdt);// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	while_Sdt(a.sdt);
	cout << "Nhap email: "; getline(in, a.email);//example@gmail.com
	while_email(a.email);

	return in;
}

ostream& operator << (ostream& out, KhachHang a)
{
	out << "Ma khach hang: " << a.maKh << endl;
	out << "Ten khach hang: " << a.ten << endl;
	out << "Dia chi :" << a.diaChi << endl;
	out << "SDT: " << a.sdt << endl;
	out << "Email: " << a.email << endl;
	return out;
}

void nhap_khach_hang(KhachHang& a, Admin b)
{
	// mã : SA (mặc định nếu là acc mới tạo) DO / BA / VA / KC
	a.maKh = "SA";
	a.maKh = a.maKh + tao_ma_khach_hang(b.quan_li_ds_kh);
	// mã kh = mã + số random (tách chuỗi số thành số)
	cout << "Nhap ten: "; getline(cin, a.ten);
	while_ten(a.ten);

	cout << "Nhap dia chi: "; getline(cin, a.diaChi);
	//while_ten(a.diaChi);

	cout << "Nhap so dien thoai: "; getline(cin, a.sdt);// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	while_Sdt(a.sdt);

	cout << "Nhap email: "; getline(cin, a.email);//example@gmail.com
	while_email(a.email);
}

void xuat_thong_tin_khach_hang(TREE t)
{
	if (t != NULL)
	{
		cout << t->data;
		xuat_thong_tin_khach_hang(t->pRight);
		xuat_thong_tin_khach_hang(t->pLeft);
	}
}

// ========================= GIO HANG ========================== 

void xuat_gio_hang(TREE t, string ma_kh)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (int i = 0; i < t->data.data_gh.hh.size(); i++)
			{
				xuat_tt_hh_ngan_gon(t->data.data_gh.hh.at(i));
			}
			return;
		}
		else if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			xuat_gio_hang(t->pLeft, ma_kh);
		}
		else
		{
			xuat_gio_hang(t->pRight, ma_kh);
		}
	}
}

// =================== Xóa cây ================================
void node_the_mang(node_kh*& k, TREE& t)
{
	if (k->pRight == NULL)
	{
		t->data = k->data;
		node_kh* tam = k;
		k = k->pLeft; // đưa node hoặc null lên
		delete tam;
	}
	else
	{
		node_the_mang(k->pRight, t);
	}
}
//(xóa khach hang theo ma)
void xoa_khach_hang_theo_ma(TREE& t, string a)
{
	if (t != NULL)
	{
		if (t->data.maKh == a)
		{
			//--- xoá ----
			if (t->pRight != NULL && t->pLeft != NULL)//2 con
			{
				node_the_mang(t->pLeft, t);
			}
			else if (t->pLeft == NULL && t->pRight == NULL)  //la
			{
				delete t;
				t = NULL;
			}
			else  //1 con
			{
				node_kh* tam = t;
				if (t->pLeft != NULL)
				{
					t = t->pLeft;
				}
				else if (t->pRight != NULL)
				{
					t = t->pRight;
				}

				delete tam;
			}
		}
		else if (stoi(a.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			xoa_khach_hang_theo_ma(t->pRight, a);
		}
		else
		{
			xoa_khach_hang_theo_ma(t->pLeft, a);
		}
	}
}

// =================== Cân bằng cây ===========================
int tim_chieu_cao_cay(TREE t) // kiểm tra node con xem ai lớn hơn thì trả về thằng lớn hơn
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		int h_trai = tim_chieu_cao_cay(t->pLeft);
		int h_phai = tim_chieu_cao_cay(t->pRight);
		return (h_phai > h_trai) ? 1 + h_phai : 1 + h_trai;
	}
}

bool kt_lech_p(TREE t, char& checkp)
{
	int h_trai = tim_chieu_cao_cay(t->pLeft);
	int h_phai = tim_chieu_cao_cay(t->pRight);
	int x = h_trai - h_phai;

	if (x >= -1 && x <= 1) // lệch không quá 1 tầng
	{
		return false; // cây đã cân bằng
	}
	else
	{
		checkp = (h_trai > h_phai) ? 'L' : 'R';
		return true; // cây mất cân bằng
	}
}

char kt_lech_q(TREE t, char checkp)
{
	int h_trai = tim_chieu_cao_cay(t->pLeft);
	int h_phai = tim_chieu_cao_cay(t->pRight);

	if (h_trai > h_phai) // Lệch trái
	{
		return 'L';
	}
	else if (h_trai < h_phai)
	{
		return 'R';
	}
	else // bằng => chọn 1 trong 2 => chon theo p để thành LL / RR
	{
		return checkp;
	}
}

void quay_phai(TREE& p, TREE& q)
{
	// p sẽ làm cây con phải q
	// cây con phải của q sẽ làm cây con trái của p
	node_kh* tam = q->pRight; // cho tam giữ cây con phải của q
	q->pRight = p; // cho cây con phải của q là p
	p->pLeft = tam; // cây con trái của p là tạm
}

void quay_trai(TREE& p, TREE& q)
{
	// p sẽ làm cây con trái q
	// cây con trái của q sẽ làm cây con phải của p
	node_kh* tam = q->pLeft; // cho tam giữ cây con trái của q
	q->pLeft = p; // cho cây con trái của q là p
	p->pRight = tam; // cây con phai của p là tạm
}

void can_bang_cay(TREE& t) // duyệt node left right NLR
{
	if (t != NULL)
	{
		// ------- NODE --------------
		char checkp = '0'; //  tạo giá trị ban đầu khác L , R
		if (kt_lech_p(t, checkp) == true) // cây mất cân bằng
		{
			node_kh* p = t;
			node_kh* q = (checkp == 'L') ? p->pLeft : p->pRight; // kiểm tra p lệch loại gì thì q sẽ là cây con thep hướng đó của p
			char checkq = kt_lech_q(q, checkp); // kiểm qua q là loại gì 

			if (checkp == 'L' && checkq == 'L')
			{
				quay_phai(p, q);
			}
			else if (checkp == 'R' && checkq == 'R')
			{
				quay_trai(p, q);
			}
			else if (checkp == 'L' && checkq == 'R')
			{
				node_kh* tam = q->pRight;
				quay_trai(q, q->pRight);
				q = tam;
				t->pLeft = q;
				can_bang_cay(t);
			}
			else if (checkp == 'R' && checkq == 'L')
			{
				node_kh* tam = q->pLeft;
				quay_trai(q, q->pLeft);
				q = tam;
				t->pRight = q;
				can_bang_cay(t);
			}
			t = q;
		}
		// ------------ Left----------------
		can_bang_cay(t->pLeft);
		// -------------Right---------------
		can_bang_cay(t->pRight);
	}
}
// =================== (ADMIN) Sửa Thông Tin Khach Hang ===========================

bool doiMatKhau(string maKh, TREE t, string matkhauMoi)
{
	if (t != NULL) {
		if (t->data.maKh == maKh) {
			t->data.mat_khau = matkhauMoi;
			return true;
		}
		else if (stoi(maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return doiMatKhau(maKh, t->pLeft, matkhauMoi);
		}
		else
		{
			return doiMatKhau(maKh, t->pRight, matkhauMoi);
		}
	}
	else
	{
		return false;
	}
}

bool suaEmail(string maKh, TREE t, string emailMoi)
{
	if (t != NULL) {
		if (t->data.maKh == maKh) {
			t->data.email = emailMoi;
			return true;
		}
		else if (stoi(maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return suaEmail(maKh, t->pLeft, emailMoi);
		}
		else
		{
			return suaEmail(maKh, t->pRight, emailMoi);
		}
	}
	else
	{
		return false;
	}
}

bool suaSdt(string maKh, TREE t, string sdtMoi)
{
	if (t != NULL) {
		if (t->data.maKh == maKh) {
			t->data.sdt = sdtMoi;
			return true;
		}
		else if (stoi(maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return suaSdt(maKh, t->pLeft, sdtMoi);
		}
		else
		{
			return suaSdt(maKh, t->pRight, sdtMoi);
		}
	}
	else
	{
		return false;
	}
}

bool suaDiaChi(string maKh, TREE t, string diaChiMoi)
{
	if (t != NULL) {
		if (t->data.maKh == maKh) {
			t->data.diaChi = diaChiMoi;
			return true;
		}
		else if (stoi(maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return suaDiaChi(maKh, t->pLeft, diaChiMoi);
		}
		else
		{
			return suaDiaChi(maKh, t->pRight, diaChiMoi);
		}
	}
	else
	{
		return false;
	}
}

bool suaTenKh(string maKh, TREE t, string tenMoi) {
	if (t != NULL)
	{
		if (t->data.maKh == maKh) {
			t->data.ten = tenMoi;
			return true;
		}
		else if (stoi(maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return suaTenKh(maKh, t->pLeft, tenMoi);
		}
		else
		{
			return suaTenKh(maKh, t->pRight, tenMoi);
		}
	}
	else
	{
		return false;
	}
}

void suaThongTinKh(TREE& t) {
	bool kt_menu = true;
	int chon;
	cout << "Nhap ma Khach hang can sua:";
	string maKh;
	getline(cin, maKh);
	while_ma_kh(maKh);
	while (check_ma_kh(maKh, t) == false)
	{
		cout << "Khong tim thay ma khach hang." << endl;
		cout << "Nhap lai:";
		getline(cin, maKh);
		while_ma_kh(maKh);
	}
	while (kt_menu == true) {
		cout << "1.Sua ten " << endl;
		cout << "2.Sua dia chi " << endl;
		cout << "3.Sua so dien thoai " << endl;
		cout << "4.Sua email " << endl;
		cout << "5.Doi mat khau " << endl;
		cout << "0.Thoat " << endl;
		do
		{
			cout << "Nhap lua chon:";
			cin >> chon;
			string tam = to_string(chon);
			while_so(tam);
			chon = stoi(tam);

		} while (chon < 0 || chon>5);

		switch (chon)
		{
		case 1:
		{
			string tenMoi;
			cout << "Nhap ten moi:";
			cin.ignore();
			getline(cin, tenMoi);
			while_ten(tenMoi);
			if (suaTenKh(maKh, t, tenMoi) == true) {
				cout << "Sua thanh conng ten moi!" << endl;
			}
			else {
				cout << "Sua that bai!" << endl;
			}
			system("pause");
			break;
		}
		case 2:
		{
			string diaChiMoi;
			cout << "Nhap dia chi moi:";
			cin.ignore();
			getline(cin, diaChiMoi);
			//while_ten(diaChiMoi);
			if (suaDiaChi(maKh, t, diaChiMoi) == true) {
				cout << "Sua thanh conng ten moi!" << endl;
			}
			else {
				cout << "Sua that bai!" << endl;
			}
			system("pause");
			break;
		}
		case 3:
		{
			string sdtMoi;
			cout << "Nhap so dien thoai moi:";
			cin.ignore();
			getline(cin, sdtMoi);
			while_Sdt(sdtMoi);
			if (suaSdt(maKh, t, sdtMoi) == true) {
				cout << "Sua thanh conng ten moi!" << endl;
			}
			else {
				cout << "Sua that bai!" << endl;
			}
			system("pause");
			break;
		}
		case 4:
		{
			string emailMoi;
			cout << "Nhap email moi:";
			cin.ignore();
			getline(cin, emailMoi);
			while_email(emailMoi);
			if (suaEmail(maKh, t, emailMoi) == true) {
				cout << "Sua thanh conng ten moi!" << endl;
			}
			else {
				cout << "Sua that bai!" << endl;
			}
			system("pause");
			break;
		}
		case 5:
		{
			string matkhauMoi;
			cout << "Nhap mat khau moi:";
			cin.ignore();
			cin >> matkhauMoi;
			if (doiMatKhau(maKh, t, matkhauMoi) == true) {
				cout << "Sua thanh conng ten moi!" << endl;
			}
			else {
				cout << "Sua that bai!" << endl;
			}
			system("pause");
			break;
		}
		case 0:
		{
			kt_menu = false;
			system("pause");
			break;
		}
		}
	}
}

// =================== (KHACH HANG) Sửa Thông Tin ===========================

void thanh_toan_hang()
{

}

void hien_thi_gio_hang(gio_hang gh)
{
	for (int i = 0; i < gh.hh.size(); i++) {
		xuat_tt_hh_ngan_gon(gh.hh[i]);
		//tong_tien += gh.hh[i].gia * gh.hh[i].soLuongTonKho;
	}
	//cout << "Tong gia tri don" << tong_tien << endl;
}

void xoa_sp_khoi_gio_hang(gio_hang& gh)
{
	bool kt_menu = true;
	string ma_sp_xoa;
	cout << "Nhap ma san pham can xoa: ";
	cin >> ma_sp_xoa;
	for (int i = 0; i < gh.hh.size(); i++) {
		if (gh.hh[i].ma_hh == ma_sp_xoa) {
			gh.hh.erase(gh.hh.begin() + i);
			cout << "San pham da duoc xoa khoi danh sach!" << endl;
			return;
		}
	}
	cout << "San pham khong ton tai trong kho!" << endl;
}

void them_sp_vao_gio_hang(DS_Hang_Hoa dshh, gio_hang& gh)
{
	bool kt_menu = true;
	int lua_chon;
	int so_luong_mua = 0;

	while (kt_menu) {
		cout << "1.Mua Ao." << endl;
		cout << "2.Mua Quan." << endl;
		cout << "3.Thoat." << endl;
		cout << "Lua chon:";
		cin >> lua_chon;
		switch (lua_chon) {
		case 1:
		{
			string ma_ao_mua;
			cout << "Nhap ma ao mua:";
			cin >> ma_ao_mua;
			for (int i = 0; i < dshh.ds_ao.size(); i++) {

				if (dshh.ds_ao[i].ma_hh == ma_ao_mua) {
					cout << "Nhap so luong: ";
					cin >> so_luong_mua;
					if (so_luong_mua > dshh.ds_ao[i].soLuongTonKho) {
						cout << "San pham khong du hoac da het hang!" << endl;

						dshh.ds_ao[i].soLuongTonKho -= so_luong_mua;
						HangHoa hang_hoa_mua = { ma_ao_mua,dshh.ds_ao[i].ten_hh,so_luong_mua,dshh.ds_ao[i].gia,dshh.ds_ao[i].size,dshh.ds_ao[i].mo_ta_sp,dshh.ds_ao[i].thoi_gian_nhap_hang };
						gh.hh.insert(gh.hh.begin(), hang_hoa_mua);
						cout << "San pham da duoc them vao gio hang!" << endl;
						return;
					}
				}
			}
			system("pause");
			break;

		}
		case 2:
		{
			string ma_quan_mua;
			cout << "Nhap ma quan mua:";
			cin >> ma_quan_mua;
			for (int i = 0; i < dshh.ds_quan.size(); i++) {
				if (dshh.ds_quan[i].ma_hh == ma_quan_mua) {
					cout << "Nhap so luong: ";
					cin >> so_luong_mua;
					return;
				}
				if (so_luong_mua > dshh.ds_quan[i].soLuongTonKho) {
					cout << "San pham khong du hoac da het hang!" << endl;
					return;
				}
				dshh.ds_quan[i].soLuongTonKho -= so_luong_mua;
				HangHoa hang_hoa_mua = { ma_quan_mua,dshh.ds_quan[i].ten_hh,so_luong_mua,dshh.ds_quan[i].gia,dshh.ds_quan[i].size,dshh.ds_quan[i].mo_ta_sp,dshh.ds_quan[i].thoi_gian_nhap_hang };
				gh.hh.insert(gh.hh.begin(), hang_hoa_mua);
				cout << "San pham da duoc them vao gio hang!" << endl;
				return;
			}
			system("pause");
			break;
		}
		case 3:
		{
			kt_menu = false;
			break;
		}
		}
	}
}

void chuc_nang_khach_hang(KhachHang a, DS_Hang_Hoa dshh, gio_hang gh)
{
	bool kt_menu = true;
	unsigned short luaChonKH;
	while (kt_menu)
	{
		cout << "1. Xem san pham ao" << endl;
		cout << "2. Xem san pham quan" << endl;
		cout << "3. Them san pham vao gio hang" << endl;
		cout << "4. Xoa san pham khoi gio hang" << endl;
		cout << "5. Hien thi gio hang va tinh tong gia tri don hang" << endl;
		cout << "6. Thanh toan" << endl;
		cout << "7. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> luaChonKH;
		switch (luaChonKH)
		{
		case 1:
		{
			xuat_thong_tin_ao(dshh);
			break;
		}
		case 2:
		{
			xuat_thong_tin_quan(dshh);
			break;
		}
		case 3:
		{
			them_sp_vao_gio_hang(dshh, a.data_gh);
			break;
		}
		case 4:
		{
			xoa_sp_khoi_gio_hang(gh);
			break;
		}
		case 5:
		{
			hien_thi_gio_hang(gh);
			break;
		}
		case 6:
		{

		}
		case 7:
		{
			kt_menu = false;
			break;
		}
		}
	}
}

// =========== sua thong tin hang hoa ===========
// ============ AO ============
bool sua_ten_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string ten_ao_moi) {

	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).ten_hh = ten_ao_moi;
			return true;
		}
	}
	return false;
}

bool sua_so_luong_ao_ton_kho(string ma_hang_hoa, DS_Hang_Hoa& a, unsigned short sl_ao_moi) {
	//AO 
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).soLuongTonKho = sl_ao_moi;
			return true;
		}
	}
	return false;

}

bool sua_gia_ao(string ma_hang_hoa, DS_Hang_Hoa& a, long long gia_ao_moi) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).gia = gia_ao_moi;
			return true;
		}
	}
	return false;

}

bool sua_size_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string size_ao_moi) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).size = size_ao_moi;
			return true;
		}
	}
	return false;

}

bool sua_mo_ta_sp_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string mo_ta_ao) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).mo_ta_sp = mo_ta_ao;
			return true;
		}
	}
	return false;

}

bool sua_thoi_gian_nhap_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string thoi_gian_nhap_ao) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).thoi_gian_nhap_hang = thoi_gian_nhap_ao;
			return true;
		}
	}
	return false;

}

// ============	QUAN ============
bool sua_ten_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string ten_quan_moi) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).ten_hh = ten_quan_moi;
			return true;
		}
	}
	return false;

}

bool sua_so_luong_quan_ton_kho(string ma_hang_hoa, DS_Hang_Hoa& a, unsigned short sl_quan_moi) {
	//quan 
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).soLuongTonKho = sl_quan_moi;
			return true;
		}
	}
	return false;

}

bool sua_gia_quan(string ma_hang_hoa, DS_Hang_Hoa& a, long long gia_quan_moi) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).gia = gia_quan_moi;
			return true;
		}
	}
	return false;

}

bool sua_size_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string size_quan_moi) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).size = size_quan_moi;
			return true;
		}
	}
	return false;

}

bool sua_mo_ta_sp_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string mo_ta_quan) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).mo_ta_sp = mo_ta_quan;
			return true;
		}
	}
	return false;

}

bool sua_thoi_gian_nhap_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string thoi_gian_nhap_quan) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).thoi_gian_nhap_hang = thoi_gian_nhap_quan;
			return true;
		}
	}
	return false;

}

// ============ QUAN & AO ============
void sua_hang_hoa(DS_Hang_Hoa& a) {
	bool kt_menu = true;
	int luaChon;
	cout << "Nhap ma hang hoa can sua:";
	string ma_hh;
	getline(cin, ma_hh);
	while_full_ma_hh(ma_hh);
	while (check_ma_hh(ma_hh, a) == -1)
	{
		cout << "Khong tim thay ma hang hoa." << endl;
		cout << "Nhap lai:";
		cin >> ma_hh;
		while_full_ma_hh(ma_hh);
	}
	while (kt_menu == true) {
		while (ma_hh[0] == 'A') {
			cout << "Nhap lua chon : " << endl;
			cout << "1.Sua ten ao " << endl;
			cout << "2.Sua so luong ao ton kho " << endl;
			cout << "3.Sua gia ao " << endl;
			cout << "4.Sua size ao " << endl;
			cout << "5.Sua mo ta ao " << endl;
			cout << "6.Sua thoi gian nhap ao " << endl;
			cout << "7.Thoat" << endl;
			do {
				cout << "Nhap lua chon :";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 7);
			switch (luaChon) {
			case 1: {
				string ao_moi;
				cout << "\nNhap ten ao moi : ";
				cin.ignore();
				getline(cin, ao_moi);
				while_ten(ao_moi);
				if (sua_ten_ao(ma_hh, a, ao_moi) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}

				break;
			}
				  // dang sua
			case 2: {
				string sl_ao_moi;
				cin.ignore();
				cout << "\nNhap so luong ao moi :"; getline(cin, sl_ao_moi);
				while_so(sl_ao_moi);
				if (sua_so_luong_ao_ton_kho(ma_hh, a, stoi(sl_ao_moi)) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 3: {
				string gia_ao;
				cin.ignore();
				cout << "\nNhap gia ao moi : "; getline(cin, gia_ao);
				while_so(gia_ao);
				if (sua_gia_ao(ma_hh, a, stoi(gia_ao)) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 4: {
				string size_ao_moi;
				cin.ignore();
				cout << "\nNhap size ao moi : "; getline(cin, size_ao_moi);
				while_size_ao(size_ao_moi);

				if (sua_size_ao(ma_hh, a, size_ao_moi) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 5: {
				string mo_ta_ao;
				cin.ignore();
				cout << "\nNhap mo ta ao moi : "; getline(cin, mo_ta_ao);
				while_ten(mo_ta_ao);
				if (sua_mo_ta_sp_ao(ma_hh, a, mo_ta_ao) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 6: {
				string thoi_gian_nhap_ao;
				cin.ignore();
				cout << "\nNhap thoi gian nhap ao moi :"; getline(cin, thoi_gian_nhap_ao);
				while (check_date(thoi_gian_nhap_ao) == false) {
					cout << "Nhap lai :"; getline(cin, thoi_gian_nhap_ao);
				}
				if (sua_thoi_gian_nhap_ao(ma_hh, a, thoi_gian_nhap_ao) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 7: {
				kt_menu = false;
				return;
			}
			}
		}
		while (ma_hh[0] == 'Q') {
			cout << "Nhap lua chon : " << endl;
			cout << "1.Sua ten quan " << endl;
			cout << "2.Sua so luong quan ton kho " << endl;
			cout << "3.Sua gia quan " << endl;
			cout << "4.Sua size quan " << endl;
			cout << "5.Sua mo ta quan " << endl;
			cout << "6.Sua thoi gian nhap quan " << endl;
			cout << "7.Thoat" << endl;
			do {
				cout << "Nhap lua chon :";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 7);
			switch (luaChon) {
			case 1: {
				string quan_moi;
				cout << "\nNhap ten quan moi : ";
				cin.ignore();
				getline(cin, quan_moi);
				while_ten(quan_moi);
				if (sua_ten_quan(ma_hh, a, quan_moi) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}

				break;
			}
			case 2: {
				string sl_quan_moi;
				cin.ignore();
				cout << "\nNhap so luong quan moi :"; getline(cin, sl_quan_moi);
				while_so(sl_quan_moi);
				if (sua_so_luong_quan_ton_kho(ma_hh, a, stoi(sl_quan_moi)) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 3: {
				string gia_quan;
				cin.ignore();
				cout << "\nNhap gia quan moi : "; getline(cin, gia_quan);
				while_so(gia_quan);
				if (sua_gia_quan(ma_hh, a, stoi(gia_quan)) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 4: {
				string size_quan_moi;
				cin.ignore();
				cout << "\nNhap size quan moi : "; getline(cin, size_quan_moi);
				while_size_quan(size_quan_moi);
				if (sua_size_quan(ma_hh, a, size_quan_moi) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 5: {
				string mo_ta_quan;
				cout << "\nNhap mo ta quan moi : ";
				cin.ignore();
				getline(cin, mo_ta_quan);
				while_ten(mo_ta_quan);
				if (sua_mo_ta_sp_quan(ma_hh, a, mo_ta_quan) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 6: {
				string thoi_gian_nhap_quan;
				cout << "\nNhap thoi gian nhap quan moi :";
				cin.ignore();
				getline(cin, thoi_gian_nhap_quan);
				while (check_date(thoi_gian_nhap_quan) == false) {
					cout << "Nhap lai :"; getline(cin, thoi_gian_nhap_quan);
				}
				if (sua_thoi_gian_nhap_quan(ma_hh, a, thoi_gian_nhap_quan) == true) {
					cout << "Sua thanh cong!" << endl;
				}
				else {
					cout << "Sua that bai!" << endl;
				}
				break;
			}
			case 7: {
				kt_menu = false;
				return;
			}
			}
		}
	}
}
