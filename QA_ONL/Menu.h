#pragma once
#include "chuong_trinh.h"


void menuAdmin(Admin a)
{
	KhachHang b;
	short luaChon;
	bool check = true;
	int n;
	while (check == true)
	{
		system("cls");
		cout << "1.Nhap hoa don.";
		cout << "\n2.Xuat hoa don ban hang.";
		cout << "\n3.Xuat hoa don nhap hang.";
		/*cout << "\n4.Load thong tin khach hang.";
		cout << "\n5.Don hang cho xu li.";*/
		cout << "\n0.Thoat";

		do
		{
			cout << "\nNhap lua chon: "; cin >> luaChon;
		} while (luaChon < 0);

		switch (luaChon)
		{
		case 1:
		{

			do
			{
				cout << "\nNhap so luong hoa don muon them: "; cin >> n;
			} while (n < 0);
			for (int i = 0; i < n; i++)
			{
				cout << "\n============ Nhap hoa don thu " << " =============\n";
				HoaDon hd;

			}
			break;
		}
		case 2:
		{
			int i = 0;
			/*for (node_hoa_don*k =a.quan_li_ds_hoa_don.pHead; k != NULL; k=k->pNext)
			{
				if (k->data.ma_hoa_don[0] == 'X')
				{
					cout << "\n\t\tHoa don ban hang thu " << i++ << " \n";
					xuatHoaDonBanHang(k->data, a.quan_li_ds_hang_hoa);
				}
			}*/
			system("pause");
			break;
		}
		case 3:
		{
			int i = 0;
			/*for (node_hoa_don*k =a.quan_li_ds_hoa_don.pHead; k != NULL; k=k->pNext)
			{
				if (k->data.ma_hoa_don[0] == 'N')
				{
					cout << "\n\t\tHoa don nhap hang thu " << i++ << " \n";
					xuatHoaDonNhapHang(k->data);
				}
			}*/
			system("pause");
			break;
		}
		case 0:
		{
			check = false;
			break;
		}

		}
	}
}

void meunKH()
{
	short luaChon;
	bool check = true;
	int n;
	while (check == true)
	{
		system("cls");
		cout << "1.Nhap thong tin hang hoa.";
		cout << "\n2.Xuat thong tin hang hoa.";
		cout << "\n3.Load file hang hoa.";
		cout << "\n4.Load thong tin khach hang.";
		cout << "\n5.Don hang cho xu li.";
		cout << "\n0.Thoat";

		do
		{
			cout << "\nNhap lua chon: "; cin >> luaChon;
		} while (luaChon < 0);

		switch (luaChon)
		{
		case 1:
		{

			do
			{
				cout << "\nNhap so luong hang hoa muon them: "; cin >> n;
			} while (n < 0);
			for (int i = 0; i < n; i++)
			{

			}
			break;
		}
		case 0:
		{
			check = false;
			break;
		}

		}
	}
}