#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<iostream>
//=====Tao cau truc nhan vien gom ten, tuoi, luong
 struct nhanvien
{

    char hoten[50];
    int tuoi;
    float luong;
};
//=====Tao cau truc NODE
struct NODE
{
    nhanvien data;
    struct NODE* next;
};
struct LIST
{
    NODE *head;
    NODE *tail;
};
//=====Khoi tao danh sach lien ket rong
void CreateList (LIST &L)
{
    L.head=L.tail=NULL;
}
//=====Tao mot node nhan vien moi
NODE* CreateNode (nhanvien x)
{
    NODE *p;
    p=new NODE;
    if(p==NULL)  exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
// Ham chen 1 node nhan vien vao danh sach lien ket
void AddLast (LIST &L, NODE *p)
{
    if(L.head==NULL)  L.head=L.tail=p;
    else
    {
        L.tail->next=p;
        L.tail=p;
    }
}
//=====Ham nhap thong tin cac nhan vien
void input (nhanvien &x)
{
	int stt;

    printf("\nNhap ten nhan vien: ");  fflush(stdin); gets(x.hoten);
    printf("\nNhap tuoi: ");  fflush(stdin); scanf("%d", &x.tuoi);  
    printf("\nNhap luong: "); scanf("%f", &x.luong);
    }


void nhap (LIST &L)
{
    nhanvien x;
    
    char kt;   
    printf("\nNhan phim bat ki de tiep tuc nhap.");
    printf("\nNhan phim 0 de dung nhap.");
    do
    {
        kt=getch();
        if(kt=='0')  break;
        input(x);
        NODE *p=CreateNode(x);
        AddLast(L,p);
    } while (1);
}
//=========Ham Hien thi danh sach
void output (nhanvien x)
{
	
    printf("\n%s                   ||               %d                ||                %f",x.hoten,x.tuoi,x.luong);
}
void xuat (LIST L)
{
    NODE *p;
    p=L.head;
    while(p!=NULL)
    {
        output(p->data);
        p=p->next;
    }
}

//==========Ham sap xep nhan vien theo thu tu tang dan cua luong
void selectionsort (LIST &L)
{
    NODE *p,*q,*min;
    p=L.head;
    nhanvien temp;
    while (p!=L.tail)
    {
        min=p;
        q=p->next;
        while (q!=NULL)
        {
            if(q->data.luong<min->data.luong)  min=q;
            q=q->next;
        }
        temp=p->data;
        p->data=min->data;
        min->data=temp;
        p=p->next;
    }
}


void delK(LIST &L, char s[50])
{

	NODE *g = new NODE; 
	for (NODE *k = L.head; k != NULL; k = k->next)
	{
		
		
		if ( k->data.hoten==s)
		{
			g->next = k->next; 
			delete k; 	
			return;
		}
		g = k; 
	}

}

//Xoa toan bo nhan vien
void deleteall(LIST &L)
{
NODE* p = L.head;
	while (L.head != NULL)
	{
		L.head= p->next;
		delete p;
		p = L.head;
	}
printf("\n Da xoa xong");


}

// =======Ham hien thi chuong trinh=============
void menu()
{
    LIST L;
    NODE *p,*q,*moi;
    nhanvien x;
    char chon;
    CreateList(L);
    do
    {
        printf("\n\t\t\t===========MENU========");
        printf("\n\t1. Nhap danh sach nhan vien");
        printf("\n\t2. In danh sach nhan vien");
        printf("\n\t3. Them nhan vien vao danh sach");
        printf("\n\t4. Xoa 1 node nhan vien thu k trong danh sach");
        printf("\n\t5. Sap xep danh sach tang dan theo luong");
        printf("\n\t6. Xoa danh sach");
        chon=getch();
        switch(chon)
        {
            case '1': { nhap(L);
			break;}
            case '2': {
            printf("\nHo va ten nhan vien  ||              Tuoi               ||                Luong nhan vien");
			 xuat(L); break;}
			 
            case '3': 
            {
            	//Them nhan vien vao danh sach
                        nhanvien them;
                        printf("\nNhap thong tin nhan vien can them: ");
                        input(them);
                        NODE *t= CreateNode(them);
                        AddLast(L,t); 
                        printf("\nDanh sach nhan vien sau khi them :");
                        xuat(L);
                        break;
                    }
        	case '4':
        		{
        			char x[50];
        			printf("\nNhap Ho ten nhan vien can xoa:");
        			scanf("%s",&x);
        			delK(L,x);
        			xuat(L);
        			break;
				}
        case '5': { selectionsort(L);printf("\nDanh sach nhan vien sau khi sap xep theo luong: "); xuat(L); break;}
        case '6':{
        	deleteall(L);
			break;
		}
case '0': exit(1);
            default: printf("\nNhap lai.");
        }
    } while (chon!='0');
}
int main()
{
    while(1)
    {
        menu();
        getch();
    }
}
