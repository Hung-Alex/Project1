#pragma once
void XuatMenu()
{
	cout << "\n=========== QUAN LY LOP HOC ============";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. nhap danh sach lop va danh sach sinh vien va in ra man hinh ";
	cout << "\n2. sap sep danh sach lop theo thu tu tang dan ";
	cout << "\n3. tim kiem phan tu co ten  X trong danh sach lop";
	cout << "\n============================================\n";
}
int ChonMenu(int soMenu, unsigned int n)
{
	int stt = -1;
	while (stt < 0 || stt > soMenu)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang tuong ung : ";
		cin >> stt;
	}

	return stt;
}
