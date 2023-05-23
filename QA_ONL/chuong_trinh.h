#pragma once
#include "Check_du_lieu_nhap.h"
#include "Xu_li_do_hoa.h"



// ================== Hàng Hóa =====================
void nhapHangHoa(HangHoa& a, DS_Hang_Hoa b)
{
	
	cout << "Nhap ma hang hoa (Q/A): "; getline(cin, a.ma_hh);// mã : Q,A
	while_ma_hh(a.ma_hh);
	a.ma_hh = a.ma_hh + tao_ma_hang_hoa(b);//mã hh = mã + số random

	cout << "Nhap ten hang hoa: "; getline(cin, a.ten_hh);
	while_ten(a.ten_hh);
	
	cout << "Nhap size: "; getline(cin , a.size);
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

void xuat_thong_tin_hh_xoa(DS_Hang_Hoa_Xoa dshh)
{
	for (int i = 0; i < dshh.ds.size(); i++)
	{
		xuat_tt_hh_ngan_gon(dshh.ds.at(i).hh);
		cout << "Ngay xoa: " << dshh.ds.at(i).ngay_xoa;
		cout << "\n\t\t====================\n";
	}
}


// =========== sua thong tin hang hoa ===========
//  AO 
void sua_ten_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string ten_ao_moi) {

	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).ten_hh = ten_ao_moi;
		}
	}
}

void sua_so_luong_ao_ton_kho(string ma_hang_hoa, DS_Hang_Hoa& a, unsigned short sl_ao_moi) {
	
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).soLuongTonKho = sl_ao_moi;
		}
	}
}

void sua_gia_ao(string ma_hang_hoa, DS_Hang_Hoa& a, long long gia_ao_moi) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).gia = gia_ao_moi;
		}
	}
}

void sua_size_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string size_ao_moi) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).size = size_ao_moi;
		}
	}
}

void sua_mo_ta_sp_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string mo_ta_ao) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).mo_ta_sp = mo_ta_ao;
		}
	}
}

void sua_thoi_gian_nhap_ao(string ma_hang_hoa, DS_Hang_Hoa& a, string thoi_gian_nhap_ao) {
	for (int i = 0; i < a.ds_ao.size(); i++) {
		if (ma_hang_hoa == a.ds_ao.at(i).ma_hh) {
			a.ds_ao.at(i).thoi_gian_nhap_hang = thoi_gian_nhap_ao;
		}
	}
}
// 	QUAN 
void sua_ten_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string ten_quan_moi) {
	
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_ao.at(i).ten_hh = ten_quan_moi;
		}
	}
}

void sua_so_luong_quan_ton_kho(string ma_hang_hoa, DS_Hang_Hoa& a, unsigned short sl_quan_moi) {
	
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).soLuongTonKho = sl_quan_moi;
		}
	}
}

void sua_gia_quan(string ma_hang_hoa, DS_Hang_Hoa& a, long long gia_quan_moi) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).gia = gia_quan_moi;
		}
	}
}

void sua_size_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string size_quan_moi) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).size = size_quan_moi;
		}
	}
}

void sua_mo_ta_sp_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string mo_ta_quan) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).mo_ta_sp = mo_ta_quan;
		}
	}
}

void sua_thoi_gian_nhap_quan(string ma_hang_hoa, DS_Hang_Hoa& a, string thoi_gian_nhap_quan) {
	for (int i = 0; i < a.ds_quan.size(); i++) {
		if (ma_hang_hoa == a.ds_quan.at(i).ma_hh) {
			a.ds_quan.at(i).thoi_gian_nhap_hang = thoi_gian_nhap_quan;
		}
	}
}

void sua_hang_hoa(DS_Hang_Hoa& a) {
	bool kt_menu = true;
	int luaChon;
	string tam;
	regex ktra_luachon(R"(\d)");
	cout << "Nhap ma hang hoa can sua:";
	string ma_hh;
	cin >> ma_hh;
	while (check_ma_hh(ma_hh, a) == -1)
	{
		cout << "Khong tim thay ma khach hang." << endl;
		cout << "Nhap lai:";
		cin >> ma_hh;
		//check
	}
	while (kt_menu == true) {
		cout << "1.Sua ten hang hoa " << endl;
		cout << "2.Sua so luong ton kho " << endl;
		cout << "3.Sua gia " << endl;
		cout << "4.Sua size " << endl;
		cout << "5.Sua mo ta san pham " << endl;
		cout << "6.Sua thoi gian nhap hang " << endl;
		cout << "0.Thoat" << endl;
		cout << "Nhap lua chon:";
		cin >> tam;
		do {
			if (regex_match(tam, ktra_luachon) == false || stoi(tam) < 0 || stoi(tam) > 5) {
				cout << "Nhap khong hop le!\n";
				cout << "Nhap lua chon:";
				cin >> tam;
			}
			else {
				luaChon = stoi(tam);
				break;
			}
		} while (true);
		switch (luaChon) {
		case 1: {
			while (true) {
				cout << "\n1. Sua ten ao.";
				cout << "\n2.Sua ten quan.";
				cout << "\n3. Thoat.";
				cout << "\nNhap lua chon :";
				int chon1;
				cin >> chon1;
				switch (chon1) {
				case 1: {
					string ao_moi;
					cout << "\nNhap ten ao moi : "; getline(cin, ao_moi);
					//check
					sua_ten_ao(ma_hh, a, ao_moi);
					break;
				}
				case 2: {
					string quan_moi;
					cout << "\nNhap ten quan moi : "; getline(cin, quan_moi);
					//check
					sua_ten_quan(ma_hh, a, quan_moi);
					break;
				}
				case 3: {
					return;
				}
				}
			}
			break;
		}
		case 2: {
			while (true) {
				cout << "\n1.Sua so luong ao ton kho.";
				cout << "\n2.Sua so luong quan ton kho.";
				cout << "\n3.Thoat";
				cout << "\nNhap lua chon :";
				int chon2;
				cin >> chon2;
				switch (chon2) {
				case 1: {
					unsigned short sl_ao_moi;
					cout << "\nNhap so luong ao moi :"; cin >> sl_ao_moi;
					//check;
					sua_so_luong_ao_ton_kho(ma_hh, a, sl_ao_moi);
					break;
				}
				case 2: {
					unsigned short sl_quan_moi;
					cout << "\nNhap so luong quan moi :"; cin >> sl_quan_moi;
					//check;
					sua_so_luong_quan_ton_kho(ma_hh, a, sl_quan_moi);
					break;
				}
				case 3: {
					return;
				}
				}
			}
			break;
		}
		case 3: {
			while (true) {
				cout << "\n1.Sua gia ao.";
				cout << "\n2.Sua gia quan.";
				cout << "\n3.Thoat.";
				cout << "\nNhap lua chon :";
				int chon3;
				cin >> chon3;
				switch (chon3) {
				case 1: {
					long long gia_ao;
					cout << "\nNhap gia ao moi : "; cin >> gia_ao;
					//check;
					sua_gia_ao(ma_hh, a, gia_ao);
					break;
				}
				case 2: {
					long long gia_quan;
					cout << "\nNhap gia quan moi : "; cin >> gia_quan;
					//check;
					sua_gia_quan(ma_hh, a, gia_quan);
					break;
				}
				case 3: {
					return;
				}
				}
				break;
			}
		}
		case 4: {
			while (true) {
				cout << "\n1.Sua size ao moi.";
				cout << "\n2.Sua size quan moi.";
				cout << "\n3.Thoat.";
				cout << "\nNhap lua chon : ";
				int chon4;
				cin >> chon4;
				switch (chon4) {
				case 1: {
					string size_ao_moi;
					cout << "\nNhap size ao moi : ";
					cin.ignore();
					getline(cin, size_ao_moi);
					//check
					sua_size_ao(ma_hh, a, size_ao_moi);
					break;
				}
				case 2: {
					string size_quan_moi;
					cout << "\nNhap size quan moi : ";
					cin.ignore();
					getline(cin, size_quan_moi);
					//check
					sua_size_quan(ma_hh, a, size_quan_moi);
					break;
				}
				case 3: {
					return;
				}
				}

			}
			break;
		}
		case 5: {
			while (true) {
				cout << "\n1.Sua mo ta ao.";
				cout << "\n2.Sua mo ta quan.";
				cout << "\n3.Thoat";
				cout << "\nNhap lua chon : ";
				int chon5;
				cin >> chon5;
				switch (chon5) {
				case 1: {
					string mo_ta_ao;
					cout << "\nNhap mo ta ao moi : ";
					cin.ignore();
					getline(cin, mo_ta_ao);
					//check
					sua_mo_ta_sp_ao(ma_hh, a, mo_ta_ao);
					break;
				}
				case 2: {
					string mo_ta_quan;
					cout << "\nNhap mo ta quan moi : ";
					cin.ignore();
					getline(cin, mo_ta_quan);
					//check
					sua_mo_ta_sp_quan(ma_hh, a, mo_ta_quan);
					break;
				}
				case 3: {
					return;
				}
				}
			}
			break;
		}
		case 6: {
			while (true) {
				cout << "\n1.Sua thoi gian nhap ao.";
				cout << "\n2.Sua thoi gian nhap quan.";
				cout << "\n3.Thoat";
				cout << "\nNhap lua chon :";
				int chon6;
				cin >> chon6;
				switch (chon6) {
				case 1: {
					string thoi_gian_nhap_ao;
					cout << "\nNhap thoi gian nhap ao moi :";
					cin.ignore();
					getline(cin, thoi_gian_nhap_ao);
					//check
					sua_thoi_gian_nhap_ao(ma_hh, a, thoi_gian_nhap_ao);
					break;
				}
				case 2: {
					string thoi_gian_nhap_quan;
					cout << "\nNhap thoi gian nhap quan moi :";
					cin.ignore();
					getline(cin, thoi_gian_nhap_quan);
					//check
					sua_thoi_gian_nhap_quan(ma_hh, a, thoi_gian_nhap_quan);
					break;
				}
				case 3: {
					return;
				}
				}
			}
			break;
		}
		case 0: {
			return;
		}
		}
	}
}
//=================== Hóa Đơn =========================
void nhapHoaDon(HoaDon& a, Admin b)
{
	long long tien;
	string loai_hd;
	cout << "Nhap loai hoa don (Ban/Nhap) : "; getline(cin, loai_hd); // cho nhập Xuat / Nhap
	while_loai_hd(loai_hd);
	if (loai_hd == "Ban")
	{
		a.ma_hoa_don = 'X';
		a.ma_hoa_don = a.ma_hoa_don + tao_ma_hoa_don(b.quan_li_ds_hoa_don_xuat);
	}
	else
	{
		a.ma_hoa_don = 'N';
		a.ma_hoa_don = a.ma_hoa_don + tao_ma_hoa_don(b.quan_li_ds_hoa_don_nhap);
	}
	if (loai_hd == "Xuat")
	{
		cout << "Nhap ma khach hang: ";
		getline(cin,a.ma_kh);
		while_ma_kh(a.ma_kh);
		cout << "Nhap ma hang hoa: "; getline(cin, a.ma_hang_hoa);
		while_full_ma_hh(a.ma_hang_hoa);
		if (a.ma_hang_hoa[0] == 'A')
		{
			for (int i = 0; i < b.quan_li_ds_hang_hoa.ds_ao.size(); i++)
			{
				if (a.ma_hang_hoa == b.quan_li_ds_hang_hoa.ds_ao.at(i).ma_hh)
				{
					tien = b.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
					a.thong_tin_hang.ten_hh = b.quan_li_ds_hang_hoa.ds_ao.at(i).ten_hh;
					a.thong_tin_hang.gia = b.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
					a.thong_tin_hang.size = b.quan_li_ds_hang_hoa.ds_ao.at(i).size;
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < b.quan_li_ds_hang_hoa.ds_quan.size(); i++)
			{
				if (a.ma_hang_hoa == b.quan_li_ds_hang_hoa.ds_quan.at(i).ma_hh)
				{
					tien = b.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
					a.thong_tin_hang.ten_hh = b.quan_li_ds_hang_hoa.ds_quan.at(i).ten_hh;
					a.thong_tin_hang.gia = b.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
					a.thong_tin_hang.size = b.quan_li_ds_hang_hoa.ds_quan.at(i).size;
					break;
				}
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
		a.ma_hang_hoa = a.ma_hang_hoa + tao_ma_hang_hoa(b.quan_li_ds_hang_hoa);

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

void taoHoaDonKhiKhachMuaHang(HoaDon& a, Admin b, string ma_hh, string ma_kh)
{
	long long tien;
	a.ma_hoa_don = 'X' + tao_ma_hoa_don(b.quan_li_ds_hoa_don_xuat);
	a.ma_hang_hoa = ma_hh;
	a.ma_kh = ma_kh;
	if (a.ma_hang_hoa[0] == 'A')
	{
		for (int i = 0; i < b.quan_li_ds_hang_hoa.ds_ao.size(); i++)
		{
			if (a.ma_hang_hoa == b.quan_li_ds_hang_hoa.ds_ao.at(i).ma_hh)
			{
				tien = b.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
				a.thong_tin_hang.ten_hh = b.quan_li_ds_hang_hoa.ds_ao.at(i).ten_hh;
				a.thong_tin_hang.gia = b.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
				a.thong_tin_hang.size = b.quan_li_ds_hang_hoa.ds_ao.at(i).size;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < b.quan_li_ds_hang_hoa.ds_quan.size(); i++)
		{
			if (a.ma_hang_hoa == b.quan_li_ds_hang_hoa.ds_quan.at(i).ma_hh)
			{
				tien = b.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
				a.thong_tin_hang.ten_hh = b.quan_li_ds_hang_hoa.ds_quan.at(i).ten_hh;
				a.thong_tin_hang.gia = b.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
				a.thong_tin_hang.size = b.quan_li_ds_hang_hoa.ds_quan.at(i).size;
				break;
			}
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

	string tam;
	cout << "Nhap so luong mua: "; 
	getline(cin, tam);
	while_so(tam);
	a.sl_mua = stoi(tam);

	cout << "Nhap phuong thuc thanh toan( COD/Bank ): "; getline(cin,a.pptt);
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
	cout << "Ma hang hoa: " << a.ma_hang_hoa << endl;
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh << endl;
	cout << "Gia: " << a.thong_tin_hang.gia << endl;
	cout << "Size: " << a.thong_tin_hang.size << endl;
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang << endl;
	cout << "Tong tien: " << a.tong_tien << endl;
	cout << "Trang thai: " << a.trang_thai << endl;
}

void xuat_ds_hoa_don_ban_hang(DS_HOA_DON a)
{
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		xuatHoaDonBanHang(k->data);
		cout << "==========================" << endl;
	}
}

void xuat_ds_hoa_don_ban_hang_xoa(DS_HOA_DON_XOA a)
{
	for (node_hoa_don_xoa* k = a.pHead; k != NULL; k = k->pNext)
	{
		xuatHoaDonBanHang(k->hdx.hd);
		cout << "Ngay xoa: " << k->hdx.ngay_xoa;
		cout << "\n\t\t====================\n";
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
}

void xuat_ds_hoa_don_nhap_hang(DS_HOA_DON a)
{
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		xuatHoaDonNhapHang(k->data);
		cout << "==========================" << endl;
	}
}

void xuat_ds_hoa_don_nhap_hang_xoa(DS_HOA_DON_XOA a)
{
	for (node_hoa_don_xoa* k = a.pHead; k != NULL; k = k->pNext)
	{
		xuatHoaDonNhapHang(k->hdx.hd);
		cout << "Ngay xoa: " << k->hdx.ngay_xoa;
		cout << "\n\t\t====================\n";
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

node_hoa_don_xoa* khoi_tao_node_hoa_don_xoa(HoaDonXoa a)
{
	node_hoa_don_xoa* p = new node_hoa_don_xoa;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->hdx = a;
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

void them_dau_ds_hoa_don(DS_HOA_DON& a, HoaDon x)
{
	node_hoa_don* p = khoi_tao_node_hoa_don(x);
	if (a.pHead == NULL)
	{
		a.pHead = a.pTail = p;
	}
	else
	{
		p->pNext = a.pHead;
		a.pHead = p;
	}
}

void them_cuoi_ds_hoa_don_xoa(DS_HOA_DON_XOA& a, HoaDonXoa x)
{
	node_hoa_don_xoa* p = khoi_tao_node_hoa_don_xoa(x);
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

void xoa_hd_theo_ma(DS_HOA_DON& a, string b)
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

// ============== Thống kê hóa đơn ==================

void thong_ke_doanh_so_theo_ngay_thang_nam(DS_HOA_DON a, string ngay)
{
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (ngay == k->data.ngay_lap_hd && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong doanh thu: " << doanh_thu;
}

void thong_ke_doanh_so_theo_thang(DS_HOA_DON a, string thang)
{
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (stoi(thang) == stoi(k->data.ngay_lap_hd.substr(3,2)) && k->data.trang_thai == "Da Nhan Hang" )
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong doanh thu: " << doanh_thu;
}

void thong_ke_doanh_so_theo_nam(DS_HOA_DON a, string nam)
{
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (stoi(nam) == stoi(k->data.ngay_lap_hd.substr(6, 4)) && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong doanh thu: " << doanh_thu;
}

void thong_ke_doanh_so_theo_ngay_hien_tai(DS_HOA_DON a)
{
	string str;
	thoiGianThuc(str);
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if ( str == k->data.ngay_lap_hd && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong doanh thu: " << doanh_thu;
}

void thong_ke_don_hang_nhap_theo_ngay_thang_nam(DS_HOA_DON a, string ngay)
{
	long long tien_nhap_hang = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (ngay == k->data.ngay_lap_hd)
		{
			xuatHoaDonNhapHang(k->data);
			tien_nhap_hang = tien_nhap_hang + k->data.tong_tien;
		}
	}
	cout << "Tong tien nhap hang: " << tien_nhap_hang;
}

void thong_ke_don_hang_nhap_theo_thang(DS_HOA_DON a, string thang)
{
	long long tien_nhap_hang = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (stoi(thang) == stoi( k->data.ngay_lap_hd.substr(3,2)))
		{
			xuatHoaDonNhapHang(k->data);
			tien_nhap_hang = tien_nhap_hang + k->data.tong_tien;
		}
	}
	cout << "Tong tien nhap hang: " << tien_nhap_hang;
}

void thong_ke_don_hang_nhap_theo_nam(DS_HOA_DON a, string nam)
{
	long long tien_nhap_hang = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (stoi(nam) == stoi(k->data.ngay_lap_hd.substr(6, 4)))
		{
			xuatHoaDonNhapHang(k->data);
			tien_nhap_hang = tien_nhap_hang + k->data.tong_tien;
		}
	}
	cout << "Tong tien nhap hang: " << tien_nhap_hang;
}

void thong_ke_don_hang_nhap_theo_ngay_hien_tai(DS_HOA_DON a)
{
	string str;
	thoiGianThuc(str);
	long long tien_nhap_hang = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (str == k->data.ngay_lap_hd)
		{
			xuatHoaDonNhapHang(k->data);
			tien_nhap_hang = tien_nhap_hang + k->data.tong_tien;
		}
	}
	cout << "Tong tien nhap hang: " << tien_nhap_hang;
}

void thong_ke_hoa_don(Admin ad)
{
	string str;
	bool kt = true;
	cout << "Nhap loai hoa don muon thong ke (ban/ nhap):";
	getline(cin, str);
	while_loai_hd(str);

	if (str == "Ban")
	{
		while (kt == true)
		{
			system("cls");
			cout << "1.Thong ke doanh so theo ngay thang nam";
			cout << "\n2.Thong ke doanh so theo thang";
			cout << "\n3.Thong ke doanh so theo nam";
			cout << "\n4.Thong ke doanh so theo ngay hien tai";
			cout << "\n0.Thoat";

			int luachon;
			string tam;
			cout << "\nNhap lua chon: ";
			getline(cin, tam);
			while (check_So(tam) == false || stoi(tam) > 4)
			{
				cout << "\nLua chon khong hop le!";
				cout << "\nNhap lua chon: ";
				getline(cin, tam);
			}
			luachon = stoi(tam);

			switch (luachon)
			{
			case 1:
			{
				string ngay;
				cout << "\nNhap ngay thang nam muon thong ke (dd/mm/yyyy): ";
				getline(cin,ngay);
				while (check_date(ngay) == false)
				{
					cout << "Ngay thang nam vua nhap khong hop le!";
					cout << "\nNhap ngay muon thong ke (dd/mm/yyyy): ";
					getline(cin, ngay);
				}
				thong_ke_doanh_so_theo_ngay_thang_nam(ad.quan_li_ds_hoa_don_xuat, ngay);
				system("pause");
				break;
			}
			case 2:
			{
				string thang;
				cout << "\nNhap thang muon thong ke: ";
				getline(cin, thang);
				while (check_So(thang) == false || stoi(thang) > 12)
				{
					cout << "Thang vua nhap khong hop le!";
					cout << "\nNhap thang muon thong ke: ";
					getline(cin, thang);
				}
				thong_ke_doanh_so_theo_thang(ad.quan_li_ds_hoa_don_xuat, thang);
				system("pause");
				break;
			}
			case 3:
			{
				string nam;
				cout << "\nNhap nam muon thong ke (yyyy): ";
				getline(cin, nam);
				while (check_So(nam) == false || stoi (nam) < 999 )
				{
					cout << "Nam vua nhap khong hop le!";
					cout << "\nNhap nam muon thong ke (yyyy): ";
					getline(cin, nam);
				}
				thong_ke_doanh_so_theo_nam(ad.quan_li_ds_hoa_don_xuat, nam);
				system("pause");
				break;
			}
			case 4:
			{
				thong_ke_doanh_so_theo_ngay_hien_tai(ad.quan_li_ds_hoa_don_xuat);
				system("pause");
				break;
			}
			case 0:
			{
				kt = false;
				break;
			}
			}
		}
	}
	else
	{
		while (kt == true)
		{
			system("cls");
			cout << "1.Thong ke don nhap hang theo ngay thang nam";
			cout << "\n2.Thong ke don nhap hang theo thang";
			cout << "\n3.Thong ke don nhap hang theo nam";
			cout << "\n4.Thong ke don nhap hang theo ngay hien tai";
			cout << "\n0.Thoat";

			int luachon;
			string tam;
			cout << "\nNhap lua chon: ";
			getline(cin, tam);
			while (check_So(tam) == false || stoi(tam) > 4)
			{
				cout << "\nLua chon khong hop le!";
				cout << "\nNhap lua chon: ";
				getline(cin, tam);
			}
			luachon = stoi(tam);

			switch (luachon)
			{
			case 1:
			{
				string ngay;
				cout << "\nNhap ngay thang nam muon thong ke (dd/mm/yyyy): ";
				getline(cin, ngay);
				while (check_date(ngay) == false)
				{
					cout << "Ngay thang nam vua nhap khong hop le!";
					cout << "\nNhap ngay muon thong ke (dd/mm/yyyy): ";
					getline(cin, ngay);
				}
				thong_ke_don_hang_nhap_theo_ngay_thang_nam(ad.quan_li_ds_hoa_don_nhap, ngay);
				system("pause");
				break;
			}
			case 2:
			{
				string thang;
				cout << "\nNhap thang muon thong ke: ";
				getline(cin, thang);
				while (check_So(thang) == false || stoi(thang) > 12)
				{
					cout << "Thang vua nhap khong hop le!";
					cout << "\nNhap thang muon thong ke: ";
					getline(cin, thang);
				}
				thong_ke_don_hang_nhap_theo_thang(ad.quan_li_ds_hoa_don_nhap, thang);
				system("pause");
				break;
			}
			case 3:
			{
				string nam;
				cout << "\nNhap nam muon thong ke (yyyy): ";
				getline(cin, nam);
				while (check_So(nam) == false || stoi(nam) < 999)
				{
					cout << "Nam vua nhap khong hop le!";
					cout << "\nNhap nam muon thong ke (yyyy): ";
					getline(cin, nam);
				}
				thong_ke_don_hang_nhap_theo_nam(ad.quan_li_ds_hoa_don_nhap, nam);
				system("pause");
				break;
			}
			case 4:
			{
				thong_ke_don_hang_nhap_theo_ngay_hien_tai(ad.quan_li_ds_hoa_don_nhap);
				system("pause");
				break;
			}
			case 0:
			{
				kt = false;
				break;
			}
			}
		}
	}
}

// ============== Sửa thông tin hóa đơn ==================

void duyet_cay_sua_thong_tin_hh(TREE& t,string ma_hd_sua, string ma_kh, string a,DS_Hang_Hoa ds_hh)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.ma_hoa_don == ma_hd_sua)
				{
					long long tien = 0;
					k->data.ma_hang_hoa = a;
					if (k->data.ma_hang_hoa[0] == 'A')
					{
						for (int i = 0; i < ds_hh.ds_ao.size(); i++)
						{
							if (k->data.ma_hang_hoa == ds_hh.ds_ao.at(i).ma_hh)
							{
								tien = ds_hh.ds_ao.at(i).gia;
								k->data.thong_tin_hang.ten_hh = ds_hh.ds_ao.at(i).ten_hh;
								k->data.thong_tin_hang.gia = ds_hh.ds_ao.at(i).gia;
								k->data.thong_tin_hang.size = ds_hh.ds_ao.at(i).size;
								break;
							}
						}
					}
					else
					{
						for (int i = 0; i < ds_hh.ds_quan.size(); i++)
						{
							if (k->data.ma_hang_hoa == ds_hh.ds_quan.at(i).ma_hh)
							{
								tien = ds_hh.ds_quan.at(i).gia;
								k->data.thong_tin_hang.ten_hh = ds_hh.ds_quan.at(i).ten_hh;
								k->data.thong_tin_hang.gia = ds_hh.ds_quan.at(i).gia;
								k->data.thong_tin_hang.size = ds_hh.ds_quan.at(i).size;
								break;
							}
						}
					}
					if (k->data.ma_kh.substr(0, 2) == "DO")
					{
						k->data.tong_tien = (tien * k->data.sl_mua) * 0, 01;
						k->data.giam_gia_theo_hang = 0, 01;
					}
					else if (k->data.ma_kh.substr(0, 2) == "BA")
					{
						k->data.tong_tien = (tien * k->data.sl_mua) * 0, 03;
						k->data.giam_gia_theo_hang = 0, 03;
					}
					else if (k->data.ma_kh.substr(0, 2) == "VA")
					{
						k->data.tong_tien = (tien * k->data.sl_mua) * 0, 05;
						k->data.giam_gia_theo_hang = 0, 05;
					}
					else if (k->data.ma_kh.substr(0, 2) == "KC")
					{
						k->data.tong_tien = (tien * k->data.sl_mua) * 0, 1;
						k->data.giam_gia_theo_hang = 0, 1;
					}
					else
					{
						k->data.tong_tien = tien * k->data.sl_mua;
						k->data.giam_gia_theo_hang = 0;
					}
					return;
				}
			}
		}
		if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin_hh(t->pLeft, ma_hd_sua, ma_kh, a,ds_hh);
		}
		else if (stoi(ma_kh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin_hh(t->pRight, ma_hd_sua, ma_kh, a,ds_hh);
		}
	}
}

void duyet_cay_sua_thong_tin_nl(TREE& t,string ma_hd_sua, string ma_kh, string nl)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.ma_hoa_don == ma_hd_sua)
				{
					k->data.ngay_lap_hd = nl;
					return;
				}
			}
		}
		if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin_nl(t->pLeft, ma_hd_sua, ma_kh,nl);
		}
		else if (stoi(ma_kh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin_nl(t->pRight, ma_hd_sua, ma_kh,nl);
		}
	}
}

void duyet_cay_sua_thong_tin_trang_thai(TREE& t, string ma_hd_sua, string ma_kh, string trang_thai_moi)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.ma_hoa_don == ma_hd_sua)
				{
					k->data.trang_thai = trang_thai_moi;
					return;
				}
			}
		}
		if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin_trang_thai(t->pLeft, ma_hd_sua, ma_kh, trang_thai_moi);
		}
		else if (stoi(ma_kh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin_trang_thai(t->pRight, ma_hd_sua, ma_kh, trang_thai_moi);
		}
	}
}

void duyet_cay_xoa_hd_theo_ma(TREE& t, string ma_kh_cu, string ma_hoa_don)
{
	if (t != NULL)
	{
		if (t->data.maKh == ma_kh_cu)
		{
			xoa_hd_theo_ma(t->data.don_mua_hang, ma_hoa_don);
			return;
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
			return;
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
			if (k->data.trang_thai == "Da Nhan Hang")
			{
				tong_tien_da_tieu = tong_tien_da_tieu + k->data.tong_tien;
				cout << tong_tien_da_tieu << endl;
			}
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
	regex ktra_dinh_dang(R"([aA-zZ]{1}\d{4})");
	cout << "Nhap ma hoa don muon sua: ";
	getline(cin, b);
	b[0] = toupper(b[0]);
	while ((check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_nhap) == -1 || check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_xuat) == -1) && regex_match(b, ktra_dinh_dang) == false)
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
			cout << "\n3.Xoa hoa don";
			cout << "\n0.Thoat";
			do
			{
				string k;
				cout << "\nChon loai thong tin muon sua: ";
				getline(cin, k);
				while_so(k);
				c = stoi(k);
			} while (c < 0 || c>2);

			switch (c)
			{
			case 1:
			{
				string str;
				cout << "\nNhap ngay lap hoa don: ";
				getline(cin, str);
				do
				{
					if (check_date(str) == false)
					{
						cout << "Ngay thang nhap khong hop le!";
						cout << "\nNhap ngay lap hoa don: ";
						getline(cin, str);
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
			case 3:
			{
				xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_nhap, b);
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
			cout << "2.Sua ma hang khach hang" << endl;
			cout << "3.Sua ngay lap hoa don" << endl;
			cout << "4.Sua trang thai cua hoa don" << endl;
			cout << "5.Xoa hoa don";
			cout << "\n0.Thoat";
			do
			{
				string k;
				cout << "\nChon loai thong tin muon sua: ";
				getline(cin,k);
				while_so(k);
				c = stoi(k);
			} while (c < 0 || c > 5);

			switch (c)
			{
			case 1:
			{
				string str;
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
						long long tien;
						duyet_cay_sua_thong_tin_hh(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str,ad.quan_li_ds_hang_hoa);
						k->data.ma_hang_hoa = str;
						if (str[0] == 'A')
						{
							for (int i = 0; i < ad.quan_li_ds_hang_hoa.ds_ao.size(); i++)
							{
								if (str == ad.quan_li_ds_hang_hoa.ds_ao.at(i).ma_hh)
								{
									tien = ad.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
									k->data.thong_tin_hang.ten_hh = ad.quan_li_ds_hang_hoa.ds_ao.at(i).ten_hh;
									k->data.thong_tin_hang.gia = ad.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
									k->data.thong_tin_hang.size = ad.quan_li_ds_hang_hoa.ds_ao.at(i).size;
									break;
								}
							}
						}
						else
						{
							for (int i = 0; i < ad.quan_li_ds_hang_hoa.ds_quan.size(); i++)
							{
								if (k->data.ma_hang_hoa == ad.quan_li_ds_hang_hoa.ds_quan.at(i).ma_hh)
								{
									tien = ad.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
									k->data.thong_tin_hang.ten_hh = ad.quan_li_ds_hang_hoa.ds_quan.at(i).ten_hh;
									k->data.thong_tin_hang.gia = ad.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
									k->data.thong_tin_hang.size = ad.quan_li_ds_hang_hoa.ds_quan.at(i).size;
									break;
								}
							}
						}
						if (k->data.ma_kh.substr(0, 2) == "DO")
						{
							k->data.tong_tien = (tien * k->data.sl_mua) * 0, 01;
							k->data.giam_gia_theo_hang = 0, 01;
						}
						else if (k->data.ma_kh.substr(0, 2) == "BA")
						{
							k->data.tong_tien = (tien * k->data.sl_mua) * 0, 03;
							k->data.giam_gia_theo_hang = 0, 03;
						}
						else if (k->data.ma_kh.substr(0, 2) == "VA")
						{
							k->data.tong_tien = (tien * k->data.sl_mua) * 0, 05;
							k->data.giam_gia_theo_hang = 0, 05;
						}
						else if (k->data.ma_kh.substr(0, 2) == "KC")
						{
							k->data.tong_tien = (tien * k->data.sl_mua) * 0, 1;
							k->data.giam_gia_theo_hang = 0, 1;
						}
						else
						{
							k->data.tong_tien = tien * k->data.sl_mua;
							k->data.giam_gia_theo_hang = 0;
						}
						break;
					}
				}
				xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
				break;
			}
			case 2:
			{
				string str;
				cout << "Nhap ma khach hang moi: ";
				getline(cin, str);
				while_ma_kh(str);
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
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						k->data.ngay_lap_hd = str;
						duyet_cay_sua_thong_tin_nl(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						break;
					}
				}
				break;
			}
			case 4:
			{
				string str;
				cout << "Nhap trang thai moi cua hoa don: ";
				getline(cin, str);
				while_trang_thai(str);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_sua_thong_tin_trang_thai(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						k->data.trang_thai = str;
						break;
					}
				}
				xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
				break;
			}
			case 5:
			{
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_xoa_hd_theo_ma(ad.quan_li_ds_kh.t, k->data.ma_kh, b);
						xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_xuat, b);
						break;
					}
				}
				xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
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

// ================== Khách Hàng ==========================
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
	cout << "Nhap so dien thoai: "; getline(in , a.sdt);// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	while_Sdt(a.sdt);
	cout << "Nhap email: "; getline(in ,a.email);//example@gmail.com
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

	cout << "Nhap so dien thoai: "; getline(cin , a.sdt);// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	while_Sdt(a.sdt);

	cout << "Nhap email: "; getline (cin, a.email);//example@gmail.com
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

void them_khachhang_vao_cay(TREE &t, KH data) 
{
	if (t == NULL) 
	{
		node_kh* p = new node_kh;
		p->data = data;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else if (t != NULL) 
	{
		if (stoi(data.maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4))) 
		{
			them_khachhang_vao_cay(t->pLeft, data);
		}
		else if (stoi(data.maKh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4))) 
		{
			them_khachhang_vao_cay(t->pRight, data);
		}
	}
}

ostream& operator << (ostream& out, KHX a)
{
	out << "Ma khach hang: " << a.kh.maKh << endl;
	out << "Ten khach hang: " << a.kh.ten << endl;
	out << "Dia chi :" << a.kh.diaChi << endl;
	out << "SDT: " << a.kh.sdt << endl;
	out << "Email: " << a.kh.email << endl;
	out << "Ngay xoa: " << a.ngay_xoa << endl;
	return out;
}

void xuat_thong_tin_khach_hang_xoa(TREE_XOA t)
{
	if (t != NULL)
	{
		cout << t->khx;
		xuat_thong_tin_khach_hang_xoa(t->pLeft);
		xuat_thong_tin_khach_hang_xoa(t->pRight);
	}
}

void them_KhachHangXoa_vao_cay(TREE_XOA& t, KHX data)
{
	if (t == NULL)
	{
		node_kh_xoa* p = new node_kh_xoa;
		p->khx = data;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else if (t != NULL)
	{
		if (stoi(data.kh.maKh.substr(2, 4)) < stoi(t->khx.kh.maKh.substr(2, 4)))
		{
			them_KhachHangXoa_vao_cay(t->pLeft, data);
		}
		else if (stoi(data.kh.maKh.substr(2, 4)) > stoi(t->khx.kh.maKh.substr(2, 4)))
		{
			them_KhachHangXoa_vao_cay(t->pRight, data);
		}
	}
}

void node_the_mang_xoa(node_kh_xoa*& k, TREE_XOA& t)
{
	if (k->pRight == NULL)
	{
		t->khx = k->khx;
		node_kh_xoa* tam = k;
		k = k->pLeft; // đưa node hoặc null lên
		delete tam;
	}
	else
	{
		node_the_mang_xoa(k->pRight, t);
	}
}

void xoa_vinh_vien_khach_hang_theo_ma(TREE_XOA& t, string a)
{
	if (t != NULL)
	{
		if (t->khx.kh.maKh == a)
		{
			//--- xoá ----
			if (t->pRight != NULL && t->pLeft != NULL)//2 con
			{
				node_the_mang_xoa(t->pLeft, t);
			}
			else if (t->pLeft == NULL && t->pRight == NULL)  //la
			{
				delete t;
				t = NULL;
			}
			else  //1 con
			{
				node_kh_xoa* tam = t;
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
		else if (stoi(a.substr(2, 4)) > stoi(t->khx.kh.maKh.substr(2, 4)))
		{
			xoa_vinh_vien_khach_hang_theo_ma(t->pRight, a);
		}
		else
		{
			xoa_vinh_vien_khach_hang_theo_ma(t->pLeft, a);
		}
	}
}

int tim_chieu_cao_cay_xoa(TREE_XOA t) 
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		int h_trai = tim_chieu_cao_cay_xoa(t->pLeft);
		int h_phai = tim_chieu_cao_cay_xoa(t->pRight);
		return (h_phai > h_trai) ? 1 + h_phai : 1 + h_trai;
	}
}

bool kt_lech_p_xoa(TREE_XOA t, char& checkp)
{
	int h_trai = tim_chieu_cao_cay_xoa(t->pLeft);
	int h_phai = tim_chieu_cao_cay_xoa(t->pRight);
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

char kt_lech_q_xoa(TREE_XOA t, char checkp)
{
	int h_trai = tim_chieu_cao_cay_xoa(t->pLeft);
	int h_phai = tim_chieu_cao_cay_xoa(t->pRight);

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

void quay_phai_xoa(TREE_XOA& p, TREE_XOA& q)
{
	node_kh_xoa* tam = q->pRight; 
	q->pRight = p;
	p->pLeft = tam; 
}

void quay_trai_xoa(TREE_XOA& p, TREE_XOA& q)
{
	node_kh_xoa* tam = q->pLeft; 
	q->pLeft = p; 
	p->pRight = tam;
}

void can_bang_cay_xoa(TREE_XOA& t) // duyệt node left right NLR
{
	if (t != NULL)
	{
		// ------- NODE --------------
		char checkp = '0'; //  tạo giá trị ban đầu khác L , R
		if (kt_lech_p_xoa(t, checkp) == true) // cây mất cân bằng
		{
			node_kh_xoa* p = t;
			node_kh_xoa* q = (checkp == 'L') ? p->pLeft : p->pRight; // kiểm tra p lệch loại gì thì q sẽ là cây con thep hướng đó của p
			char checkq = kt_lech_q_xoa(q, checkp); // kiểm qua q là loại gì 

			if (checkp == 'L' && checkq == 'L')
			{
				quay_phai_xoa(p, q);
			}
			else if (checkp == 'R' && checkq == 'R')
			{
				quay_trai_xoa(p, q);
			}
			else if (checkp == 'L' && checkq == 'R')
			{
				node_kh_xoa* tam = q->pRight;
				quay_trai_xoa(q, q->pRight);
				q = tam;
				t->pLeft = q;
				can_bang_cay_xoa(t);
			}
			else if (checkp == 'R' && checkq == 'L')
			{
				node_kh_xoa* tam = q->pLeft;
				quay_phai_xoa(q, q->pLeft);
				q = tam;
				t->pRight = q;
				can_bang_cay_xoa(t);
			}
			t = q;
		}
		// ------------ Left----------------
		can_bang_cay_xoa(t->pLeft);
		// -------------Right---------------
		can_bang_cay_xoa(t->pRight);
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

// ====================== Đơn mua hàng ========================
void xuat_don_mua(TREE t, string ma_kh)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				xuatHoaDonBanHang(k->data);
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
				quay_phai(q, q->pLeft);
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
	cout << "Nhap ma Khach hang can sua:";
	string maKh;
	getline(cin, maKh);
	while_ma_kh(maKh);
	while (check_ma_kh(maKh, t) == false )
	{
		cout << "Khong tim thay ma khach hang." << endl;
		cout << "Nhap lai:";
		getline(cin, maKh);
		while_ma_kh(maKh);
	}
	while (kt_menu==true) {
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

		} while (chon<0||chon>5);
		
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
void hien_thi_gio_hang(gio_hang gh)
{
	for (int i = 0; i < gh.hh.size(); i++) {
		xuat_tt_hh_ngan_gon(gh.hh[i]);
		//tong_tien += gh.hh[i].gia * gh.hh[i].soLuongTonKho;
	}
	//cout << "Tong gia tri don" << tong_tien << endl;
}

void xoa_sp_khoi_gio_hang(gio_hang &gh)
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

void them_sp_vao_gio_hang(DS_Hang_Hoa dshh, gio_hang &gh)
{
	bool kt_menu = true;
	int lua_chon;
	int so_luong_mua=0;
	
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

void chuc_nang_khach_hang(KhachHang a,DS_Hang_Hoa dshh,gio_hang gh)
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
			them_sp_vao_gio_hang(dshh,a.data_gh);
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

//==================== Khách hàng truy vấn đơn mua hàng =====================

void thong_ke_don_mua_theo_ngay_thang_nam(DS_HOA_DON a, string ngay)
{
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (ngay == k->data.ngay_lap_hd && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong tien da mua: " << doanh_thu;
}

void thong_ke_don_mua_theo_thang(DS_HOA_DON a, string thang)
{
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (stoi(thang) == stoi(k->data.ngay_lap_hd.substr(3, 2)) && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong tien da mua: " << doanh_thu;
}

void thong_ke_don_mua_theo_nam(DS_HOA_DON a, string nam)
{
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (stoi(nam) == stoi(k->data.ngay_lap_hd.substr(6, 4)) && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong tien da mua: " << doanh_thu;
}

void thong_ke_don_mua_theo_ngay_hien_tai(DS_HOA_DON a)
{
	string str;
	thoiGianThuc(str);
	long long doanh_thu = 0;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		if (str == k->data.ngay_lap_hd && k->data.trang_thai == "Da Nhan Hang")
		{
			xuatHoaDonBanHang(k->data);
			doanh_thu = doanh_thu + k->data.tong_tien;
		}
	}
	cout << "Tong tien da mua: " << doanh_thu;
}

void duyet_cay_thong_ke_theo_ngay_thang_nam(TREE t,string ngay, string makh)
{
	if (t != NULL)
	{
		if (makh == t->data.maKh)
		{
			thong_ke_don_mua_theo_ngay_thang_nam(t->data.don_mua_hang,ngay);
			return;
		}
		else if (stoi(makh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_thong_ke_theo_ngay_thang_nam(t->pLeft,ngay, makh);
		}
		else
		{
			duyet_cay_thong_ke_theo_ngay_thang_nam(t->pRight,ngay, makh);
		}
	}
}

void duyet_cay_thong_ke_theo_thang(TREE t, string thang, string makh)
{
	if (t != NULL)
	{
		if (makh == t->data.maKh)
		{
			thong_ke_don_mua_theo_thang(t->data.don_mua_hang, thang);
			return;
		}
		else if (stoi(makh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_thong_ke_theo_thang(t->pLeft,thang, makh);
		}
		else
		{
			duyet_cay_thong_ke_theo_thang(t->pRight,thang, makh);
		}
	}
}

void duyet_cay_thong_ke_theo_nam(TREE t, string nam, string makh)
{
	if (t != NULL)
	{
		if (makh == t->data.maKh)
		{
			thong_ke_don_mua_theo_nam(t->data.don_mua_hang, nam);
			return;
		}
		else if (stoi(makh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_thong_ke_theo_nam(t->pLeft,nam, makh);
		}
		else
		{
			duyet_cay_thong_ke_theo_nam(t->pRight,nam, makh);
		}
	}
}

void duyet_cay_thong_ke_theo_ngay_hien_tai(TREE t, string makh)
{
	if (t != NULL)
	{
		if (makh == t->data.maKh)
		{
			thong_ke_don_mua_theo_ngay_hien_tai(t->data.don_mua_hang);
			return;
		}
		else if (stoi(makh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_thong_ke_theo_ngay_hien_tai(t->pLeft, makh);
		}
		else
		{
			duyet_cay_thong_ke_theo_ngay_hien_tai(t->pRight, makh);
		}
	}
}

void thong_ke_don_mua_hang(Admin ad, string makh)
{
	bool kt = true;
	while (kt == true)
	{
		system("cls");
		cout << "1.Thong ke don mua theo ngay thang nam";
		cout << "\n2.Thong ke don mua theo thang";
		cout << "\n3.Thong ke don mua theo nam";
		cout << "\n4.Thong ke don mua theo ngay hien tai";
		cout << "\n0.Thoat";

		int luachon;
		string tam;
		cout << "\nNhap lua chon: ";
		getline(cin, tam);
		while (check_So(tam) == false || stoi(tam) > 4)
		{
			cout << "\nLua chon khong hop le!";
			cout << "\nNhap lua chon: ";
			getline(cin, tam);
		}
		luachon = stoi(tam);

		switch (luachon)
		{
		case 1:
		{
			string ngay;
			cout << "\nNhap ngay thang nam muon thong ke (dd/mm/yyyy): ";
			getline(cin, ngay);
			while (check_date(ngay) == false)
			{
				cout << "Ngay thang nam vua nhap khong hop le!";
				cout << "\nNhap ngay muon thong ke (dd/mm/yyyy): ";
				getline(cin, ngay);
			}
			duyet_cay_thong_ke_theo_ngay_thang_nam(ad.quan_li_ds_kh.t,ngay,makh);
			system("pause");
			break;
		}
		case 2:
		{
			string thang;
			cout << "\nNhap thang muon thong ke: ";
			getline(cin, thang);
			while (check_So(thang) == false || stoi(thang) > 12)
			{
				cout << "Thang vua nhap khong hop le!";
				cout << "\nNhap thang muon thong ke: ";
				getline(cin, thang);
			}
			duyet_cay_thong_ke_theo_thang(ad.quan_li_ds_kh.t, thang, makh);
			system("pause");
			break;
		}
		case 3:
		{
			string nam;
			cout << "\nNhap nam muon thong ke (yyyy): ";
			getline(cin, nam);
			while (check_So(nam) == false || stoi(nam) < 999)
			{
				cout << "Nam vua nhap khong hop le!";
				cout << "\nNhap nam muon thong ke (yyyy): ";
				getline(cin, nam);
			}
			duyet_cay_thong_ke_theo_nam(ad.quan_li_ds_kh.t, nam, makh);
			system("pause");
			break;
		}
		case 4:
		{
			duyet_cay_thong_ke_theo_ngay_hien_tai(ad.quan_li_ds_kh.t, makh);
			system("pause");
			break;
		}
		case 0:
		{
			kt = false;
			break;
		}
		}
	
	}
}


//============================== Khách hàng mua hang ============================
void duyet_cay_them_don_mua_hang(TREE& t, string ma_kh,HoaDon a)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			them_dau_ds_hoa_don(t->data.don_mua_hang, a);
			t->data.don_mua_hang.sl++;
			return;
		}
		else if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_them_don_mua_hang(t->pLeft, ma_kh,a);
		}
		else
		{
			duyet_cay_them_don_mua_hang(t->pRight, ma_kh,a);
		}
	}
}

void mua_hang(Admin ad, string ma_kh)
{
	HoaDon a;
	string ma;
	cout << "Nhap ma hang hoa muon mua: ";
	getline(cin, ma);
	while_full_ma_hh(ma);
	taoHoaDonKhiKhachMuaHang(a, ad, ma, ma_kh);
	them_dau_ds_hoa_don(ad.quan_li_ds_hoa_don_xuat, a);
	ad.quan_li_ds_hoa_don_xuat.sl++;
	duyet_cay_them_don_mua_hang(ad.quan_li_ds_kh.t, ma_kh, a);
}

// =================== Đơn hàng chờ ===========================
void xuat_ds_don_hang_cho(ds_dh_cho a)
{
	for (int i = 0; i < a.don_cho.size(); i++)
	{
		xuatHoaDonBanHang(a.don_cho.at(i));
	}
}

void xu_ly_don_hang_cho(Admin &ad)
{
	int luachon;
	string tam;
	cout << "Ban co muon xac nhan don hang " << ad.quan_li_don_hang_cho.don_cho.at(0).ma_hoa_don << " khong?";
	cout << "\n1.Co";
	cout << "\n2.Khong";
	cout << "\nNhap lua chon: "; getline(cin, tam);
	while (check_So(tam) == false || stoi(tam) != 1 || stoi(tam) != 2)
	{
		cout << "\nNhap khong hop le!";
		cout << "\nNhap lua chon: "; getline(cin, tam);
	}
	luachon = stoi(tam);

	if (luachon == 1)
	{
		ad.quan_li_don_hang_cho.don_cho.at(0).trang_thai = "Chua Nhan Hang";
		them_dau_ds_hoa_don(ad.quan_li_ds_hoa_don_xuat, ad.quan_li_don_hang_cho.don_cho.at(0));
		ad.quan_li_don_hang_cho.don_cho.erase(ad.quan_li_don_hang_cho.don_cho.begin() + 0);
	}
	else
	{
		return;
	}

}