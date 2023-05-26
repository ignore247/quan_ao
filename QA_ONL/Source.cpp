#include "Xu_li_do_hoa.h"
#include "docFile.h"
#include "Menu.h"

int main()
{		
	Admin ad;
	// --- Load thông tin áo quần ---
	load_file_thong_tin_ao(ad.quan_li_ds_hang_hoa);
	load_file_thong_tin_quan(ad.quan_li_ds_hang_hoa);
	// --- Load thông tin khách hàng ---
	load_file_thong_tin_khach_hang(ad.quan_li_ds_kh);
	load_file_don_mua_kh(ad.quan_li_ds_kh.t);
	load_file_gio_hang(ad.quan_li_ds_kh.t);
	// --- Load thông tin hóa đơn nhập xuất
	load_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	load_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	// --- Load thông tin hóa đơn đã xóa
	load_file_hoa_don_xuat_xoa(ad.quan_li_hd_xuat_xoa);
	load_file_hoa_don_nhap_xoa(ad.quan_li_hd_nhap_xoa);

	
	//chuong_trinh(ad);

	// ghi file;
	ghi_thong_tin_kh(ad.quan_li_ds_kh);
	ghi_file_quan(ad.quan_li_ds_hang_hoa);
	ghi_file_ao(ad.quan_li_ds_hang_hoa);
	ghi_file_hoa_don_xuat(ad.quan_li_ds_hoa_don_xuat);
	ghi_file_hoa_don_nhap(ad.quan_li_ds_hoa_don_nhap);
	ghi_file_hoa_don_nhap_xoa(ad.quan_li_hd_nhap_xoa);
	ghi_file_hoa_don_xuat_xoa(ad.quan_li_hd_xuat_xoa);
	ghi_don_mua_cua_1_kh(ad.quan_li_ds_kh.t->data);
	ghi_don_mua_cua_dskh(ad.quan_li_ds_kh.t);
	ghi_gio_hang_cua_1_kh(ad.quan_li_ds_kh.t->data);
	ghi_gio_hang_cua_dskh(ad.quan_li_ds_kh.t);

	string dia_chi;
	cout << "Nhap dia chi: ";
	getline(cin, dia_chi);
	regex check_dia_chi("^[0-9]+[\w\s]+(Pho | pho | Duong | duong | Hem | hem | Ngo | ngo | Quoc lo | quoc lo | Xa | xa | Phuong | phuong | Quan | quan | Huyen | huyen) + [\w\s] + ((Quan\s[A-Za-z\s]*[1-9][0-9] *) | (Huyen\s[A-Za-z\s]*[1-9][0-9] *) | (Xa\s[A-Za-z\s]*[1-9][0-9] *) | (Phuong\s[A-Za-z\s]*[1-9][0-9] *)) + (, [\w\s] + (Tinh | Thanh pho)\s[A - Za - z\s] + ) ? $");
	if (regex_match(dia_chi, check_dia_chi) == true)
	{
		cout << "dung!\n";
	}
	else
	{
		cout << "Sai!\n";
	}

	//sp_Best(ad);

	system("pause");
	return 0;
}