#pragma once

#include "chuong_trinh.h"

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
	//ofstream fo("thong_tin_hoa_don_nhap_hang.txt", ios::app);
	ofstream fo;
	fo.open("test.txt", ios::out);
	fo << "";
	fo.close();

	fo.open("test.txt", ios::app);
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
		fo << endl;
	}
	fo.close();
}

void load_file_hoa_don_xuat(ds_hoa_don &a)
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
		/*getline(fi, b.thong_tin_hang.ten_hh, ',');*/
		/*fi >> b.thong_tin_hang.gia;*/
		/*fi.ignore();*/
		/*getline(fi, b.thong_tin_hang.size, ',');*/
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
			getline(fi, b.mat_khau);
			them_khachhang_vao_cay(a.t, b);
			can_bang_cay(a.t);
		}
		fi.close();
}

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
		if (stoi(tam.substr(2, 4)) < stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_don_mua(a->pLeft,tam,fi);
		}
		else if (stoi(tam.substr(2, 4)) > stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_don_mua(a->pRight,tam,fi);
		}
	}
}
void load_file_don_mua_kh(TREE &a)
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
		fi >> tam;
		fi.ignore();
		duyet_load_don_mua(a, tam, fi);
	}
	fi.close();
}

void duyet_ghi_tt_kh(TREE t) {
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
		fo << endl;
		duyet_ghi_tt_kh(t->pLeft);
		duyet_ghi_tt_kh(t->pRight);
	}
	fo.close();
}
void ghi_thong_tin_kh(ds_khach_hang a)
{
	ofstream fo("thong_tin_khach_hang.txt",ios::out);
	if (fo.fail() == true)
	{
		cout << "Khong mo duoc!" << endl;
		fo.close();
		return;
	}
	fo << a.sl;
	fo << endl;
	duyet_ghi_tt_kh(a.t);
	fo.close();
}

void ghi_don_mua_kh(ds_khach_hang a)
{

}

void ghi_gio_hang_kh(ds_khach_hang a)
{

}

// ============ Gio hang ============
void duyet_load_gio_hang(TREE& a, string tam, ifstream& fi)
{
	if (a != NULL)
	{
		if (tam == a->data.maKh)
		{
			fi >> a->data.hh_gio_hang.sl;
			fi.ignore();
			for (int i = 0; i < a->data.hh_gio_hang.sl; i++)
			{
				gio_hang b;
				getline(fi, b.data.ma_hh, ',');
				getline(fi, b.data.ten_hh, ',');
				fi >> b.data.soLuongTonKho;
				fi.ignore();
				fi >> b.data.gia;
				fi.ignore();
				getline(fi, b.data.size, ',');
				getline(fi, b.data.mo_ta_sp);
				ThemVaoDau_DanhSach_GioHang(a->data.hh_gio_hang, b);
			}
		}
		if (stoi(tam.substr(2, 4)) < stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_gio_hang(a->pLeft, tam, fi);
		}
		else if (stoi(tam.substr(2, 4)) > stoi(a->data.maKh.substr(2, 4)))
		{
			duyet_load_gio_hang(a->pRight, tam, fi);
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
		duyet_load_gio_hang(a, tam, fi);
	}
	fi.close();
}

// ============== Quan Ao ================
void load_file_thong_tin_quan(DS_Hang_Hoa& dshh) 
{
	ifstream fi("quan.txt", ios::in);
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

void load_file_thong_tin_ao(DS_Hang_Hoa &dshh)
{
	ifstream fi("ao.txt", ios::in);
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

