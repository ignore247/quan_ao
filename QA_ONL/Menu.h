#pragma once
#include "chuong_trinh.h"


void menuAdmin(Admin a)
{
	int luaChon;
	bool check = true;
	while (check == true)
	{
		system("cls");
		cout << "\n1.Muc Khach hang.";
		cout << "\n2.Muc hang hoa.";
		cout << "\n3.Muc hoa don.";
		cout << "\n4.Thoat.";
		do
		{
			cout << "\nNhap lua chon :";
			cin >> luaChon;
			string tam = to_string(luaChon);
			while_so(tam);
			luaChon = stoi(tam);
		} while (luaChon < 0 || luaChon > 4);
		switch (luaChon)
		{
		case 1:
		{
			cout << "\n1.Them khach hang.";
			cout << "\n2.Hien thi thong tin khach hang.";
			cout << "\n3.Sua thong tin khach hang.";
			cout << "\n4.Xoa khac hang.";
			cout << "\n5.Thoat.";
			do {
				cout << "\nNhap lua chon :";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 5);
			switch (luaChon) {
			case 1: {
				//ham them khach hang
				break;
			}
			case 2 : {
				//Hien thi thong tin khach hang
				break;
			}
			case 3: {
				//ham sua thong tin khach hang
				break;
			}
			case 4: {
				// ham xoa khach hang
				break;
			}
			case 5: {
				check = false;
				break;
			}
			}
			break;
		}
		case 2:
		{
			cout << "\n1.Them hang hoa ao.";
			cout << "\n2.Them hang hoa quan.";
			cout << "\n3.Hien thi hang hoa ao.";
			cout << "\n4.Hien thi hang hoa quan.";
			cout << "\n5.Sua thong tin hang hoa.";
			cout << "\n6.Sua thong tin hang hoa.";
			cout << "\n7.Thoat.";
			do {
				cout << "\nNhap lua chon : ";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 7);
			switch (luaChon) {
			case 1: {
				//ham them hang hoa ao
				break;
			}
			case 2: {
				//ham them hang hoa quan
				break;
			}
			case 3: {
				//Hien thi hang hoa ao
				break;
			}
			case 4: {
				//Hien thi hang hoa quan
				break;
			}
			case 5: {
				//ham sua thong tin hang hoa
				break;
			}
			case 6: {
				//ham xoa hang hoa
				break;
			}
			case 7: {
				check = false;
				break;
			}
			}
			break;
		}
		case 3:
		{
			cout << "\n1.Hien thi hoa don nhap.";
			cout << "\n2.Hien thi don ban.";
			cout << "\n3.Sua hoa don nhap.";
			cout << "\n4.Sua hoa don ban.";
			cout << "\n5.Xoa hoa don.";
			cout << "\n6.Thoat.";
			do {
				cout << "\nNhap lua chon : ";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 6);
			switch (luaChon) {
			case 1: {
				//Hien thi hoa don nhap
				break;
			}
			case 2: {
				//Hien thi don ban
				break;
			}
			case 3: {
				//ham sua hoa don nhap
				break;
			}
			case 4: {
				//ham sua hoa don ban
				break;
			}
			case 5: {
				//ham xoa hoa don
				break;
			}
			case 6: {
				check = false;
				break;
			}
			}
			break;
		}
		case 4:
		{
			check = false;
			return;
		}

		}
	}
}

void menuKH(KhachHang b)
{
	int luaChon;
	bool check = true;
	while (check == true)
	{
		system("cls");
		cout << "\n1.Xem hang hoa.";
		cout << "\n2.Gio hang.";
		cout << "\n3.Ca nhan.";
		cout << "\n4.Thoat";
		do
		{
			cout << "\nNhap lua chon: ";
			cin >> luaChon;
			string tam = to_string(luaChon);
			while_so(tam);
			luaChon = stoi(tam);
		} while (luaChon < 0 || luaChon > 4);
		switch (luaChon)
		{
		case 1:
		{
			cout << "\n1.Xem ao.";
			cout << "\n2.Xem quan.";
			cout << "\n3.Xem san pham hot.";
			cout << "\n4.Thoat.";
			do
			{
				cout << "\nNhap lua chon: ";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 4);
			switch (luaChon) {
			case 1: {
				//Xem ao
				break;
			}
			case 2 : {
				//Xem quan
				break;
			}
			case 3 : {
				//Xem san pham hot
				break;
			}
			case 4: {
				check = false;
				break;
			}
			}
			break;
		}
		case 2: {
			cout << "\n1.Them vao gio hang.";
			cout << "\n2.Hien thi Gio hang.";
			cout << "\n3.Xoa gio Hang.";
			cout << "\n4.Thoat";
			do {
				cout << "\nNhap lua chon: ";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 4);
			switch (luaChon) {
			case 1: {
				//Them vao gio hang
				break;
			}
			case 2: {
				//Hien thi gio hang
				break;
			}
			case 3: {
				//Xoa gio hang
				break;
			}
			case 4: {
				check = false;
				break;
			}
			}
			break;
		}
		case 3: {
			cout << "\n1.Hien thi thon tin ca nhan.";
			cout << "\n2.Sua thong tin ca nhan.";
			cout << "\n3.Xoa tai khoan.";
			cout << "\n4.Thoat.";
			do {
				cout << "\nNhap lua chon: ";
				cin >> luaChon;
				string tam = to_string(luaChon);
				while_so(tam);
				luaChon = stoi(tam);
			} while (luaChon < 0 || luaChon > 4);
			switch (luaChon) {
			case 1: {
				//Hien thi thon tin ca nhan
				break;
			}
			case 2: {
				//Sua thong tin ca nhan
				break;
			}
			case 3: {
				//Xoa tai khoan
				break;
			}
			case 4: {
				check = false;
				break;
			}
			}
			break;
		}
		case 4:
		{
			check = false;
			return;
		}

		}
	}
}
