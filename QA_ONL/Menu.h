#pragma once
#include "chuong_trinh.h"


void menuAdmin(Admin &ad)
{
	string chon;
	int luaChon;
	// muc hang hoa
	HangHoa a;
	// muc hoa don
	HoaDon c;

	bool check = true;
	while (check == true)
	{
		bool check_case = true;
		system("cls");
		cout << "\n1. Muc Khach hang.";
		cout << "\n2. Muc hang hoa.";
		cout << "\n3. Muc hoa don."; 
		cout << "\n4. Muc thong ke.";
		cout << "\n5. Muc hang cho.";
		cout << "\n6. Muc hang tra.";
		cout << "\n7. Muc danh sach da xoa.";
		cout << "\n0. Thoat.";
		do
		{
			cout << "\nNhap lua chon: ";
			getline(cin, chon);
			while_so(chon);
			luaChon = stoi(chon);
			cout << endl;
		} while (luaChon < 0 || luaChon > 4);
		switch (luaChon)
		{
		case 1: // khach hang
		{
			while (check_case == true)
			{
				system("cls");
				cout << "\n1.Them khach hang.";
				cout << "\n2.Hien thi thong tin khach hang.";
				cout << "\n3.Sua thong tin khach hang.";
				cout << "\n4.Xoa khach hang.";
				cout << "\n5.Thoat.";
				do
				{
					cout << "\nNhap lua chon: ";
					getline(cin, chon);
					while_so(chon);
					luaChon = stoi(chon);
				} while (luaChon < 0 || luaChon > 5);
				cout << endl;
				switch (luaChon) {
				case 1: 
				{
					dang_ky_tai_khoan(ad.quan_li_ds_kh);
					ad.quan_li_ds_kh.sl++;
					break;
				}
				case 2: 
				{
					if (ad.quan_li_ds_kh.t == NULL)
					{
						cout << "Chua co khach hang!\n";
						cout << "Hay them vao!\n";
						system("pause");
					}
					else
					{
						xuat_thong_tin_khach_hang(ad.quan_li_ds_kh.t);
						system("pause");
					}
					break;
				}
				case 3:
				{
					if (ad.quan_li_ds_kh.t == NULL)
					{
						cout << "Chua co khach hang!\n";
						cout << "Hay them vao!\n";
						system("pause");
					}
					else
					{
						ghi_thong_tin_kh(ad.quan_li_ds_kh);
						suaThongTinKh(ad.quan_li_ds_kh.t);
						system("pause");
					}
					break;
				}
				case 4: 
				{
					string ma_kh_muon_xoa;
					if (ad.quan_li_ds_kh.t == NULL)
					{
						cout << "Chua co khach hang!\n";
						system("pause");
					}
					else
					{
						cout << "Nhap ma khach hang can xoa: ";
						getline(cin, ma_kh_muon_xoa);
						while_ma_kh(ma_kh_muon_xoa);
						if (ad.quan_li_ds_kh.t->data.maKh == ma_kh_muon_xoa)
						{
							them_KhachHangXoa_vao_cay(ad.quan_li_kh_xoa.t, ad.quan_li_kh_xoa.t->khx);
							ad.quan_li_kh_xoa.sl++;
							xoa_khach_hang_theo_ma(ad.quan_li_ds_kh.t, ma_kh_muon_xoa);
							ad.quan_li_ds_kh.sl--;
							cout << "Da xong!\n";
							system("pause");
						}
						else
						{
							cout << "Khong ton tai hoac khong dung ma khach hang!\n";
							system("pause");
						}
						system("pause");
					}
					break;
				}
				case 5: {
					check_case = false;
					break;
				}
				}
			}
			break;
		}
		case 2: // hang hoa
		{
			while (check_case == true)
			{
				system("cls");
				cout << "\n1.Them hang hoa.";
				cout << "\n2.Hien thi hang hoa ao.";
				cout << "\n3.Hien thi hang hoa quan.";
				cout << "\n4.Hien thi hang hoa theo bo loc.";
				cout << "\n5.Sua thong tin ao.";
				cout << "\n6.Sua thong tin quan.";
				cout << "\n7.Xoa hang hoa.";
				cout << "\n0.Thoat.";
				do {
					cout << "\nNhap lua chon: ";
					getline(cin, chon);
					while_so(chon);
					luaChon = stoi(chon);
					cout << endl;
				} while (luaChon < 0 || luaChon > 7);
				switch (luaChon) {
				case 1: 
				{
					nhapHangHoa(a, ad.quan_li_ds_hang_hoa);
					if (a.ma_hh[0] == 'A')
					{
						ad.quan_li_ds_hang_hoa.ds_ao.push_back(a);
					}
					else if (a.ma_hh[0] == 'Q')
					{
						ad.quan_li_ds_hang_hoa.ds_quan.push_back(a);
					}
					break;
				}
				case 2:             
				{
					xuat_thong_tin_ao(ad.quan_li_ds_hang_hoa);
					system("pause");
					break;
				}
				case 3: 
				{
					xuat_thong_tin_quan(ad.quan_li_ds_hang_hoa);
					system("pause");
					break;
				}
				case 4:
				{
					loc_HangHoa(ad.quan_li_ds_hang_hoa);
					system("pause");
					break;
				}
				case 5: 
				{
					string tim_ma_hh, tam;
					cout << "Nhap ma hang hoa can sua: "; getline(cin, tim_ma_hh);
					while_full_ma_hh(tim_ma_hh);
					if (ad.quan_li_ds_hang_hoa.ds_ao.empty())
					{
						cout << "Danh sach dang rong! Hay them san pham vao!\n";
						system("pause");
						break;
					}
					else
					{
						for (int i = 0; i < ad.quan_li_ds_hang_hoa.ds_ao.size(); i++)
						{
							if (tim_ma_hh == ad.quan_li_ds_hang_hoa.ds_ao[i].ma_hh)
							{
								bool check_case_4_in2 = true;
								while (check_case_4_in2 == true)
								{
									system("cls");
									cout << "\n1. Sua ten.";
									cout << "\n2. Sua gia.";
									cout << "\n3. Sua size.";
									cout << "\n4. Sua mo ta.";
									cout << "\n5. Sua so luong ton kho.";
									cout << "\n6. Sua thoi gian nhap.";
									cout << "\n7. Thoat.\n";
									do {
										cout << "\nNhap lua chon: ";
										getline(cin, chon);
										while_so(chon);
										luaChon = stoi(chon);
									} while (luaChon < 0 || luaChon > 7);
									if (luaChon == 1)
									{
										cout << "Nhap ten ao moi: "; getline(cin, tam);
										while_ten(tam);
										sua_ten_ao(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 2)
									{
										int gia_moi;
										cout << "Nhap gia ao moi: "; getline(cin, tam);
										while_so(tam);
										gia_moi = stoi(tam);
										sua_gia_ao(tim_ma_hh, ad.quan_li_ds_hang_hoa, gia_moi);
									}
									else if (luaChon == 3)
									{
										cout << "Nhap size: "; getline(cin, tam);
										while_size_ao(tam);
										sua_size_ao(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 4)
									{
										cout << "Nhap mo ta: "; getline(cin, tam);
										sua_mo_ta_sp_ao(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 5)
									{
										int so_luong_ton;
										cout << "So luong ton kho: "; getline(cin, tam);
										while_so(tam);
										so_luong_ton = stoi(tam);
										sua_so_luong_ao_ton_kho(tim_ma_hh, ad.quan_li_ds_hang_hoa, so_luong_ton);
									}
									else if (luaChon == 6)
									{
										cout << "Thoi gian nhap hang: "; getline(cin, tam);
										chuan_hoa_tg(tam);
										check_date(tam);
										sua_thoi_gian_nhap_ao(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 7)
									{
										check_case_4_in2 = false;
									}
									ghi_file_ao(ad.quan_li_ds_hang_hoa);
								}
								break;
							}
							// ma nhap vao khong khop voi ma trong danh sach
							else if (tim_ma_hh != ad.quan_li_ds_hang_hoa.ds_ao[i].ma_hh && i == (ad.quan_li_ds_hang_hoa.ds_ao.size() - 1))
							{
								cout << "Ma khong khop hoac khong co trong danh sach!\n";
								system("pause");
							}
						}
					}
					break;
				}
				case 6: 
				{
					string tim_ma_hh, tam;
					cout << "Nhap ma hang hoa can sua: "; getline(cin, tim_ma_hh);
					while_full_ma_hh(tim_ma_hh);
					if (ad.quan_li_ds_hang_hoa.ds_quan.empty())
					{
						cout << "Danh sach dang rong! Hay them san pham vao!\n";
						system("pause");
						break;
					}
					else
					{
						for (int i = 0; i < ad.quan_li_ds_hang_hoa.ds_quan.size(); i++)
						{
							if (tim_ma_hh == ad.quan_li_ds_hang_hoa.ds_quan[i].ma_hh)
							{
								bool check_case_5_in2 = true;
								while (check_case_5_in2 == true)
								{
									system("cls");
									cout << "\n1. Sua ten.";
									cout << "\n2. Sua gia.";
									cout << "\n3. Sua size.";
									cout << "\n4. Sua mo ta.";
									cout << "\n5. Sua so luong ton kho.";
									cout << "\n6. Sua thoi gian nhap.";
									cout << "\n7. Thoat.\n";
									do {
										cout << "\nNhap lua chon: ";
										getline(cin, chon);
										while_so(chon);
										luaChon = stoi(chon);
									} while (luaChon < 0 || luaChon > 7);
									if (luaChon == 1)
									{
										cout << "Nhap ten quan moi: "; getline(cin, tam);
										while_ten(tam);
										sua_ten_quan(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 2)
									{
										int gia_moi;
										cout << "Nhap gia quan moi: "; getline(cin, tam);
										while_so(tam);
										gia_moi = stoi(tam);
										sua_gia_quan(tim_ma_hh, ad.quan_li_ds_hang_hoa, gia_moi);
									}
									else if (luaChon == 3)
									{
										cout << "Nhap size: "; getline(cin, tam);
										while_size_quan(tam);
										sua_size_quan(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 4)
									{
										cout << "Nhap mo ta: "; getline(cin, tam);
										sua_mo_ta_sp_quan(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 5)
									{
										int so_luong_ton;
										cout << "So luong ton kho: "; getline(cin, tam);
										while_so(tam);
										so_luong_ton = stoi(tam);
										sua_so_luong_quan_ton_kho(tim_ma_hh, ad.quan_li_ds_hang_hoa, so_luong_ton);
									}
									else if (luaChon == 6)
									{
										cout << "Thoi gian nhap hang: "; getline(cin, tam);
										chuan_hoa_tg(tam);
										check_date(tam);
										sua_thoi_gian_nhap_quan(tim_ma_hh, ad.quan_li_ds_hang_hoa, tam);
									}
									else if (luaChon == 7)
									{
										check_case_5_in2 = false;
									}
									ghi_file_quan(ad.quan_li_ds_hang_hoa);
								}
								break;
							}
							// ma nhap vao khong khop voi ma trong danh sach
							else if (tim_ma_hh != ad.quan_li_ds_hang_hoa.ds_quan[i].ma_hh && i == (ad.quan_li_ds_hang_hoa.ds_quan.size() - 1))
							{
								cout << "Ma khong khop hoac khong co trong danh sach!\n";
								system("pause");
							}
						}
					}
					break;

					break;
				}
				case 7:
				{
					
					
					cout << "Da xong!";
					break;
				}
				case 0: 
				{
					check_case = false;
					break;
				}
				}
			}
			break;
		}
		case 3: // hoa don
		{
			while (check_case == true)
			{
				system("cls");
				cout << "\n1. Nhap hoa don.";
				cout << "\n2. Hien thi hoa don nhap.";
				cout << "\n3. Hien thi hoa don ban.";
				cout << "\n4. Sua hoa don.";
				cout << "\n5. Xoa hoa don.";
				cout << "\n6. Thoat.";
				do 
				{
					cout << "\nNhap lua chon: ";
					getline(cin, chon);
					while_so(chon);
					luaChon = stoi(chon);
				} while (luaChon < 0 || luaChon > 7);
				switch (luaChon) 
				{
				case 1:
				{
					//  k nhap size van ok
					nhapHoaDon(c, ad);
					if (c.ma_hoa_don[0] == 'X')
					{
						them_cuoi_ds_hoa_don(ad.quan_li_ds_hoa_don_xuat, c);
						ad.quan_li_ds_hoa_don_xuat.sl++;
						
					}
					else if (c.ma_hoa_don[0] == 'N')
					{
						them_cuoi_ds_hoa_don(ad.quan_li_ds_hoa_don_nhap, c);
						ad.quan_li_ds_hoa_don_nhap.sl++;
					}
					break;
				}
				case 2: 
				{
					xuat_ds_hoa_don_nhap_hang(ad.quan_li_ds_hoa_don_nhap);
					system("pause");
					break;
				}
				case 3: 
				{
					xuat_ds_hoa_don_ban_hang(ad.quan_li_ds_hoa_don_xuat);
					system("pause");
					break;
				}
				case 4:
				{
					sua_thong_tin_hoa_don(ad);
					cout << "Da xong!\n";
					break;
				}
				case 5:
				{
					string ma_hoa_don;
					do 
					{
						cout << "Nhap ma hoa don can xoa: ";
						getline(cin, ma_hoa_don);
					} while (ma_hoa_don.length() > 4 || ma_hoa_don[0] != 'X' || ma_hoa_don[0] != 'N');
					if (ma_hoa_don[0] == 'X')
					{
						xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_xuat, ma_hoa_don);
						ad.quan_li_ds_hoa_don_xuat.sl--;
					}
					else if (ma_hoa_don[0] == 'N')
					{
						xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_nhap, ma_hoa_don);
						ad.quan_li_ds_hoa_don_nhap.sl--;
					}

					break;
				}
				case 6: 
				{
					check_case = false;
					break;
				}
				}
			}
			break;
		}
		case 4: // thong ke 
		{
			thong_ke_hoa_don(ad);
			break;
		}
		case 5: // hang cho
		{
			while (check_case == true)
			{
				cout << "1. Xuat don hang cho.\n";
				cout << "2. Xu ly.\n";
				cout << "0. Thoat.\n";
				do
				{
					cout << "\nNhap lua chon: ";
					getline(cin, chon);
					while_so(chon);
					luaChon = stoi(chon);
					cout << endl;
				} while (luaChon < 0 || luaChon > 4);
				if (luaChon == 1)
				{
					xuat_ds_don_hang_cho(ad.quan_li_don_hang_cho);
					system("pause");
				}
				else if (luaChon == 2)
				{
					xu_ly_don_hang_cho(ad);
				}
				else if (luaChon == 0)
				{
					check_case = false;
				}
			}
			break;
		}
		case 6: // hang tra
		{
			while (check_case == true)
			{
				cout << "1. Xuat don hang tra.\n";
				cout << "2. Xu ly.\n";
				cout << "0. Thoat.\n";
				do
				{
					cout << "\nNhap lua chon: ";
					getline(cin, chon);
					while_so(chon);
					luaChon = stoi(chon);
					cout << endl;
				} while (luaChon < 0 || luaChon > 4);
				if (luaChon == 1)
				{
					xuat_ds_don_hang_tra(ad);
					system("pause");
				}
				else if (luaChon == 2)
				{
					xac_nhan_da_nhan_hang_tra(ad);
				}
				else if (luaChon == 0)
				{
					check_case = false;
				}
			}

			break;
		}
		case 7: // danh sach xóa
		{
			while (check_case == true)
			{
				system("cls");
				cout << "\n1. Danh sach khach hang xoa.";
				cout << "\n2. Danh sach hang hoa xoa.";
				cout << "\n3. Danh sach hoa don xoa.";
				cout << "\n0. Thoat.";
				do
				{
					cout << "\nNhap lua chon: ";
					getline(cin, chon);
					while_so(chon);
					luaChon = stoi(chon);
					cout << endl;
				} while (luaChon < 0 || luaChon > 4);
				switch (luaChon)
				{
				case 1:
				{
					xuat_thong_tin_khach_hang_xoa(ad.quan_li_kh_xoa.t);
					break;
				}
				case 2:
				{
					xuat_thong_tin_hh_xoa(ad.quan_li_hh_xoa);
					break;
				}
				case 3:
				{
					bool check_3_in_case = true;
					while (check_3_in_case == true)
					{
						system("cls");
						cout << "\n1. Hoa don nhap.";
						cout << "\n2. Hoa don xuat.";
						cout << "\n0. Thoat.";
						do
						{
							cout << "\nNhap lua chon: ";
							getline(cin, chon);
							while_so(chon);
							luaChon = stoi(chon);
							cout << endl;
						} while (luaChon < 0 || luaChon > 4);
						switch (luaChon)
						{
						case 1:
						{
							xuat_ds_hoa_don_nhap_hang_xoa(ad.quan_li_hd_nhap_xoa);
							break;
						}
						case 2:
						{
							xuat_ds_hoa_don_ban_hang_xoa(ad.quan_li_hd_xuat_xoa);
							break;
						}
						case 0:
						{
							check_3_in_case = false;
							break;
						}
						}
					}
					break;
				}
				case 0:
				{
					check_case = false;
					break;
				}
				}
			}
			break;
		}
		case 0:
		{
			check = false;
			return;
		}

		}
	}
}

void menuKH(Admin ad, string makh)
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

void dang_nhap_user(Admin ad, string makh)
{
	string username;
	string password;
	cout << "Nhap tai khoan:";
	getline(cin, username);
	cout << "Nhap mat khau: ";
	getline(cin, password);
	while (check_dinh_dang_tk(username) == false || password == "\0" || username == "\0" || check_tk_mk(username, password, ad.quan_li_ds_kh.t, makh) == false)
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
				int  c = 0;
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
