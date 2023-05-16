#pragma once
#include "Do_Hoa.h"
#include "chuong_trinh.h"


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

// =============== Gio Hang ===============
void khung_chu_gio_hang(int x, int y, int w, int h, int mau_khung, int mau_chu, string nd) {
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

void thanh_sang(int x, int y, int w, int h, int mau_khung, gio_hang a) {
	textcolor(mau_khung);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	for (int i = 0; i < a.hh.size(); i++) {
		SetColor(7);
		gotoXY(x + 1, y + 1);
		cout << a.hh.at(i).ten_hh;
	}
}

void khung_hang_hoa_trong_gio(int x, int y, int w, int h, int mau_khung, int mau_chu, gio_hang a) {
	if (h <= 1) return;
	textcolor(mau_chu);
	for (int iy = y; iy <= y + h - 1; iy++) {
		for (int ix = x; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	for (int i = 0; i < a.hh.size(); i++) {
		SetColor(7);
		gotoXY(x + 7, y + 1);
		cout << a.hh.at(i).ten_hh;
	}
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

void n_khung_hang_hoa_trong_gio(int x, int y, int w, int h, int mau_khung, int mau_chu, gio_hang a) {
	for (int i = 0; i < a.hh.size(); i++) {
		khung_hang_hoa_trong_gio(x, y + (i * 2), w, h, mau_khung, mau_chu, a);
		if (i != 0) {
			gotoXY(x, y + (i * 2)); cout << char(195);
			gotoXY(x + w, y + (i * 2)); cout << char(180);
		}
	}
}

// di chuyen thanh sang 
void di_chuyen_thanh_sang(int x, int y, int w, int h, int mau_khung, gio_hang a) {
	int px = x; int py = y; // toa do thanh sang
	int xcu = px; int ycu = py;
	bool kt = true;
	while (true) {
		if (kt == true) {
			// back space 
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, mau_khung, a); // reset thanh sang
			xcu = px; ycu = py;
			// in
			int mau_khung_sang = 75;
			thanh_sang(px, py, w, h, mau_khung_sang, a);
			kt = false;
		}
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;
				c = _getch();
				if (c == 72)
				{
					if (py != y) {
						py = py - 2;
					}
					else {
						py = y + h * (a.hh.size() - 1);
					}
				}
				else if (c == 80) {
					if (py != y + h * (a.hh.size() - 1)) {
						py = py + 2;
					}
					else {
						py = y;
					}
				}
			}
			// chi tiet hang trong gio hang
			for (int i = 0; i < a.hh.size(); i++) {
				if (c == 13) {
					system("cls");
					textcolor(11);
					gotoXY(x - 40, y + 5 + h * a.hh.size()); 
					xuat_tt_hh_ngan_gon(a.hh[i]);
				}
			}

		}

	}
}

