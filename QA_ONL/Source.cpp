﻿#include "Xu_li_do_hoa.h"
#include "load_ghi_file.h"
#include <thread>
#include <mutex>

mutex bk;

void xuat_gio_hang1(TREE t)
{
	if (t != NULL)
	{
		cout << t->data.maKh << endl;
		for (int i = 0; i < t->data.data_gh.hh.size(); i++)
		{
			xuat_tt_hh_ngan_gon(t->data.data_gh.hh.at(i));
		}

		xuat_gio_hang1(t->pLeft);


		xuat_gio_hang1(t->pRight);

	}
}
void ve_chu_QAOL(int x, int y)
{
	while (true)
	{

		//	bk.lock();
		for (int i = 0; i < 13; i++)
		{
			SetColor(i);
			gotoXY(x, y);
			cout << R"(  ____  _   _    _     _     _        _     ____              )" << endl;
			SetColor(i + 1);
			gotoXY(x, y + 1);
			cout << R"( / __ \| | | |  / \   | \   | |      / \   /    \             )" << endl;
			SetColor(i + 2);
			gotoXY(x, y + 2);
			cout << R"(| |  | | | | | / _ \  | |\  | |     / _ \ |  __  |            )" << endl;
			SetColor(i + 3);
			gotoXY(x, y + 3);
			cout << R"(| |  | | | | |/ /_\ \ | | \ | |    / / \ \| |  | |            )" << endl;
			SetColor(i + 4);
			gotoXY(x, y + 4);
			cout << R"(| |__| | |_|_/ /   \ \| |  \| |   / /___\ |  --  |            )" << endl;
			SetColor(i + 5);
			gotoXY(x, y + 5);
			cout << R"( \____\_\___/_/     \_|_|   \_|  /_/     \_\____/             )" << endl;
			SetColor(i + 6);
			gotoXY(x + 33, y + 7);
			cout << R"(  ____  _     _ _     (O)_     _ _____                    )" << endl;
			SetColor(i + 7);
			gotoXY(x + 33, y + 8);
			cout << R"( /    \| \   | | |    | | \   | |  ___|                   )" << endl;
			SetColor(i + 8);
			gotoXY(x + 33, y + 9);
			cout << R"(|  __  | |\  | | |    | | |\  | | |___                    )" << endl;
			SetColor(i + 9);
			gotoXY(x + 33, y + 10);
			cout << R"(| |  | | | \ | | |    | | | \ | |  ___|                   )" << endl;
			SetColor(i + 10);
			gotoXY(x + 33, y + 11);
			cout << R"(|  --  | |  \| | |____| | |  \| | |___                    )" << endl;
			SetColor(i + 11);
			gotoXY(x + 33, y + 12);
			cout << R"( \____/|_|   \_|______|_|_|   \_|_____|                   )" << endl;
			Sleep(60);
			XoaManHinh();
		}
		//	bk.unlock();
	}
}

void NLR(TREE t)
{
	if (t != NULL)
	{

		for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
		{

			xuatHoaDonBanHang(k->data);
		}
		NLR(t->pLeft);
		NLR(t->pRight);

	}
}

int main()
{

	Admin ad;
	HoaDon a;
	DS_HOA_DON b;
	DS_Hang_Hoa c;
	//
	//load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	//load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	//load_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	//load_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	//load_file_thong_tin_khach_hang(ad.quan_li_ds_kh);
	//load_file_don_mua_kh(ad.quan_li_ds_kh.t);
	//load_file_gio_hang(ad.quan_li_ds_kh.t);
	//xuat_hoa_don_mua_khach_hang(ad.quan_li_ds_kh.t, ad.quan_li_ds_hang_hoa);
	//xuat_gio_hang_kh(ad.quan_li_ds_kh.t,ad.quan_li_ds_kh.t->data.hh_gio_hang);
	//SetWindowSize(209, 54);
	//ShowScrollbar(0);
	//thread th1(dang_nhap);
	//thread th2(ve_chu_QAOL,90,5);
	//ve_chu_QAOL(90, 5);
	//ve_khung_console();
	//th1.join();
	//th2.join();

	//ve_nhap_bang_hoa_don_nhap_hang(85,4,a,b,c);
	/*xuat_hoa_don_nhap_hang(60,2,a);
	xuat_hoa_don_nhap_hang(130,2,a);
	xuat_hoa_don_nhap_hang(60,2  + 17,a);*/
	//xuat_hoa_don_nhap_hang(130,2 + 17,a);
	/*int hang = 0;
	int cot = 0;
	int tt = 0;
	for (int i = hang; i < 1; i++)
	{
		for (int j = cot; j < 1; j++)
		{
			xuat_hoa_don_nhap_hang(60*cot +10 , 2+ (hang*17), a);
		}
	}*/
	//dang_nhap();
	//gotoXY(0,54);
	/*for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
	{

		xuatHoaDonBanHang(k->data);

	}*/
	//ghi_don_mua_cua_dskh(ad.quan_li_ds_kh.t);
	//ghi_file_quan(ad.quan_li_ds_hang_hoa);
	//ghi_file_ao(ad.quan_li_ds_hang_hoa);
	//ghi_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	//ghi_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	//ghi_thong_tin_kh(ad.quan_li_ds_kh);
	//ghi_gio_hang_cua_dskh(ad.quan_li_ds_kh.t);


	system("pause");
	return 0;
}