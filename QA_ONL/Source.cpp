#include "Xu_li_do_hoa.h"
#include "load_ghi_file.h"

void xuat_hoa_don_mua_khach_hang(TREE a, DS_Hang_Hoa b)
{
	if (a != NULL)
	{
		for (node_hoa_don* k = a->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
		{
			xuatHoaDonBanHang(k->data, b);
		}
		xuat_hoa_don_mua_khach_hang(a->pLeft, b);
		xuat_hoa_don_mua_khach_hang(a->pRight, b);

	}
}
void xuat_gio_hang_kh(TREE a, ds_hh_trong_gio_hang b)
{
	if (a != NULL)
	{
		cout << "\t\t" << a->data.maKh << endl;
		for (node_gio_hang* k = a->data.hh_gio_hang.pHead; k != NULL; k = k->pNext)
		{
			XuatGioHang(b, k->data.data);
			cout << "\n\t\t==============================\n";
		}

		xuat_gio_hang_kh(a->pLeft, b);
		xuat_gio_hang_kh(a->pRight, b);

	}
}


int voi(int a,int  b)
{
	if (a == 1)
	{
		return a + b;
	}
	return b;
}
int main()
{
	Admin ad;
	//HoaDon a;
	//DS_HOA_DON b;
	//DS_Hang_Hoa c;
	//
	//load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	//load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	//load_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	//load_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	load_file_thong_tin_khach_hang(ad.quan_li_ds_kh);
	//load_file_don_mua_kh(ad.quan_li_ds_kh.t);
	//load_file_gio_hang(ad.quan_li_ds_kh.t);
	//xuat_hoa_don_mua_khach_hang(ad.quan_li_ds_kh.t, ad.quan_li_ds_hang_hoa);
	//xuat_gio_hang_kh(ad.quan_li_ds_kh.t,ad.quan_li_ds_kh.t->data.hh_gio_hang);
	//SetWindowSize(209, 54);
	//ShowScrollbar(0);
	//ve_khung_console();
	
	//ve_nhap_bang_hoa_don_nhap_hang(10,4,a,b,c);
	//duyet_NLR_xuat_thong_tin_KH(ad.quan_li_ds_kh.t);

	//gotoXY(0, 51);
	/*system("pause");
	return 0;*/
	// suaThongTinKh(ad.quan_li_ds_kh.t);
	string a = "DO1237";
	if( check_ma_kh(a, ad.quan_li_ds_kh.t) ==true )
	{
		cout << "alo";
	}
	
	
}