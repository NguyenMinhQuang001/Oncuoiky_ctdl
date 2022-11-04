// Them theo ma, tim theo ma, sua diem sv theo ma, tang diem sv, xoa theo ma, cap nhat dong loat theo dieu kien cu the. 

#include<iostream>
using namespace std;

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

typedef NODE* Tree;

void NhapSV(SINHVIEN &x)
{
	cout<<"Ma SV: ";
	cin>>x.MaSV;
	cin.ignore();
	cout<<"Ho ten SV: ";
	gets(x.HoTen);
	cout<<"Diem: ";
	cin>>x.Diem;
	cin.ignore(x.Diem);
}

void XuatSV(SINHVIEN x)
{
	cout<<x.MaSV<<"\t"<<x.HoTen<<"\t\t"<<x.Diem<<"\n";
}

void Init(Tree &TREE) 
{ 
 	TREE = NULL; 
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

void CreateTree(Tree &pRoot) 
{ 
	int n;
	SINHVIEN x; 
	
	printf("Nhap vao so node: ");
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++ )
	{ 
	 printf("Nhap vao SV thu %d: \n", i+1); 
	 NhapSV(x);
	 insertNode(pRoot, x); 
	 }; 
} 

void NLR(NODE* pTree) 
{ 
	if(pTree != NULL) 
	 { 
	 XuatSV(pTree->Key); 
	 NLR(pTree->pLeft); 
	 NLR(pTree->pRight); 
	 }
} 

int main()
{
 	NODE* pTree, *p;
	int x; 
 	Init(pTree); 
	   
   	int kt=1;
	int chon;
	
	char k[8];
	
	while(kt){
	printf("\nCAY NHI PHAN TIM KIEM");	
	printf("\n1. Tao danh sach moi");
	printf("\n2. In ra danh sach");
	printf("\n3. Tinh thanh tien");
	printf("\n4. Xoa phan tu theo ma");
	printf("\n5. Thoat!");
	printf("\nGo so tuong ung chuc nang can chon :");
	scanf("%d",&chon);	
	switch(chon){
			case 1:
		 			CreateTree(pTree);
					break;
			case 2:
		 			printf("\nCay sau khi duyet:\n");
		 			cout<<"Ma sinh vien\t|Ho ten\t\t\t\t|Diem\n";
	 				NLR(pTree);
					break;
			case 3:
//   				printf("Tong thanh tien = %d",TinhThanhTien(l));
					break;
			case 4:
//					printf("Nhap ma can xoa");
//					fflush(stdin);
//					gets(k);
//   				XoaTheoMa(l,k);
					break;								
			case 5:	kt=0;															
		}
	}		
}