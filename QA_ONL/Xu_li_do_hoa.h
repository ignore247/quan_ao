#pragma once
#include "Do_Hoa.h"
#include "chuong_trinh.h"
#include <mutex>

mutex bk;

void ve_khung_console()
{
	SetColor(11);
	// ============= ngang ========
	for (int i = 0; i < 209; i++)
	{
		if (i == 0)
		{
			gotoXY(i, 0);
			cout << char(221);
			continue;
		}
		gotoXY(i, 0);
		cout << char(219);
	}
	for (int i = 0; i < 209; i++)
	{
		gotoXY(i, 54);
		cout << char(219);
	}
	// =========== dọc =============
	for (int i = 0; i < 54; i++)
	{
		gotoXY(0, i);
		cout << char(219);
		gotoXY(1, i);
		cout << char(219);
	}
	for (int i = 0; i < 54; i++)
	{
		gotoXY(209, i);
		cout << char(219);
		gotoXY(207, i);
		cout << char(219);
	}
	SetColor(7);
	gotoXY(13, 2);
	cout << "Su dung bon phim "<< char(30) << " " << char(31) << " " << char(16) << " " << char(17);
	gotoXY(18, 3);
	cout << "de dieu khien";
	gotoXY(13, 4);
	cout << "Enter: Chon    ESC: Huy";
	SetColor(11);
	for (int i = 0; i < 54; i++)
	{
		gotoXY(48, i);
		cout << char(219);
		gotoXY(49, i);
		cout << char(219);
	}
	for (int i = 0; i < 49; i++)
	{
		gotoXY(i, 6);
		cout << char(219);
	}
}

void box(int x, int y, int w, int h, int t_color, int b_color,int mau_chu, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(mau_chu);
	gotoXY( x+ (w - nd.length())/2, y + h / 2);
	cout << nd;

	//============= ve vien =============
	textcolor(1);
	SetColor(t_color);//update
	if (h <= 1 || w <= 1)return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);


}

void bang_size_ao()
{
	SetColor(11);
	gotoXY(12, 1);
	for (int i = 0; i < 34; i++)
	{
		if (i == 0)
		{
			cout << char(218);
			continue;
		}
		if (i == 15 || i == 21 || i == 27)
		{
			cout << char(194);
			continue;
		}
		if (i == 33)
		{
			cout << char(191);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	gotoXY(12, 2);
	cout << char(179) << "     Size     " << char(179) << "  S  " << char(179) << "  M  " << char(179) << "  L  " << char(179);
	cout << endl;
	gotoXY(12, 3);
	for (int i = 0; i < 33; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 14 || i == 20 || i == 26)
		{
			cout << char(197);
			continue;
		}
		if (i == 32)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	gotoXY(12, 4);
	cout << char(179) << " Chieu dai ao " << char(179) << " 61  " << char(179) << " 71  " << char(179) << " 76  " << char(179);
	cout << endl;
	gotoXY(12, 5);
	for (int i = 0; i < 33; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 14 || i == 20 || i == 26)
		{
			cout << char(197);
			continue;
		}
		if (i == 32)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	gotoXY(12, 6);
	cout << char(179) << "     Vai      " << char(179) << " 55  " << char(179) << " 57  " << char(179) << " 60  " << char(179);
	cout << endl;
	gotoXY(12, 7);
	for (int i = 0; i < 33; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 14 || i == 20 || i == 26)
		{
			cout << char(197);
			continue;
		}
		if (i == 32)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	gotoXY(12, 8);
	cout << char(179) << "  Chieu rong  " << char(179) << " 48  " << char(179) << " 50  " << char(179) << " 52  " << char(179);
	cout << endl;
	gotoXY(12, 9);
	for (int i = 0; i < 34; i++)
	{
		if (i == 0)
		{
			cout << char(192);
			continue;
		}
		if (i == 15 || i == 21 || i == 27)
		{
			cout << char(193);
			continue;
		}
		if (i == 33)
		{
			cout << char(217);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
}

void bang_size_quan()
{
	SetColor(11);
	for (int i = 0; i < 79; i++)
	{
		if (i == 0)
		{
			cout << char(218);
			continue;
		}
		if (i == 15 || i == 22 || i == 29 || i == 36 || i == 43 || i == 50 || i == 57 || i == 64 || i == 71)
		{
			cout << char(194);
			continue;
		}
		if (i == 78)
		{
			cout << char(191);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	cout << char(179) << "     Size     " << char(179) << "  28  " << char(179) << "  29  " << char(179) << "  30  " << char(179)
		<< "  31  " << char(179) << "  32  " << char(179) << "  33  " << char(179)
		<< "  34  " << char(179) << "  35  " << char(179) << "  36  " << char(179);
	cout << endl;
	for (int i = 0; i < 79; i++)
	{
		if (i == 0)
		{
			cout << char(195);
			continue;
		}
		if (i == 15 || i == 22 || i == 29 || i == 36 || i == 43 || i == 50 || i == 57 || i == 64 || i == 71)
		{
			cout << char(197);
			continue;
		}
		if (i == 78)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	cout << char(179) << "   Dai quan   " << char(179) << "  94  " << char(179) << "  95  " << char(179) << "  96  " << char(179)
		<< "  97  " << char(179) << "  98  " << char(179) << "  99  " << char(179)
		<< " 100  " << char(179) << " 102  " << char(179) << " 105  " << char(179);
	cout << endl;
	for (int i = 0; i < 78; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 14 || i == 21 || i == 28 || i == 35 || i == 42 || i == 49 || i == 56 || i == 63 || i == 70)
		{
			cout << char(197);
			continue;
		}
		if (i == 77)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	cout << char(179) << "   Vong bung  " << char(179) << "  74  " << char(179) << "  76  " << char(179) << "  78  " << char(179)
		<< "  80  " << char(179) << "  84  " << char(179) << "  88  " << char(179)
		<< "  90  " << char(179) << "  92  " << char(179) << "  95  " << char(179);
	cout << endl;
	for (int i = 0; i < 78; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 14 || i == 21 || i == 28 || i == 35 || i == 42 || i == 49 || i == 56 || i == 63 || i == 70)
		{
			cout << char(197);
			continue;
		}
		if (i == 77)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	cout << char(179) << "   Rong ong   " << char(179) << "  16  " << char(179) << " 16,5 " << char(179) << "  17  "
		<< char(179) << " 17,5 " << char(179) << "  18  " << char(179) << " 18,5 "
		<< char(179) << " 18,5 " << char(179) << " 19,5 " << char(179) << " 21,5 " << char(179);
	cout << endl;
	for (int i = 0; i < 78; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 14 || i == 21 || i == 28 || i == 35 || i == 42 || i == 49 || i == 56 || i == 63 || i == 70)
		{
			cout << char(197);
			continue;
		}
		if (i == 77)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	cout << endl;
	cout << char(179) << "   Vong dui   " << char(179) << "  24  " << char(179) << "  25  " << char(179) << "  26  "
		<< char(179) << "  26  " << char(179) << "  26  " << char(179) << "  27  "
		<< char(179) << "  29  " << char(179) << "  30  " << char(179) << "  32  " << char(179);
	cout << endl;
	for (int i = 0; i < 79; i++)
	{
		if (i == 0)
		{
			cout << char(192);
			continue;
		}
		if (i == 15 || i == 22 || i == 29 || i == 36 || i == 43 || i == 50 || i == 57 || i == 64 || i == 71)
		{
			cout << char(193);
			continue;
		}
		if (i == 78)
		{
			cout << char(217);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);

}

void nhap_us_pass(string &username, string &password)
{
	
	bool cl = true;
	gotoXY(121 + username.length(), 38);
	while (true)
	{
		if (_kbhit())
		{
			char c = _getch();
			cl = true;// đã bấm
			if (c == 13)
			{
				break;
			}
			else if (c == 32)
			{
				continue;
			}
			else if (c == 8)
			{
				if (username == "\0")
				{
					continue;
				}
				gotoXY(120 + username.length(), 38);
				cout << " ";
				username.pop_back();
				gotoXY(121, 38);
				cout << username;
			}
			else
			{
				gotoXY(121 + username.length(), 38);
				cout << c;
				username.push_back(c);
			}
		}
	}

	while (true)
	{
		if (_kbhit())
		{
			char c = _getch();
			cl = true;// đã bấm
			if (c == 13)
			{
				break;
			}
			else if (c == 32)
			{
				continue;
			}
			else if (c == 8)
			{
				if (password == "\0")
				{
					continue;
				}
				gotoXY(120 + password.length(), 40);
				cout << " ";
				password.pop_back();
				gotoXY(121, 40);
				for (int i = 0; i < password.length(); i++)
				{
					cout << "*";
				} 

			}
			else
			{
				gotoXY(121 + password.length(), 40);
				cout << "*";
				password.push_back(c);
			}
		}
	}
}

bool nhap_us_pass_v2(string& username, string& password)
{
	bool cl = true;
	int vi_tri_x = 121;
	int vi_tri_y = 38;
	// 38 user
	// 40 pass
	SetColor(7);
	gotoXY(121, 38);

	while (true)
	{
		if (_kbhit())
		{
			char c = _getch();
			cl = true;// đã bấm
			//================ Xử lí 4 phím mũi tên ==============
			if (c == -32)
			{
				cl = true;// đã bấm
				c = _getch();
				//================ Xử lí lên xuống ===================
				if (c == 80) // xuống
					{
						if (vi_tri_y == 38) // đnag ở user name
						{
							vi_tri_x = 121 + password.length();
							vi_tri_y = 40;
							gotoXY(vi_tri_x, vi_tri_y);
							continue;
						}
						else if (vi_tri_y == 40) // đang ở pass
						{
							vi_tri_x = 118;
							vi_tri_y = 44;
							box(118, 44, 14, 2, 11, 70,7, "  Dang nhap");
							SetColor(7);
							continue;
						}
						else if (vi_tri_y == 44 && vi_tri_x == 118)
						{
							vi_tri_x = 138;
							box(118, 44, 14, 2, 11, 3,7, "  Dang nhap");
							box(138, 44, 14, 2, 11, 70,7, "    Thoat");
							SetColor(7);
							continue;
						}
					}
				else if (c == 72) // lên
					{
						if (vi_tri_y == 44 && vi_tri_x == 138)
						{
							vi_tri_x = 118;
							box(138, 44, 14, 2, 11, 3,7, "    Thoat");
							box(118, 44, 14, 2, 11, 70,7, "  Dang nhap");
							SetColor(7);
							continue;
						}
						else if (vi_tri_y == 44 && vi_tri_x == 118)
						{
							vi_tri_x = 121 + password.length();
							vi_tri_y = 40;
							box(138, 44, 14, 2, 11, 3,7, "    Thoat");
							box(118, 44, 14, 2, 11, 3,7, "  Dang nhap");
							gotoXY(vi_tri_x, vi_tri_y);
							SetColor(7);
							continue;
						}
						else if(vi_tri_y == 40) // đang ở passwword
						{
							vi_tri_x = 121 + username.length();
							vi_tri_y = 38;
							gotoXY(vi_tri_x, vi_tri_y);
							continue;
						}
					}
				//================ Xử lí qua trái qua phải ===========
				else if (c == 75) // qua trái
				{
					if (vi_tri_y == 44 && vi_tri_x == 138)
						{
							vi_tri_x = 118;
							box(138, 44, 14, 2, 11, 3,7, "    Thoat");
							box(118, 44, 14, 2, 11, 70,7, "  Dang nhap");
							continue;
						}
					else if (vi_tri_y == 44 && vi_tri_x == 118)
						{
							vi_tri_x = 121 + password.length();
							vi_tri_y = 40;
							box(138, 44, 14, 2, 11, 3,7, "    Thoat");
							box(118, 44, 14, 2, 11, 3,7, "  Dang nhap");
							gotoXY(vi_tri_x, vi_tri_y);
							continue;
						}
					else if (vi_tri_y == 40) // đang ở password
					{
						if (vi_tri_x == 121)
						{
							vi_tri_x = 121 + username.length();
							vi_tri_y = 38;
							gotoXY(vi_tri_x, vi_tri_y);
							continue;
						}
						gotoXY(--vi_tri_x , vi_tri_y);
						continue;
					}
					else if (vi_tri_y == 38) // đang ở username
						{
							if (vi_tri_x == 121)
							{
								continue;
							}
							gotoXY(--vi_tri_x, vi_tri_y);
							continue;
						}
				}
				else if (c == 77) // qua phải
					{
						if (vi_tri_y == 44 && vi_tri_x == 118)
						{
							vi_tri_x = 138;
							box(118, 44, 14, 2, 11, 3,7, "  Dang nhap");
							box(138, 44, 14, 2, 11, 70,7, "    Thoat");
							continue;
						}
						else if (vi_tri_y == 40) // đang ở password
						{
							if (vi_tri_x == 121 + password.length())
							{
								vi_tri_x = 118;
								vi_tri_y = 44;
								box(118, 44, 14, 2, 11, 70,7, "  Dang nhap");
								continue;
							}
							gotoXY(++vi_tri_x, vi_tri_y);
							continue;
						}
						else if (vi_tri_y == 38) // đang ở username
						{
							if (vi_tri_x == 121 + username.length())
							{
								vi_tri_x = 121 + password.length();
								vi_tri_y = 40;
								gotoXY(vi_tri_x, vi_tri_y);
								continue;
							}
							gotoXY(++vi_tri_x, vi_tri_y);
							continue;
						}
					}	
			}
			//================ Xử lí nhập ========================
			else
			{
				if (c == 32) // nút cách
				{
					continue;
				}
				else if (c == 8) // xóa 
				{
					if (vi_tri_y == 38) // con trỏ đang ở username
					{
						if (username == "\0" || vi_tri_x == 121)
						{
							continue;
						}
						int vi_tri_xoa = vi_tri_x - 121 - 1;// vị trí xóa là vị trí con trỏ  -1 
						username.erase(vi_tri_xoa,1);
						vi_tri_x = 121 + vi_tri_xoa;	// cập nhật lại con trỏ
						gotoXY(121, 38);
						for (int i = 0; i < username.length()+1; i++)
						{
							cout << " ";
						}
						gotoXY(121, 38);
						cout << username;
						gotoXY(vi_tri_x, 38); // đưa con trỏ về chỗ vừa xóa
						continue;
					}
					else if (vi_tri_y == 40) // con trỏ đang ở pass
					{
						if (password == "\0" || vi_tri_x == 121)
						{
							continue;
						}
						int vi_tri_xoa = vi_tri_x - 121 - 1;
						password.erase(vi_tri_xoa, 1);
						vi_tri_x = 121 + vi_tri_xoa; // cập nhật lại con trỏ
						gotoXY(121, 40);
						for (int i = 0; i < password.length() + 1; i++)
						{
							cout << " ";
						}
						gotoXY(121, 40);
						for (int i = 0; i < password.length(); i++)
						{
							cout << "*";
						}
						gotoXY(vi_tri_x, 40);// đưa con trỏ về chỗ vừa xóa
						continue;
					}
				}
				else if (c == 13) // nhấn enter
				{
					if (vi_tri_y == 44 && vi_tri_x == 118) // enter ở đăng nhập
					{
						return true;
					}
					else if (vi_tri_y == 44 && vi_tri_x == 138) // enter ở thoát
					{
						return false;
					}
					else if (vi_tri_y == 38) // đang ở user name
					{
						vi_tri_x = 121 + password.length();
						vi_tri_y = 40;
						gotoXY(vi_tri_x, vi_tri_y);
						continue;
					}
					else if (vi_tri_y == 40) // đang ở pass
					{
						vi_tri_x = 118;
						vi_tri_y = 44;
						box(118, 44, 14, 2, 11, 70, 7,"  Dang nhap");
						continue;
					}
				}
				else // thêm 
				{
					if (vi_tri_y == 38)
					{
						int vi_tri_them = vi_tri_x - 121; // vị trí thêm là vị trí con trỏ 
						gotoXY(vi_tri_x, 38);
						username.insert(username.begin() + vi_tri_them, c);
						vi_tri_x = 121 + vi_tri_them +1;		// cập nhật lại con trỏ
						gotoXY(121, 38);
						for (int i = 0; i < username.length(); i++)
						{
							cout << " ";
						}
						gotoXY(121, 38);
						cout << username;
						gotoXY(vi_tri_x, 38); // đưa con trỏ về chỗ vừa thêm
						continue;
					}
					else if (vi_tri_y == 40)
					{
						int vi_tri_them = vi_tri_x - 121;
						gotoXY(vi_tri_x, 40);
						password.insert(password.begin() + vi_tri_them, c);
						vi_tri_x = 121 + vi_tri_them + 1;
						gotoXY(121, 40);
						for (int i = 0; i < password.length(); i++)
						{
							cout << "*";
						}
						gotoXY(vi_tri_x, 40);
						continue;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
}

//========================================
string username;
string password;

//void dang_nhap(TREE t)
//{
//
//	bk.lock();
//	SetColor(11);
//	gotoXY(110, 38);
//	cout << " Username ";
//	gotoXY(110, 40);
//	cout << " Password ";
//	gotoXY(110, 40);
//	box(120, 37, 30, 2, 11, 3,7, username);
//	box(120, 39, 30, 2, 11, 3,7, password);
//	gotoXY(120, 39); cout << char(195);
//	gotoXY(120 + 30, 39); cout << char(180);
//	//_getch();
//
//	box(118, 44, 14, 2, 11, 3,7, "Dang nhap");
//	box(138, 44, 14, 2, 11, 3,7, "Thoat");
//	//_getch();
//	
//	bk.unlock();
//	if (nhap_us_pass_v2(username, password) == false)
//	{
//		return;
//	}
//	while (check_dinh_dang_tk(username) == false || password == "\0" || username == "\0" || check_tk_mk(username,password,t) == false)
//	{
//		username.clear();
//		password.clear();
//		SetColor(12);
//		gotoXY(118, 42);
//		cout << "Tai khoan hoac mat khau khung dung!";
//		box(120, 37, 30, 2, 12, 3,7, "                            ");
//		box(120, 39, 30, 2, 12, 3,7, "                            ");
//		gotoXY(120, 39); cout << char(195);
//		gotoXY(120 + 30, 39); cout << char(180);
//		box(118, 44, 14, 2, 11, 3,7, "Dang nhap");
//		nhap_us_pass_v2(username, password);
//	}
//
//	box(120, 37, 30, 2, 11, 3,7, username);
//	box(120, 39, 30, 2, 11, 3,7, password);
//	gotoXY(120, 39); cout << char(195);
//	gotoXY(120 + 30, 39); cout << char(180);
//	gotoXY(118, 42);
//	cout << "                                   ";
//	
//	box(85, 15, 90, 20, 0, 233,7, "");
//	gotoXY(98 + 22, 25);
//	textcolor(236);
//	cout << "Dang nhap thanh cong!";
//
//}
//============== Hóa đơn ===========================
void ve_nhap_bang_hoa_don_nhap_hang( HoaDon a, ds_hoa_don b, DS_Hang_Hoa c)
{
	SetColor(11);
	int vi_tri_x = 80;
	int vi_tri_y = 3;
	box(80, vi_tri_y, 79, 32, 11, 0, 11, "");

	// ================== Nội dung ================= //
	textcolor(252);
	gotoXY(vi_tri_x + 30, vi_tri_y + 1);
	cout << "HOA DON NHAP HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y + 2);
	for (int i = 0; i < 79; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 78)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 4);
	cout << "Nhap ma hang hoa (Q/A): ";
	box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 11, 1, 7,a.ma_hang_hoa);
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 8);
	cout << "Nhap ten hang hoa: ";
	box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 11, 1,7, a.thong_tin_hang.ten_hh);
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 12);
	cout << "Nhap size: ";
	box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 11, 1, 7,a.thong_tin_hang.size);
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 16);
	cout << "Nhap gia: ";
	box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 11, 1, 7,"                             ");
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 20);
	cout << "Nhap so luong mua: ";
	box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 11, 1, 7,"                             ");
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 24);
	cout << "Nhap phuong thuc thanh toan (Cod/Bank): ";
	SetColor(7);
	box(vi_tri_x + 45, vi_tri_y + 23, 30, 2, 11, 1,7, a.pptt);
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 28);
	cout << "Trang thai: ";
	box(vi_tri_x + 45, vi_tri_y + 27, 30, 2, 11, 1,7, a.trang_thai);

	SetColor(7);
	gotoXY(vi_tri_x + 46, vi_tri_y + 4);
	getline(cin, a.ma_hang_hoa);
	while (true)
	{
		if (check_Ma_Hang_Hoa(a.ma_hang_hoa) == false)
		{
			box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 12, 1,7, a.ma_hang_hoa);
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 6); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 4); getline(cin, a.ma_hang_hoa);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 11, 1,7, a.ma_hang_hoa);
			gotoXY(vi_tri_x + 50, vi_tri_y + 6); cout << "                   ";
			SetColor(7);
			break;
		}

	}
	a.ma_hang_hoa[0] = toupper(a.ma_hang_hoa[0]);
	gotoXY(vi_tri_x + 46, vi_tri_y + 8);
	getline(cin, a.thong_tin_hang.ten_hh);
	chuanHoa(a.thong_tin_hang.ten_hh);
	while (true)
	{
		if (check_Ten(a.thong_tin_hang.ten_hh) == false)
		{
			box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 12, 1,7, a.thong_tin_hang.ten_hh);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 10); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 8);
			getline(cin, a.thong_tin_hang.ten_hh);
			chuanHoa(a.thong_tin_hang.ten_hh);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 11, 1,7, a.thong_tin_hang.ten_hh);
			gotoXY(vi_tri_x + 50, vi_tri_y + 10); cout << "                    ";
			SetColor(7);
			break;
		}
	}

	gotoXY(vi_tri_x + 46, vi_tri_y + 12);
	getline(cin, a.thong_tin_hang.size);
	if (a.ma_hang_hoa[0] == 'A')
	{
		while (true)
		{
			if (check_size_ao(a.thong_tin_hang.size) == false)
			{
				box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 12, 1,7, a.thong_tin_hang.size);
				SetColor(12);
				gotoXY(vi_tri_x + 50, vi_tri_y + 10); cout << "Nhap khong hop le!";
				box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 12, 1,7, "                            ");
				SetColor(7);
				gotoXY(vi_tri_x + 46, vi_tri_y + 12);
				getline(cin, a.thong_tin_hang.size);
			}
			else
			{
				box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 11, 1,7, a.thong_tin_hang.size);
				gotoXY(vi_tri_x + 50, vi_tri_y + 14); cout << "                    ";
				SetColor(7);
				break;
			}
		}
	}
	else if (a.ma_hang_hoa[0] == 'Q')
	{
		while (true)
		{

			if (check_size_quan(a.thong_tin_hang.size) == false)
			{
				box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 12, 1,7, a.thong_tin_hang.size);
				SetColor(12);
				gotoXY(vi_tri_x + 50, vi_tri_y + 14); cout << "Nhap khong hop le!";
				box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 12, 1,7, "                            ");
				SetColor(7);
				gotoXY(vi_tri_x + 46, vi_tri_y + 12);
				getline(cin, a.thong_tin_hang.size);
			}
			else
			{
				box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 11, 1,7, a.thong_tin_hang.size);
				gotoXY(vi_tri_x + 50, vi_tri_y + 14); cout << "                    ";
				SetColor(7);
				break;
			}


		}

	}
	string tam;
	gotoXY(vi_tri_x + 46, vi_tri_y + 16);
	getline(cin, tam);
	while (true)
	{
		if (check_So(tam) == false || tam == "0")
		{
			box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 12, 1,7, "                            ");
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 18); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 16); getline(cin, tam);
		}
		else
		{
			a.thong_tin_hang.gia = stoll(tam);
			box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 11, 1,7, to_string(a.thong_tin_hang.gia));
			gotoXY(vi_tri_x + 50, vi_tri_y + 18); cout << "                    ";
			SetColor(7);
			break;
		}
	}

	string tam1;
	gotoXY(vi_tri_x + 46, vi_tri_y + 20);
	getline(cin, tam1);
	while (true)
	{
		if (check_So(tam1) == false || tam1 == "0")
		{
			box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 12, 1,7, "                            ");
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 22); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 20); getline(cin, tam1);
		}
		else
		{
			a.sl_mua = stoi(tam1);
			box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 11, 1,7, to_string(a.sl_mua));
			gotoXY(vi_tri_x + 50, vi_tri_y + 22); cout << "                    ";
			SetColor(7);
			break;
		}
	}


	gotoXY(vi_tri_x + 46, vi_tri_y + 24);
	getline(cin, a.pptt);
	chuanHoa(a.pptt);
	while (true)
	{
		if (check_PTTT(a.pptt) == false)
		{
			box(vi_tri_x + 45, vi_tri_y + 23, 30, 2, 12, 1,7, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 26); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 23, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 24); getline(cin, a.pptt);
			chuanHoa(a.pptt);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 23, 30, 2, 11, 1,7, a.pptt);
			gotoXY(vi_tri_x + 50, vi_tri_y + 26); cout << "                    ";
			SetColor(7);
			break;

		}

	}
	gotoXY(vi_tri_x + 46, vi_tri_y + 28);
	getline(cin, a.trang_thai);
	chuanHoa(a.trang_thai);
	while (true)
	{
		if (check_trang_thai(a.trang_thai) == false)
		{
			box(vi_tri_x + 45, vi_tri_y + 27, 30, 2, 12, 1,7, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 30); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 27, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 28); getline(cin, a.trang_thai);
			chuanHoa(a.trang_thai);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 27, 30, 2, 11, 1,7, a.trang_thai);
			gotoXY(vi_tri_x +50, vi_tri_y + 30); cout << "                    ";
			SetColor(7);
			break;
		}
	}

	Sleep(300);
	box(80, 12, 79, 16, 0, 238, 13, "Them Thanh Cong!");
	Sleep(300);
	box(80, 3, 80, 33, 0, 0, 11, "");
}

void ve_nhap_hoa_don_ban_hang(HoaDon a, ds_hoa_don b, DS_Hang_Hoa c, ds_khach_hang d)
{
	long long tien;
	int vi_tri_y = 7;
	int vi_tri_x = 80;
	box(80, vi_tri_y, 79, 23, 11, 0, 11, "");
	// ================== Nội dung ============= //
	textcolor(252);
	gotoXY(vi_tri_x + 30, vi_tri_y + 1);
	cout << "HOA DON BAN HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y+ 2);
	for (int i = 0; i < 79; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 78)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 4);
	cout << "Nhap ma khach hang: ";
	box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 11, 1,7, a.ma_kh);
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 8);
	cout << "Nhap ma hang hoa: ";
	box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 11, 1,7, a.ma_hang_hoa);
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 12);
	cout << "Nhap so luong mua: ";
	box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 11, 1,7, "                             ");
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 16);
	cout << "Nhap phuong thuc thanh toan (Cod/Bank): ";
	box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 11, 1,7, a.pptt);
	gotoXY(vi_tri_x + 2, vi_tri_y + 20);
	SetColor(7);
	cout << "Trang thai: ";
	box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 11, 1,7, a.trang_thai);


	// ================== Nhập =========================== //
	SetColor(7);
	gotoXY(vi_tri_x + 46, vi_tri_y + 4); getline(cin,a.ma_kh);
	a.ma_kh[0] = toupper(a.ma_kh[0]);
	a.ma_kh[1] = toupper(a.ma_kh[1]);
	while (true)
	{
		if (check_ma_kh(a.ma_kh, d.t) == false)
		{

			box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 12, 1,7, a.ma_kh);
			SetColor(12);
			gotoXY(vi_tri_x + 48, vi_tri_y + 6); cout << "Khach hang khong ton tai!";
			box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 4);
			getline(cin, a.ma_kh);
			a.ma_kh[0] = toupper(a.ma_kh[0]);
			a.ma_kh[1] = toupper(a.ma_kh[1]);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 3, 30, 2, 11, 1,7, a.ma_kh);
			gotoXY(vi_tri_x + 50, vi_tri_y + 6); cout << "                    ";
			SetColor(7);
			break;
		}
	}


	gotoXY(vi_tri_x + 46, vi_tri_y + 8);
	getline(cin,a.ma_hang_hoa);
	while (true)
	{
		if (check_ma_hh(a.ma_hang_hoa, c) == -1)
		{
			box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 12, 1,7, a.ma_hang_hoa);
			SetColor(12);
			gotoXY(vi_tri_x + 49, vi_tri_y + 10); cout << "Hang hoa khong ton tai!";
			box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 8);
			getline(cin, a.ma_hang_hoa);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 7, 30, 2, 11, 1,7, a.ma_hang_hoa);
			gotoXY(vi_tri_x + 50, vi_tri_y + 10); cout << "                    ";
			SetColor(7);
			break;
		}
	}
	string tam;
	gotoXY(vi_tri_x + 46, vi_tri_y + 12);
	getline(cin, tam);
	while (true)
	{
		if (check_So(tam) == false || tam == "0")
		{
			box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 12, 1,7, "                            ");
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 14); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 12); getline(cin, tam);
		}
		else
		{
			a.sl_mua = stoi(tam);
			box(vi_tri_x + 45, vi_tri_y + 11, 30, 2, 11, 1,7, to_string(a.sl_mua));
			gotoXY(vi_tri_x + 50, vi_tri_y + 14); cout << "                    ";
			SetColor(7);
			break;
		}
	}
	gotoXY(vi_tri_x + 46, vi_tri_y + 16);
	getline(cin ,a.pptt);
	chuanHoa(a.pptt);
	while (true)
	{
		if (check_PTTT(a.pptt) == false)
		{
			box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 12, 1,7, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 18); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 16); getline(cin, a.pptt);
			chuanHoa(a.pptt);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 15, 30, 2, 11, 1,7, a.pptt);
			gotoXY(vi_tri_x + 50, vi_tri_y + 18); cout << "                    ";
			SetColor(7);
			break;

		}
	}
	gotoXY(vi_tri_x + 46, vi_tri_y + 20);
	getline(cin, a.trang_thai);
	while (true)
	{
		if (check_trang_thai(a.trang_thai) == false)
		{
			box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 12, 1,7, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, vi_tri_y + 22); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 12, 1,7, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, vi_tri_y + 20); getline(cin, a.trang_thai);
		}
		else
		{
			box(vi_tri_x + 45, vi_tri_y + 19, 30, 2, 11, 1,7, a.trang_thai);
			gotoXY(vi_tri_x + 50, vi_tri_y + 22); cout << "                    ";
			SetColor(7);
			break;
		}
	}
	if (a.ma_hang_hoa[0] == 'A')
	{
		for (int i = 0; i < c.ds_ao.size(); i++)
		{
			if (a.ma_hang_hoa == c.ds_ao.at(i).ma_hh)
			{
				tien = c.ds_ao.at(i).gia;
				a.thong_tin_hang.ten_hh = c.ds_ao.at(i).ten_hh;
				a.thong_tin_hang.gia = c.ds_ao.at(i).gia;
				a.thong_tin_hang.size = c.ds_ao.at(i).size;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < c.ds_quan.size(); i++)
		{
			if (a.ma_hang_hoa == c.ds_quan.at(i).ma_hh)
			{
				tien = c.ds_quan.at(i).gia;
				a.thong_tin_hang.ten_hh = c.ds_quan.at(i).ten_hh;
				a.thong_tin_hang.gia = c.ds_quan.at(i).gia;
				a.thong_tin_hang.size = c.ds_quan.at(i).size;
				break;
			}
		}
	}
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
	Sleep(300);
	box(80, 12, 79, 16, 0, 238, 13, "Them Thanh Cong!");
	Sleep(300);
	box(80, 3, 80, 33, 0, 0, 11, "");
}

void xuat_hoa_don_nhap_hang(int vi_tri_x, int vi_tri_y, HoaDon a)
{
	//========= Khung ============== //
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y );
	for (int i = 0; i < 60; i++)
	{
		if (i == 0)
		{
			cout << char(218);
			continue;
		}
		if (i == 59)
		{
			cout << char(191);
			continue;
		}
		cout << char(196);
	}
	for (int j = vi_tri_y + 1; j < vi_tri_y + 14; j++)
	{
		gotoXY(vi_tri_x, j);
		cout << char(179);
	}

	for (int j = vi_tri_y + 1; j < vi_tri_y + 14; j++)
	{
		gotoXY(vi_tri_x + 59, j);
		cout << char(179);
	}
	gotoXY(vi_tri_x, vi_tri_y + 14);
	for (int i = 0; i < 60; i++)
	{
		if (i == 0)
		{
			cout << char(192);
			continue;
		}
		if (i == 59)
		{
			cout << char(217);
			continue;
		}
		cout << char(196);
	}
	//=============== Nội dung =================//
	textcolor(252);
	gotoXY(vi_tri_x + 22, vi_tri_y + 1);
	cout << "HOA DON NHAP HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y + 2);
	for (int i = 0; i < 59; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 58)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 3);
	cout << "Ma hoa don:" << a.ma_hoa_don;
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y + 4);
	for (int i = 0; i < 59; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 58)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	gotoXY(vi_tri_x + 20, vi_tri_y + 4);
	cout << " Thong tin hang hoa ";
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 5);
	cout << "Ma hang hoa: " << a.thong_tin_hang.ma_hh;
	gotoXY(vi_tri_x + 2, vi_tri_y + 6);
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh;
	gotoXY(vi_tri_x + 2, vi_tri_y + 7);
	cout << "Size: " << a.thong_tin_hang.size;
	gotoXY(vi_tri_x + 2, vi_tri_y + 8);
	cout << "Gia: " << a.thong_tin_hang.gia;
	gotoXY(vi_tri_x + 2, vi_tri_y + 9);
	cout << "So luong mua: " << a.sl_mua;
	gotoXY(vi_tri_x, vi_tri_y + 10);
	SetColor(11);
	for (int i = 0; i < 59; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 58)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
	a.tong_tien = (a.thong_tin_hang.gia * a.sl_mua);
	gotoXY(vi_tri_x + 2, vi_tri_y + 11);
	cout << "Tong tien: " << a.tong_tien;
	gotoXY(vi_tri_x + 2, vi_tri_y + 12);
	cout << "Trang thai: " << a.trang_thai;
	gotoXY(vi_tri_x + 2, vi_tri_y + 13);
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd;
}

void xuat_hoa_don_ban_hang(int vi_tri_x, int vi_tri_y, HoaDon a)
{
	//========= Khung ============== //
	SetColor(11);
	gotoXY(vi_tri_x,  vi_tri_y );
	for (int i = 0; i < 60; i++)
	{
		if (i == 0)
		{
			cout << char(218);
			continue;
		}
		if (i == 59)
		{
			cout << char(191);
			continue;
		}
		cout << char(196);
	}
	for (int j = vi_tri_y + 1; j < vi_tri_y + 16; j++)
	{
		gotoXY(vi_tri_x, j);
		cout << char(179);
	}

	for (int j = vi_tri_y  + 1; j < vi_tri_y + 16; j++)
	{
		gotoXY(vi_tri_x + 59, j);
		cout << char(179);
	}
	gotoXY(vi_tri_x, vi_tri_y + 16);
	for (int i = 0; i < 60; i++)
	{
		if (i == 0)
		{
			cout << char(192);
			continue;
		}
		if (i == 59)
		{
			cout << char(217);
			continue;
		}
		cout << char(196);
	}
	//=============== Nội dung =================//
	textcolor(252);
	gotoXY(vi_tri_x + 22, vi_tri_y + 1);
	cout << "HOA DON BAN HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y + 2);
	for (int i = 0; i < 59; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 58)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 3);
	cout << "Ma hoa don: " << a.ma_hoa_don;
	gotoXY(vi_tri_x + 2, vi_tri_y + 4);
	cout << "Ma khach hang: " << a.ma_kh;
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y + 5);
	for (int i = 0; i < 59; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 58)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	gotoXY(vi_tri_x + 20, vi_tri_y + 5);
	cout << " Thong tin hang hoa ";
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 6);
	cout << "Ma hang hoa: " << a.ma_hang_hoa;
	gotoXY(vi_tri_x + 2, vi_tri_y + 7);
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh << endl;
	gotoXY(vi_tri_x + 2, vi_tri_y + 8);
	cout << "Gia: " << a.thong_tin_hang.gia << endl;
	gotoXY(vi_tri_x + 2, vi_tri_y + 9);
	cout << "Size: " << a.thong_tin_hang.size << endl;
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y + 10);
	for (int i = 0; i < 59; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 58)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y + 11);
	cout << "So luong mua: " << a.sl_mua;
	gotoXY(vi_tri_x + 2, vi_tri_y + 12);
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang;
	gotoXY(vi_tri_x + 2, vi_tri_y + 13);
	cout << "Tong tien: " << a.tong_tien;
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);
	gotoXY(vi_tri_x + 2, vi_tri_y + 14);
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd;
	gotoXY(vi_tri_x + 2, vi_tri_y + 15);
	cout << "Trang thai: " << a.trang_thai;
}

void xuat_1_trang_hd_nhap_hang(int trang_ht, vector < vector <HoaDon> > ds_tam)
{
	int tt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			xuat_hoa_don_nhap_hang(65 + (70 * j), 7 + (i * 17), ds_tam.at(trang_ht-1).at(tt));
			if (tt == ds_tam.at(trang_ht-1).size() - 1)
			{
				tt = 0;
				return;
			}
			tt++;
		}
	}
}

void xuat_ds_hoa_don_nhap(Admin ad)
{
	bool cl = true;
	int trang_ht = 1;
	int trang;
	int dem = 0;
	bool kt = true;
	if (ad.quan_li_ds_hoa_don_nhap.sl % 4 == 0)
	{
		trang = (ad.quan_li_ds_hoa_don_nhap.sl / 4);
	}
	else
	{
		trang = (ad.quan_li_ds_hoa_don_nhap.sl / 4) + 1;
	}
	vector <HoaDon> tam;
	vector < vector <HoaDon> > ds_tam;
	for (node_hoa_don* k = ad.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
	{
		dem++;
		if (trang - ds_tam.size() == 1)
		{
			if (dem > ds_tam.size() * 4)
			{
				if (k->pNext == NULL)
				{
					tam.push_back(k->data);
					ds_tam.push_back(tam);
					tam.clear();
					break;
				}
				tam.push_back(k->data);
				continue;
			}
		}
		tam.push_back(k->data);
		if (tam.size() == 4)
		{
			ds_tam.push_back(tam);
			tam.clear();
		}
	}
	
	if (trang == 1)
	{
		while (true)
		{
			xuat_1_trang_hd_nhap_hang(trang_ht, ds_tam);
			box(190, 50, 10, 2, 11, 3,7, "   Esc");
			if (_kbhit())
			{
				char c = _getch();
				
				if (c == 27)
				{
					box(190, 50, 10, 2, 11, 58,7, "   Esc");
					Sleep(120);
					break;
				}
			}
		}
		return;
	}


	xuat_1_trang_hd_nhap_hang(trang_ht, ds_tam);
	box(118, 42, 5, 2, 11, 1,11, " <<");
	box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(1));
	box(118 + 13, 42, 5, 2, 11, 1,11, " >>");
	box(190, 50, 10, 2, 11, 3,11, "   Esc");
	while (kt == true)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				cl = true;// đã bấm
				c = _getch();
				if (c == 75) // mũi tên trái
				{
					if (trang_ht == 1)
					{
						box(118, 42, 5, 2, 11, 58,7, " <<");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht = trang;
						xuat_1_trang_hd_nhap_hang(trang_ht, ds_tam);
						box(118, 42, 5, 2, 11, 1,11, " <<");
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
					}
					else
					{
						box(118, 42, 5, 2, 11, 58,11, " <<");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht--;
						xuat_1_trang_hd_nhap_hang(trang_ht, ds_tam);
						box(118, 42, 5, 2, 11, 1,11, " <<");
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
					}
				}
				else if (c == 77) // mũi tên phải 
				{
					if (trang_ht == trang)
					{
						box(118 + 13, 42, 5, 2, 11, 58,11, " >>");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht = 1;	
						xuat_1_trang_hd_nhap_hang(trang_ht, ds_tam);
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
						box(118 + 13, 42, 5, 2, 11, 1,11, " >>");
					}
					else
					{
						box(118 + 13, 42, 5, 2, 11, 58,11, " >>");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht++;	
						xuat_1_trang_hd_nhap_hang(trang_ht, ds_tam);
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
						box(118 + 13, 42, 5, 2, 11, 1,11, " >>");
					}
				}
			}
			else if (c == 27)
			{
				box(190, 50, 10, 2, 11, 58,11, "   Esc");
				Sleep(120);
				kt = false;
			}
		}
	}

}

void xuat_1_trang_hd_ban_hang(int trang_ht, vector < vector <HoaDon> > ds_tam)
{
	int tt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			xuat_hoa_don_ban_hang(60 + (70 * j), 7 + (i * 17), ds_tam.at(trang_ht - 1).at(tt));
			if (tt == ds_tam.at(trang_ht - 1).size() - 1)
			{
				tt = 0;
				return;
			}
			tt++;
		}
	}
}

void xuat_ds_hoa_don_ban(Admin ad)
{
	bool cl = true;
	int trang_ht = 1;
	int trang;
	int dem = 0;
	bool kt = true;
	if (ad.quan_li_ds_hoa_don_xuat.sl % 4 == 0)
	{
		trang = (ad.quan_li_ds_hoa_don_xuat.sl / 4);
	}
	else
	{
		trang = (ad.quan_li_ds_hoa_don_xuat.sl / 4) + 1;
	}
	vector <HoaDon> tam;
	vector < vector <HoaDon> > ds_tam;
	for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
	{
		dem++;
		if (trang - ds_tam.size() == 1)
		{
			if (dem > ds_tam.size() * 4)
			{
				if (k->pNext == NULL)
				{
					tam.push_back(k->data);
					ds_tam.push_back(tam);
					tam.clear();
					break;
				}
				tam.push_back(k->data);
				continue;
			}
		}
		tam.push_back(k->data);
		if (tam.size() == 4)
		{
			ds_tam.push_back(tam);
			tam.clear();
		}
	}

	if (trang == 1)
	{
		while (true)
		{
			xuat_1_trang_hd_ban_hang(trang, ds_tam);
			box(190, 50, 10, 2, 11, 3,11, "   Esc");
			if (_kbhit())
			{
				char c = _getch();

				if (c == 27)
				{
					box(190, 50, 10, 2, 11, 58,11, "   Esc");
					Sleep(120);
					break;
				}
			}
		}
		return;
	}


	xuat_1_trang_hd_ban_hang(trang_ht, ds_tam);
	box(118, 42, 5, 2, 11, 1,11, " <<");
	box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(1));
	box(118 + 13, 42, 5, 2, 11, 1,11, " >>");
	box(190, 50, 10, 2, 11, 3,11, "   Esc");
	while (kt == true)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				cl = true;// đã bấm
				c = _getch();
				if (c == 75) // mũi tên trái
				{
					if (trang_ht == 1)
					{
						box(118, 42, 5, 2, 11, 58,11, " <<");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht = trang;
						xuat_1_trang_hd_ban_hang(trang_ht, ds_tam);
						box(118, 42, 5, 2, 11, 1,11, " <<");
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
					}
					else
					{
						box(118, 42, 5, 2, 11, 58,11, " <<");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht--;
						xuat_1_trang_hd_ban_hang(trang_ht, ds_tam);
						box(118, 42, 5, 2, 11, 1,11, " <<");
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
					}
				}
				else if (c == 77) // mũi tên phải 
				{
					if (trang_ht == trang)
					{
						box(118 + 13, 42, 5, 2, 11, 58,11, " >>");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht = 1;
						xuat_1_trang_hd_ban_hang(trang_ht, ds_tam);
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
						box(118 + 13, 42, 5, 2, 11, 1,11, " >>");
					}
					else
					{
						box(118 + 13, 42, 5, 2, 11, 58,11, " >>");
						Sleep(200);
						box(60, 7, 129, 34, 0, 0, 7, "");
						trang_ht++;
						xuat_1_trang_hd_ban_hang(trang_ht, ds_tam);
						box(118 + 6, 42, 6, 2, 11, 1,11, "  " + to_string(trang_ht));
						box(118 + 13, 42, 5, 2, 11, 1,11, " >>");
					}
				}
			}
			else if (c == 27)
			{
				box(190, 50, 10, 2, 11, 58,11, "   Esc");
				Sleep(120);
				kt = false;
			}
		}
	}

}

bool khung_chon_tiep_tuc_sua_tt()
{
	bool cl = true;
	int vi_tri_x = 102;
	box(90, 15, 81, 21, 11, 0, 7, "");
	gotoXY(120, 22);
	SetColor(12);
	cout << "Chinh sua thanh cong!";
	box(102, 30, 20, 4, 11, 70, 10, "Tiep tuc chinh sua");
	box(140, 30, 19, 4, 11, 0, 10, "      Thoat");
	while (true)
		if (_kbhit())
		{
			char c = _getch();
			cl = true;
			if (c == -32)
			{
				cl = true;
				c = _getch();
				if (c == 77)
				{
					if (vi_tri_x == 102)
					{
						vi_tri_x = 140;
						box(102, 30, 20, 4, 11, 0, 10, "Tiep tuc chinh sua");
						box(140, 30, 19, 4, 11, 70, 10, "      Thoat");
						continue;
					}
					else if (vi_tri_x == 140)
					{
						vi_tri_x = 102;
						box(102, 30, 20, 4, 11, 70, 10, "Tiep tuc chinh sua");
						box(140, 30, 19, 4, 11, 0, 10, "      Thoat");
						continue;
					}
				}
				else if (c == 75)
				{
					if (vi_tri_x == 102)
					{
						vi_tri_x = 140;
						box(102, 30, 20, 4, 11, 0, 10, "Tiep tuc chinh sua");
						box(140, 30, 19, 4, 11, 70, 10, "      Thoat");
						continue;
					}
					else if (vi_tri_x == 140)
					{
						vi_tri_x = 102;
						box(102, 30, 20, 4, 11, 70, 10, "Tiep tuc chinh sua");
						box(140, 30, 19, 4, 11, 0, 10, "      Thoat");
						continue;
					}
				}
			}
			else if (c == 13)
			{
				if (vi_tri_x == 102)
				{
					return true;
				}
				else if (vi_tri_x == 140)
				{
					return false;
				}
			}

	}

}
 
void menu_sua_tt_hd(string b, Admin&ad)
{
	bool cl = true;
	int vi_tri_y = 1;
	if (b[0] == 'N')
	{
		box(85, 1, 50, 2, 0, 70, 11, "Sua ngay lap hoa don");
		box(85, 3, 50, 2, 0, 0, 11, "Sua trang thai cua hoa don");
		box(85, 5, 50, 2, 0, 0, 11, "Xoa hoa don");
		box(190, 50, 10, 2, 11, 3, 11, "  Thoat");

		SetColor(11);
		for (int i = 50; i < 209; i++)
		{
			gotoXY(i, 8);
			cout << char(219);
		}
		while (true)
		{
			if (_kbhit())
			{
				char c = _getch();
				cl = true;// đã bấm
				//================ Xử lí lên xuống ==============
				if (c == -32)
				{
					cl = true;// đã bấm
					c = _getch();
					if (c == 80) // xuống
					{
						if (vi_tri_y == 1)
						{
							vi_tri_y = 3;
							box(85, 1, 50, 2, 0, 0, 11, "Sua ngay lap hoa don");
							box(85, 3, 50, 2, 0, 70, 11, "Sua trang thai cua hoa don");
							continue;
						}
						else if (vi_tri_y == 3)
						{
							vi_tri_y = 5;
							box(85, 3, 50, 2, 0, 0, 11, "Sua trang thai cua hoa don");
							box(85, 5, 50, 2, 0, 70, 11, "Xoa hoa don");
							continue;
						}
						else if (vi_tri_y == 5)
						{
							vi_tri_y = 50;
							box(85, 5, 50, 2, 0, 0, 11, "Xoa hoa don");
							box(190, 50, 10, 2, 11, 70, 11, "  Thoat");
							continue;
						}
						else if (vi_tri_y == 50)
						{
							vi_tri_y = 1;
							box(190, 50, 10, 2, 11, 3, 11, "  Thoat");
							box(85, 1, 50, 2, 0, 70, 11, "Sua ngay lap hoa don");
							continue;
						}
					}
					else if (c == 72) // lên 
					{
						if (vi_tri_y == 50)
						{
							vi_tri_y = 5;
							box(190, 50, 10, 2, 11, 3, 11, "  Thoat");
							box(85, 5, 50, 2, 0, 70, 11, "Xoa hoa don");
							continue;
						}
						else if (vi_tri_y == 5)
						{
							vi_tri_y = 3;
							box(85, 3, 50, 2, 0, 70, 11, "Sua trang thai cua hoa don");
							box(85, 5, 50, 2, 0, 0, 11, "Xoa hoa don");
							continue;
						}
						else if (vi_tri_y == 3)
						{
							vi_tri_y = 1;
							box(85, 1, 50, 2, 0, 70, 11, "Sua ngay lap hoa don");
							box(85, 3, 50, 2, 0, 0, 11, "Sua trang thai cua hoa don");
							continue;
						}
						else if (vi_tri_y == 1)
						{
							vi_tri_y = 50;
							box(85, 1, 50, 2, 0, 0, 11, "Sua ngay lap hoa don");
							box(190, 50, 10, 2, 11, 70, 11, "  Thoat");
							continue;
						}
					}
				}
				//================ Xử lí enter ==================
				else if (c == 13)
				{
					if (vi_tri_y == 1)
					{
						box(90, 15, 80, 20, 11, 0, 7, "");
						string str;
						SetColor(11);
						gotoXY(92, 25);
						cout << "Nhap ngay lap hoa don: ";
						box(117, 24, 50, 2, 11, 0, 7, "");
						gotoXY(118, 25);
						SetColor(7);
						getline(cin, str);
						do
						{
							if (check_date(str) == false)
							{
								box(117, 24, 50, 2, 12, 0, 7, "                                                 ");
								gotoXY(125, 27);
								SetColor(12);
								cout << "Ngay thang nhap khong hop le!";
								SetColor(7);
								gotoXY(118, 25);
								getline(cin, str);
							}
							else
							{
								box(117, 24, 50, 2, 11, 0, 7, str);
								gotoXY(117, 25);
								cout << "                             ";
								break;
							}
						} while (true);
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
						{
							if (k->data.ma_hoa_don == b)
							{
								k->data.ngay_lap_hd = str;
								break;
							}
						}
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(90, 15, 81, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 3)
					{
						box(70, 15, 115, 20, 11, 0, 7, "");
						string str;
						SetColor(11);
						gotoXY(72, 25);
						cout << "Nhap trang thai moi cua hoa don: ";
						gotoXY(74, 26);
						cout << "(Da nhan hang | Chua nhan hang)";
						box(106, 24, 77, 2, 11, 0, 7, "");
						gotoXY(107, 25);
						SetColor(7);
						getline(cin, str);
						do
						{	
							if (check_trang_thai(str) == false)
							{
								box(106, 24, 77, 2, 12, 0, 7, "                                                                            ");
								gotoXY(109, 27);
								SetColor(12);
								cout << "Trang thai khong phu hop!";
								gotoXY(107, 25);
								SetColor(7);
								getline(cin, str);
							}
							else
							{
								box(70, 15, 115, 20, 11, 0, 7, str);
								gotoXY(109, 27);
								cout << "                          ";
								break;
							}

						} while (true);
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
						{
							if (k->data.ma_hoa_don == b)
							{
								k->data.trang_thai = str;
								break;
							}
						}
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(70, 15, 116, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 5)
					{
						xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_nhap, b);
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(70, 15, 116, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 50)
					{
						return;
					}
				}
			}
		}
	}
	else
	{
		box(85, 1, 50, 2, 0, 70, 11, "Sua ma hang hoa");
		box(85, 3, 50, 2, 0, 0, 11, "Sua ma hang khach hang");
		box(85, 5, 50, 2, 0, 0, 11, "Sua ngay lap hoa don");
		box(85, 7, 50, 2, 0, 0, 11, "Sua trang thai cua hoa don");
		box(85, 9, 50, 2, 0, 0, 11, "Xoa hoa don");
		box(190, 50, 10, 2, 11, 3, 11, "  Thoat");
		SetColor(11);
		for (int i = 50; i < 208; i++)
		{
			gotoXY(i, 12);
			cout << char(219);
		}
		while (true)
		{
			if (_kbhit())
			{
				char c = _getch();
				cl = true;// đã bấm
				//================ Xử lí lên xuống ==============
				if (c == -32)
				{
					cl = true;// đã bấm
					c = _getch();
					if (c == 80) // xuống
					{
						if (vi_tri_y == 1)
						{
							vi_tri_y = 3;
							box(85, 1, 50, 2, 0, 0, 11, "Sua ma hang hoa");
							box(85, 3, 50, 2, 0, 70, 11, "Sua ma hang khach hang");
							continue;
						}
						else if (vi_tri_y == 3)
						{
							vi_tri_y = 5;
							box(85, 3, 50, 2, 0, 0, 11, "Sua ma hang khach hang");
							box(85, 5, 50, 2, 0, 70, 11, "Sua ngay lap hoa don");
							continue;
						}
						else if (vi_tri_y == 5)
						{
							vi_tri_y = 7;
							box(85, 5, 50, 2, 0, 0, 11, "Sua ngay lap hoa don");
							box(85, 7, 50, 2, 0, 70, 11, "Sua trang thai cua hoa don");
							continue;
						}
						else if (vi_tri_y == 7)
						{
							vi_tri_y = 9;
							box(85, 7, 50, 2, 0, 0, 11, "Sua trang thai cua hoa don");
							box(85, 9, 50, 2, 0, 70, 11, "Xoa hoa don");
							continue;
						}
						else if (vi_tri_y == 9)
						{
							vi_tri_y = 50;
							box(85, 9, 50, 2, 0, 0, 11, "Xoa hoa don");
							box(190, 50, 10, 2, 11, 70, 11, "  Thoat");
							continue;
						}
						else if (vi_tri_y == 50)
						{
							vi_tri_y = 1;
							box(85, 1, 50, 2, 0, 70, 11, "Sua ma hang hoa");
							box(190, 50, 10, 2, 11, 0, 11, "  Thoat");
							continue;
						}
					}
					else if (c == 72) // lên 
					{
						if (vi_tri_y == 50)
						{
							vi_tri_y = 9;
							box(85, 9, 50, 2, 0, 70, 11, "Xoa hoa don");
							box(190, 50, 10, 2, 11, 3, 11, "  Thoat");
							continue;
						}
						else if(vi_tri_y == 9)
						{
							vi_tri_y = 7;
							box(85, 9, 50, 2, 0, 0, 11, "Xoa hoa don");
							box(85, 7, 50, 2, 0, 70, 11, "Sua trang thai cua hoa don");
							continue;
						}
						else if (vi_tri_y == 7)
						{
							vi_tri_y = 5;
							box(85, 7, 50, 2, 0, 0, 11, "Sua trang thai cua hoa don");
							box(85, 5, 50, 2, 0, 70, 11, "Sua ngay lap hoa don");
							continue;
						}
						else if (vi_tri_y == 5)
						{
							vi_tri_y = 3;
							box(85, 3, 50, 2, 0, 70, 11, "Sua ma hang Khach hang");
							box(85, 5, 50, 2, 0, 0, 11, "Sua ngay lap hoa don");
							continue;
						}
						else if (vi_tri_y == 3)
						{
							vi_tri_y = 1;
							box(85, 1, 50, 2, 0, 70, 11, "Sua ma hang hoa");
							box(85, 3, 50, 2, 0, 0, 11, "Sua ma hang Khach hang");
							continue;
						}
						else if (vi_tri_y == 1)
						{
							vi_tri_y = 50;
							box(85, 1, 50, 2, 0, 0, 11, "Sua ma hang hoa");
							box(190, 50, 10, 2, 11, 70, 11, "  Thoat");
							continue;
						}
					}
				}
				//================ Xử lí enter ==================
				else if (c == 13)
				{
					if (vi_tri_y == 1)
					{
						box(90, 15, 80, 20, 11, 0, 7, "");
						string str;
						SetColor(11);
						gotoXY(92, 25);
						cout << "Nhap ma hang hoa: ";
						box(117, 24, 50, 2, 11, 0, 7, "");
						gotoXY(118, 25);
						SetColor(7);
						getline(cin, str);
						str[0] = toupper(str[0]);
						do
						{
							if(check_full_maHH(str) == false )
							{
								box(117, 24, 50, 2, 12, 0, 7, "                                                 ");
								gotoXY(125, 27);
								SetColor(12);
								cout << "Hang hoa khong ton tai!";
								SetColor(7);
								gotoXY(118, 25);
								getline(cin, str);
								str[0] = toupper(str[0]);
							}
							else
							{
								box(117, 24, 50, 2, 11, 0, 7, str);
								gotoXY(125, 27);
								cout << "                       ";
								break;
							}
						} while (true);
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
						{

							if (k->data.ma_hoa_don == b)
							{
								long long tien = 0;
								duyet_cay_sua_thong_tin_hh(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str, ad.quan_li_ds_hang_hoa);
								k->data.ma_hang_hoa = str;
								if (str[0] == 'A')
								{
									for (int i = 0; i < ad.quan_li_ds_hang_hoa.ds_ao.size(); i++)
									{
										if (str == ad.quan_li_ds_hang_hoa.ds_ao.at(i).ma_hh)
										{
											tien = ad.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
											k->data.thong_tin_hang.ten_hh = ad.quan_li_ds_hang_hoa.ds_ao.at(i).ten_hh;
											k->data.thong_tin_hang.gia = ad.quan_li_ds_hang_hoa.ds_ao.at(i).gia;
											k->data.thong_tin_hang.size = ad.quan_li_ds_hang_hoa.ds_ao.at(i).size;
											break;
										}
									}
								}
								else
								{
									for (int i = 0; i < ad.quan_li_ds_hang_hoa.ds_quan.size(); i++)
									{
										if (k->data.ma_hang_hoa == ad.quan_li_ds_hang_hoa.ds_quan.at(i).ma_hh)
										{
											tien = ad.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
											k->data.thong_tin_hang.ten_hh = ad.quan_li_ds_hang_hoa.ds_quan.at(i).ten_hh;
											k->data.thong_tin_hang.gia = ad.quan_li_ds_hang_hoa.ds_quan.at(i).gia;
											k->data.thong_tin_hang.size = ad.quan_li_ds_hang_hoa.ds_quan.at(i).size;
											break;
										}
									}
								}
								if (k->data.ma_kh.substr(0, 2) == "DO")
								{
									k->data.tong_tien = (tien * k->data.sl_mua) * 0, 01;
									k->data.giam_gia_theo_hang = 0, 01;
								}
								else if (k->data.ma_kh.substr(0, 2) == "BA")
								{
									k->data.tong_tien = (tien * k->data.sl_mua) * 0, 03;
									k->data.giam_gia_theo_hang = 0, 03;
								}
								else if (k->data.ma_kh.substr(0, 2) == "VA")
								{
									k->data.tong_tien = (tien * k->data.sl_mua) * 0, 05;
									k->data.giam_gia_theo_hang = 0, 05;
								}
								else if (k->data.ma_kh.substr(0, 2) == "KC")
								{
									k->data.tong_tien = (tien * k->data.sl_mua) * 0, 1;
									k->data.giam_gia_theo_hang = 0, 1;
								}
								else
								{
									k->data.tong_tien = tien * k->data.sl_mua;
									k->data.giam_gia_theo_hang = 0;
								}
								break;
							}
						}
						xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(90, 15, 81, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 3)
					{
						box(90, 15, 82, 22, 11, 0, 7, "");
						string str;
						SetColor(11);
						gotoXY(92, 25);
						cout << "Nhap ma khach hang moi: ";
						box(124, 24, 46, 2, 11, 0, 7, "");
						gotoXY(125, 25);
						SetColor(7);
						getline(cin, str);
						str[0] = toupper(str[0]);
						str[1] = toupper(str[1]);
						do
						{
							if ( check_dinh_dang_ma_kh(str) == false)
							{
								box(124, 24, 46, 2, 12, 0, 7, "                                             ");
								gotoXY(125, 27);
								SetColor(12);
								cout << "Khach hang khong ton tai!";
								SetColor(7);
								gotoXY(125, 25);
								getline(cin, str);
								str[0] = toupper(str[0]);
								str[1] = toupper(str[1]);
							}
							else
							{
								box(124, 24, 46, 2, 11, 0, 7, str);
								gotoXY(125, 27);
								cout << "                         ";
								break;
							}
						} while (true);
						do
						{
							if (check_ma_kh(str,ad.quan_li_ds_kh.t) == false || check_dinh_dang_ma_kh(str) == false  )
							{
								box(124, 24, 46, 2, 12, 0, 7, "                                             ");
								gotoXY(125, 27);
								SetColor(12);
								cout << "Khach hang khong ton tai!";
								SetColor(7);
								gotoXY(125, 25);
								getline(cin, str);
								str[0] = toupper(str[0]);
								str[1] = toupper(str[1]);
							}
							else
							{
								box(124, 24, 46, 2, 11, 0, 7, str);
								gotoXY(125, 27);
								cout << "                       ";
								break;
							}
						} while (true);
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
						{
							if (k->data.ma_hoa_don == b)
							{
								duyet_cay_xoa_hd_theo_ma(ad.quan_li_ds_kh.t, k->data.ma_kh, b);
								k->data.ma_kh = str;
								duyet_cay_them_hd(ad.quan_li_ds_kh.t, str, k->data);
								break;
							}
						}
						xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(90, 15, 83, 23, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 5)
					{
						box(90, 15, 80, 20, 11, 0, 7, "");
						string str;
						SetColor(11);
						gotoXY(92, 25);
						cout << "Nhap ngay lap hoa don: ";
						box(117, 24, 50, 2, 11, 0, 7, "");
						gotoXY(118, 25);
						SetColor(7);
						getline(cin, str);
						do
						{
							if (check_date(str) == false)
							{
								box(117, 24, 50, 2, 12, 0, 7, "                                                 ");
								gotoXY(125, 27);
								SetColor(12);
								cout << "Ngay thang nhap khong hop le!";
								SetColor(7);
								gotoXY(118, 25);
								getline(cin, str);
							}
							else
							{
								box(117, 24, 50, 2, 11, 0, 7, str);
								gotoXY(117, 25);
								cout << "                             ";
								break;
							}
						} while (true);
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
						{
							if (k->data.ma_hoa_don == b)
							{
								k->data.ngay_lap_hd = str;
								duyet_cay_sua_thong_tin_nl(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
								break;
							}
						}
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(90, 15, 81, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 7)
					{
						box(90, 15, 80, 20, 11, 0, 7, "");
						string str;
						SetColor(11);
						gotoXY(92, 25);
						cout << "Nhap trang thai moi cua hoa don: ";
						gotoXY(92, 26);
						cout << "(Da nhan hang | Chua nhan hang)";
						box(127, 24, 39, 2, 11, 0, 7, "");
						gotoXY(128, 25);
						SetColor(7);
						getline(cin, str);
						chuanHoa(str);
						do
						{
							if (check_trang_thai(str) == false)
							{
								box(127, 24, 39, 2, 12, 0, 7, "                                                 ");
								gotoXY(129, 27);
								SetColor(12);
								cout << "Trang thai khong phu hop!";
								SetColor(7);
								gotoXY(128, 25);
								getline(cin, str);
								chuanHoa(str);
							}
							else
							{
								box(127, 24, 39, 2, 11, 0, 7, str);
								gotoXY(128, 25);
								cout << "                         ";
								break;
							}
						} while (true);
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
						{
							if (k->data.ma_hoa_don == b)
							{
								duyet_cay_sua_thong_tin_trang_thai(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
								k->data.trang_thai = str;
								break;
							}
						}
						xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(90, 15, 81, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 9)
					{
						for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
						{
							if (k->data.ma_hoa_don == b)
							{
								duyet_cay_xoa_hd_theo_ma(ad.quan_li_ds_kh.t, k->data.ma_kh, b);
								xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_xuat, b);
								break;
							}
						}
						xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
						if (khung_chon_tiep_tuc_sua_tt() == true)
						{
							box(90, 15, 81, 21, 0, 0, 7, "");
							gotoXY(85, vi_tri_y);
							continue;
						}
						else
						{
							return;
						}
					}
					else if (vi_tri_y == 50)
					{
						return;
					}
				}
			}
		}
	}
}

void sua_tt_hd(Admin& ad)
{
	string b, tam;
	int c;
	regex ktra_nhap(R"(\d)");
	regex ktra_dinh_dang(R"([aA-zZ]{1}\d{4})");
	bool check = true;  


	box(85, 10, 90, 20,11, 0,7, "");
	gotoXY(90, 20);
	cout << "Nhap ma hoa don muon sua: ";
	box(120, 19, 50, 2, 11, 0,7, "");
	gotoXY(121, 20);
	SetColor(7);
	getline(cin, b);
	b[0] = toupper(b[0]);
	do
	{
		if ( (check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_nhap) == -1 && check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_xuat) == -1  )|| regex_match(b, ktra_dinh_dang) == false)
		{
			box(120, 19, 50, 2, 12, 0,7, b);
			gotoXY(131, 22);
			cout << "Ma hoa don khong ton tai!";
			gotoXY(121, 20); cout << "                                                ";
			gotoXY(121, 20);
			SetColor(7);
			getline(cin, b);
			b[0] = toupper(b[0]);
		}
		else
		{
			gotoXY(133, 22);
			cout << "                         ";
			box(120, 19, 50, 2, 11, 0,7, b);
			break;
		}
	} while (true);

	box(85, 10, 90, 20, 0, 7,7, "");

	menu_sua_tt_hd(b,ad);
}

void ve_chu_QAOL(int x, int y)
{
	while (true)
	{
		for (int i = 0; i < 13; i++)
		{
			bk.lock();
			SetColor(i);
			gotoXY(x, y);
			cout << R"(  ____  _   _    _     _     _        _     ____              )" << endl;
			SetColor(i+1);
			gotoXY(x, y + 1);
			cout << R"( / __ \| | | |  / \   | \   | |      / \   /    \             )" << endl;
			SetColor(i+2);
			gotoXY(x, y + 2);
			cout << R"(| |  | | | | | / _ \  | |\  | |     / _ \ |  __  |            )" << endl;
			SetColor(i+3);
			gotoXY(x, y + 3);
			cout << R"(| |  | | | | |/ /_\ \ | | \ | |    / / \ \| |  | |            )" << endl;
			SetColor(i+4);
			gotoXY(x, y + 4);
			cout << R"(| |__| | |_|_/ /   \ \| |  \| |   / /___\ |  --  |            )" << endl;
			SetColor(i+5);
			gotoXY(x, y + 5);
			cout << R"( \____\_\___/_/     \_|_|   \_|  /_/     \_\____/             )" << endl;
			SetColor(i+6);
			gotoXY(x + 33, y + 7);
			cout << R"(  ____  _     _ _     (O)_     _ _____                    )" << endl;
			SetColor(i+7);
			gotoXY(x + 33, y + 8);
			cout << R"( /    \| \   | | |    | | \   | |  ___|                   )" << endl;
			SetColor(i+8);
			gotoXY(x + 33, y + 9);
			cout << R"(|  __  | |\  | | |    | | |\  | | |___                    )" << endl;
			SetColor(i+9);
			gotoXY(x + 33, y + 10);
			cout << R"(| |  | | | \ | | |    | | | \ | |  ___|                   )" << endl;
			SetColor(i+10);
			gotoXY(x + 33, y + 11);
			cout << R"(|  --  | |  \| | |____| | |  \| | |___                    )" << endl;
			SetColor(i+11);
			gotoXY(x + 33, y + 12);
			cout << R"( \____/|_|   \_|______|_|_|   \_|_____|                   )" << endl;
			bk.unlock();
			Sleep(60);


		}
	}
}