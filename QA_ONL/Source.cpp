#include "Xu_li_do_hoa.h"
#include <string>
#include "load_ghi_file.h"
//#include <string>
void menu_gio_hang() {
	ShowCur(0);
	khung_chu_gio_hang(50, 5, 20, 2, 11, 1, "GIO HANG");
	/*int x = 45; int y = 15;
	int w = 30; int h = 2;
	int mau_khung = 11;
	int mau_chu = 1;
	int mau_khung_sang = 75;*/
	gio_hang a;
	n_khung_hang_hoa_trong_gio(45, 15, 30, 2, 11, 1, a);
	thanh_sang(45, 15, 30, 2, 75, a);
	textcolor(11);
	gotoXY(25, 12); cout << "Dung mui ten len va xuong den di chuyen, nhan Enter de chon xem hang.";
	// ============= di chuyen thanh sang =============
	di_chuyen_thanh_sang(45, 15, 30, 2, 11, a);
}

int main()
{
	//bang_size_ao();
	
	Admin ad;
	//load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	//load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	//ghi_file_ao(ad.quan_li_ds_hang_hoa);
	//ghi_file_quan(ad.quan_li_ds_hang_hoa);
	//sua_hang_hoa(ad.quan_li_ds_hang_hoa);
	//xoa_hang_hoa(ad.quan_li_ds_hang_hoa);
	//xuat_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	//xuat_thong_tin_quan(ad.quan_li_ds_hang_hoa);

	//============================
	/*SetWindowSize(209, 54);
	TREE t;
	string ma_kh = "BA1236";
	xuat_gio_hang(ad.quan_li_ds_kh.t, ma_kh);
	khung_gio_hang(30, 5, 30, 2, 11, 3, 3 ,t);*/
	//==================
	//menuAdmin(ad);
	//menuKH(a);

	//===========
	/*ds_khach_hang a;
	string ma_kh = "DO1237";
	load_file_thong_tin_khach_hang(ad.quan_li_ds_kh);
	hien_thi_thong_tin_ca_nhan(ad.quan_li_ds_kh.t,ma_kh);*/
	system("pause");
	return 0;
}
