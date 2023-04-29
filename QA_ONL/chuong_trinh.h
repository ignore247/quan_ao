#pragma once
#include "Check_du_lieu_nhap.h"
#include "Xu_li_do_hoa.h"
//-----------Load thông tin----------
//===Khach hang===//
void duyet_NLR_xuat_thong_tin_KH(TREE t) {
	if (t != NULL) {
		cout << t->data.ten << endl;
		duyet_NLR_xuat_thong_tin_KH(t->pLeft);
		duyet_NLR_xuat_thong_tin_KH(t->pRight);
	}
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
void load_thong_tin_khach_hang(TREE& t) {
	ifstream fileinThongTinKH("thong_tin_khach_hang.txt", ios::in);
	int soLuong;
	fileinThongTinKH >> soLuong;
	cin.ignore();
	cout << endl;
	while (fileinThongTinKH.eof() == false) {
		KH a;
		getline(fileinThongTinKH, a.email, ',');
		getline(fileinThongTinKH, a.mat_khau, ',');
		getline(fileinThongTinKH, a.maKh, ',');
		getline(fileinThongTinKH, a.ten, ',');
		getline(fileinThongTinKH, a.diaChi, ',');
		getline(fileinThongTinKH, a.sdt);
		them_khachhang_vao_cay(t, a);
	}
	fileinThongTinKH.close();
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
void load_thong_tin_hoadon_nhap(DS_HOA_DON& dshd) {
	ifstream fileinThongTinHDN("thong_tin_hoa_don_nhap_hang.txt", ios::in);
	while (fileinThongTinHDN.eof() == false) {
		HoaDon a;
		getline(fileinThongTinHDN, a.ma_hoa_don, ',');
		cout << a.ma_hoa_don << endl;

		getline(fileinThongTinHDN, a.ma_hang_hoa, ',');
		cout << a.ma_hang_hoa << endl;

		getline(fileinThongTinHDN, a.thong_tin_hang.ten_hh, ',');
		cout << a.thong_tin_hang.ten_hh << endl;

		fileinThongTinHDN >> a.thong_tin_hang.gia;
		cout << a.thong_tin_hang.gia << endl;
		fileinThongTinHDN.ignore();

		getline(fileinThongTinHDN, a.thong_tin_hang.size, ',');
		cout << a.thong_tin_hang.size << endl;

		fileinThongTinHDN >> a.sl_mua;
		cout << a.sl_mua << endl;
		fileinThongTinHDN.ignore();

		getline(fileinThongTinHDN, a.ngay_lap_hd, ',');
		cout << a.ngay_lap_hd << endl;

		fileinThongTinHDN >> a.tong_tien;
		cout << a.tong_tien << endl;
		fileinThongTinHDN.ignore();
		them_HoaDonNhap_vao_ds(dshd, a);
	}
	fileinThongTinHDN.close();
}
void load_thong_tin_hoadon_xuat() {
	//chưa làm
}
//===Thong Tin San Pham===//
void xuat_thong_tin_quan_ao(DS_Hang_Hoa dshh) {
	for (int i = 0; i < dshh.ds_quan.size(); i++) {
		cout << dshh.ds_quan[i].ma_hh << endl;
	}
	for (int i = 0; i < dshh.ds_ao.size(); i++) {
		cout << dshh.ds_ao[i].ma_hh << endl;
	}
}
void load_thong_tin_quan_ao(DS_Hang_Hoa& dshh) {

	ifstream fileinThongTinQuan("quan.txt", ios::in);
	while (fileinThongTinQuan.eof() == false) {
		HangHoa a;
		getline(fileinThongTinQuan, a.ma_hh, ',');
		cout << a.ma_hh << endl;
		getline(fileinThongTinQuan, a.ten_hh, ',');
		cout << a.ten_hh << endl;
		fileinThongTinQuan >> a.soLuongTonKho;

		fileinThongTinQuan.ignore();
		fileinThongTinQuan >> a.gia;
		fileinThongTinQuan.ignore();
		fileinThongTinQuan >> a.size;
		fileinThongTinQuan.ignore();
		getline(fileinThongTinQuan, a.mo_ta_sp, '.');
		getline(fileinThongTinQuan, a.thoi_gian_nhap_hang);

		dshh.ds_quan.push_back(a);
	}
	fileinThongTinQuan.close();
	ifstream fileinThongTinAo("ao.txt", ios::in);
	while (fileinThongTinAo.eof() == false) {
		HangHoa a;
		getline(fileinThongTinAo, a.ma_hh, ',');
		getline(fileinThongTinAo, a.ten_hh, ',');
		fileinThongTinAo >> a.soLuongTonKho;
		fileinThongTinAo.ignore();
		fileinThongTinAo >> a.gia;
		fileinThongTinAo.ignore();
		fileinThongTinAo >> a.size;
		fileinThongTinAo.ignore();
		getline(fileinThongTinAo, a.mo_ta_sp, '.');
		getline(fileinThongTinAo, a.thoi_gian_nhap_hang);
		dshh.ds_ao.push_back(a);
	}
	fileinThongTinAo.close();
}
//==================================================================
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
	float tien;
	cout << "Ma hoa don: " << a.ma_hoa_don << endl;
	cout << "Ma khach hang: " << a.ma_kh << endl;
	cout << "\tThong tin hang hoa: " << endl;
	cout << "Ma hang hoa: " << a.ma_hang_hoa << endl;
	for (int i = 0; c.ds_ao.size(); i++)
	{
		if (a.ma_hang_hoa == c.ds_ao.at(i).ma_hh)
		{
			cout << "Ten hang hoa: " << c.ds_ao.at(i).ten_hh << endl;
			cout << "Gia: " << c.ds_ao.at(i).gia << endl;
			tien = c.ds_ao.at(i).gia;
			cout << "Size: " << c.ds_ao.at(i).size << endl;
			break;
		}
	}
	for (int i = 0; c.ds_quan.size(); i++)
	{
		if (a.ma_hang_hoa == c.ds_quan.at(i).ma_hh)
		{
			cout << "Ten hang hoa: " << c.ds_quan.at(i).ten_hh << endl;
			cout << "Gia: " << c.ds_quan.at(i).gia << endl;
			tien = c.ds_quan.at(i).gia;
			cout << "Size: " << c.ds_quan.at(i).size << endl;
			break;
		}
	}
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
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
	cout << endl;
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang << endl;
	cout << "Tong tien: " << a.tong_tien;
	cout << "Trang thai: " << a.trang_thai << endl;
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
	a.sl++;
}

// Hàm xếp hạng khách hàng theo số tiền đã tiêu
void xep_hang_khach_hang_theo_tien(TREE t)
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

// =============================GIO HANG============================= 
// Hàm khởi tạo danh sách giỏ hàng
void KhoiTao_DanhSach_GioHang(ds_hh_trong_gio_hang& ds_gh) {
	ds_gh.pHead = NULL;
	ds_gh.pTail = NULL;
}
// Hàm khỏi tạo 1 node
node_gio_hang* khoiTao_node_gio_hang(gio_hang a) {
	node_gio_hang* p = new node_gio_hang;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat" << endl;
		return NULL;
	}
	else {
		p->data = a;
		p->pNext = NULL;
		return p;
	}
}
// Hàm thêm vào đầu danh sách giỏ hàng 
void ThemVaoDau_DanhSach_GioHang(ds_hh_trong_gio_hang& ds_gh, gio_hang a) {
	// danh sach rong 
	node_gio_hang* p = khoiTao_node_gio_hang(a);
	if (ds_gh.pHead == NULL) {
		ds_gh.pHead = ds_gh.pTail = p;
	}
	else {
		p->pNext = ds_gh.pHead;
		ds_gh.pHead = p;
	}
}

//  Hàm xoá hàng hoá ở vị trí bất kì trong danh sách giỏi hàng 
void Xoa_hangHoa_ViTriBatKi(ds_hh_trong_gio_hang& ds_gh, string vt)
{
	node_gio_hang* h = NULL;
	for (node_gio_hang* k = ds_gh.pHead; k != NULL;)
	{
		// vt nằm ở đầu danh sách
		if (_stricmp(k->data.data.ma_hh.c_str(), vt.c_str()) == 0 && k == ds_gh.pHead)
		{
			ds_gh.pHead = ds_gh.pHead->pNext;
			delete k;
			k = ds_gh.pHead;
		}
		else
		{
			// xoá vị trí bất kì(ko ở đầu)
			if (_stricmp(k->data.data.ma_hh.c_str(), vt.c_str()) == 0)
			{
				h->pNext = k->pNext;
				delete k;
				k = h;
				// sau khi xoá vt nằm ở cuối
				if (h->pNext == NULL) {
					ds_gh.pTail = h;
					return;
				}
			}
			h = k;
			k = k->pNext;
		}
	}
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


//void test()
//{
//	Admin a;
//	for (node_hoa_don* k = a.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
//	{
//
//	}
//	for (node_hoa_don* k = a.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
//	{
//
//	}
//	if (a.quan_li_ds_kh.t != NULL)
//	{
//		for (node_hoa_don* k = a.quan_li_ds_kh.t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
//		{
//
//		}
//	}
//}
