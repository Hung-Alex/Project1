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
int ChonMenu(int soMenu)
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
void HamXuLyMenu(LopHoc* a, int &length, int chonMenu)
{
	string ten;
	switch (chonMenu)
	{
	case 0:
		cout<<"0. Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1. nhap danh sach lop va danh sach sinh vien va in ra man hinh\n ";
		NhapLopVaDanhSach(a,length);
		Xuat_Thong_Tin_Nguyen_1_Lop(a, length);
		break;
	case 2:
		cout << "\n2. sap sep danh sach lop theo thu tu tang dan\n ";
		Sort_TenLop_TangDan(a, length);
		Xuat_Thong_Tin_Nguyen_1_Lop(a, length);
		break;
	case 3:
		cout << "\n3. tim kiem phan tu co ten  X trong danh sach lop\n";
		cout << "MOi ban Nhap Ten Muon Tim Trong Danh Sach Lop-> ";
		cin >> ten;
		TimKiemPhanTuCoTenXTrongDanhSachLop(ten, a, length);
		break;
	default:
		break;
	}
	_getch();
}
