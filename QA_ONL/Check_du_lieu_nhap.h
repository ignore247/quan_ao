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

void chuan_hoa_ma_kh(string&a)
{
	a[1] = toupper(a[1]);
	a[2] = toupper(a[2]);
}


//========================================================
bool kt_nam_nhuan(string a)
{
	if (stoi(a.substr(6, 4)) % 4 == 0 && stoi(a.substr(6, 4)) % 100 != 0 || stoi(a.substr(6, 4)) % 400 == 0)
	{
		return true;
	}
	else
		return false;
}

bool check_date(string &a)
{
	regex date(R"((\d{1,2})/(\d{1,2})/(\d{4}))");
	if (regex_match(a, date) == false)
	{
		return false;
	}
	chuan_hoa_tg(a);
	if (stoi(a.substr(3, 2)) > 12 || stoi(a.substr(3, 2)) < 0)
	{
		return false;
	}
	if (stoi(a.substr(6, 4)) < 0)
	{
		return false;
	}
	switch (stoi(a.substr(3, 2)))
	{
	case 2:
	{
		if (kt_nam_nhuan(a) == true)
		{
			if (stoi(a.substr(0, 2)) > 29 || stoi(a.substr(0, 2)) < 0)
			{
				return false;
			}
		}
		else
		{
			if (stoi(a.substr(0, 2)) > 28 || stoi(a.substr(0, 2)) < 0)
			{
				return false;
			}
		}
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
		if (stoi(a.substr(0, 2)) > 30 || stoi(a.substr(0, 2)) < 0)
		{
			return false;
		}
		break;
	default:
		if (stoi(a.substr(0, 2)) > 31 || stoi(a.substr(0, 2)) < 0)
		{
			return false;
		}
	}
	return true;
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

int check_trung_ma_hd(string a, ds_hoa_don b)
{
	int check = -1;
	int i = 0;
	for (node_hoa_don* k = b.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.ma_hoa_don == a)
		{
			check = i;
			return check;
		}
		i++;
	}
	return check;
}

string tao_ma_hoa_don(ds_hoa_don b)
{
	string a = "0000";
	do
	{
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_trung_ma_hd(a, b) > -1);
	return a;
}

bool check_Ma_Hang_Hoa(string& a)
{
	regex check_ma("([QqAa])");
	if (regex_match(a, check_ma) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_Ten(string& a)
{
	regex check_ten("^[^0-9]+$"); // ( ^ sau ngoặc [ là phủ định)
	if (regex_match(a, check_ten) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_size_ao(string& a)
{
	regex check_size_ao("([SsMmLl])");
	a[0] = toupper(a[0]);
	if (regex_match(a, check_size_ao) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_size_quan(string& a)
{
	regex check_size_quan("(26|27|28|29|30|31|32|33|34|35|36)");
	if (regex_match(a, check_size_quan) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_So(string& a)
{
	regex check_so("^[0-9]+$");
	if (regex_match(a, check_so) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_Loai_Hoa_Don(string& a)
{
	regex check_ma("(Nhap|Ban)");
	if (regex_match(a, check_ma) == false)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

bool check_PTTT(string& a)
{
	regex check_pttt("(Cod|Bank)");
	if (regex_match(a, check_pttt) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_Sdt(string& a)
{
	regex check_sdt("^(0[3-9][0-9]{8})$");
	if (regex_match(a, check_sdt) == false)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

bool check_email(string& a)
{
	regex check_email("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9._]+\\.[a-zA-Z]{2,}$");
	if (regex_match(a, check_email) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_tk_mk(string a, string b, TREE t, string& makh)
{
	if (t != NULL)
	{
		if (t->data.ten_dang_nhap == a && b == t->data.mat_khau)
		{
			makh = t->data.maKh;
			return true;
		}
		bool l = check_tk_mk(a, b, t->pLeft, makh);
		bool r = check_tk_mk(a, b, t->pRight, makh);
		return l || r;
	}
	else
	{
		return false;
	}
}

bool check_dinh_dang_tk(string a)
{
	regex check_username("^[a-zA-Z0-9@_]+$");
	if (regex_match(a, check_username) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool check_dinh_dang_mk(string a)
{
	regex mat_khau("^[a-zA-Z0-9!@#$%^&*()-=_+]{1,}$");
	if (regex_match(a, mat_khau) == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Hàm kiểm tra mã khách hàng trùng
bool kt_trung_ma_kh(string a, TREE t) 
{
	if (t != NULL) 
	{
		if (stoi(a.substr(2, 4)) == stoi(t->data.maKh.substr(2, 4)))
		{
			return true;
		}
		else if (stoi(a.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return kt_trung_ma_kh(a, t->pLeft);
		}
		else if (stoi(a.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			return kt_trung_ma_kh(a, t->pRight);
		}
	}
	else
	{
		return false;
	}
}

bool check_ma_kh(string a, TREE t)
{
	if (t != NULL)
	{
		if ( a == t->data.maKh)
		{
			return true;
		}
		else if (stoi(a.substr(2, 4)) < stoi(t->data.maKh.substr(2, 4)))
		{
			return check_ma_kh(a, t->pLeft);
		}
		else if (stoi(a.substr(2, 4)) > stoi(t->data.maKh.substr(2, 4)))
		{
			return check_ma_kh(a, t->pRight);
		}
	}
	else
	{
		return false;
	}
}

//==========Tạo mã khách hàng==========
string tao_ma_khach_hang(ds_khach_hang b)
{
	string a = "0000";
	do
	{
		for (int i = 0; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48; // 0 -> 9 : 48 -> 57 (mã ascii)
		}

	} while (kt_trung_ma_kh(a, b.t) == true);
	return a;

}

bool check_dinh_dang_ma_kh(string a)
{
	regex ma_kh(R"([aA-zZ]{2}\d{4})");
	if (regex_match(a, ma_kh) == false)
	{
		return false;
	}
	else {
		return true;
	}
}

bool check_full_maHH(string a)
{

	regex ma_hh(R"((A|Q){1}\d{4})");
	if (regex_match(a, ma_hh) == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool check_trang_thai(string a)
{
	regex trang_thai("(Da Nhan Hang|Chua Nhan Hang)");
	if (regex_match(a, trang_thai) == false)
	{
		return false;
	}
	else {
		return true;
	}
}
//=================================================================
void while_ten(string& a)
{
	chuanHoa(a);
	while (check_Ten(a) == false) {

		cout << "Nhap ten khong phu hop, nhap lai[aA-zZ] :"; getline(cin, a);
		chuanHoa(a);
	}
}

void while_so(string& a)
{
	while (check_So(a) == false)
	{
		cout << "Nhap gia tri so , nhap lai :"; getline(cin, a);
	}
}

void while_Sdt(string& a)
{
	while (check_Sdt(a) == false)
	{
		cout << "Nhap so dien thoai khong hop le,nhap lai:"; getline(cin, a);
	}
}

void  while_ma_hh(string &a)
{
	a[0] = toupper(a[0]);
	while (check_Ma_Hang_Hoa(a) == false)
	{
		cout << "Nhap ma hang hoa chi gom ky tu Q/A:"; getline(cin, a);
		a[0] = toupper(a[0]);
	}
}

void while_size_ao(string& a)
{
	a[0] = toupper(a[0]);
	while (check_size_ao(a) == false)
	{
		cout << "Nhap khong phu hop, nhap lai:"; getline(cin, a);
		a[0] = toupper(a[0]);
	}
}

void while_size_quan(string& a)
{
	while (check_size_quan(a) == false)
	{
		cout << "Nhap khong phu hop, nhap lai:"; getline(cin, a);
	}
}

void while_loai_hd(string &a)
{
	chuanHoa(a);
	while (check_Loai_Hoa_Don(a) == false)
	{
		cout << "Nhap loai hoa don chi co (Ban/Nhap):"; getline(cin, a);
		chuanHoa(a);
	}
}

void while_ma_kh(string& a)
{
	a[0] = toupper(a[0]);
	a[1] = toupper(a[1]);
	while (check_dinh_dang_ma_kh(a) == false)
	{
		cout << "Ma khach hang khong phu hop, nhap lai:"; getline(cin, a); 
		a[0] = toupper(a[0]);
		a[1] = toupper(a[1]);
	}
}

void while_full_ma_hh(string& a)
{
	a[0] = toupper(a[0]);
	while (check_full_maHH(a) == false)
	{
		cout << "Nhap ma hang hoa khong phu hop, nhap lai:"; getline(cin, a);
		a[0] = toupper(a[0]);
	}
}

void while_pttt(string& a)
{
	chuanHoa(a);
	while (check_PTTT(a) == false)
	{
		cout << "Nhap phuong thuc thanh toan khong phu hop, nhap lai:"; getline(cin, a);
		chuanHoa(a);
	}
}

void while_trang_thai(string& a)
{
	while (check_trang_thai(a) == false)
	{
		cout << "Da Nhan Hang|Chua Nhan Hang" << endl;
		cout << "Trang thai khong phu hop, nhap lai:"; getline(cin, a);
		chuanHoa(a);
	}
}

void while_email(string& a)
{
	while (check_email(a) == false)
	{
		cout << "Nhap email khong hop le, nhap lai:"; getline(cin, a);
	}
}

void while_mk(string& a)
{
	while (check_dinh_dang_mk(a) == false)
	{
		cout << "Nhap khong dung dinh dang! Nhap lai: "; getline(cin, a);
	}
}

void while_tk(string& a)
{
	while (check_dinh_dang_tk(a) == false)
	{
		cout << "Nhap tai khoan khong phu hop! Nhap lai: "; getline(cin, a);
	}
}

void while_nhap_ngay(string& a)
{
	chuan_hoa_tg(a);
	while (check_date(a) == false)
	{
		cout << "Nhap ngay khong hop le. Nhap lai:"; getline(cin, a);
	}
}

bool check_trung_sdt(string a, TREE t)
{
	if (t != NULL)
	{
		if (a == t->data.sdt)
		{
			return true;
		}
		bool l = check_trung_sdt(a, t->pLeft);
		bool r = check_trung_sdt(a, t->pRight);
		return l || r;
	}
	else
	{
		return false;
	}
}

void while_kt_trung_sdt(string& a, TREE t)
{
	while (check_trung_sdt(a, t) == true)
	{
		cout << "So dien thoai da ton tai! Hay nhap lai: "; getline(cin, a);
	}
}

bool check_trung_email(string a, TREE t)
{
	if (t != NULL)
	{
		if (a == t->data.email)
		{
			return true;
		}
		bool l = check_trung_email(a, t->pLeft);
		bool r = check_trung_email(a, t->pRight);
		return l || r;
	}
	else
	{
		return false;
	}
}

void while_kt_trung_email(string& a, TREE t)
{
	while (check_trung_email(a, t) == true)
	{
		cout << "Email da ton tai! Hay nhap lai: "; getline(cin, a);
	}
}

bool check_trung_ten_dn(string a, TREE t)
{
	if (t != NULL)
	{
		if (a == t->data.ten_dang_nhap)
		{
			return true;
		}
		bool l = check_trung_ten_dn(a, t->pLeft);
		bool r = check_trung_ten_dn(a, t->pRight);
		return l || r;
	}
	else
	{
		return false;
	}
}

void while_kt_trung_ten_dn(string& a, TREE t)
{
	while (check_trung_ten_dn(a, t) == true)
	{
		cout << "Ten da ton tai! Hay nhap lai: "; getline(cin, a);
	}
}

