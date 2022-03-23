#include<iostream>
#include<stdio.h>
using namespace std;


struct node
{
	int data; // queue dang ch?a các s? nguyên
	struct node *pNext; // con tr? liên k?t gi?a các node v?i nhau
};
typedef struct node NODE;

// khai báo c?u trúc c?a queue
struct queue
{
	NODE *pHead; //  con tr? d?u
	NODE *pTail; // con tr? cu?i 
};
typedef struct queue QUEUE;

// hàm kh?i t?o queue
void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

// hàm kh?i t?o 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
	printf("\nKhong du bo nho de cap phat !!!");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(QUEUE q)
{
	// n?u danh sách r?ng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// n?u danh sách r?ng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; 
	}
	else 
	{
		q.pTail->pNext = p; 
		q.pTail = p; 
	}
	return true;
}
bool Pop(QUEUE &q, int &x) // x chính là giá tr? c?n l?y trong node
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead; 
		x = p->data; 	
		q.pHead = q.pHead->pNext; 
		delete p; 

	}
	return true;
}
bool Top(QUEUE &q, int &x) // x chính là giá tr? c?n l?y ra d? xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data; 
	return true;
}

// hàm xu?t danh sách queue
void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Pop(q, x);
		cout << x << " ";
	}

	if (IsEmpty(q) == true)
	{
			printf("\nDanh sach dang rong !!!");
	}
	else
	{
		printf("\nDanh sach dang ton tai phan tu");
	}
}
void NhapQueue(QUEUE &q)
{
	int luachon;
	while (true)
	{
		system("cls");
		printf("\n\n\t\t ============== Menu ==============");
		printf("\n\t1. Them phan tu vao queue - Push");
		printf("\n\t2. Xuat danh sach queue ra man hinh - Pop");
		printf("\n\t3. Xem thong tin phan tu dau queue - Top");
		printf("\n\t0. Ket thuc");
		printf("\n\n\t\t ============== End ==============");

		printf("\nNhap lua chon: ");
		scanf("%d",&luachon);
		if (luachon == 1)
		{
			int x;
			printf("\nNhap phan tu can them");
			scanf("%d",&x);
			NODE *p = KhoiTaoNode(x);
			Push(q, p);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(q, x);
			printf("\nPhan tu dau queue la: %d",x);
			system("pause");
		}
		else
		{
			break;
		}
	}
}

int main()
{
	QUEUE q;
	KhoiTaoQueue(q);
	NhapQueue(q);
	system("pause");
	return 0;
}
