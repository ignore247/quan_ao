#include "Xu_li_do_hoa.h"


// tạo box
void box1(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	DS_Hang_Hoa a;
	textcolor(b_color);
	for (int iy = y; iy < y + h; iy++)
	{
		for (int ix = x; ix < x + w; ix++)
		{
			gotoXY(ix, iy); cout << " ";
		}
	}

	// ===== noi dung ====='
	for (int i = 0; i < a.ds_ao.size(); i++)
	{
		SetColor(7);
		gotoXY(x + 1 + i, y + 1 + i);
		sanPhammoi(a); 
		// ===== ve vien =====
		textcolor(1);
		SetColor(t_color);
		if (h <= 1 || w <= 1) return;
		for (int ix = x; ix < x + w; ix++)
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
}
int main()
{
	//box1(2, 5, 10, 10, 11, 1, a);
	/*HoaDon a;
	ds_hoa_don b;
	DS_Hang_Hoa c;
	
	
	ve_nhap_bang_hoa_don_nhap_hang(0,a, b, c);
	gotoXY(0, 100);
	ve_nhap_bang_hoa_don_nhap_hang(80,a, b, c);
	*/
	cout << " nghia test";
	return 0;
}