#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#define MAX 50000

struct MatHang{
	char ID[8];
	char Name[15];
	long Price;
	int Quantity;
	char Date[11];
};

struct Node{
	MatHang data;
	Node *link;
};

struct List{
	MatHang data;
	Node *pHead;
	Node *pTail;
};

void NullList(List &l);
Node *GetNode(MatHang mh);
void AddFirstMH(Node *newNode, List &l);
void InsertFirst(MatHang mh, List &l);
void CreateList(List &l);
long TinhThanhTien(List &l);
void XoaTheoMa(List &l, char k[8]);
void PrintfListMH(List &l);

int main()
{
	
    List l;
    NullList(l);
	   
   	int kt=1;
	int chon;
	
	char k[8];
	
	while(kt){
	printf("\nDANH SACH LIEN KET DON");	
	printf("\n1. Tao danh sach moi");
	printf("\n2. In ra danh sach");
	printf("\n3. Tinh thanh tien");
	printf("\n4. Xoa phan tu theo ma");
	printf("\n10. Thoat!");
	printf("\nGo so tuong ung chuc nang can chon chon:");
	scanf("%d",&chon);	
	switch(chon){
			case 1:
					CreateList(l);
					break;
			case 2:
   					PrintfListMH(l);
					break;
			case 3:
   					printf("Tong thanh tien = %d",TinhThanhTien(l));
					break;
			case 4:
					printf("Nhap ma can xoa");
					fflush(stdin);
					gets(k);
   					XoaTheoMa(l,k);
					break;								
			case 10:	kt=0;															
		}
	}		
}

void NullList(List &l){
	l.pHead = l.pTail = NULL;
}

Node *GetNode(MatHang mh){
	Node *p = new Node;
	if(p==NULL){
		return NULL;
	}
	p->data = mh;
	p->link = NULL;
}

void AddFirstMH(Node *newNode, List &l){
	if(l.pHead == NULL){
		l.pHead = l.pTail = newNode;
	}
	else{
		newNode->link=l.pHead;
		l.pHead = newNode;
	}
}

void InsertFirst(MatHang mh, List &l){
	Node *p = GetNode(mh);
	if(p == NULL){
		return;
	}
	AddFirstMH(p,l);
}

void CreateList(List &l){
	MatHang mh;
	int n;
	int i=0;
	printf("Nhap so luong MAT HANG:");
	scanf("%d",&n);
	if(n>100){
		printf("So luong hang khong lon hon 100");
		return;
	}
	do{
		printf("\nMat hang thu: %d\n",i=i+1);
		printf("Nhap ma hang:");
		fflush(stdin);
		gets(mh.ID);
		printf("Nhap ten hang:");
	 	fflush(stdin);	
		gets(mh.Name);
		printf("Nhap don gia:");
		scanf("%d",&mh.Price);
		printf("Nhap so luong:");
		scanf("%d",&mh.Quantity);
		printf("Nhap ngay ban:");
		fflush(stdin);
		gets(mh.Date);
		InsertFirst(mh,l);
		n=n-1;
	}while(n!=0);
}

void PrintfListMH(List &l){
	int i=0;
	Node *pNode;
	pNode = l.pHead;
	while(pNode!=NULL){
		printf("\nMat hang thu - %d\n",i=i+1);
		printf("Ma hang: %s\n",pNode->data.ID);
		printf("Ten hang: %s\n",pNode->data.Name);	
		printf("Don gia: %d\n",pNode->data.Price);
		printf("So luong: %d\n",pNode->data.Quantity);
		printf("Ngay ban: %s\n",pNode->data.Date);
		pNode=pNode->link;
	}
}

long TinhThanhTien(List &l){
	long s=0;
	Node *pNode;
	pNode = l.pHead;
	while(pNode!=NULL){
		s =s+ pNode->data.Quantity * pNode->data.Price;
		pNode=pNode->link;
		
	}
	return s;
}

void XoaTheoMa(List &l, char k[8]){
	Node *pNode;
	pNode = l.pHead;
	while(pNode!=NULL){
		if(strcmp(pNode->data.ID,k) == 1){
			Node *q;
			q =	pNode;
			pNode=pNode->link;
			delete q;
		}
	}
}

