#include "Xu_li_do_hoa.h"

#include "load_ghi_file.h"

int main()
{
	//bang_size_ao();
	Admin ad;
	load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	//ghi_file_ao(ad.quan_li_ds_hang_hoa);
	//ghi_file_quan(ad.quan_li_ds_hang_hoa);
	sua_hang_hoa(ad.quan_li_ds_hang_hoa);
	xuat_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	xuat_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	//menu_gio_hang();
	system("pause");
	return 0;
}
