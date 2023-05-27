#pragma once

#include "chuong_trinh.h"
//================ Hàng Hóa ====================
void load_file_thong_tin_quan(DS_Hang_Hoa& dshh) 
{
	ifstream fi("Quan.txt", ios::in);
	while (fi.eof() == false) {
		HangHoa a;
		getline(fi, a.ma_hh, ',');
		getline(fi, a.ten_hh, ',');
		fi >> a.soLuongTonKho;
		fi.ignore();
		fi >> a.gia;
		fi.ignore();
		getline(fi, a.size,',');
		getline(fi, a.mo_ta_sp, '.');
		getline(fi, a.thoi_gian_nhap_hang);
		dshh.ds_quan.push_back(a);
	}
	fi.close();
}

void ghi_file_quan(DS_Hang_Hoa dshh) 
{
	ofstream fo;
	fo.open("Quan.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();
	fo.open("Quan.txt", ios::app);
	for (int i = 0; i < dshh.ds_quan.size(); i++) 
	{
		fo << dshh.ds_quan.at(i).ma_hh;
		fo << ',';
		fo << dshh.ds_quan.at(i).ten_hh;
		fo << ',';
		fo << dshh.ds_quan.at(i).soLuongTonKho;
		fo << ',';
		fo << dshh.ds_quan.at(i).gia;
		fo << ',';
		fo << dshh.ds_quan.at(i).size;
		fo << ',';
		fo << dshh.ds_quan.at(i).mo_ta_sp;
		fo << ',';
		fo << dshh.ds_quan.at(i).thoi_gian_nhap_hang;
		if (i == dshh.ds_quan.size() - 1)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
	fo.close();
}

void load_file_thong_tin_ao(DS_Hang_Hoa &dshh)
{
	ifstream fi("Ao.txt", ios::in);
	while (fi.eof() == false) 
	{
		HangHoa a;
		getline(fi, a.ma_hh, ',');
		getline(fi, a.ten_hh, ',');
		fi >> a.soLuongTonKho;
		fi.ignore();
		fi >> a.gia;
		fi.ignore();
		getline(fi, a.size, ',');
		getline(fi, a.mo_ta_sp, '.');
		getline(fi, a.thoi_gian_nhap_hang);
		dshh.ds_ao.push_back(a);
	}
	fi.close();
}

void ghi_file_ao(DS_Hang_Hoa dshh) 
{
	ofstream fo;
	fo.open("Ao.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();
	fo.open("Ao.txt", ios::app);
	for (int i = 0; i < dshh.ds_ao.size(); i++) 
	{
		fo << dshh.ds_ao.at(i).ma_hh;
		fo << ',';
		fo << dshh.ds_ao.at(i).ten_hh;
		fo << ',';
		fo << dshh.ds_ao.at(i).soLuongTonKho;
		fo << ',';
		fo << dshh.ds_ao.at(i).gia;
		fo << ',';
		fo << dshh.ds_ao.at(i).size;
		fo << ',';
		fo << dshh.ds_ao.at(i).mo_ta_sp;
		fo << ',';
		fo << dshh.ds_ao.at(i).thoi_gian_nhap_hang;
		if (i == dshh.ds_ao.size() - 1)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
}

//================ Hàng Hóa Xóa ====================
void load_file_thong_tin_hh_xoa(DS_Hang_Hoa_Xoa& dshh)
{
	ifstream fi("DS_hh_xoa.txt", ios::in);
	while (fi.eof() == false) {
		Hang_Hoa_Xoa a;
		getline(fi, a.hh.ma_hh, ',');
		getline(fi, a.hh.ten_hh, ',');
		fi >> a.hh.soLuongTonKho;
		fi.ignore();
		fi >> a.hh.gia;
		fi.ignore();
		getline(fi, a.hh.size, ',');
		getline(fi, a.hh.mo_ta_sp, '.');
		getline(fi, a.hh.thoi_gian_nhap_hang,',');
		getline(fi, a.ngay_xoa);
		dshh.ds.push_back(a);
	}
	fi.close();
}

void ghi_file_hh_xoa(DS_Hang_Hoa_Xoa dshh)
{
	ofstream fo;
	fo.open("DS_hh_xoa.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();
	fo.open("DS_hh_xoa.txt", ios::app);
	for (int i = 0; i < dshh.ds.size(); i++)
	{
		fo << dshh.ds.at(i).hh.ma_hh;
		fo << ',';
		fo << dshh.ds.at(i).hh.ten_hh;
		fo << ',';
		fo << dshh.ds.at(i).hh.soLuongTonKho;
		fo << ',';
		fo << dshh.ds.at(i).hh.gia;
		fo << ',';
		fo << dshh.ds.at(i).hh.size;
		fo << ',';
		fo << dshh.ds.at(i).hh.mo_ta_sp;
		fo << ',';
		fo << dshh.ds.at(i).hh.thoi_gian_nhap_hang;
		fo << ',';
		fo << dshh.ds.at(i).ngay_xoa;
		if (i == dshh.ds.size() - 1)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
}

//================ Hóa Đơn =====================

void load_file_hoa_don_nhap(DS_HOA_DON &a)
{
	ifstream fi("thong_tin_hoa_don_nhap_hang.txt",ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	fi >> a.sl;
	fi.ignore();
	for (int i = 0; i < a.sl; i++)
	{
		HoaDon k;
		getline(fi, k.ma_hoa_don,',');
		getline(fi, k.thong_tin_hang.ma_hh,',');
		getline(fi, k.thong_tin_hang.ten_hh, ',');
		fi >> k.thong_tin_hang.gia;
		fi.ignore();
		getline(fi, k.thong_tin_hang.size, ',');
		fi >> k.sl_mua;
		fi.ignore();
		getline(fi, k.ngay_lap_hd,',');
		fi >> k.tong_tien;
		fi.ignore();
		getline(fi, k.trang_thai);
		them_cuoi_ds_hoa_don(a, k);
	}
	fi.close();
}

void ghi_file_hoa_don_nhap(DS_HOA_DON a)
{
	ofstream fo;
	fo.open("thong_tin_hoa_don_nhap_hang.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();

	fo.open("thong_tin_hoa_don_nhap_hang.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		fo << k->data.ma_hoa_don;
		fo << ',';
		fo << k->data.thong_tin_hang.ma_hh;
		fo << ',';
		fo << k->data.thong_tin_hang.ten_hh;
		fo << ',';
		fo << k->data.thong_tin_hang.gia;
		fo << ',';
		fo << k->data.thong_tin_hang.size;
		fo << ',';
		fo << k->data.sl_mua;
		fo << ',';
		fo << k->data.ngay_lap_hd;
		fo << ',';
		fo << k->data.tong_tien;
		fo << ',';
		fo << k->data.trang_thai;
		if (k->pNext == NULL)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
	fo.close();
}

void load_file_hoa_don_xuat(DS_HOA_DON &a)
{
	ifstream fi("thong_tin_hoa_don_ban_hang.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	fi >> a.sl;
	fi.ignore();
	for (int i = 0; i < a.sl; i++)
	{
		HoaDon b;
		getline(fi, b.ma_hoa_don, ',');
		getline(fi, b.ma_kh, ',');
		getline(fi, b.ma_hang_hoa, ',');
		getline(fi, b.thong_tin_hang.ten_hh, ',');
		fi >> b.thong_tin_hang.gia;
		fi.ignore();
		getline(fi, b.thong_tin_hang.size, ',');
		fi >> b.sl_mua;
		fi.ignore();
		getline(fi, b.ngay_lap_hd,',');
		fi >> b.giam_gia_theo_hang;
		fi.ignore();
		fi >> b.tong_tien;
		fi.ignore();
		getline(fi, b.trang_thai);
		them_cuoi_ds_hoa_don(a, b);
	}
	fi.close();
}

void ghi_file_hoa_don_xuat(DS_HOA_DON a)
{
	ofstream fo;
	fo.open("thong_tin_hoa_don_ban_hang.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();

	fo.open("thong_tin_hoa_don_ban_hang.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		fo << k->data.ma_hoa_don;
		fo << ',';
		fo << k->data.ma_kh;
		fo << ',';
		fo << k->data.ma_hang_hoa;
		fo << ',';
		fo << k->data.thong_tin_hang.ten_hh;
		fo << ',';
		fo << k->data.thong_tin_hang.gia;
		fo << ',';
		fo << k->data.thong_tin_hang.size;
		fo << ',';
		fo << k->data.sl_mua;
		fo << ',';
		fo << k->data.ngay_lap_hd;
		fo << ',';
		fo << k->data.giam_gia_theo_hang;
		fo << ',';
		fo << k->data.tong_tien;
		fo << ',';
		fo << k->data.trang_thai;
		if (k->pNext == NULL)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
	fo.close();
}

//================ Hóa Đơn Xóa =====================
void load_file_hoa_don_nhap_xoa(DS_HOA_DON_XOA& a)
{
	ifstream fi("DS_hoa_don_nhap_xoa.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	fi >> a.sl;
	fi.ignore();
	for (int i = 0; i < a.sl; i++)
	{
		HoaDonXoa k;
		getline(fi, k.hd.ma_hoa_don, ',');
		getline(fi, k.hd.thong_tin_hang.ma_hh, ',');
		getline(fi, k.hd.thong_tin_hang.ten_hh, ',');
		fi >> k.hd.thong_tin_hang.gia;
		fi.ignore();
		getline(fi, k.hd.thong_tin_hang.size, ',');
		fi >> k.hd.sl_mua;
		fi.ignore();
		getline(fi, k.hd.ngay_lap_hd, ',');
		fi >> k.hd.tong_tien;
		fi.ignore();
		getline(fi, k.hd.trang_thai,',');
		getline(fi, k.ngay_xoa);
		them_cuoi_ds_hoa_don_xoa(a, k);
	}
	fi.close();
}

void ghi_file_hoa_don_nhap_xoa(DS_HOA_DON_XOA a)
{
	ofstream fo;
	fo.open("DS_hoa_don_nhap_xoa.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();

	fo.open("DS_hoa_don_nhap_xoa.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	for (node_hoa_don_xoa* k = a.pHead; k != NULL; k = k->pNext)
	{
		fo << k->hdx.hd.ma_hoa_don;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.ma_hh;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.ten_hh;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.gia;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.size;
		fo << ',';
		fo << k->hdx.hd.sl_mua;
		fo << ',';
		fo << k->hdx.hd.ngay_lap_hd;
		fo << ',';
		fo << k->hdx.hd.tong_tien;
		fo << ',';
		fo << k->hdx.hd.trang_thai;
		fo << ',';
		fo << k->hdx.ngay_xoa;
		if (k->pNext == NULL)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
	fo.close();
}

void load_file_hoa_don_xuat_xoa(DS_HOA_DON_XOA& a)
{
	ifstream fi("Ds_hoa_don_xuat_xoa.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	fi >> a.sl;
	fi.ignore();
	for (int i = 0; i < a.sl; i++)
	{
		HoaDonXoa b;
		getline(fi, b.hd.ma_hoa_don, ',');
		getline(fi, b.hd.ma_kh, ',');
		getline(fi, b.hd.ma_hang_hoa, ',');
		getline(fi, b.hd.thong_tin_hang.ten_hh, ',');
		fi >> b.hd.thong_tin_hang.gia;
		fi.ignore();
		getline(fi, b.hd.thong_tin_hang.size, ',');
		fi >> b.hd.sl_mua;
		fi.ignore();
		getline(fi, b.hd.ngay_lap_hd, ',');
		fi >> b.hd.giam_gia_theo_hang;
		fi.ignore();
		fi >> b.hd.tong_tien;
		fi.ignore();
		getline(fi, b.hd.trang_thai,',');
		getline(fi, b.ngay_xoa);
		them_cuoi_ds_hoa_don_xoa(a, b);
	}
	fi.close();
}

void ghi_file_hoa_don_xuat_xoa(DS_HOA_DON_XOA a)
{
	ofstream fo;
	fo.open("DS_hoa_don_xuat_xoa.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();

	fo.open("DS_hoa_don_xuat_xoa.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	for (node_hoa_don_xoa* k = a.pHead; k != NULL; k = k->pNext)
	{
		fo << k->hdx.hd.ma_hoa_don;
		fo << ',';
		fo << k->hdx.hd.ma_kh;
		fo << ',';
		fo << k->hdx.hd.ma_hang_hoa;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.ten_hh;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.gia;
		fo << ',';
		fo << k->hdx.hd.thong_tin_hang.size;
		fo << ',';
		fo << k->hdx.hd.sl_mua;
		fo << ',';
		fo << k->hdx.hd.ngay_lap_hd;
		fo << ',';
		fo << k->hdx.hd.giam_gia_theo_hang;
		fo << ',';
		fo << k->hdx.hd.tong_tien;
		fo << ',';
		fo << k->hdx.hd.trang_thai;
		fo << ',';
		fo << k->hdx.ngay_xoa;
		if (k->pNext == NULL)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
	fo.close();
}

// ============== Đơn hàng trả ================
void load_file_don_hang_tra(DS_HOA_DON& a)
{
	ifstream fi("don_hang_tra.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	fi >> a.sl;
	fi.ignore();
	for (int i = 0; i < a.sl; i++)
	{
		HoaDon b;
		getline(fi, b.ma_hoa_don, ',');
		getline(fi, b.ma_kh, ',');
		getline(fi, b.ma_hang_hoa, ',');
		getline(fi, b.thong_tin_hang.ten_hh, ',');
		fi >> b.thong_tin_hang.gia;
		fi.ignore();
		getline(fi, b.thong_tin_hang.size, ',');
		fi >> b.sl_mua;
		fi.ignore();
		getline(fi, b.ngay_lap_hd, ',');
		fi >> b.giam_gia_theo_hang;
		fi.ignore();
		fi >> b.tong_tien;
		fi.ignore();
		getline(fi, b.trang_thai);
		them_cuoi_ds_hoa_don(a, b);
	}
	fi.close();
}

void ghi_file_don_hang_tra(DS_HOA_DON a)
{
	ofstream fo;
	fo.open("don_hang_tra.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();

	fo.open("don_hang_tra.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	for (node_hoa_don* k = a.pHead; k != NULL; k = k->pNext)
	{
		fo << k->data.ma_hoa_don;
		fo << ',';
		fo << k->data.ma_kh;
		fo << ',';
		fo << k->data.ma_hang_hoa;
		fo << ',';
		fo << k->data.thong_tin_hang.ten_hh;
		fo << ',';
		fo << k->data.thong_tin_hang.gia;
		fo << ',';
		fo << k->data.thong_tin_hang.size;
		fo << ',';
		fo << k->data.sl_mua;
		fo << ',';
		fo << k->data.ngay_lap_hd;
		fo << ',';
		fo << k->data.giam_gia_theo_hang;
		fo << ',';
		fo << k->data.tong_tien;
		fo << ',';
		fo << k->data.trang_thai;
		if (k->pNext == NULL)
		{
			fo.close();
			return;
		}
		fo << endl;
	}
	fo.close();
}

// ============== Khách hàng ================
void load_file_thong_tin_khach_hang(ds_khach_hang &a)
{
		ifstream fi("thong_tin_khach_hang.txt", ios::in);
		if (fi.fail() == true)
		{
			cout << "Khong mo duoc!" << endl;
			fi.close();
			return;
		}
		fi >> a.sl;
		fi.ignore();
		for (int i = 0; i < a.sl; i++) 
		{
			KH b;
			getline(fi, b.email, ',');
			getline(fi, b.maKh, ',');
			getline(fi, b.ten, ',');
			getline(fi, b.diaChi, ',');
			getline(fi, b.sdt,',');
			getline(fi, b.ten_dang_nhap, ',');
			getline(fi, b.mat_khau,',');
			getline(fi, b.ngay_dk);
			them_khachhang_vao_cay(a.t, b);
			can_bang_cay(a.t);
		}
		fi.close();
}

void tim_diem_cuoi_cua_duyet_cay_NLR(TREE t, node_kh*& dc)
{
	if (t != NULL)
	{
		dc = t;
		tim_diem_cuoi_cua_duyet_cay_NLR(t->pLeft, dc);
		tim_diem_cuoi_cua_duyet_cay_NLR(t->pRight, dc);
	}
	return;
}
void duyet_ghi_tt_kh(TREE t, node_kh*dc) 
{
	ofstream fo("thong_tin_khach_hang.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	if (t != NULL)
	{
		fo << t->data.email;
		fo << ',';
		fo << t->data.maKh;
		fo << ',';
		fo << t->data.ten;
		fo << ',';
		fo << t->data.diaChi;
		fo << ',';
		fo << t->data.sdt;
		fo << ',';
		fo << t->data.ten_dang_nhap;
		fo << ',';
		fo << t->data.mat_khau;
		fo << ',';
		fo << t->data.ngay_dk;
		if (dc == t)
		{
			fo.close();
			return;
		}
		fo << endl;
		duyet_ghi_tt_kh(t->pLeft,dc);
		duyet_ghi_tt_kh(t->pRight,dc);
	}
	fo.close();
}
void ghi_thong_tin_kh(ds_khach_hang a)
{
	node_kh* dc = NULL;
	tim_diem_cuoi_cua_duyet_cay_NLR(a.t, dc);
	ofstream fo("thong_tin_khach_hang.txt",ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	duyet_ghi_tt_kh(a.t,dc);
	fo.close();
}

// ============== Khách hàng xóa ================
void load_file_thong_tin_khach_hang_xoa(ds_khach_hang_xoa& a)
{
	ifstream fi("DS_khach_hang_xoa.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	fi >> a.sl;
	fi.ignore();
	for (int i = 0; i < a.sl; i++)
	{
		KHX b;
		getline(fi, b.kh.email, ',');
		getline(fi, b.kh.maKh, ',');
		getline(fi, b.kh.ten, ',');
		getline(fi, b.kh.diaChi, ',');
		getline(fi, b.kh.sdt, ',');
		getline(fi, b.kh.ten_dang_nhap, ',');
		getline(fi, b.kh.mat_khau,',');
		getline(fi, b.ngay_xoa);
		them_KhachHangXoa_vao_cay(a.t, b);
		can_bang_cay_xoa(a.t);
	}
	fi.close();
}

void tim_diem_cuoi_cua_duyet_cay_xoa_NLR(TREE_XOA t, node_kh_xoa*& dc)
{
	if (t != NULL)
	{
		dc = t;
		tim_diem_cuoi_cua_duyet_cay_xoa_NLR(t->pLeft, dc);
		tim_diem_cuoi_cua_duyet_cay_xoa_NLR(t->pRight, dc);
	}
	return;
}
void duyet_ghi_tt_kh_xoa(TREE_XOA t, node_kh_xoa* dc)
{
	ofstream fo("DS_khach_hang_xoa.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	if (t != NULL)
	{
		fo << t->khx.kh.email;
		fo << ',';
		fo << t->khx.kh.maKh;
		fo << ',';
		fo << t->khx.kh.ten;
		fo << ',';
		fo << t->khx.kh.diaChi;
		fo << ',';
		fo << t->khx.kh.sdt;
		fo << ',';
		fo << t->khx.kh.ten_dang_nhap;
		fo << ',';
		fo << t->khx.kh.mat_khau;
		fo << ',';
		fo << t->khx.ngay_xoa;
		if (dc == t)
		{
			fo.close();
			return;
		}
		fo << endl;
		duyet_ghi_tt_kh_xoa(t->pLeft, dc);
		duyet_ghi_tt_kh_xoa(t->pRight, dc);
	}
	fo.close();
}
void ghi_thong_tin_kh_xoa(ds_khach_hang_xoa a)
{
	node_kh_xoa* dc = NULL;
	tim_diem_cuoi_cua_duyet_cay_xoa_NLR(a.t, dc);
	ofstream fo("DS_khach_hang_xoa.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	duyet_ghi_tt_kh_xoa(a.t, dc);
	fo.close();
}

// ============== Đơn mua hàng ================
void duyet_load_don_mua(TREE& a, string tam, ifstream& fi)	
{
	if (a != NULL)
	{
		if (tam == a->data.maKh)
		{
			fi >> a->data.don_mua_hang.sl;
			fi.ignore();
			for (int i = 0; i < a->data.don_mua_hang.sl; i++)
			{
				HoaDon b;
				getline(fi, b.ma_hoa_don, ',');
				getline(fi, b.ma_kh, ',');
				getline(fi, b.ma_hang_hoa, ',');
				getline(fi, b.thong_tin_hang.ten_hh, ',');
				fi >> b.thong_tin_hang.gia;
				fi.ignore();
				getline(fi, b.thong_tin_hang.size, ',');
				fi >> b.sl_mua;
				fi.ignore();
				getline(fi, b.ngay_lap_hd, ',');
				fi >> b.giam_gia_theo_hang;
				fi.ignore();
				fi >> b.tong_tien;
				fi.ignore();
				getline(fi, b.trang_thai);
				them_cuoi_ds_hoa_don(a->data.don_mua_hang, b);
			}
		}
		else if (stoi(tam.substr(2, 4)) < stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_don_mua(a->pLeft, tam, fi);
		}
		else if (stoi(tam.substr(2, 4)) > stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_don_mua(a->pRight, tam, fi);
		}
	}
}
void load_file_don_mua_kh(TREE& a)
{
	ifstream fi;
	fi.open("don_mua_hang.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	while (fi.eof() == false)
	{
		string tam;
		fi >>  tam;
		fi.ignore();
		duyet_load_don_mua(a, tam, fi);
	}
	fi.close();
}

void ghi_don_mua_cua_1_kh(KhachHang a)
{
	ofstream fo;
	fo.open("don_mua_hang.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.maKh;
	fo << endl;
	fo << a.don_mua_hang.sl;
	fo << endl;
	for (node_hoa_don* k = a.don_mua_hang.pHead; k != NULL; k = k->pNext)
	{
		fo << k->data.ma_hoa_don;
		fo << ',';
		fo << k->data.ma_kh;
		fo << ',';
		fo << k->data.ma_hang_hoa;
		fo << ',';
		fo << k->data.thong_tin_hang.ten_hh;
		fo << ',';
		fo << k->data.thong_tin_hang.gia;
		fo << ',';
		fo << k->data.thong_tin_hang.size;
		fo << ',';
		fo << k->data.sl_mua;
		fo << ',';
		fo << k->data.ngay_lap_hd;
		fo << ',';
		fo << k->data.giam_gia_theo_hang;
		fo << ',';
		fo << k->data.tong_tien;
		fo << ',';
		fo << k->data.trang_thai;
		fo << endl;
	}
	fo.close();
}
void duyet_cay_ghi_don_mua(TREE t,node_kh* dc)
{
	if (t != NULL)
	{
		if (dc == t)
		{
			ofstream fo;
			fo.open("don_mua_hang.txt", ios::app);
			if (fo.fail() == true)
			{
				cout << "Khong mo duoc!" << endl;
				fo.close();
				return;
			}
			fo << t->data.maKh;
			fo << endl;
			fo << t->data.don_mua_hang.sl;
			if (t->data.don_mua_hang.sl == 0 && dc == t)
			{
				fo.close();
				return;
			}
			fo << endl;
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				fo << k->data.ma_hoa_don;
				fo << ',';
				fo << k->data.ma_kh;
				fo << ',';
				fo << k->data.ma_hang_hoa;
				fo << ',';
				fo << k->data.thong_tin_hang.ten_hh;
				fo << ',';
				fo << k->data.thong_tin_hang.gia;
				fo << ',';
				fo << k->data.thong_tin_hang.size;
				fo << ',';
				fo << k->data.sl_mua;
				fo << ',';
				fo << k->data.ngay_lap_hd;
				fo << ',';
				fo << k->data.giam_gia_theo_hang;
				fo << ',';
				fo << k->data.tong_tien;
				fo << ',';
				fo << k->data.trang_thai;
				if (k->pNext == NULL)
				{
					fo.close();
					return;
				}
				fo << endl;
			}
			fo.close();
		}
		ghi_don_mua_cua_1_kh(t->data);
		duyet_cay_ghi_don_mua(t->pLeft,dc);
		duyet_cay_ghi_don_mua(t->pRight,dc);
	}
}
void ghi_don_mua_cua_dskh(TREE t)
{
	node_kh* dc = NULL;
	tim_diem_cuoi_cua_duyet_cay_NLR(t, dc);
	ofstream fo;
	fo.open("don_mua_hang.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();
	duyet_cay_ghi_don_mua(t,dc);
}

// =================== Gio hang =================
void duyet_load_gio_hang(TREE& a, string tam, ifstream& fi, int size)
{
	if (a != NULL)
	{
		if (tam == a->data.maKh)
		{
			for (int i = 0; i < size; i++)
			{
				HangHoa b;
				getline(fi, b.ma_hh, ',');
				getline(fi, b.ten_hh, ',');
				fi >> b.soLuongTonKho;
				fi.ignore();
				fi >> b.gia;
				fi.ignore();
				getline(fi, b.size, ',');
				getline(fi, b.mo_ta_sp, '.');
				getline(fi, b.thoi_gian_nhap_hang);
				a->data.data_gh.hh.push_back(b);
			}
		}
		else if (stoi(tam.substr(2, 4)) < stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_gio_hang(a->pLeft, tam, fi,size);
		}
		else if (stoi(tam.substr(2, 4)) > stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_gio_hang(a->pRight, tam, fi,size);
		}
	}
}
void load_file_gio_hang(TREE& a)
{
	ifstream fi;
	fi.open("gio_hang.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	while (fi.eof() == false)
	{
		string tam;
		fi >> tam;
		fi.ignore();
		int size;
		fi >> size;
		fi.ignore();
		duyet_load_gio_hang(a, tam, fi,size);
	}
}

void ghi_gio_hang_cua_1_kh(KhachHang a)
{
	ofstream fo;
	fo.open("gio_hang.txt", ios::app);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.maKh;
	fo << endl;
	fo << a.data_gh.hh.size();
	fo << endl;
	for (int  i = 0; i < a.data_gh.hh.size(); i++)
	{
		fo << a.data_gh.hh.at(i).ma_hh;
		fo << ',';
		fo << a.data_gh.hh.at(i).ten_hh;
		fo << ',';
		fo << a.data_gh.hh.at(i).soLuongTonKho;
		fo << ',';
		fo << a.data_gh.hh.at(i).gia;
		fo << ',';
		fo << a.data_gh.hh.at(i).size;
		fo << ',';
		fo << a.data_gh.hh.at(i).mo_ta_sp;
		fo << ',';
		fo << a.data_gh.hh.at(i).thoi_gian_nhap_hang;
		fo << endl;
	}
}
void duyet_cay_ghi_gio_hang(TREE t,node_kh*dc)
{
	if (t != NULL)
	{
		if (dc == t)
		{
			ofstream fo;
			fo.open("gio_hang.txt", ios::app);
			if (fo.fail() == true)
			{
				cout << "Khong mo duoc!" << endl;
				fo.close();
				return;
			}
			fo << t->data.maKh;
			fo << endl;
			fo << t->data.data_gh.hh.size();
			if (t->data.data_gh.hh.size() == 0 && dc == t )
			{
				fo.close();
				return;
			}
			fo << endl;
			for (int i = 0; i < t->data.data_gh.hh.size(); i++)
			{
				fo << t->data.data_gh.hh.at(i).ma_hh;
				fo << ',';
				fo << t->data.data_gh.hh.at(i).ten_hh;
				fo << ',';
				fo << t->data.data_gh.hh.at(i).soLuongTonKho;
				fo << ',';
				fo << t->data.data_gh.hh.at(i).gia;
				fo << ',';
				fo << t->data.data_gh.hh.at(i).size;
				fo << ',';
				fo << t->data.data_gh.hh.at(i).mo_ta_sp;
				fo << ',';
				fo << t->data.data_gh.hh.at(i).thoi_gian_nhap_hang;
				if (i == t->data.data_gh.hh.size() - 1)
				{
					fo.close();
					return;
				}
				fo << endl;
			}
		}
		ghi_gio_hang_cua_1_kh(t->data);
		duyet_cay_ghi_gio_hang(t->pLeft,dc);
		duyet_cay_ghi_gio_hang(t->pRight,dc);
	}
}
void ghi_gio_hang_cua_dskh(TREE t)
{
	node_kh* dc = NULL;
	tim_diem_cuoi_cua_duyet_cay_NLR(t, dc);
	ofstream fo;
	fo.open("gio_hang.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << "";
	fo.close();
	duyet_cay_ghi_gio_hang(t,dc);
}

//================== Admin =================
void load_tk_mk(string &tk, string &mk)
{
	ifstream fi;
	fi.open("tk_mk_ad.txt", ios::in);
	if (fi.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fi.close();
		return;
	}
	while (fi.eof() == false)
	{
		getline(fi, tk);
		getline(fi, mk);
	}
	fi.close();
}

void ghi_tk_mk_ad(string tk, string mk)
{
	ofstream fo;
	fo.open("tk_mk_ad.txt", ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << tk;
	fo << endl;
	fo << mk;
	fo.close();
}

void load_full(Admin& ad)
{
	load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	load_file_thong_tin_hh_xoa(ad.quan_li_hh_xoa);
	load_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	load_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	load_file_hoa_don_nhap_xoa(ad.quan_li_hd_nhap_xoa);
	load_file_hoa_don_xuat_xoa(ad.quan_li_hd_xuat_xoa);
	load_file_don_hang_tra(ad.quan_li_don_hang_tra);
	load_file_thong_tin_khach_hang(ad.quan_li_ds_kh);
	load_file_don_mua_kh(ad.quan_li_ds_kh.t);
	load_file_gio_hang(ad.quan_li_ds_kh.t);
	load_file_thong_tin_khach_hang_xoa(ad.quan_li_kh_xoa);
}

void ghi_full(Admin ad)
{
	ghi_file_quan(ad.quan_li_ds_hang_hoa);
	ghi_file_ao(ad.quan_li_ds_hang_hoa);
	ghi_file_hh_xoa(ad.quan_li_hh_xoa);
	ghi_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	ghi_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	ghi_file_hoa_don_nhap_xoa(ad.quan_li_hd_nhap_xoa);
	ghi_file_hoa_don_xuat_xoa(ad.quan_li_hd_xuat_xoa);
	ghi_file_don_hang_tra(ad.quan_li_don_hang_tra);
	ghi_thong_tin_kh(ad.quan_li_ds_kh);
	ghi_don_mua_cua_dskh(ad.quan_li_ds_kh.t);
	ghi_gio_hang_cua_dskh(ad.quan_li_ds_kh.t);
	ghi_thong_tin_kh_xoa(ad.quan_li_kh_xoa);

}
