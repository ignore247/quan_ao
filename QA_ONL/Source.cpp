
#include "Xu_li_do_hoa.h"
#include "load_ghi_file.h"
#include "Menu.h"
#include <thread>




//void xuat_dm(TREE t)
//{
//	if (t != NULL)
//	{
//		for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
//		{
//			cout << k->data.ma_hoa_don << endl;
//		}
//		xuat_dm(t->pLeft);
//		xuat_dm(t->pRight);
//	}
//}
//void xuat_gio_hang1(TREE t)
//{
//	if (t != NULL)
//	{
//		cout << t->data.maKh << endl;
//			for (int i = 0; i < t->data.data_gh.hh.size(); i++)
//			{
//				xuat_tt_hh_ngan_gon(t->data.data_gh.hh.at(i));
//			}
//			
//			xuat_gio_hang1(t->pLeft);
//
//	
//			xuat_gio_hang1(t->pRight);
//
//	}
//}
//
//void ve_chu_QAOL1()
//{
//	bool ht = true;
//	while (ht == true)
//	{
//		//bk.lock();
//		for (int i = 0; i < 13; i++)
//		{
//		//if (_kbhit())
//		//{
//		//	char c = _getch();
//		//	if (c == 13)
//		//	{
//		//		system("cls");
//		//		cout << "enter";
//
//		//	}
//		//	else if (c == 27)
//		//	{
//		//		ht = false;
//		//	}
//		//}
//
//			cout << endl << endl << endl << endl << endl;
//			SetColor(i);
//			//gotoXY(0, 5);
//			cout << R"(                                                                                            ____  _   _    _     _     _        _     ____   )" << endl;
//			SetColor(i + 1);
//			cout << R"(                                                                                           / __ \| | | |  / \   | \   | |      / \   /    \  )" << endl;
//			SetColor(i + 2);
//			cout << R"(                                                                                          | |  | | | | | / _ \  | |\  | |     / _ \ |  __  | )" << endl;
//			SetColor(i + 3);
//			cout << R"(                                                                                          | |  | | | | |/ /_\ \ | | \ | |    / / \ \| |  | | )" << endl;
//			SetColor(i + 4);
//			cout << R"(                                                                                          | |__| | |_|_/ /   \ \| |  \| |   / /___\ |  --  | )" << endl;
//			SetColor(i + 5);
//			cout << R"(                                                                                           \____\_\___/_/     \_|_|   \_|  /_/     \_\____/  )" << endl << endl;;
//			SetColor(i + 6);
//			cout << R"(                                                                                                                            ____  _     _ _     (O)_     _ _____  )" << endl;
//			SetColor(i + 7);
//			cout << R"(                                                                                                                           /    \| \   | | |    | | \   | |  ___| )" << endl;
//			SetColor(i + 8);
//			cout << R"(                                                                                                                          |  __  | |\  | | |    | | |\  | | |___  )" << endl;
//			SetColor(i + 10);
//			cout << R"(                                                                                                                          | |  | | | \ | | |    | | | \ | |  ___| )" << endl;
//			SetColor(i + 11);
//			cout << R"(                                                                                                                          |  --  | |  \| | |____| | |  \| | |___  )" << endl;
//			SetColor(i + 12);
//			cout << R"(                                                                                                                           \____/|_|   \_|______|_|_|   \_|_____| )" << endl;
//			Sleep(60);
//			XoaManHinh();
//		}
//		//bk.unlock();
//	}
//}
//
//void load_trang(int vi_tri_x,int vi_tri_y, int trang)
//{
//	bool kt = true;
//	bool cl = true;
//	box(vi_tri_x, vi_tri_y, 5, 2, 11,1 , " <<");
//	box(vi_tri_x+6, vi_tri_y, 6, 2, 11, 1,"  " + to_string(trang));
//	box(vi_tri_x+13, vi_tri_y, 5, 2, 11, 1, " >>");
//	while (kt == true)
//	{
//		if (_kbhit())
//		{
//			char c = _getch();
//			if (c == -32)
//			{
//				cl = true;// đã bấm
//				c = _getch();
//				if (c == 75) // mũi tên trái
//				{
//					box(vi_tri_x, vi_tri_y, 5, 2, 11, 58, " <<");
//					Sleep(120);
//					trang--;
//					box(vi_tri_x, vi_tri_y, 5, 2, 11, 1, " <<");
//					box(vi_tri_x+6, vi_tri_y, 6, 2, 11, 1, "  " + to_string(trang));
//				}
//				else if (c == 77) // mũi tên phải 
//				{
//					box(vi_tri_x+13, vi_tri_y, 5, 2, 11, 58, " >>");
//					Sleep(120);
//					trang++;
//					box(vi_tri_x+13, vi_tri_y, 5, 2, 11, 1, " >>");
//					box(vi_tri_x+6, vi_tri_y, 6, 2, 11, 1, "  " + to_string(trang));
//
//				}
//			}
//			else if (c == 27)
//			{
//				kt = false;
//			}
//		}
//	}
//}

void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data.ten_dang_nhap << endl;
		cout << t->data.mat_khau << endl;
		NLR(t->pLeft);
		NLR(t->pRight);

	}
}


int main()
{
	Admin ad;
	load_full(ad);
	ve_khung_console();
//	xuat_sua_ds_hoa_don_ban(ad);
//	chuong_trinh(ad);
	xuat_sua_ds_hoa_don_nhap(ad);
//	khung_xac_nhan_xoa();
//	khung_chon_doi_bo_loc() = true;
	string size,luaChonNgayThang,ngay_min,ngay_max,thang;
	bool a = false;
	bool b = false;
	bool c = false;
	int y = 0;

	system("pause");
	return 0; 
}
//01
//23
 

// lên   72
// xuống 80
// trái  75
// phải  77
// enter 13

//vi_tri_y - 7,
//vi_tri_y - 4,
//vi_tri_y - 1,
//vi_tri_y + 2,
//vi_tri_y + 5,