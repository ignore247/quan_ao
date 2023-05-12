#pragma once
#include "Check_du_lieu_nhap.h"
#include "Xu_li_do_hoa.h"

// ================== Hàng Hóa =====================
void nhapHangHoa(HangHoa& a, DS_Hang_Hoa b)
{
	// mã : Q,A
	cout << "Nhap ma hang hoa (Q/A): "; cin >> a.ma_hh;
	check_Ma_Hang_Hoa(a.ma_hh);
	a.ma_hh = toupper(a.ma_hh[0]);
	//mã hh = mã + số random
	a.ma_hh = a.ma_hh + tao_ma_hang_hoa(b);
	cin.ignore();

	cout << "Nhap ten hang hoa: "; getline(cin, a.ten_hh);
	check_Ten(a.ten_hh);
	chuanHoa(a.ten_hh);

	cout << "Nhap size: "; cin >> a.size;
	check_Size(a.size);

	regex check_gia("^[0-9]+$");
	string tam;
	cout << "Gia: "; cin >> tam;
	check_So(tam);
	a.gia = stoll(tam);
	cin.ignore();

	cout << "Nhap mo ta san pham: "; getline(cin, a.mo_ta_sp);
	// mô tả k cần nhập kích thước chi tiết vì đã kẻ bảng


	cout << "Nhap so luong trong kho: "; cin >> tam;
	check_So(tam);
	a.soLuongTonKho = stoi(tam);
	// thời  gian nhập hàng : lấy thời gian máy tính
	a.thoi_gian_nhap_hang = thoiGianThuc(a.thoi_gian_nhap_hang);
}

void xuat_tt_hh_ngan_gon(HangHoa a)
{
	cout << "Ma hang hoa: " << a.ma_hh << endl;
	cout << "Ten hang hoa: " << a.ten_hh << endl;
	cout << "Gia: " << a.gia << endl;
	cout << "Size: " << a.size << endl;
	cout << "So luong con trong kho: " << a.soLuongTonKho << endl;
}
 
void xuat_thong_tin_quan(DS_Hang_Hoa dshh) 
{
	for (int i = 0; i < dshh.ds_quan.size(); i++)
	{
		xuat_tt_hh_ngan_gon(dshh.ds_quan.at(i));
	}
}

void xuat_thong_tin_ao(DS_Hang_Hoa dshh) 
{
	for (int i = 0; i < dshh.ds_quan.size(); i++) 
	{
		xuat_tt_hh_ngan_gon(dshh.ds_ao.at(i));
	}
}

//=================== Hóa Đơn =========================
void nhapHoaDon(HoaDon& a, ds_hoa_don b, DS_Hang_Hoa c, ds_khach_hang d)
{
	string loai_hd;
	cout << "Nhap loai hoa don (Xuat/Nhap) : "; cin >> loai_hd; // cho nhập Xuat / Nhap
	chuanHoa(loai_hd);
	check_Loai_Hoa_Don(loai_hd);
	if (loai_hd == "Xuat")
	{
		a.ma_hoa_don = 'X';
	}
	else
	{
		a.ma_hoa_don = 'N';
	}
	a.ma_hoa_don = a.ma_hoa_don + tao_ma_hoa_don(b);
	if (loai_hd == "Xuat")
	{
		long long tien;
		cout << "Nhap ma khach hang: ";
		cin >> a.ma_kh;
		a.ma_kh[0] = toupper(a.ma_kh[0]);
		a.ma_kh[1] = toupper(a.ma_kh[1]);
		// ktra mã khách hàng xem có tồn tại không
		while (true)
		{
			if (check_ma_kh(a.ma_kh, d.t) == 0)
			{
				cout << "Khach hang khong ton tai!";
				cout << "\nNhap ma khach hang: ";
				cin >> a.ma_kh;
				a.ma_kh[0] = toupper(a.ma_kh[0]);
				a.ma_kh[1] = toupper(a.ma_kh[1]);
			}
			else
			{
				break;
			}
		}
		cout << "Nhap ma hang hoa: "; cin >> a.ma_hang_hoa;
		a.ma_hang_hoa[0] = toupper(a.ma_hang_hoa[0]);
		// ktra hh có tồn tại hay không 
		while (true)
		{
			if (check_ma_hh(a.ma_hang_hoa, c) == -1)
			{
				cout << "Hang hao khong ton tai!";
				cout << "\nNhap ma hang hoa: ";
				cin >> a.ma_kh;
				a.ma_hang_hoa[0] = toupper(a.ma_hang_hoa[0]);
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < c.ds_ao.size(); i++)
		{
			if (a.ma_hang_hoa == c.ds_ao.at(i).ma_hh)
			{
				tien = c.ds_ao.at(i).gia;
				a.thong_tin_hang.ten_hh = c.ds_ao.at(i).ten_hh ;
				a.thong_tin_hang.gia = c.ds_ao.at(i).gia ;
				a.thong_tin_hang.size = c.ds_ao.at(i).size;
				break;
			}
		}
		for (int i = 0; i < c.ds_quan.size(); i++)
		{
			if (a.ma_hang_hoa == c.ds_quan.at(i).ma_hh)
			{
				tien = c.ds_ao.at(i).gia;
				a.thong_tin_hang.ten_hh = c.ds_ao.at(i).ten_hh;
				a.thong_tin_hang.gia = c.ds_ao.at(i).gia;
				a.thong_tin_hang.size = c.ds_ao.at(i).size;
				break;
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
	}
	else
	{
		cout << "Nhap ma hang hoa (Q/A): "; cin >> a.ma_hang_hoa;
		check_Ma_Hang_Hoa(a.ma_hang_hoa);
		cin.ignore();
		a.thong_tin_hang.ma_hh = a.thong_tin_hang.ma_hh + tao_ma_hang_hoa(c);
		cout << "Nhap ten hang hoa: ";
		getline(cin, a.thong_tin_hang.ten_hh);
		chuanHoa(a.thong_tin_hang.ten_hh);
		check_Ten(a.thong_tin_hang.ten_hh);
		cout << "Nhap size: ";
		cin >> a.thong_tin_hang.size;
		check_Size(a.thong_tin_hang.size);
		a.thong_tin_hang.size[0] = toupper(a.thong_tin_hang.size[0]);
		string gia;
		cout << "Nhap gia: ";
		cin >> gia;
		check_So(gia);
		a.gia_nhap = stoll(gia);
	}
	string tam;
	cout << "Nhap so luong mua: "; cin >> tam;
	check_So(tam);
	a.sl_mua = stoi(tam);

	cout << "Nhap phuong thuc thanh toan( Cod/Bank ): "; cin >> a.pptt;
	chuanHoa(a.pptt);
	check_PTTT(a.pptt);

	// ngày lập hóa đơn : lấy thời gian máy tính
	thoiGianThuc(a.ngay_lap_hd);
	chuan_hoa_tg(a.ngay_lap_hd);
	cin.ignore();
	cout << "Trang thai: ";
	getline(cin, a.trang_thai);
}

void taoHoaDonKhiKhachDatHang(HoaDon& a, ds_hoa_don b, HangHoa c)
{
	a.ma_hoa_don = 'X' + tao_ma_hoa_don(b);
	a.ma_hang_hoa = c.ma_hh;
	cout << "Nhap so luong mua: "; cin >> a.sl_mua;
	cout << "Nhap phuong thuc thanh toan( COD/Bank ): "; cin >> a.pptt;
	// ngày lập hóa đơn : lấy thời gian máy tính
	thoiGianThuc(a.ngay_lap_hd);
}

void xuatHoaDonBanHang(HoaDon a, DS_Hang_Hoa c)
{
	cout << "Ma hoa don: " << a.ma_hoa_don << endl;
	cout << "Ma khach hang: " << a.ma_kh << endl;
	cout << "\tThong tin hang hoa: " << endl;
	cout << "Ma hang hoa: " << a.ma_hang_hoa << endl;
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh << endl;
	cout << "Gia: " << a.thong_tin_hang.gia << endl;
	cout << "Size: " << a.thong_tin_hang.size << endl;
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
	cout << "Gia duoc giam: " << a.giam_gia_theo_hang << endl;
	cout << "Tong tien: " << a.tong_tien << endl;
	cout << "Trang thai: " << a.trang_thai << endl;
	cout << "\n\t\t=============\n";
}

void xuatHoaDonNhapHang(HoaDon a)
{
	cout << "Ma hoa don: " << a.ma_hoa_don << endl;
	cout << "Thong tin hang hoa: " << endl;
	cout << "Ma hang hoa: " << a.thong_tin_hang.ma_hh << endl;
	cout << "Ten hang hoa: " << a.thong_tin_hang.ten_hh << endl;
	cout << "Gia: " << a.thong_tin_hang.gia << endl;
	cout << "Size: " << a.thong_tin_hang.size << endl;
	cout << "So luong mua: " << a.sl_mua << endl;
	cout << "Ngay lap hoa don: " << a.ngay_lap_hd << endl;
	a.tong_tien = (a.thong_tin_hang.gia * a.sl_mua);
	cout << "Tong tien: " << a.tong_tien << endl;
	cout << "Trang thai: " << a.trang_thai << endl;
}

node_hoa_don* khoi_tao_node_hoa_don(HoaDon a)
{
	node_hoa_don* p = new node_hoa_don;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat";
		return NULL;
	}
	p->data = a;
	p->pNext = NULL;
	return p;
}

void them_cuoi_ds_hoa_don(DS_HOA_DON& a, HoaDon x)
{
	node_hoa_don* p = khoi_tao_node_hoa_don(x);
	if (a.pHead == NULL)
	{
		a.pHead = a.pTail = p;
	}
	else
	{
		a.pTail->pNext = p;
		a.pTail = p;
	}
}

void xoa_hd_theo_ma(DS_HOA_DON& a, string b)
{
	node_hoa_don* h = NULL;
	for (node_hoa_don* k = a.pHead; k != NULL;)
	{
		// vt nằm ở đầu danh sách
		if (k->data.ma_hoa_don == b && k == a.pHead)
		{
			a.pHead = a.pHead->pNext;
			delete k;
			k = a.pHead;
		}
		else
		{
			// xoá vị trí bất kì(ko ở đầu)
			if (k->data.ma_hoa_don == b)
			{
				h->pNext = k->pNext;
				delete k;
				k = h;
				// sau khi xoá vt nằm ở cuối
				if (h->pNext == NULL) 
				{
					a.pTail = h;
					return;
				}
			}
			h = k;
			k = k->pNext;
		}
	}
	a.sl--;
}

// ============== Sửa thông tin hóa đơn ==================
void duyet_cay_sua_thong_tin(TREE& t,string ma_hd_sua, string ma_kh, string a)
{
	if (t != NULL)
	{
		if (ma_kh == t->data.maKh)
		{
			for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
			{
				if (k->data.ma_hoa_don == ma_hd_sua)
				{
					k->data.ma_hang_hoa = a;
					return;
				}
			}
		}
		if (stoi(ma_kh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin(t->pLeft, ma_hd_sua, ma_kh, a);
		}
		else if (stoi(ma_kh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_sua_thong_tin(t->pRight, ma_hd_sua, ma_kh, a);
		}
	}
}

void duyet_cay_xoa_hd_theo_ma(TREE& t, string ma_kh_cu, string ma_hoa_don)
{
	if (t != NULL)
	{
		if (t->data.maKh == ma_kh_cu)
		{
			xoa_hd_theo_ma(t->data.don_mua_hang, ma_hoa_don);
			return;
		}
		if (stoi(ma_kh_cu.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_xoa_hd_theo_ma(t->pLeft, ma_kh_cu, ma_hoa_don);
		}
		else if (stoi(ma_kh_cu.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_xoa_hd_theo_ma(t->pRight, ma_kh_cu, ma_hoa_don);
		}
	}
}

void duyet_cay_them_hd(TREE& t, string ma_moi, HoaDon a)
{
	if (t != NULL)
	{
		if (t->data.maKh == ma_moi)
		{
			them_cuoi_ds_hoa_don(t->data.don_mua_hang, a);
			t->data.don_mua_hang.sl++;
			return;
		}
		if (stoi(ma_moi.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_them_hd(t->pLeft, ma_moi, a);
		}
		else if (stoi(ma_moi.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			duyet_cay_them_hd(t->pRight, ma_moi, a);
		}
	}
}

void xep_hang_khach_hang_theo_tien(TREE &t)
{
	long long tong_tien_da_tieu = 0;
	if (t != NULL)
	{
		xep_hang_khach_hang_theo_tien(t->pLeft);
		for (node_hoa_don* k = t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
		{
			tong_tien_da_tieu = tong_tien_da_tieu + k->data.tong_tien;
		}
		if (tong_tien_da_tieu <= 500000)
		{
			t->data.maKh.replace(0, 2, "SA");
			tong_tien_da_tieu = 0;
		}
		else if (tong_tien_da_tieu > 500000 && tong_tien_da_tieu <= 1000000) {
			t->data.maKh.replace(0, 2, "DO");
			tong_tien_da_tieu = 0;
		}
		else if (tong_tien_da_tieu > 1000000 && tong_tien_da_tieu <= 2000000) {
			t->data.maKh.replace(0, 2, "BA");
			tong_tien_da_tieu = 0;
		}
		else if (tong_tien_da_tieu > 2000000 && tong_tien_da_tieu <= 5000000) {
			t->data.maKh.replace(0, 2, "VA");
			tong_tien_da_tieu = 0;
		}
		else
		{
			t->data.maKh.replace(0, 2, "KC");
			tong_tien_da_tieu = 0;
		}
		xep_hang_khach_hang_theo_tien(t->pRight);
	}

}

void sua_thong_tin_hoa_don(Admin &ad)
{
	string b,tam;
	int c;
	regex ktra_nhap(R"(\d)");
	bool check = true;
	cout << "Nhap ma hoa don muon sua: ";
	cin >> b;
	b[0] = toupper(b[0]);
	while (check_trung_ma_hd(b,ad.quan_li_ds_hoa_don_nhap) == -1 || check_trung_ma_hd(b, ad.quan_li_ds_hoa_don_xuat) == -1)
	{
		cout << "Ma hoa don khong ton tai!";
		cout << "Nhap ma hoa don muon sua: ";
		cin >> b;
	}
	if (b[0] == 'N')
	{
		while (check == true)
		{
			cout << "\n1.Sua ngay lap hoa don" << endl;
			cout << "2.Sua trang thai cua hoa don" << endl;
			cout << "3.Xoa hoa don";
			cout << "\n0.Thoat";
			
			cout << "Chon loai thong tin muon sua: ";
			cin >> tam;
			
			do
			{
				if (regex_match(tam, ktra_nhap) == false || stoi(tam) < 0 || stoi(tam) > 3)
				{
					cout << "Lua chon khong hop le!\n";
					cout << "Chon loai thong tin muon sua: ";
					cin >> tam;
				}
				else
				{
					c = stoi(tam);
					break;
				}
			} while (true);
				
			switch (c)
			{
				case 1:
				{
					string str;
					cout << "Nhap ngay lap hoa don: ";
					cin >> str;
					do
					{
						if (check_date(str) == false)
						{
							cout << "Ngay thang nhap khong hop le!\n";
							cout << "Nhap ngay lap hoa don: ";
							cin >> str;
						}
						else
						{
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
					break;
				}
				case 2:
				{
					string str;
					cout << "Nhap trang thai moi cua hoa don: ";
					cin >> str;
					for (node_hoa_don* k = ad.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
					{
						if (k->data.ma_hoa_don == b)
						{
							k->data.trang_thai = str;
							break;
						}
					}
					break;
				}
				case 3:
				{
					xoa_hd_theo_ma(ad.quan_li_ds_hoa_don_nhap, b);
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
	else
	{
		while (check == true)
		{
			cout << "\n1.Sua ma hang hoa" << endl;
			cout << "2.Sua ma hang Khach hang" << endl;
			cout << "3.Sua ngay lap hoa don" << endl;
			cout << "4.Sua trang thai cua hoa don" << endl;
			cout << "5.Xoa hoa don" << endl;
			cout << "\n0.Thoat";
			cout << "Chon loai thong tin muon sua: ";
			cin >> tam;

			do
			{
				if (regex_match(tam, ktra_nhap) == false || stoi(tam) < 0 || stoi(tam) > 5)
				{
					cout << "Lua chon khong hop le!\n";
					cout << "Chon loai thong tin muon sua: ";
					cin >> tam;
				}
				else
				{
					c = stoi(tam);
					break;
				}
			} while (true);

			switch (c)
			{
			case 1:
			{
				string str;
				cout << "Nhap ma hang hoa : ";
				cin >> str;
				str[0] = toupper(str[0]);
				do
				{
					if (check_ma_hh(str, ad.quan_li_ds_hang_hoa) == -1)
					{
						cout << "Hang hoa khong ton tai!\n";
						cout << "Nhap ma hang hoa: ";
						cin >> str;
						str[0] = toupper(str[0]);
					}
					else
					{
						break;
					}
				} while (true);

				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_sua_thong_tin(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						k->data.ma_hang_hoa = str;
						break;
					}
				}
				break;
			}
			case 2:
			{
				string str,ma_cu;
				cout << "Nhap ma khach hang muon sua: ";
				cin >> str;
				str[0] = toupper(str[0]);
				str[1] = toupper(str[1]);
				do
				{
					if (check_ma_kh(str,ad.quan_li_ds_kh.t) == 0)
					{
						cout << "Khach hang khong ton tai!" << endl;
						cout << "Nhap ma khach hang muon sua: ";
						cin >> str;
						str[0] = toupper(str[0]);
						str[1] = toupper(str[1]);
					}
					else
					{
						break;
					}
				} while (true);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_xoa_hd_theo_ma(ad.quan_li_ds_kh.t, k->data.ma_kh,b);
						k->data.ma_kh = str;
						duyet_cay_them_hd(ad.quan_li_ds_kh.t,str,k->data);
						break;
					}
				}
				xep_hang_khach_hang_theo_tien(ad.quan_li_ds_kh.t);
				break;
			}
			case 3:
			{
				string str;
				cout << "Nhap ngay lap hoa don: ";
				cin >> str;
				do
				{
					if (check_date(str) == false)
					{
						cout << "Ngay thang nhap khong hop le!\n";
						cout << "Nhap ngay lap hoa don: ";
						cin >> str;
					}
					else
					{
						break;
					}
				} while (true);
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						k->data.ngay_lap_hd = str;
						duyet_cay_sua_thong_tin(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						break;
					}
				}
				break;
			}
			case 4:
			{
				string str;
				cout << "Nhap trang thai moi cua hoa don: ";
				cin >> str;
				for (node_hoa_don* k = ad.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
				{
					if (k->data.ma_hoa_don == b)
					{
						duyet_cay_sua_thong_tin(ad.quan_li_ds_kh.t, b, k->data.ma_kh, str);
						k->data.trang_thai = str;
						break;
					}
				}
				break;
			}
			case 5:
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
}

// ================== Khách Hàng ==========================
istream& operator >> (istream& in, KhachHang& a)
{
	// mã : SA (mặc định nếu là acc mới tạo) DO / BA / VA / KC
	/*ds_kh b;
	a.maKh = "SA";
	a.maKh = a.maKh + tao_ma_khach_hang(b);*/ // sai r ddcm m BARO
	// mã kh = mã + số random (tách chuỗi số thành số)
	cout << "Nhap ten: "; getline(in, a.ten);
	check_Ten(a.ten);

	cout << "Nhap dia chi: "; getline(in, a.diaChi);
	in.ignore();
	cout << "Nhap so dien thoai: "; in >> a.sdt;// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	check_Sdt(a.sdt);
	cout << "Nhap email: "; in >> a.email;//example@gmail.com
	check_email(a.email);

	return in;
}

ostream& operator << (ostream& out, KhachHang a)
{
	out << "Ma khach hang: " << a.maKh << endl;
	out << "Ten khach hang: " << a.ten << endl;
	out << "Dia chi :" << a.diaChi << endl;
	out << "SDT: " << a.sdt << endl;
	out << "Email: " << a.email << endl;
	return out;
}

void nhap_khach_hang(KhachHang& a, Admin b)
{
	// mã : SA (mặc định nếu là acc mới tạo) DO / BA / VA / KC
	a.maKh = "SA";
	a.maKh = a.maKh + tao_ma_khach_hang(b.quan_li_ds_kh);
	// mã kh = mã + số random (tách chuỗi số thành số)
	cout << "Nhap ten: "; getline(cin, a.ten);
	check_Ten(a.ten);
	cout << "Nhap dia chi: "; getline(cin, a.diaChi);
	cin.ignore();
	cout << "Nhap so dien thoai: "; cin >> a.sdt;// số đầu tiên là số 0, số thứ 2 là 3-9, 8 số còn lại 0-9
	check_Sdt(a.sdt);
	cout << "Nhap email: "; cin >> a.email;//example@gmail.com
	check_email(a.email);
}

void them_khachhang_vao_cay(TREE &t, KH data) {
	if (t == NULL) {
		node_kh* p = new node_kh;
		p->data = data;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else if (t != NULL) {
		if (stoi(data.maKh.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4))) {
			them_khachhang_vao_cay(t->pLeft, data);
		}
		else if (stoi(data.maKh.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4))) {
			them_khachhang_vao_cay(t->pRight, data);
		}
	}
}

// ========================= GIO HANG ========================== 
node_gio_hang* khoiTao_node_gio_hang(gio_hang a) {
	node_gio_hang* p = new node_gio_hang;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat" << endl;
		return NULL;
	}
	p->data = a;
	p->pNext = NULL;
	return p;
}
 
void ThemVaoDau_DanhSach_GioHang(ds_hh_trong_gio_hang& ds_gh, gio_hang a) {
	// danh sach rong 
	node_gio_hang* p = khoiTao_node_gio_hang(a);
	if (ds_gh.pHead == NULL) {
		ds_gh.pHead = ds_gh.pTail = p;
	}
	else {
		p->pNext = ds_gh.pHead;
		ds_gh.pHead = p;
	}
}
 
void Xoa_hangHoa_ViTriBatKi(ds_hh_trong_gio_hang& ds_gh, string vt)
{
	node_gio_hang* h = NULL;
	for (node_gio_hang* k = ds_gh.pHead; k != NULL;)
	{
		// vt nằm ở đầu danh sách
		if (k->data.data.ma_hh == vt && k == ds_gh.pHead)
		{
			ds_gh.pHead = ds_gh.pHead->pNext;
			delete k;
			k = ds_gh.pHead;
		}
		else
		{
			// xoá vị trí bất kì(ko ở đầu)
			if (k->data.data.ma_hh == vt)
			{
				h->pNext = k->pNext;
				delete k;
				k = h;
				// sau khi xoá vt nằm ở cuối
				if (h->pNext == NULL) {
					ds_gh.pTail = h;
					return;
				}
			}
			h = k;
			k = k->pNext;
		}
	}
}

void XuatGioHang(ds_hh_trong_gio_hang l,HangHoa a)
{
	for (node_gio_hang* k = l.pHead; k != NULL; k = k->pNext) 
	{
		xuat_tt_hh_ngan_gon(k->data.data);
	}
}

// =================== Xóa cây ================================
void node_the_mang(node_kh*& k, TREE& t)
{
	if (k->pRight == NULL)
	{
		t->data = k->data;
		node_kh* tam = k;
		k = k->pLeft; // đưa node hoặc null lên
		delete tam;
	}
	else
	{
		node_the_mang(k->pRight, t);
	}
}

void xoa_khach_hang_theo_ma(TREE &t, string a)
{
	if (t != NULL)
	{
		if (t->data.maKh == a)
		{
			//--- xoá ----
			if (t->pRight != NULL && t->pLeft != NULL)//2 con
			{
				node_the_mang(t->pLeft, t);
			}
			else if (t->pLeft == NULL && t->pRight == NULL)  //la
			{
				delete t;
				t = NULL;
			}
			else  //1 con
			{
				node_kh* tam = t;
				if (t->pLeft != NULL)
				{
					t = t->pLeft;
				}
				else if (t->pRight != NULL)
				{
					t = t->pRight;
				}

				delete tam;
			}
		}
		else if (stoi (a.substr(2,4) ) > stoi(t->data.maKh.substr(2,4)))
		{
			xoa_khach_hang_theo_ma(t->pRight, a);
		}
		else
		{
			xoa_khach_hang_theo_ma(t->pLeft, a);
		}
	}
}

// =================== Cân bằng cây ===========================
int tim_chieu_cao_cay(TREE t) // kiểm tra node con xem ai lớn hơn thì trả về thằng lớn hơn
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		int h_trai = tim_chieu_cao_cay(t->pLeft);
		int h_phai = tim_chieu_cao_cay(t->pRight);
		return (h_phai > h_trai) ? 1 + h_phai : 1 + h_trai;
	}
}

bool kt_lech_p(TREE t, char& checkp)
{
	int h_trai = tim_chieu_cao_cay(t->pLeft);
	int h_phai = tim_chieu_cao_cay(t->pRight);
	int x = h_trai - h_phai;

	if (x >= -1 && x <= 1) // lệch không quá 1 tầng
	{
		return false; // cây đã cân bằng
	}
	else
	{
		checkp = (h_trai > h_phai) ? 'L' : 'R';
		return true; // cây mất cân bằng
	}
}

char kt_lech_q(TREE t, char checkp)
{
	int h_trai = tim_chieu_cao_cay(t->pLeft);
	int h_phai = tim_chieu_cao_cay(t->pRight);

	if (h_trai > h_phai) // Lệch trái
	{
		return 'L';
	}
	else if (h_trai < h_phai)
	{
		return 'R';
	}
	else // bằng => chọn 1 trong 2 => chon theo p để thành LL / RR
	{
		return checkp;
	}
}

void quay_phai(TREE& p, TREE& q)
{
	// p sẽ làm cây con phải q
	// cây con phải của q sẽ làm cây con trái của p
	node_kh* tam = q->pRight; // cho tam giữ cây con phải của q
	q->pRight = p; // cho cây con phải của q là p
	p->pLeft = tam; // cây con trái của p là tạm
}

void quay_trai(TREE& p, TREE& q)
{
	// p sẽ làm cây con trái q
	// cây con trái của q sẽ làm cây con phải của p
	node_kh* tam = q->pLeft; // cho tam giữ cây con trái của q
	q->pLeft = p; // cho cây con trái của q là p
	p->pRight = tam; // cây con phai của p là tạm
}

void can_bang_cay(TREE& t) // duyệt node left right NLR
{
	if (t != NULL)
	{
		// ------- NODE --------------
		char checkp = '0'; //  tạo giá trị ban đầu khác L , R
		if (kt_lech_p(t, checkp) == true) // cây mất cân bằng
		{
			node_kh* p = t;
			node_kh* q = (checkp == 'L') ? p->pLeft : p->pRight; // kiểm tra p lệch loại gì thì q sẽ là cây con thep hướng đó của p
			char checkq = kt_lech_q(q, checkp); // kiểm qua q là loại gì 

			if (checkp == 'L' && checkq == 'L')
			{
				quay_phai(p, q);
			}
			else if (checkp == 'R' && checkq == 'R')
			{
				quay_trai(p, q);
			}
			else if (checkp == 'L' && checkq == 'R')
			{
				node_kh* tam = q->pRight;
				quay_trai(q, q->pRight);
				q = tam;
				t->pLeft = q;
				can_bang_cay(t);
			}
			else if (checkp == 'R' && checkq == 'L')
			{
				node_kh* tam = q->pLeft;
				quay_trai(q, q->pLeft);
				q = tam;
				t->pRight = q;
				can_bang_cay(t);
			}
			t = q;
		}
		// ------------ Left----------------
		can_bang_cay(t->pLeft);
		// -------------Right---------------
		can_bang_cay(t->pRight);
	}
}

//void test()
//{
//	Admin a;
//	for (node_hoa_don* k = a.quan_li_ds_hoa_don_xuat.pHead; k != NULL; k = k->pNext)
//	{
//
//	}
//	for (node_hoa_don* k = a.quan_li_ds_hoa_don_nhap.pHead; k != NULL; k = k->pNext)
//	{
//
//	}
//	if (a.quan_li_ds_kh.t != NULL)
//	{
//		for (node_hoa_don* k = a.quan_li_ds_kh.t->data.don_mua_hang.pHead; k != NULL; k = k->pNext)
//		{
//
//		}
//	}
//}
