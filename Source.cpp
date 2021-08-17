#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;
#include"Header.h"
#include"Menu.h"

void Run_Program()
{
	
	LopHoc* a = new LopHoc[500];
	int length = 0;
	int menu = 3;
	int n = 0;
	do
	{
		n = ChonMenu(menu);
		HamXuLyMenu(a, length, n);
	} while (n!=0);
	cout << "\nCam on da su dung chuong trinh";
	delete [] a;
	_getch();
}
int main()
{
	Run_Program();
	return 0;
}