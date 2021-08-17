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
		int n=0;
		LopHoc* a = new LopHoc;
		cout << "lop thu " << length<<endl;
		cout << "moi ban nhap ma lop";
		cin >> a->maLop;
		cout << "moi ban nhap ten lop";
		cin >> a->TenLop;
		cout << "moi ban nhap ten sinh vien trong lop";
		Init(a->DSSV->lo);
		cout << "ban muon nhap bao nhieu hoc vien ->> ";
		cin >> n;
		for (size_t i = 0; i < n; i++)
		{
			
			
			AddHead(a->DSSV->lo, a->DSSV);
		}
		Add(x, length, a);
	

}