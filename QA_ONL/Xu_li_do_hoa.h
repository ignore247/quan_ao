#pragma once
#include "Do_Hoa.h"
#include "chuong_trinh.h"
#include "docFile.h"


void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
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

void n_box(int vi_tri_x, int y, int w, int h, int t_color, int b_color, string nd, int sl)
{
	for (int i = 0; i < sl; i++)
	{
		box(vi_tri_x + 5, y + (i * 2), 56, 2, 7, 7, nd);
	}
	for (int i = 1; i < sl; i++)
	{
		// ve goc khung
		gotoXY(vi_tri_x + 5, y + (i * 2)); cout << char(195);
		gotoXY(vi_tri_x + 61, y + (i * 2)); cout << char(180);
	}
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

void dang_nhap()
{
	string username;
	string password;
	gotoXY(40, 18);
	cout << " Username ";
	gotoXY(40, 20);
	cout << " Password ";
	box(50, 17, 30, 2, 11, 3, username);
	box(50, 19, 30, 2, 11, 3, password);
	gotoXY(50, 19); cout << char(195);
	gotoXY(50 + 30, 19); cout << char(180);
	box(50, 22, 10, 2, 11, 3, "  Enter");
	box(68, 22, 10, 2, 11, 3, "  Esc");
	gotoXY(51, 18); cin >> username;
	gotoXY(51, 20); cin >> password;
	rewind(stdin);
	while (true)
	{
		bool kt = true;
		if (_kbhit())
		{
			char c = _getch();
			if (c == 13)
			{
				system("cls");
				cout << "enter";
				system("pause");
			}
			else if (c == 27)
			{
				system("cls");
				cout << "esc";
				system("pause");

			}
		}

	}
}

void ve_nhap_bang_hoa_don_nhap_hang(int vi_tri_x, HoaDon a, ds_hoa_don b, DS_Hang_Hoa c)
{

	//========= Khung ============== //
	SetColor(11);
	gotoXY(vi_tri_x, 0);
	for (int i = 0; i < 80; i++)
	{
		if (i == 0)
		{
			cout << char(218);
			continue;
		}
		if (i == 79)
		{
			cout << char(191);
			continue;
		}
		cout << char(196);
	}
	for (int j = 1; j < 31; j++)
	{
		gotoXY(vi_tri_x, j);
		cout << char(179);
	}

	for (int j = 1; j < 31; j++)
	{
		gotoXY(vi_tri_x + 79, j);
		cout << char(179);
	}
	gotoXY(vi_tri_x, 31);
	for (int i = 0; i < 80; i++)
	{
		if (i == 0)
		{
			cout << char(192);
			continue;
		}
		if (i == 79)
		{
			cout << char(217);
			continue;
		}
		cout << char(196);
	}
	box(vi_tri_x + 5, 32, 12, 2, 11, 3, "   Enter");
	box(vi_tri_x + 60, 32, 12, 2, 11, 3, "    Esc");

	// ================== Nội dung ================= //
	textcolor(252);
	gotoXY(vi_tri_x + 30, 1);
	cout << "HOA DON NHAP HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, 2);
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
	gotoXY(vi_tri_x + 2, 4);
	cout << "Nhap ma hang hoa (Q/A): ";
	box(vi_tri_x + 45, 3, 30, 2, 11, 1, a.ma_hang_hoa);
	SetColor(7);
	gotoXY(vi_tri_x + 2, 8);
	cout << "Nhap ten hang hoa: ";
	box(vi_tri_x + 45, 7, 30, 2, 11, 1, a.thong_tin_hang.ten_hh);
	SetColor(7);
	gotoXY(vi_tri_x + 2, 12);
	cout << "Nhap size: ";
	box(vi_tri_x + 45, 11, 30, 2, 11, 1, a.thong_tin_hang.size);
	SetColor(7);
	gotoXY(vi_tri_x + 2, 16);
	cout << "Nhap gia: ";
	box(vi_tri_x + 45, 15, 30, 2, 11, 1, "                             ");
	SetColor(7);
	gotoXY(vi_tri_x + 2, 20);
	cout << "Nhap so luong mua: ";
	box(vi_tri_x + 45, 19, 30, 2, 11, 1, "                             ");
	SetColor(7);
	gotoXY(vi_tri_x + 2, 24);
	cout << "Nhap phuong thuc thanh toan (Cod/Bank): ";
	SetColor(7);
	box(vi_tri_x + 45, 23, 30, 2, 11, 1, a.pptt);
	SetColor(7);
	gotoXY(vi_tri_x + 2, 28);
	cout << "Trang thai: ";
	box(vi_tri_x + 45, 27, 30, 2, 11, 1, a.trang_thai);

	SetColor(7);
	gotoXY(vi_tri_x + 46, 4);
	cin >> a.ma_hang_hoa;
	regex check_ma("([QqAa])");
	while (true)
	{
		if (regex_match(a.ma_hang_hoa, check_ma) == false)
		{
			box(vi_tri_x + 45, 3, 30, 2, 12, 1, a.ma_hang_hoa);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 6); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 3, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 4); cin >> a.ma_hang_hoa;
		}
		else
		{
			box(vi_tri_x + 45, 3, 30, 2, 11, 1, a.ma_hang_hoa);
			gotoXY(vi_tri_x + 50, 6); cout << "                   ";
			SetColor(7);
			break;
		}

	}
	a.ma_hang_hoa[0] = toupper(a.ma_hang_hoa[0]);
	cin.ignore();
	gotoXY(vi_tri_x + 46, 8);
	getline(cin, a.thong_tin_hang.ten_hh);
	chuanHoa(a.thong_tin_hang.ten_hh);
	regex check_ten("^[^0-9]+$");
	while (true)
	{
		if (regex_match(a.thong_tin_hang.ten_hh, check_ten) == false)
		{
			box(vi_tri_x + 45, 7, 30, 2, 12, 1, a.thong_tin_hang.ten_hh);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 10); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 7, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 8);
			getline(cin, a.thong_tin_hang.ten_hh);
		}
		else
		{
			box(vi_tri_x + 45, 7, 30, 2, 11, 1, a.thong_tin_hang.ten_hh);
			gotoXY(vi_tri_x + 50, 10); cout << "                    ";
			SetColor(7);
			break;
		}
	}

	gotoXY(vi_tri_x + 46, 12);
	cin >> a.thong_tin_hang.size;
	regex check_size_ao("([SsMmLl])");
	regex check_size_quan("(26|27|28|29|30|31|32|33|34|35|36)");
	if (a.ma_hang_hoa[0] == 'A')
	{
		while (true)
		{
			if (regex_match(a.thong_tin_hang.size, check_size_ao) == false)
			{
				box(vi_tri_x + 45, 11, 30, 2, 12, 1, a.thong_tin_hang.size);
				SetColor(12);
				gotoXY(vi_tri_x + 50, 10); cout << "Nhap khong hop le!";
				box(vi_tri_x + 45, 11, 30, 2, 12, 1, "                            ");
				SetColor(7);
				gotoXY(vi_tri_x + 46, 12);
				cin >> a.thong_tin_hang.size;
			}
			else
			{
				box(vi_tri_x + 45, 11, 30, 2, 11, 1, a.thong_tin_hang.size);
				gotoXY(vi_tri_x + 50, 14); cout << "                    ";
				SetColor(7);
				break;
			}
		}
	}
	if (a.ma_hang_hoa[0] == 'Q')
	{
		while (true)
		{
			if (regex_match(a.thong_tin_hang.size, check_size_quan) == false)
			{
				box(vi_tri_x + 45, 11, 30, 2, 12, 1, a.thong_tin_hang.size);
				SetColor(12);
				gotoXY(vi_tri_x + 50, 14); cout << "Nhap khong hop le!";
				box(vi_tri_x + 45, 11, 30, 2, 12, 1, "                            ");
				SetColor(7);
				gotoXY(vi_tri_x + 46, 12);
				cin >> a.thong_tin_hang.size;
			}
			else
			{
				box(vi_tri_x + 45, 11, 30, 2, 11, 1, a.thong_tin_hang.size);
				gotoXY(vi_tri_x + 50, 14); cout << "                    ";
				SetColor(7);
				break;
			}
		}
	}

	string tam;
	gotoXY(vi_tri_x + 46, 16);
	cin >> tam;
	regex check_gia("^[0-9]+$");
	while (true)
	{
		if (regex_match(tam, check_gia) == false || tam == "0")
		{
			box(vi_tri_x + 45, 15, 30, 2, 12, 1, "                            ");
			SetColor(12);
			gotoXY(vi_tri_x + 50, 18); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 15, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 16); cin >> tam;
		}
		else
		{
			a.thong_tin_hang.gia = stoll(tam);
			box(vi_tri_x + 45, 15, 30, 2, 11, 1, to_string(a.thong_tin_hang.gia));
			gotoXY(vi_tri_x + 50, 18); cout << "                    ";
			SetColor(7);
			break;
		}
	}

	string tam1;
	gotoXY(vi_tri_x + 46, 20);
	cin >> tam1;
	while (true)
	{
		if (regex_match(tam1, check_gia) == false || tam1 == "0")
		{
			box(vi_tri_x + 45, 19, 30, 2, 12, 1, "                            ");
			SetColor(12);
			gotoXY(vi_tri_x + 50, 22); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 19, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 20); cin >> tam1;
		}
		else
		{
			a.sl_mua = stoi(tam1);
			box(vi_tri_x + 45, 19, 30, 2, 11, 1, to_string(a.sl_mua));
			gotoXY(vi_tri_x + 50, 22); cout << "                    ";
			SetColor(7);
			break;
		}
	}


	gotoXY(vi_tri_x + 46, 24);
	cin >> a.pptt;
	chuanHoa(a.pptt);
	regex check_pttt("(Cod|Bank)");
	while (true)
	{
		if (regex_match(a.pptt, check_pttt) == false)
		{
			box(vi_tri_x + 45, 23, 30, 2, 12, 1, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 26); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 23, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 24); cin >> a.pptt;
			chuanHoa(a.pptt);
		}
		else
		{
			box(vi_tri_x + 45, 23, 30, 2, 11, 1, a.pptt);
			gotoXY(vi_tri_x + 50, 26); cout << "                    ";
			SetColor(7);
			break;

		}

	}

	cin.ignore();
	gotoXY(vi_tri_x + 46, 28);
	getline(cin, a.trang_thai);
	while (true)
	{
		if (regex_match(a.trang_thai, check_ten) == false)
		{
			box(vi_tri_x + 45, 27, 30, 2, 12, 1, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 30); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 27, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 28); getline(cin, a.trang_thai);
		}
		else
		{
			box(vi_tri_x + 45, 27, 30, 2, 11, 1, a.trang_thai);
			gotoXY(vi_tri_x + 50, 30); cout << "                    ";
			SetColor(7);
			break;
		}
	}



}

void ve_nhap_hoa_don_ban_hang(int vi_tri_x, HoaDon a, ds_hoa_don b, DS_Hang_Hoa c, ds_khach_hang d)
{
	//========= Khung ============== //
	SetColor(11);
	gotoXY(vi_tri_x, 0);
	for (int i = 0; i < 80; i++)
	{
		if (i == 0)
		{
			cout << char(218);
			continue;
		}
		if (i == 79)
		{
			cout << char(191);
			continue;
		}
		cout << char(196);
	}
	for (int j = 1; j < 23; j++)
	{
		gotoXY(vi_tri_x, j);
		cout << char(179);
	}

	for (int j = 1; j < 23; j++)
	{
		gotoXY(vi_tri_x + 79, j);
		cout << char(179);
	}
	gotoXY(vi_tri_x, 23);
	for (int i = 0; i < 80; i++)
	{
		if (i == 0)
		{
			cout << char(192);
			continue;
		}
		if (i == 79)
		{
			cout << char(217);
			continue;
		}
		cout << char(196);
	}
	box(vi_tri_x + 5, 24, 12, 2, 11, 3, "   Enter");
	box(vi_tri_x + 60, 24, 12, 2, 11, 3, "    Esc");

	// ================== Nội dung ============= //
	textcolor(252);
	gotoXY(vi_tri_x + 30, 1);
	cout << "HOA DON BAN HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, 2);
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
	gotoXY(vi_tri_x + 2, 4);
	cout << "Nhap ma khach hang: ";
	box(vi_tri_x + 45, 3, 30, 2, 11, 1, a.ma_kh);
	SetColor(7);
	gotoXY(vi_tri_x + 2, 8);
	cout << "Nhap ma hang hoa: ";
	box(vi_tri_x + 45, 7, 30, 2, 11, 1, a.ma_hang_hoa);
	SetColor(7);
	gotoXY(vi_tri_x + 2, 12);
	cout << "Nhap so luong mua: ";
	box(vi_tri_x + 45, 11, 30, 2, 11, 1, "                             ");
	SetColor(7);
	gotoXY(vi_tri_x + 2, 16);
	cout << "Nhap phuong thuc thanh toan (Cod/Bank): ";
	box(vi_tri_x + 45, 15, 30, 2, 11, 1, a.pptt);
	gotoXY(vi_tri_x + 2, 20);
	SetColor(7);
	cout << "Trang thai: ";
	box(vi_tri_x + 45, 19, 30, 2, 11, 1, a.trang_thai);


	// ================== Nhập =========================== //
	SetColor(7);
	gotoXY(vi_tri_x + 46, 4); cin >> a.ma_kh;
	a.ma_kh[0] = toupper(a.ma_kh[0]);
	a.ma_kh[1] = toupper(a.ma_kh[1]);
	while (true)
	{
		if (check_ma_kh(a.ma_kh, d.t) == -1)
		{

			box(vi_tri_x + 45, 3, 30, 2, 12, 1, a.ma_kh);
			SetColor(12);
			gotoXY(vi_tri_x + 48, 6); cout << "Khach hang khong ton tai!";
			box(vi_tri_x + 45, 3, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 4);
			cin >> a.ma_kh;
			a.ma_kh[0] = toupper(a.ma_kh[0]);
			a.ma_kh[1] = toupper(a.ma_kh[1]);
		}
		else
		{
			box(vi_tri_x + 45, 3, 30, 2, 11, 1, a.ma_kh);
			gotoXY(vi_tri_x + 50, 6); cout << "                    ";
			SetColor(7);
			break;
		}
	}


	gotoXY(vi_tri_x + 46, 8);
	cin >> a.ma_hang_hoa;
	while (true)
	{
		if (check_ma_hh(a.ma_hang_hoa, c) == -1)
		{
			box(vi_tri_x + 45, 7, 30, 2, 12, 1, a.ma_hang_hoa);
			SetColor(12);
			gotoXY(vi_tri_x + 49, 10); cout << "Hang hoa khong ton tai!";
			box(vi_tri_x + 45, 7, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 8);
			cin >> a.ma_hang_hoa;
		}
		else
		{
			box(vi_tri_x + 45, 7, 30, 2, 11, 1, a.ma_hang_hoa);
			gotoXY(vi_tri_x + 50, 10); cout << "                    ";
			SetColor(7);
			break;
		}
	}
	string tam;
	gotoXY(vi_tri_x + 46, 12);
	cin >> tam;
	regex check_gia("^[0-9]+$");
	while (true)
	{
		if (regex_match(tam, check_gia) == false || tam == "0")
		{
			box(vi_tri_x + 45, 11, 30, 2, 12, 1, "                            ");
			SetColor(12);
			gotoXY(vi_tri_x + 50, 14); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 11, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 12); cin >> tam;
		}
		else
		{
			a.sl_mua = stoi(tam);
			box(vi_tri_x + 45, 11, 30, 2, 11, 1, to_string(a.sl_mua));
			gotoXY(vi_tri_x + 50, 14); cout << "                    ";
			SetColor(7);
			break;
		}
	}

	gotoXY(vi_tri_x + 46, 16);
	cin >> a.pptt;
	chuanHoa(a.pptt);
	regex check_pttt("(Cod|Bank)");
	while (true)
	{
		if (regex_match(a.pptt, check_pttt) == false)
		{
			box(vi_tri_x + 45, 15, 30, 2, 12, 1, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 18); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 15, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 16); cin >> a.pptt;
			chuanHoa(a.pptt);
		}
		else
		{
			box(vi_tri_x + 45, 15, 30, 2, 11, 1, a.pptt);
			gotoXY(vi_tri_x + 50, 18); cout << "                    ";
			SetColor(7);
			break;

		}
	}
	cin.ignore();
	gotoXY(vi_tri_x + 46, 20);
	getline(cin, a.trang_thai);
	regex check_ten("^[^0-9]+$");
	while (true)
	{
		if (regex_match(a.trang_thai, check_ten) == false)
		{
			box(vi_tri_x + 45, 19, 30, 2, 12, 1, a.pptt);
			SetColor(12);
			gotoXY(vi_tri_x + 50, 22); cout << "Nhap khong hop le!";
			box(vi_tri_x + 45, 19, 30, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(vi_tri_x + 46, 20); getline(cin, a.trang_thai);
		}
		else
		{
			box(vi_tri_x + 45, 19, 30, 2, 11, 1, a.trang_thai);
			gotoXY(vi_tri_x + 50, 22); cout << "                    ";
			SetColor(7);
			break;
		}
	}
}

void xuat_hoa_don_nhap_hang(int vi_tri_x, int vi_tri_y, HoaDon a)
{
	//========= Khung ============== //
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y * 17);
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
	for (int j = vi_tri_y * 17 + 1; j < vi_tri_y * 17 + 14; j++)
	{
		gotoXY(vi_tri_x, j);
		cout << char(179);
	}

	for (int j = vi_tri_y * 17 + 1; j < vi_tri_y * 17 + 14; j++)
	{
		gotoXY(vi_tri_x + 59, j);
		cout << char(179);
	}
	gotoXY(vi_tri_x, vi_tri_y * 17 + 14);
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
	gotoXY(vi_tri_x + 22, vi_tri_y * 17 + 1);
	cout << "HOA DON NHAP HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y * 17 + 2);
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
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 3);
	cout << "Ma hoa don:" << a.ma_hoa_don;
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y * 17 + 4);
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
	gotoXY(vi_tri_x + 20, vi_tri_y * 17 + 4);
	cout << " Thong tin hang hoa ";
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 5);
	cout << "Ma hang hoa: " << a.thong_tin_hang.ma_hh;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 6);
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 7);
	cout << "Size: " << a.thong_tin_hang.size;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 8);
	cout << "Gia: " << a.thong_tin_hang.gia;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 9);
	cout << "So luong mua: " << a.sl_mua;
	gotoXY(vi_tri_x, vi_tri_y * 17 + 10);
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
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 11);
	cout << "Tong tien: " << a.tong_tien;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 12);
	cout << "Trang thai: " << a.trang_thai;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 13);
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd;
}

void xuat_hoa_don_ban_hang(int vi_tri_x, int vi_tri_y, HoaDon a, DS_Hang_Hoa c)
{
	float tien;
	//========= Khung ============== //
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y * 17);
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
	for (int j = vi_tri_y * 17 + 1; j < vi_tri_y * 17 + 16; j++)
	{
		gotoXY(vi_tri_x, j);
		cout << char(179);
	}

	for (int j = vi_tri_y * 17 + 1; j < vi_tri_y * 17 + 16; j++)
	{
		gotoXY(vi_tri_x + 59, j);
		cout << char(179);
	}
	gotoXY(vi_tri_x, vi_tri_y * 17 + 16);
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
	gotoXY(vi_tri_x + 22, vi_tri_y * 17 + 1);
	cout << "HOA DON BAN HANG";
	textcolor(0);
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y * 17 + 2);
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
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 3);
	cout << "Ma hoa don: " << a.ma_hoa_don;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 4);
	cout << "Ma khach hang: " << a.ma_kh;
	SetColor(11);
	gotoXY(vi_tri_x, vi_tri_y * 17 + 5);
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
	gotoXY(vi_tri_x + 20, vi_tri_y * 17 + 5);
	cout << " Thong tin hang hoa ";
	SetColor(7);
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 6);
	cout << "Ma hang hoa: " << a.ma_hang_hoa;
	for (int i = 0; c.ds_ao.size(); i++)
	{
		if (a.ma_hang_hoa == c.ds_ao.at(i).ma_hh)
		{
			gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 7);
			cout << "Ten hang hoa: " << c.ds_ao.at(i).ten_hh << endl;
			gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 8);
			cout << "Gia: " << c.ds_ao.at(i).gia << endl;
			tien = c.ds_ao.at(i).gia;
			gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 9);
			cout << "Size: " << c.ds_ao.at(i).size << endl;
			break;
		}
	}
	for (int i = 0; c.ds_quan.size(); i++)
	{
		if (a.ma_hang_hoa == c.ds_quan.at(i).ma_hh)
		{
			gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 7);
			cout << "Ten hang hoa: " << c.ds_ao.at(i).ten_hh << endl;
			gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 8);
			cout << "Gia: " << c.ds_ao.at(i).gia << endl;
			tien = c.ds_ao.at(i).gia;
			gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 9);
			cout << "Size: " << c.ds_ao.at(i).size << endl;
			break;
		}
	}
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
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 11);
	cout << "So luong mua: " << a.sl_mua;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 12);
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
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 13);
	cout << "Tong tien: " << a.tong_tien;
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 14);
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd;
	gotoXY(vi_tri_x + 2, vi_tri_y * 17 + 15);
	cout << "Trang thai: " << a.trang_thai;
}

void thanh_sang(int x, int y, int w, int h, int mau_khung, string nd) 
{
	textcolor(mau_khung);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++) 
		{
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 7, y + 1);
	cout << nd;
}

void n_box_sp_moi(int vi_tri_x, int y, int w, int h, int t_color, int b_color, int sl, string nd, Admin &a)
{
	for (int i = 0; i < sl; i++)
	{
		box(vi_tri_x + 5, y + (i * 2), 56, 2, 7, 7, nd);
	}

	for (int i = 1; i < sl; i++)
	{
		// ve goc khung
		gotoXY(vi_tri_x + 5, y + (i * 2)); cout << char(195);
		gotoXY(vi_tri_x + 61, y + (i * 2)); cout << char(180);
	}
	
	// lay thoi gian de xuat ra san pham moi
	//time_t now = time(0);
	//tm* ltm = localtime(&now);

	//int iy = 0;
	//for (node_hoa_don* k = a.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
	//{
	//	if ((1 + ltm->tm_mon) - stoi(k->data.ngay_lap_hd.substr(3, 2)) <= 1)
	//	{
	//		gotoXY(vi_tri_x + 11, y + 1 + (iy * 2));
	//		cout << "San pham: " << k->data.thong_tin_hang.ten_hh;
	//		gotoXY(vi_tri_x + 44, y + 1 + (iy * 2));
	//		cout << "Gia: " << k->data.thong_tin_hang.gia;
	//		iy++;
	//	}
	//	if (iy > 5)
	//	{
	//		break;
	//	}
	//}
	int iy = 0;

	for (node_hoa_don* k = a.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
	{
		gotoXY(vi_tri_x + 11, y + 1 + (iy * 2));
		cout << "San pham: " << k->data.thong_tin_hang.ten_hh;
		gotoXY(vi_tri_x + 44, y + 1 + (iy * 2));
		cout << "Gia: " << k->data.thong_tin_hang.gia;
		iy++;
		if (iy > 5)
		{
			break;
		}

	}
}

// Thanh sáng của sp mới
void thanh_sang_sp_moi(int x, int y, int w, int h, int mau_khung, string ten, long long gia_hh)
{ 
	textcolor(mau_khung);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoXY(ix, iy); cout << " ";
		}
	}

	int iy = 0;
	SetColor(7);
	gotoXY(x + 5, y + 1 + iy * 2);
	cout << "San pham: " << ten;
	gotoXY(x + 38, y + 1 + iy * 2);
	cout << "Gia: " << gia_hh;
}

void luu_ds_hang_moi(Admin& a)
{	
	// lay thoi gian de xuat ra san pham moi
	time_t now = time(0);
	tm* ltm = localtime(&now);

	string ten;
	long long gia;


}

// di chuyển thanh sáng

void di_chuyen_thanh_sang_sp_moi(int x, int y, int w, int h, int mau_khung, string nd, int sl, Admin& a) 
{
	// lay thoi gian de xuat ra san pham moi
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int px = x; int py = y; // toa do thanh sang
	int xcu = px; int ycu = py;

	string ten;
	long long gia = 0;
	int iy = 0;

	bool kt = true;
	while (true)
	{
		if (kt == true) 
		{
			// back space 
			gotoXY(xcu, ycu);

			for (node_hoa_don* k = a.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
			{
				if ((1 + ltm->tm_mon) - stoi(k->data.ngay_lap_hd.substr(3, 2)) <= 1)
				{
					gotoXY(x + 5, y + 1 + (iy * 2));
					cout << "San pham: " << k->data.thong_tin_hang.ten_hh;
					gotoXY(x + 38, y + 1 + (iy * 2));
					cout << "Gia: " << k->data.thong_tin_hang.gia;
					thanh_sang_sp_moi(px, py, 54, h, mau_khung, k->data.thong_tin_hang.ten_hh, k->data.thong_tin_hang.gia);
					iy++;
					break;
				}
			}

			xcu = px; ycu = py;

			// in
			iy = 0;
			int mau_khung_sang = 75;
			for (node_hoa_don* k = a.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
			{
				if ((1 + ltm->tm_mon) - stoi(k->data.ngay_lap_hd.substr(3, 2)) <= 1)
				{
					gotoXY(x + 5, y + 1 + (iy * 2));
					cout << "San pham: " << k->data.thong_tin_hang.ten_hh;
					gotoXY(x + 38, y + 1 + (iy * 2));
					cout << "Gia: " << k->data.thong_tin_hang.gia;
					thanh_sang_sp_moi(px, py, 54, h, mau_khung_sang, k->data.thong_tin_hang.ten_hh, k->data.thong_tin_hang.gia);
					iy++;
					break;
				}
			}

			kt = false;
		}
		// di chuyen
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72 && py != y - 1)
				{

					if (py != y) 
					{
						py = py - 2;
					}
					else 
					{
						py = y + h * (sl - 1);
					}
				}
				else if (c == 80 && py != y - 1 + h * (sl - 1)) 
				{
					if (py != y + h * (sl - 1)) 
					{
						py = py + 2;
					}
					else 
					{
						py = y;
					}
				}
			}
			// Khi nhấn enter
			if (c == 13) {
				//textcolor(11);
				//string mo_ta = "Do co dan, thoang mat, de chiu. Mau sac mau ma dep, da dang. Dich vu, gia ca tot.";
				//gotoXY(x - 40, y + 5 + h * sl); cout << "Mo ta san pham  :" << mo_ta << endl;
			}

		}
	}
}

void ve_sp_moi(int vi_tri_x, int y, Admin& a)
{
	load_file_hoa_don_nhap(a.quan_li_ds_hoa_don_nhap);

	ShowCur(0);

	// sẽ để ở ngoài riêng
	//box(vi_tri_x + 62, y + 2, 13, 2, 11, 1, "  Tim kiem"); 

	gotoXY(vi_tri_x + 9, y + 5);
	textcolor(14); // 14 là màu vàng
	cout << "San pham moi: ";

	n_box_sp_moi(vi_tri_x + 7, y + 6, 50, 2, 14, 1, 6, " ", a);
	// ------
	int h = 2;
	int sl = 6; 
	int px = vi_tri_x + 13; int py = y + 6;
	int xcu = px; int ycu = py;

	int mau_sang = 75;

	string nd;
	string ten;
	long long gia_hh = 0;

	/*thanh_sang_sp_moi(px, py, 54, h, mau_sang, ten, gia_hh);
	di_chuyen_thanh_sang_sp_moi(px, py, 54, h, 0, nd, sl, a);*/
}

void ve_sp_hot(int vi_tri_x, Admin a)
{
	vector<HoaDon> b;
	//sanPhamHot(a, b);
	gotoXY(vi_tri_x + 9, 20);
	textcolor(14);
	cout << "San pham best seller:";
	n_box(vi_tri_x + 7, 21, 50, 2, 14, 1, "  San pham:", 3);

	int y = 22;
	int iy = 0;
	for (int i = b.size() - 1; i > b.size() - 4; i--)
	{
		gotoXY(vi_tri_x + 25, y + iy * 2);
		cout << b[i].thong_tin_hang.ten_hh;
		gotoXY(vi_tri_x + 50, y + iy * 2);
		cout << "Gia: " << b[i].thong_tin_hang.gia;
		iy++;
	}
}

void khung_gio_hang(int x, int y, int w, int h, int mau_khung, int mau_chu, string nd)
{
	if (h <= 1) return;
	textcolor(mau_chu);
	for (int iy = y; iy <= y + h - 1; iy++) {
		for (int ix = x; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(11);
	gotoXY(x + 7, y + 1);
	cout << nd;
	// ==================== ve khung ====================
	textcolor(1);
	SetColor(mau_khung);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);
		gotoXY(ix, y + h); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);
		gotoXY(x + w, iy); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);
}

void khung_hang_hoa_trong_gio(int x, int y, int w, int h, int mau_khung, int mau_chu, string nd) {
	if (h <= 1) return;
	textcolor(mau_chu);
	for (int iy = y; iy <= y + h - 1; iy++) {
		for (int ix = x; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 7, y + 1);
	cout << nd;
	// ==================== ve khung ====================
	textcolor(1);
	SetColor(mau_khung);
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y); cout << char(196);
		gotoXY(ix, y + h); cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy); cout << char(179);
		gotoXY(x + w, iy); cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);
}

void n_khung_hang_hoa_trong_gio(int x, int y, int w, int h, int mau_khung, int mau_chu, string nd, int sl) {
	for (int i = 0; i < sl; i++) {
		khung_hang_hoa_trong_gio(x, y + (i * 2), w, h, mau_khung, mau_chu, nd);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}

void menu_sp_moi()
{
	ShowCur(0);
	DS_Hang_Hoa a;
	Admin b;
	//docFile_ds_hang(a);
	load_file_hoa_don_nhap(b.quan_li_ds_hoa_don_nhap);

	int x = 90;
	int y = 13;
	box(x, y, 80, 30, 11, 1, " ");
	ve_sp_moi(x, y, b);

}

void menu_gio_hang() {
	ShowCur(0);
	khung_gio_hang(50, 5, 20, 2, 11, 1, "GIO HANG");
	int x = 45; int y = 15;
	int w = 30; int h = 2;
	int mau_khung = 11;
	int mau_chu = 1;
	int mau_khung_sang = 75;
	string nd = "cheese baro";
	int sl = 10;
	n_khung_hang_hoa_trong_gio(x, y, w, h, mau_khung, mau_chu, nd, sl);
	thanh_sang(x, y, w, h, mau_khung_sang, nd);
	textcolor(11);
	gotoXY(x - 20, y - 3); cout << "Dung mui ten len va xuong den di chuyen, nhan Enter de chon xem hang.";
	// ============= di chuyen thanh sang =============
	//di_chuyen_thanh_sang(x, y, w, h, mau_khung, nd, sl);
	
}

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
	cout << "Su dung bon phim " << char(30) << " " << char(31) << " " << char(16) << " " << char(17);
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

// ve khung dk // done
void khung_dk(int x, int y, ds_khach_hang &dskh)
{
	KhachHang a;
	// === khung ===
	box(x, y, 80, 35, 11, 0, " ");
	// noi dung
	textcolor(14);
	gotoXY(x + 32, y + 1);
	cout << "DANG KY THANH VIEN";
	SetColor(11);
	gotoXY(x,y + 3);
	for (int i = 0; i < 80; i++)
	{
		if (i == 0)
		{
			cout << char(195);
		}
		if (i == 79)
		{
			cout << char(180);
			continue;
		}
		cout << char(196);
	}

	int y_thong_tin = 0;
	SetColor(14);
	gotoXY(x + 32, y + 5);
	cout << "THONG TIN CA NHAN";

	SetColor(7);
	gotoXY(x + 6, y + 8);
	cout << "Ho ten: ";
	box(x + 24, y + 7, 50, 2, 11, 1, " ");

	SetColor(7);
	gotoXY(x + 6, y + 12);
	cout << "So dien thoai: ";
	box(x + 24, y + 11, 50, 2, 11, 1, " ");

	SetColor(7);
	gotoXY(x + 6, y + 16);
	cout << "Dia chi: ";
	box(x + 24, y + 15, 50, 2, 11, 1, " ");

	SetColor(7);
	gotoXY(x + 6, y + 20);
	cout << "Email: ";
	box(x + 24, y + 19, 50, 2, 11, 1, " ");

	SetColor(7);
	gotoXY(x + 6, y + 24);
	cout << "Ten dang nhap: ";
	box(x + 24, y + 23, 50, 2, 11, 1, " ");

	SetColor(7);
	gotoXY(x + 6, y + 28);
	cout << "Mat khau: ";
	box(x + 24, y + 27, 50, 2, 11, 1, " ");

	SetColor(7);
	gotoXY(x + 6, y + 32);
	cout << "Xac nhan mat khau: ";
	box(x + 24, y + 31, 50, 2, 11, 1, " ");


	SetColor(7);
	gotoXY(x + 25, y + 8);
	getline(cin, a.ten);
	chuanHoa(a.ten);
	
	while (true)
	{
		if (check_Ten(a.ten) == false)
		{
			SetColor(12);
			gotoXY(x + 40, y + 10); cout << "Nhap khong hop le!";
			box(x + 24, y + 7, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 8); getline(cin, a.ten);
			chuanHoa(a.ten);
		}
		else
		{
			box(x + 24, y + 7, 50, 2, 11, 1, a.ten);
			gotoXY(x + 40, y + 10); cout << "                   ";
			SetColor(7);
			break;
		}
	}

	SetColor(7);
	gotoXY(x + 25, y + 12);
	getline(cin, a.sdt);
	while (true)
	{
		if (check_Sdt(a.sdt) == false)
		{
			SetColor(12);
			gotoXY(x + 40, y + 14); cout << "Nhap khong hop le!";
			box(x + 24, y + 11, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 12); getline(cin, a.sdt);
		}
		else
		{
			box(x + 24, y + 11, 50, 2, 11, 1, a.sdt);
			gotoXY(x + 40, y + 14); cout << "                   ";
			SetColor(7);
			break;

		}
	}

	SetColor(7);
	gotoXY(x + 25, y + 16);
	getline(cin, a.diaChi);
	while (true)
	{
		if (check_Ten(a.diaChi) == false) // sua regex
		{
			SetColor(12);
			gotoXY(x + 40, y + 18); cout << "Nhap khong hop le!";
			box(x + 24, y + 15, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 16); getline(cin, a.diaChi);
		}
		else 
		{
			box(x + 24, y + 15, 50, 2, 11, 1, a.diaChi);
			gotoXY(x + 40, y + 18); cout << "                   ";
			SetColor(7);
			break;

		}
	}
	
	SetColor(7);
	gotoXY(x + 25, y + 20);
	getline(cin, a.email);
	while (true)
	{
		if (check_email(a.email) == false)
		{
			SetColor(12);
			gotoXY(x + 40, y + 22); cout << "Nhap khong hop le!";
			box(x + 24, y + 19, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 20); getline(cin, a.email);
		}
		else 
		{
			box(x + 24, y + 19, 50, 2, 11, 1, a.email);
			gotoXY(x + 40, y + 22); cout << "                   ";
			SetColor(7);
			break;

		}
	}

	SetColor(7);
	gotoXY(x + 25, y + 24);
	getline(cin, a.ten_dang_nhap);
	while (true)
	{
		if (check_Ten(a.ten_dang_nhap) == false) // sua regex
		{
			SetColor(12);
			gotoXY(x + 40, y + 26); cout << "Nhap khong hop le!";
			box(x + 24, y + 23, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 24); getline(cin, a.ten_dang_nhap);
		}
		else 
		{
			box(x + 24, y + 23, 50, 2, 11, 1, a.ten_dang_nhap);
			gotoXY(x + 40, y + 26); cout << "                   ";
			SetColor(7);
			break;

		}
	}

	SetColor(7);
	gotoXY(x + 25, y + 28);
	getline(cin, a.mat_khau);
	regex check_mk("^[a-zA-Z0-9!@#$%^&*()-=_+]{1,}$");
	while (true)
	{
		if (regex_match(a.mat_khau, check_mk) == false) // sua regex
		{
			SetColor(12);
			gotoXY(x + 40, y + 30); cout << "Nhap khong hop le!";
			box(x + 24, y + 27, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 28); getline(cin, a.mat_khau);
		}
		else 
		{
			box(x + 24, y + 27, 50, 2, 11, 1, a.mat_khau);
			gotoXY(x + 40, y + 30); cout << "                   ";
			SetColor(7);
			break;
		}
	}

	string mk_nhap_lai;
	SetColor(7);
	gotoXY(x + 25, y + 32);
	getline(cin, mk_nhap_lai);
	while (true)
	{
		if (mk_nhap_lai != a.mat_khau) 
		{
			SetColor(12);
			gotoXY(x + 40, y + 34); cout << "Nhap khong hop le!";
			box(x + 24, y + 31, 50, 2, 12, 1, "                            ");
			SetColor(7);
			gotoXY(x + 25, y + 32); getline(cin, mk_nhap_lai);
		}
		else 
		{
			box(x + 24, y + 31, 50, 2, 11, 1, mk_nhap_lai);
			gotoXY(x + 40, y + 34); cout << "                   ";
			SetColor(7);
			break;
		}
	}
}

