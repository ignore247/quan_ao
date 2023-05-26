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

void menuKH(Admin ad,string makh)
{
	int luaChon;
	string k;
	bool check = true;
	int n;
	while (check == true)
	{
		system("cls");
		cout << "1.Xem hang hoa.";
		cout << "\n2.Xem sam pham hot/best seller hang hoa.";
		cout << "\n3.Tim kiem hang hoa";
		cout << "\n4.Them san pham vao gio hang.";
		cout << "\n5.Xem gio hang.";
		cout << "\n6.Xoa hang hoa trong gio hang.";
		cout << "\n7.Mua hang.";
		cout << "\n8.Xac nhan don hang (tra hang / xac nhan da nhan hang).";
		cout << "\n9.Xem don mua hang.";
		cout << "\n10.Xem thong tin ca nhan.";
		cout << "\n11.Sua thong tin ca nhan.";
		cout << "\n0.Thoat";

		cout << "\nNhap lua chon: ";
		getline(cin, k);
		luaChon = stoi(k);
		while (luaChon < 0 || luaChon > 11 || check_So(k) == false)
		{
			cout << "\nNhap khong hop le!";
			cout << "\nNhap lua chon: ";
			getline(cin, k);
			luaChon = stoi(k);
		}

		switch (luaChon)
		{
		case 1:
		{
			xuat_thong_tin_quan(ad.quan_li_ds_hang_hoa);
			xuat_thong_tin_ao(ad.quan_li_ds_hang_hoa);
			break;
		}
		case 2:
		{
			
			break;
		}
		case 3:
		{

			break;
		}
		case 4:
		{
			them_sp_vao_gio_hang(ad.quan_li_ds_hang_hoa, ad.quan_li_ds_kh.t, makh);
			break;
		}
		case 5:
		{
			duyet_cay_xem_gio_hang(ad.quan_li_ds_kh.t, makh);
			break;
		}
		case 6:
		{
			duyet_cay_xoa_sp_gio_hang(ad.quan_li_ds_kh.t, makh);
			break;
		}
		case 7:
		{
			mua_hang(ad, makh);
			break;
		}
		case 8:
		{
			xac_nhan_don_hang(ad, makh);
			break;
		}
		case 9:
		{
			int luaChon;
			string k;
			bool check = true;
			while (check == true)
			{
				system("cls");
				cout << "\n1.Xem tat ca don hang.";
				cout << "\n2.Thong ke don hang.";
				cout << "\n0.Thoat";

				do
				{
					cout << "\nNhap lua chon: ";
					getline(cin, k);
					while_so(k);
					luaChon = stoi(k);
				} while (luaChon < 0 || luaChon > 2);

				switch (luaChon)
				{
				case 1:
				{
					xuat_don_mua(ad.quan_li_ds_kh.t, makh);
					break;
				}
				case 2:
				{
					thong_ke_don_mua_hang(ad, makh);
					break;
				}
				case 0:
				{
					check = false;
					break;
				}
				}
			}
			break;
		}
		case 10:
		{
			xuat_thong_tin_khach_hang_theo_ma(ad.quan_li_ds_kh.t, makh);
			break;
		}
		case 11:
		{
			suaThongTinKhTheoMa(ad.quan_li_ds_kh.t, makh);
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

void dang_nhap_admin()
{
	string username;
	string password;
	cout << "Nhap tai khoan:";
	getline(cin, username);
	cout << "Nhap mat khau: ";
	getline(cin, password);
	while (check_dinh_dang_tk(username) == false || password == "\0" || username == "\0" || password != "admin123" || username != "admin567")
	{
		cout << "Tai khoan hoac mat khau khung dung!";
		cout << "Nhap tai khoan:";
		getline(cin, username);
		cout << "Nhap mat khau: ";
		getline(cin, password);
	}
}

void dang_nhap_user(Admin ad,string makh)
{
	string username;
	string password;
	cout << "Nhap tai khoan:";
	getline(cin, username);
	cout << "Nhap mat khau: ";
	getline(cin, password);
	while (check_dinh_dang_tk(username) == false || password == "\0" || username == "\0" || check_tk_mk(username, password, ad.quan_li_ds_kh.t,makh) == false)
	{
		cout << "Tai khoan hoac mat khau khung dung!";
		cout << "Nhap tai khoan:";
		getline(cin, username);
		cout << "Nhap mat khau: ";
		getline(cin, password);
	}
}

void chuong_trinh(Admin ad)
{
	int luaChon;
	string k;
	bool check = true;
	int n;
	string makh;
	while (check == true)
	{
		system("cls");
		cout << "\nBan dang nhap voi tu cach: ";
		cout << "\n1.Admin ";
		cout << "\n2.Nguoi dung";
		cout << "\n0.Thoat";

		cout << "\nNhap lua chon: ";
		getline(cin, k);
		luaChon = stoi(k);
		while (luaChon < 0 || luaChon > 2 || check_So(k) == false)
		{
			cout << "\nNhap khong hop le!";
			cout << "\nNhap lua chon: ";
			getline(cin, k);
			luaChon = stoi(k);
		}
		switch (luaChon)
		{
		case 1:
		{
			dang_nhap_admin();
			menuAdmin(ad);
			break;
		}
		case 2:
		{
			bool kt = true;
			while (kt == true)
			{
				system("cls");
				cout << "\n1.Dang nhap ";
				cout << "\n2.Dang ky";
				cout << "\n0.Thoat";
				string str;
				int  c;
				cout << "\nNhap lua chon: ";
				getline(cin, str);
				luaChon = stoi(k);
				while (c < 0 || c > 2 || check_So(str) == false)
				{
					cout << "\nNhap khong hop le!";
					cout << "\nNhap lua chon: ";
					getline(cin, str);
					c = stoi(str);
				}
				switch (c)
				{
				case 1:
				{

					break;
				}
				case 2:
				{
					dang_nhap_user(ad, makh);
					menuKH(ad, makh);
					break;
				}
				case 0:
				{
					kt = false;
					break;
				}
				}
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