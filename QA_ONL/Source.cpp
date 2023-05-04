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
		for (node_gio_hang* k = a->data.hh_gio_hang.pHead; k != NULL; k = k->pNext)
		{
			XuatGioHang(b, k->data.data);

		}
		xuat_gio_hang_kh(a->pLeft, b);
		xuat_gio_hang_kh(a->pRight, b);

	}
}
int main()
{
	Admin ad;
	KhachHang kh;
	load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	load_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	load_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	load_file_thong_tin_khach_hang(ad.quan_li_ds_kh);
	//load_file_don_mua_kh(ad.quan_li_ds_kh.t);
	load_file_gio_hang(ad.quan_li_ds_kh.t);
	//xuat_hoa_don_mua_khach_hang(ad.quan_li_ds_kh.t, ad.quan_li_ds_hang_hoa);
	//xuat_gio_hang_kh(ad.quan_li_ds_kh.t,ad.quan_li_ds_hang_hoa);
	//for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
	//{
	//	xuatHoaDonBanHang(k->data, ad.quan_li_ds_hang_hoa);
	//}






	return 0;
}