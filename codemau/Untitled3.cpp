#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//tao cau truc sinh vien
struct MatHang
{
	char ID[8];
	char Name[15];
	long Price;
	int Quantity;
	char Date[11];
};
//tao cau truc danh sach lien ket don
struct Node
{
    MatHang *data;
    Node *pNext;
};
struct SingleList
{
    Node *pHead;
};
//khoi tao danh sach lien ket don
void Initialize(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}
//nhap thong tin sinh vien
MatHang *NhapMatHang()
{
    MatHang *mh=new MatHang;
    cout<<"Nhap ma hang:";
    gets(mh->Name);
    cout<<"Nhap ten hang:";
    gets(mh->ID);
    cout<<"Nhap gia:";
    cin>>mh->Price;
    cin.ignore();
    cout<<"Nhap so luong:";
    cin>>mh->Quantity;
    cin.ignore();
    cout<<"Nhap ngay:";
	gets(mh->Date);
    return mh;
}
//tao node sinh vien
Node *CreateNode(MatHang *mh)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=mh;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList *&list,MatHang *mh)
{
    Node *pNode=CreateNode(mh);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}
//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    cout<<"ma hang"<<"\t"<<"ten hang"<<"\t"<<"gia hang"<<"\t"<<"so luong"<<"\t"<<"ngay"<<"\n";
    while(pTmp!=NULL)
    {
        MatHang *mh=pTmp->data;
        
       	cout<<mh->ID<<"\t"<<mh->Name<<"\t\t"<<mh->Price<<"\t\t"<<mh->Quantity<<"\t\t"<<mh->Date<<"\n";
        pTmp=pTmp->pNext;
    }
}

int main(int argc, char** argv) {
    SingleList *list;
    Initialize(list);
    MatHang *teo=NhapMatHang();
    InsertLast(list,teo);
    MatHang *ty=NhapMatHang();
    InsertLast(list,ty);
    PrintList(list);
 
}