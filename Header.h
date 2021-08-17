#pragma once

struct  DanhSachSinhVien;
struct  ThongTin
{
	string maSinhVien;
	string ho;
	string ten;
	string gioiTinh;
};
struct List
{
	DanhSachSinhVien* pHead;
	DanhSachSinhVien* pTail;
};
typedef struct List LIST;
struct  DanhSachSinhVien
{
	ThongTin a;
	struct DanhSachSinhVien* pNext;
	LIST lo;
};

struct  LopHoc
{
	string maLop;
	string TenLop;
	 DanhSachSinhVien *DSSV=new DanhSachSinhVien[30];
};


void Init(LIST& list)
{
	list.pHead = list.pTail = NULL;
}
DanhSachSinhVien* GetNode(ThongTin x)
{
	DanhSachSinhVien* pNode = new DanhSachSinhVien;
	if (pNode == NULL)
		return NULL;
	pNode ->a = x;
	pNode->pNext = NULL;
	return pNode;
}
void AddHead(LIST& list, DanhSachSinhVien *pNode)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = pNode;
	else
	{
		pNode->pNext = list.pHead;
		list.pHead = pNode;
	}
}
void Add(LopHoc *x, int &length,LopHoc *a)
{
	*(x + length) = *a;
	length++;
}
void NhapLopVaDanhSach(LopHoc *x,int &length)
{
		int sl = 0;
		int n = 0;
		cout << "Moi ban nhap So luong lop  ->";
		cin >> sl;
		for (size_t i = 0; i < sl; i++)
		{
			cout << "lop thu " << i << endl;
			cout << "moi ban nhap ma lop -> ";
			cin>>(x+i)->maLop;
			cout << "moi ban nhap ten lop ->";
			cin >> (x+i)->TenLop;
			Init((x+i)->DSSV->lo);
			cout << "ban muon nhap bao nhieu hoc vien ->> ";
			cin >> n;
			for (size_t j = 0; j < n; j++)
			{
				cout << "moi ban nhap ho sinh vien -> ";
				cin >> ((x+i)->DSSV + j)->a.ho;
				cout << "moi ban nhap ten sinh vien -> ";
				cin >> ((x+i)->DSSV + j)->a.ten;
				cout << "moi ban nhap gioi tinh sinh vien ->";
				cin >> ((x+i)->DSSV + j)->a.gioiTinh;
				cout << "moi ban nhap ma sinh vien ->";
				cin >> ((x+i)->DSSV + j)->a.maSinhVien;
				((x+i)->DSSV + j)->pNext = NULL;
				AddHead((x+i)->DSSV->lo, ((x+i)->DSSV + j));
			}
			Add(x, length, (x+i));
		}
}
void TieuDe()
{
	cout << setiosflags(ios::left) << ':'
		<< setw(20) << "MA LOP" << ':'
		<< setw(20) << "TEN LOP" << ':'
		<< setw(20) << "HO SV" << ':'
		<< setw(20) << "TEN SV" << ':'
		<< setw(20) << "Gioi TINH" << ':'
		<< setw(20) << "MA SV" ;
	cout << "\n";
}
void Xuat_Thong_Tin_1_Lop(DanhSachSinhVien *a)
{
	
	cout << setiosflags(ios::left) 
		<< setw(22) << a->a.ho 
		<< setw(22) << a->a.ten 
		<< setw(22) << a->a.gioiTinh 
		<< setw(22) << a->a.maSinhVien 
		<< endl;
}
void Xuat_Ke_Ngang()
{
	for (size_t i = 0; i < 150; i++)
	{
		cout << "*";
	}
	cout<<endl;
}
void Xuat_Thong_Tin_Nguyen_1_Lop(LopHoc* a, int length)
{
	Xuat_Ke_Ngang();
	Xuat_Ke_Ngang();
	TieuDe();
	Xuat_Ke_Ngang();
	Xuat_Ke_Ngang();
	for (size_t i = 0; i < length; i++)
	{
		
		DanhSachSinhVien* p = (a+i)->DSSV->lo.pHead;
		while (p!=NULL)
		{
			cout << setw(20) << (a + i)->maLop << ':'
				<< setw(20) << (a + i)->TenLop << ':';
			Xuat_Thong_Tin_1_Lop(p);
			p = p->pNext;
		}
		Xuat_Ke_Ngang();
		
	}
}
void Sort_TenLop_TangDan(LopHoc* a, int length)
{
	for (size_t i = 0; i < length-1; i++)
	{
		for (size_t j = i+1; j < length; j++)
		{
			if ((a + i)->TenLop.compare((a+j)->TenLop)>0)
			{
				LopHoc temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
			}
		}
	}
}
int TimKiemPhanTuCoTenXTrongDanhSachLop(string ten,LopHoc *a,int length)
{
	bool x = false;
	for (size_t i = 0; i < length; i++)
	{
		if ((a + i)->TenLop.compare(ten) == 0)
		{
			x = true;
			break;
		}
	}
	if (x)
	{
		cout << "CO  " << ten << " TRONG DANH SACH LOP\n\n";
		for (size_t i = 0; i < length; i++)
		{
			if ((a + i)->TenLop.compare(ten) == 0)
			{
				Xuat_Ke_Ngang();
				Xuat_Ke_Ngang();
				TieuDe();
				Xuat_Ke_Ngang();
				Xuat_Ke_Ngang();
				DanhSachSinhVien* p = (a + i)->DSSV->lo.pHead;
				while (p != NULL)
				{
					cout << setw(20) << (a + i)->maLop << ':'
						<< setw(20) << (a + i)->TenLop << ':';
					Xuat_Thong_Tin_1_Lop(p);
					p = p->pNext;
				}
			}
		}
	}
	else
	{
		cout << "KHONG CO  " << ten << " TRONG DANH SACH LOP";
	}
	return 0;
}
		