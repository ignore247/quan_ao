#pragma once
#include "Check_du_lieu_nhap.h"
#include "Xu_li_do_hoa.h"
//-----------Load thông tin----------
//===Khach hang===//
void duyet_NLR_xuat_thong_tin_KH(TREE t) {
	if (t != NULL) {
		cout << t->data.ten << endl;
		cout << t->data.maKh << endl;
		duyet_NLR_xuat_thong_tin_KH(t->pLeft);
		duyet_NLR_xuat_thong_tin_KH(t->pRight);
	}
	cout << "alo alo" << endl;
}
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

//===Danh sach hoa don===//
void xuat_ds_hd_nhap(DS_HOA_DON dshd) {
	if (dshd.pHead == NULL) {
		cout << "Danh sach hoa don trong!" << endl;
		system("pause");
	}
	else {
		for (node_hoa_don* k = dshd.pHead; k != NULL; k = k->pNext) {
			cout << k->data.ma_hoa_don << endl;
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
	// mã : Q,A
	cout << "Nhap ma hang hoa (Q/A): "; cin >> a.ma_hh;
	check_Ma_Hang_Hoa(a.ma_hh);
	a.ma_hh = toupper(a.ma_hh[0]);
	//mã hh = mã + số random
	a.ma_hh = a.ma_hh + tao_ma_hang_hoa(b);
	cin.ignore();

	cout << "Nhap ten hang hoa: "; getline(cin, a.ten_hh);
	check_Ten(a.ten_hh);
	chuanHoa(a.ten_hh);

	cout << "Nhap size: "; cin >> a.size;
	check_Size(a.size);

	regex check_gia("^[0-9]+$");
	string tam;
	cout << "Gia: "; cin >> tam;
	check_So(tam);
	a.gia = stoll(tam);
	cin.ignore();

	cout << "Nhap mo ta san pham: "; getline(cin, a.mo_ta_sp);
	// mô tả k cần nhập kích thước chi tiết vì đã kẻ bảng


	cout << "Nhap so luong trong kho: "; cin >> tam;
	check_So(tam);
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
	for (int i = 0; i < dshh.ds_quan.size(); i++) 
	{
		xuat_tt_hh_ngan_gon(dshh.ds_ao.at(i));
	}
}

//=================== Hóa Đơn =========================
void nhapHoaDon(HoaDon& a, ds_hoa_don b, DS_Hang_Hoa c, ds_khach_hang d)
{
	string loai_hd;
	cout << "Nhap loai hoa don (Xuat/Nhap) : "; cin >> loai_hd; // cho nhập Xuat / Nhap
	chuanHoa(loai_hd);
	check_Loai_Hoa_Don(loai_hd);
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
		cin >> a.ma_kh;
		a.ma_kh[0] = toupper(a.ma_kh[0]);
		a.ma_kh[1] = toupper(a.ma_kh[1]);
		// ktra mã khách hàng xem có tồn tại không
		while (true)
		{
			if (check_ma_kh(a.ma_kh, d.t) == -1)
			{
				cout << "Khach hang khong ton tai!";
				cout << "\nNhap ma khach hang: ";
				cin >> a.ma_kh;
				a.ma_kh[0] = toupper(a.ma_kh[0]);
				a.ma_kh[1] = toupper(a.ma_kh[1]);
			}
			else
			{
				break;
			}
		}
		cout << "Nhap ma hang hoa: "; cin >> a.ma_hang_hoa;
		a.ma_hang_hoa[0] = toupper(a.ma_hang_hoa[0]);
		// ktra hh có tồn tại hay không 
		while (true)
		{
			if (check_ma_hh(a.ma_hang_hoa, c) == -1)
			{
				cout << "Hang hao khong ton tai!";
				cout << "\nNhap ma hang hoa: ";
				cin >> a.ma_kh;
				a.ma_hang_hoa[0] = toupper(a.ma_hang_hoa[0]);
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
		cout << "Nhap ma hang hoa (Q/A): "; cin >> a.ma_hang_hoa;
		check_Ma_Hang_Hoa(a.ma_hang_hoa);
		cin.ignore();
		a.thong_tin_hang.ma_hh = a.thong_tin_hang.ma_hh + tao_ma_hang_hoa(c);
		cout << "Nhap ten hang hoa: ";
		getline(cin, a.thong_tin_hang.ten_hh);
		chuanHoa(a.thong_tin_hang.ten_hh);
		check_Ten(a.thong_tin_hang.ten_hh);
		cout << "Nhap size: ";
		cin >> a.thong_tin_hang.size;
		check_Size(a.thong_tin_hang.size);
		a.thong_tin_hang.size[0] = toupper(a.thong_tin_hang.size[0]);
		string gia;
		cout << "Nhap gia: ";
		cin >> gia;
		check_So(gia);
		a.gia_nhap = stoll(gia);
	}
	string tam;
	cout << "Nhap so luong mua: "; cin >> tam;
	check_So(tam);
	a.sl_mua = stoi(tam);

	cout << "Nhap phuong thuc thanh toan( Cod/Bank ): "; cin >> a.pptt;
	chuanHoa(a.pptt);
	check_PTTT(a.pptt);

	// ngày lập hóa đơn : lấy thời gian máy tính
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);
	cin.ignore();
	cout << "Trang thai: ";
	getline(cin, a.trang_thai);
}

void taoHoaDonKhiKhachDatHang(HoaDon& a, ds_hoa_don b, HangHoa c)
{
	a.ma_hoa_don = 'X' + tao_ma_hoa_don(b);
	a.ma_hang_hoa = c.ma_hh;
	cout << "Nhap so luong mua: "; cin >> a.sl_mua;
	cout << "Nhap phuong thuc thanh toan( COD/Bank ): "; cin >> a.pptt;
	// ngày lập hóa đơn : lấy thời gian máy tính
	thoiGianThuc(a.ngay_lap_hd);
}

void xuatHoaDonBanHang(HoaDon a, DS_Hang_Hoa c)
{
	cout << "Ma hoa don: " << a.ma_hoa_don << endl;
	cout << "Ma khach hang: " << a.ma_kh << endl;
	cout << "\tThong tin hang hoa: " << endl;
	cout << "Ma hang hoa: " << a.ma_hang_hoa << endl;
	for (int i = 0;i < c.ds_ao.size(); i++)
	{
		if (a.ma_hang_hoa == c.ds_ao.at(i).ma_hh)
		{
			cout << "Ten hang hoa: " << c.ds_ao.at(i).ten_hh << endl;
			cout << "Gia: " << c.ds_ao.at(i).gia << endl;
			cout << "Size: " << c.ds_ao.at(i).size << endl;
			break;
		}
	}
	for (int i = 0; i < c.ds_quan.size(); i++)
	{
		if (a.ma_hang_hoa == c.ds_quan.at(i).ma_hh)
		{
			cout << "Ten hang hoa: " << c.ds_quan.at(i).ten_hh << endl;
			cout << "Gia: " << c.ds_quan.at(i).gia << endl;
			cout << "Size: " << c.ds_quan.at(i).size << endl;
			break;
		}
	}
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang << endl;
	cout << "Tong tien: " << a.tong_tien << endl;
	cout << "Trang thai: " << a.trang_thai << endl;
	cout << "\n\t\t=============\n";
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
void duyet_cay_sua_thong_tin(TREE& t,string ma_hd_sua, string ma_kh, string a)
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
		xep_hang_khach_hang_theo_tien(t->pLeft);
		for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
		{
			tong_tien_da_tieu = tong_tien_da_tieu + k->data.tong_tien;
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
		xep_hang_khach_hang_theo_tien(t->pRight);
	}

}

void sua_thong_tin_hoa_don(Admin &ad)
{
	string b;
	int c;
	bool check = true;
	cout << "Nhap ma hoa don muon sua: ";
	cin >> b;
	b[0] = toupper(b[0]);
	while (check_trung_ma_hd(b,ad.quan_li_ds_hoa_don_nhap) > -1 || check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_xuat) > -1)
	{
		cout << "Ma hoa don khong ton tai!";
		cout << "Nhap ma hoa don muon sua: ";
		cin >> b;
	}
	if (b[0] == 'N')
	{
		while (check == true)
		{
			cout << "\n1.Sua ngay lap hoa don" << endl;
			cout << "2.Sua trang thai cua hoa don" << endl;
			cout << "\n0.Thoat";
			do
			{
				cout << "Chon loai thong tin muon sua: ";
				cin >> c;
			} while (c < 0);
				
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
					cin >> str;
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
			} while (c < 0);

			switch (c)
			{
			case 1:
			{
				string str,tam;
				cout << "Nhap ma hang hoa : ";
				cin >> str;
				str[0] = toupper(str[0]);
				do
				{
					if (check_ma_hh(str, ad.quan_li_ds_hang_hoa) == -1)
					{
						cout << "Hang hoa khong ton tai!\n";
						cout << "Nhap ma hang hoa: ";
						cin >> str;
						str[0] = toupper(str[0]);
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
				string str,ma_cu;
				cout << "Nhap ma khach hang muon sua: ";
				cin >> str;
				str[0] = toupper(str[0]);
				str[1] = toupper(str[1]);
				int asd = 0;
				do
				{
					if (check_ma_kh(str,ad.quan_li_ds_kh.t) == -1)
					{
						cout << "Khach hang khong ton tai!" << endl;
						cout << "Nhap ma khach hang muon sua: ";
						cin >> str;
						str[0] = toupper(str[0]);
						str[1] = toupper(str[1]);
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
						duyet_cay_xoa_hd_theo_ma(ad.quan_li_ds_kh.t, k->data.ma_kh,b);
						k->data.ma_kh = str;
						duyet_cay_them_hd(ad.quan_li_ds_kh.t,str,k->data);
						break;
					}
				}
				xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
				break;
			}
			case 3:
			{
				string str,tam;
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
				string str,tam;
				cout << "Nhap trang thai moi cua hoa don: ";
				cin >> str;
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
	check_Ten(a.ten);

	cout << "Nhap dia chi: "; getline(in, a.diaChi);
	in.ignore();
	cout << "Nhap so dien thoai: "; in >> a.sdt;// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	check_Sdt(a.sdt);
	cout << "Nhap email: "; in >> a.email;//example@gmail.com
	check_email(a.email);

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
	check_Ten(a.ten);
	cout << "Nhap dia chi: "; getline(cin, a.diaChi);
	cin.ignore();
	cout << "Nhap so dien thoai: "; cin >> a.sdt;// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	check_Sdt(a.sdt);
	cout << "Nhap email: "; cin >> a.email;//example@gmail.com
	check_email(a.email);
}

// ========================= GIO HANG ========================== 


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

void xoa_khach_hang_theo_ma(TREE &t, string a)
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
		else if (stoi (a.substr(2,4) ) > stoi(t->data.maKh.substr(2,4)))
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
			return true ;
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

bool suaDiaChi(string maKh, TREE t, string diaChiMoi )
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

bool suaTenKh(string maKh,TREE t,string tenMoi) {
	if (t != NULL) 
	{
		if (t->data.maKh == maKh) {
			t->data.ten = tenMoi;
			return true;
		}
		else if (stoi(maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return suaTenKh(maKh, t->pLeft,tenMoi);
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

void suaThongTinKh(TREE &t) {
	bool kt_menu = true;
	int chon;
	string tam;
	regex ktra_luachon(R"(\d)");
	cout << "Nhap ma Khach hang can sua:";
	string maKh;
	cin>> maKh;
	while (check_ma_kh(maKh, t) == -1)
	{
		cout << "Khong tim thay ma khach hang." << endl;
		cout << "Nhap lai:";
		cin>> maKh;
	}
	while (kt_menu==true) {
		cout << "1.Sua ten " << endl;
		cout << "2.Sua dia chi " << endl;
		cout << "3.Sua so dien thoai " << endl;
		cout << "4.Sua email " << endl;
		cout << "5.Doi mat khau " << endl;
		cout << "0.Thoat " << endl;
		cout << "Nhap lua chon:";
		cin >> tam;
		do
		{
			if (regex_match(tam,ktra_luachon) == false || stoi(tam) <0 || stoi(tam) >5)
			{
				cout << "Nhap khong hop le!\n";
				cout << "Nhap lua chon:";
				cin >> tam;
			}
			else
			{
				chon = stoi(tam);
				break;
			}
		} while (true);
		switch (chon) 
		{
		case 1:
		{
			string tenMoi;
			cout << "Nhap ten moi:";
			getline(cin, tenMoi);
			check_Ten(tenMoi);
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
			getline(cin, diaChiMoi);
			check_Ten(diaChiMoi);
			if (suaDiaChi(maKh, t, diaChiMoi)==true) {
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
			getline(cin, sdtMoi);
			check_email(sdtMoi);
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
			getline(cin, emailMoi);
			check_email(emailMoi);
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

void hien_thi_gio_hang()
{

}

void xoa_sp_khoi_gio_hang(DS_Hang_Hoa dshh,gio_hang &gh)
{
	bool kt_menu = true;

}

void them_sp_vao_gio_hang(DS_Hang_Hoa dshh, gio_hang &gh)
{
	bool kt_menu = true;
	int lua_chon;
	int so_luong_mua;
	
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
				}
				if (so_luong_mua > dshh.ds_ao[i].soLuongTonKho) {
					cout << "San pham khong du hoac da het hang!" << endl;
					return;
				}
				dshh.ds_ao[i].soLuongTonKho -= so_luong_mua;
				HangHoa hang_hoa_mua = { ma_ao_mua,dshh.ds_ao[i].ten_hh,so_luong_mua,dshh.ds_ao[i].gia,dshh.ds_ao[i].size,dshh.ds_ao[i].mo_ta_sp,dshh.ds_ao[i].thoi_gian_nhap_hang };
				gh.hh.insert(gh.hh.begin(), hang_hoa_mua);
				cout << "San pham da duoc them vao gio hang!" << endl;
				return;
			}
			system("pause");
			break;

		}
		case 2:
		{
			string ma_quan_mua;
			cout << "Nhap ma ao mua:";
			cin >> ma_quan_mua;
			for (int i = 0; i < dshh.ds_ao.size(); i++) {
				if (dshh.ds_ao[i].ma_hh == ma_quan_mua) {
					cout << "Nhap so luong: ";
					cin >> so_luong_mua;
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

void chuc_nang_khach_hang(DS_Hang_Hoa dshh,gio_hang gh)
{
	bool kt_menu = true;
	unsigned short luaChonKH;
	while (kt_menu)
	{
		cout << "1. Them san pham vao gio hang" << endl;
		cout << "2. Xoa san pham khoi gio hang" << endl;
		cout << "3. Hien thi gio hang va tinh tong gia tri don hang" << endl;
		cout << "4. Thanh toan" << endl;
		cout << "5. Thoat" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> luaChonKH;
		switch (luaChonKH)
		{
		case 1:
		{
			them_sp_vao_gio_hang(dshh,gh);
			break;
		}
		case 2:
		{
			xoa_sp_khoi_gio_hang(dshh, gh);
			break;
		}
		case 3:
		{

		}
		}
	}
}