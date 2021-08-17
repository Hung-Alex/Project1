#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
#include"Header.h"
#include"Menu.h"
struct contro
{
	int *a=new int[10];
};
void Run_Program()
{
	/*LopHoc *x = new LopHoc[500];
	int length = 0;
	NhapLopVaDanhSach(x, length);*/
	contro x;
	x.*(DanhSachSinhVien::a+1) = 1;
	cout << x.a;


	cout << "\nCam on da su dung chuong trinh";
	
	_getch();
}
int main()
{
	Run_Program();
	return 0;
}