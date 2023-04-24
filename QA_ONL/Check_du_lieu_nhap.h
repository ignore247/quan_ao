#pragma once

#include "ctdl.h"

void chuanHoa(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a.back() == ' ')
	{
		a.pop_back();
	}
	int n = a.length();
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i);
			i--;
			n--;
		}
	}

	for (int i = 0; i < n; i++)
	{
		a[i] = tolower(a[i]);
	}

	a[0] = toupper(a[0]);

	for (int i = 1; i < n; i++)
	{
		if (a[i] == ' ')
		{
			a[i + 1] = toupper(a[i + 1]);
			i++;
		}
	}
}

void chuan_hoa_tg(string& date)
{
	if (date[2] != '/') date.insert(date.begin(), '0');
	if (date[5] != '/') date.insert(date.begin() + 3, '0');
}

string thoiGianThuc(string& s) {
	// tra ve date/time hien tai dua tren system hien tai 
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	// in cac thanh phan cua cau truc tm struct. 
	/*cout << "Nam: " << 1900 + ltm->tm_year << endl;
	cout << "Thang: " << 1 + ltm->tm_mon << endl;
	cout << "Ngay: " << ltm->tm_mday << endl;*/

	s = to_string(ltm->tm_mday) + '/' + to_string(1 + ltm->tm_mon) + '/' + to_string(1900 + ltm->tm_year);
	chuan_hoa_tg(s);
	return s;
}

int kt_trung_ma_hh(string a, DS_Hang_Hoa b)
{
	int check = -1;
	for (int i = 0; i < b.ds_ao.size(); i++)
	{
		if (b.ds_ao.at(i).ma_hh.substr(1, 4) == a)
		{
			check = i;
			return check;
		}
	}
	for (int i = 0; i < b.ds_quan.size(); i++)
	{
		if (b.ds_quan.at(i).ma_hh.substr(1, 4) == a)
		{
			check = i;
			return check;
		}
	}
	return check;
}

int check_ma_hh(string a, DS_Hang_Hoa b)
{
	int check = -1;
	for (int i = 0; i < b.ds_ao.size(); i++)
	{
		if (b.ds_ao.at(i).ma_hh == a)
		{
			check = i;
			return check;
		}
	}
	for (int i = 0; i < b.ds_quan.size(); i++)
	{
		if (b.ds_quan.at(i).ma_hh == a)
		{
			check = i;
			return check;
		}
	}
	return check;
}

string tao_ma_hang_hoa(DS_Hang_Hoa b)
{
	string a = "0000";
	do
	{
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48; // 0 -> 9 : 48 -> 57 (mã ascii)
		}
	} while (kt_trung_ma_hh(a, b) > -1);

	return a;
}

int kt_trung_ma_hd(string a, ds_hoa_don b)
{
	int check = -1;
	int i = 0;
	for (node_hoa_don* k = b.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.ma_hoa_don.substr(1, 4) == a)
		{
			check = i;
			return check;
		}
		i++;
	}
	return check;
}




string tao_ma_hoa_don(ds_hoa_don b) {
	string a = "0000";
	do {
		for (int i = 0; i < a.length(); i++) {
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung_ma_hd(a, b) > -1);
	return a;
}

void check_Ma_Hang_Hoa(string& a)
{
	regex check_ma("([QqAa])");
	while (regex_match(a, check_ma) == false)
	{
		cout << "Nhap ma hang hoa (Q/A): "; cin >> a;
	}
}
void check_Ten(string& a)
{
	regex check_ten("^[^0-9]+$"); // ( ^ sau ngoặc [ là phủ định)
	while (regex_match(a, check_ten) == false)
	{
		cout << "Nhap ten hang hoa: "; getline(cin, a);
	}
}
void check_Size(string& a) {
	if (a[0] == 'A') {
		regex check_size_ao("([SsMmLl])");
		while (regex_match(a, check_size_ao) == false) {
			cout << "Nhap size: "; cin >> a;
		}
	}
	if (a[0] == 'Q')
	{
		regex check_size_quan("(26|27|28|29|30|31|32|33|34|35|36)");

		while (regex_match(a, check_size_quan) == false)
		{
			cout << "Nhap size: "; cin >> a;
		}

	}
}
void check_So(string& a) {
	regex check_gia("^[0-9]+$");
	while (regex_match(a, check_gia) == false || a == "0") {
		cout << "Gia: "; cin >> a;
	}
}
void check_Loai_Hoa_Don(string& a) {
	regex check_ma("(Nhap|Xuat)");
	while (regex_match(a, check_ma) == false)
	{
		cout << "Nhap loai hoa don: "; cin >> a;
		chuanHoa(a);
	}
}
void check_PTTT(string& a) {
	regex check_pttt("(Cod|Bank)");
	while (regex_match(a, check_pttt) == false) {
		cout << "Nhap phuong thuc thanh toan (Cod/Bank): "; cin >> a;
		chuanHoa(a);
	}
}
void check_Sdt(string& a) {
	regex check_sdt("^(0[3-9][0-9]{8})$");
	while (regex_match(a, check_sdt) == false) {
		cout << "Nhap so dien thoai: "; cin >> a;
	}
}
void check_email(string& a) {
	regex check_email("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9._]+\.[a-zA-Z]{2,}$");
	while (regex_match(a, check_email) == false) {
		cout << "Nhap email:"; cin >> a;
	}
}

// Hàm kiểm tra mã khách hàng trùng
int kt_trung_ma_kh(string a, TREE t) {
	int check = -1;
	int i = 0;
	if (t != NULL) {
		if (t->data.maKh.substr(2, 4) == a) {
			check = i;
			return check;
		}
		i++;
		kt_trung_ma_kh(a, t->pLeft);
		kt_trung_ma_kh(a, t->pRight);
	}
	return check;
}

int check_ma_kh(string a, TREE t)
{
	int check = -1;
	int i = 0;
	if (t != NULL) {
		if (t->data.maKh == a)
		{
			check = i;
			return check;
		}
		i++;
		kt_trung_ma_kh(a, t->pLeft);
		kt_trung_ma_kh(a, t->pRight);
	}
	return check;
}

// ==========Tạo mã khách hàng==========
string tao_ma_khach_hang(ds_khach_hang b) {
	string a = "0000";
	do
	{
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48; // 0 -> 9 : 48 -> 57 (mã ascii)
		}

	} while (kt_trung_ma_kh(a, b.t) > -1);

	return a;

}
