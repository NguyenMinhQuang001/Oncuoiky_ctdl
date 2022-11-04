#include<Stdio.h>

struct SINHVIEN
{
	int MaSV;
	char HoTen[30];
	float Diem;
};

struct NODE{ 
	SINHVIEN Key; 
	NODE *pLeft; 
	NODE *pRight; 
}; 

typedef NODE *Tree;
//
void NhapSV(SINHVIEN &x)
{
	printf("Ma SV: ");
	scanf("%d", &x.MaSV);	
	
	printf("Ten SV : ");
	fflush(stdin);
	gets(x.HoTen);
	
	printf("Diem: ");
	scanf("%f", &x.Diem);
	
}
// xuat mot may tinh
void XuatSV(SINHVIEN x)
{
	printf("\n%d %s %f ", x.MaSV, x.HoTen, x.Diem);
	 
}
//
//
void Init(Tree &T) 
{ 
 	T = NULL; 
} 

int insertNode (Tree &T,  SINHVIEN  X)
{	if (T) {
		if(T->Key.MaSV == X.MaSV) return 0; 
		if(T->Key.MaSV > X.MaSV)
			return insertNode(T->pLeft, X);
		else
			return insertNode(T->pRight, X);
	}
	T = new NODE;
	if (T == NULL) return -1; 
	T->Key = X;
	T->pLeft = T->pRight = NULL;
	return 1;  
}

void CreateTree(Tree &T) 
{ 
	int n;
	SINHVIEN x; 
	Init(T);
	printf("\n Nhap vao so node: ");
	scanf("%d",&n);
	

	for(int i = 0; i < n; i++ )
	{ 
	 printf("Nhap vao SV thu %d: ", i); 	 
	 NhapSV(x);	
	 insertNode(T, x); 
	 }
} 
// 
void NLR(Tree T) 
{ 
	if(T != NULL) 
	 { 
		 XuatSV(T->Key); 
		 printf("\n");
		 NLR(T->pLeft); 
		 NLR(T->pRight); 
	 } 
} 
//
int main()
{
	Tree pRoot;
	SINHVIEN x;
	//NhapSV(x);
	//XuatSV(x);
	CreateTree(pRoot);
	NLR(pRoot);
}