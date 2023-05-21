#pragma once
#include<iostream>
#include<string>
#include<cstdlib>//rand,srand
#include<ctime>
#include<conio.h>
#include<fstream>
#include<vector>
#include <regex>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

// ============================ HÀNG HÓA ======================================//

struct HangHoa {
	string ma_hh;
	string ten_hh;
	unsigned short soLuongTonKho;
	long long gia;
	string size;
	string mo_ta_sp;
	string thoi_gian_nhap_hang;
};
typedef struct HangHoa HangHoa;

struct DS_Hang_Hoa
{
	vector <HangHoa> ds_ao;
	vector <HangHoa> ds_quan;
};
typedef struct DS_Hang_Hoa DS_Hang_Hoa;

struct Hang_Hoa_Xoa
{
	HangHoa hh;
	string ngay_xoa;
};
typedef struct Hang_Hoa_Xoa Hang_Hoa_Xoa;

struct DS_Hang_Hoa_Xoa
{
	vector <Hang_Hoa_Xoa> ds;
};
typedef struct DS_Hang_Hoa_Xoa DS_Hang_Hoa_Xoa;

// ===============================HÓA ĐƠN============================================//
struct HoaDon
{
	//nhap X: Xuat - N: Nhap
	string ma_hoa_don;
	string ma_hang_hoa;
	string ma_kh;
	long long gia_nhap;
	HangHoa thong_tin_hang;
	int sl_mua;
	string pptt;
	string ngay_lap_hd;
	string trang_thai;
	float giam_gia_theo_hang;
	long long tong_tien;

};
typedef struct HoaDon HoaDon;

struct HoaDonXoa
{
	HoaDon hd;
	string ngay_xoa;
};
typedef struct HoaDonXoa HoaDonXoa;

struct node_hoa_don
{
	HoaDon data;
	node_hoa_don* pNext;
};
typedef struct node_hoa_don node_hoa_don;

struct ds_hoa_don
{
	node_hoa_don* pHead = NULL;
	node_hoa_don* pTail = NULL;
	int sl = 0;
};
typedef struct ds_hoa_don DS_HOA_DON;

struct node_hoa_don_xoa
{
	HoaDonXoa hdx;
	node_hoa_don_xoa* pNext;
};
typedef struct node_hoa_don_xoa node_hoa_don_xoa;

struct ds_hoa_don_xoa
{
	node_hoa_don_xoa* pHead = NULL;
	node_hoa_don_xoa* pTail = NULL;
	int sl = 0;
};
typedef struct ds_hoa_don_xoa DS_HOA_DON_XOA;

//============================= Khách hàng ============================================//

typedef struct gio_hang
{
	vector <HangHoa> hh;
}gio_hang;


struct KhachHang {
	//data
	string maKh;
	string ten;
	string diaChi;
	string sdt;
	string email;
	

	//DS_Don_Mua ds_mua_hang; 
	ds_hoa_don don_mua_hang;

	//Gio_Hang mua_hang
	gio_hang data_gh;

	//account 
	string ten_dang_nhap;
	string mat_khau;

};
typedef struct KhachHang KH;

struct KhachHangXoa
{
	KhachHang kh;
	string ngay_xoa;
};
typedef struct KhachHang KH;

struct node_kh
{
	KH data;
	struct node_kh* pLeft;
	struct node_kh* pRight;
};
typedef struct node_kh node_kh;
typedef struct node_kh* TREE;

struct DS_KH 
{
	TREE t = NULL;
	int sl = 0;  //so luong khach hang
};
typedef struct DS_KH ds_khach_hang;

struct node_kh_xoa
{
	KhachHangXoa khx;
	struct node_kh_xoa* pLeft;
	struct node_kh_xoa* pRight;
};
typedef struct node_kh_xoa node_kh_xoa;
typedef struct node_kh_xoa* TREE_XOA;

struct DS_KH_XOA
{
	TREE_XOA t = NULL;
	int sl = 0;  //so luong khach hang
};
typedef struct DS_KH_XOA ds_khach_hang_xoa;

//============================ Admin ============================================//

typedef struct don_hang_cho
{
	HoaDon hoa_don;
}don_hang_cho;

struct ds_don_hang_cho
{
	vector <don_hang_cho> don_cho;
};

struct Admin
{
	ds_khach_hang quan_li_ds_kh;
	DS_Hang_Hoa quan_li_ds_hang_hoa;
	DS_HOA_DON quan_li_ds_hoa_don_xuat;
	DS_HOA_DON quan_li_ds_hoa_don_nhap;
	ds_don_hang_cho quan_li_don_hang_cho;
	
	DS_HOA_DON_XOA quan_li_hd_nhap_xoa;
	DS_HOA_DON_XOA quan_li_hd_xuat_xoa;
	DS_Hang_Hoa_Xoa quan_li_hh_xoa;
	ds_khach_hang_xoa quan_li_kh_xoa;
};
typedef struct Admin Admin;

void test()
{
	
}
