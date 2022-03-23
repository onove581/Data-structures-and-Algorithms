#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
struct stack
{
	NODE *pTop; 
};
typedef struct stack STACK;

void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		printf( "\nKhong du bo nho de cap phat !");
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
	{
		return false;
	}
	return true;
}
bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}
	if (IsEmpty(s) == false)
	{
		s.pTop = p;
	}
	else
	{
		p->pNext = s.pTop; 
		s.pTop = p;
	}
	return true;
}

bool Pop(STACK &s, int &x) 
{
	if (IsEmpty(s) == false)
	{
		return false; 
	}
	NODE *p = s.pTop;
	s.pTop = s.pTop->pNext; 
	x = p->data;
	return true; 
}
bool Top(STACK s, int &x) 
{

	if (IsEmpty(s) == false)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

void Chuyen_So_So(STACK &s, int cosocandoi, int hethapphan)
{
	while (hethapphan != 0)
	{
		int x = hethapphan % cosocandoi;
		NODE *p = KhoiTaoNode(x); 
		Push(s, p);
		hethapphan /= cosocandoi;
	}
}
void XuatStack(STACK &s)
{
	while (IsEmpty(s) == true)
	{
		int x;
		Pop(s, x);
		if (x < 10)
		{
			cout << x;
		}
		else
		{
			if (x == 10)
			{
				printf("A");
			}
			else if (x == 11)
			{
				printf("B");
			}
			else if (x == 12)
			{
				printf("C");
			}
			else if (x == 13)
			{
				printf("D");
			}
			else if (x == 14)
			{
				printf("E");
			}
			else if (x == 15)
			{
				printf("F");
			}
			
		}
	}
}



int main()
{
	STACK s;
	KhoiTaoStack(s);
	
	int hethapphan;
	printf("\nNhap gia tri he thap phan(10) can chuyen: ");
	scanf("%d",&hethapphan);
	int cosocandoi;
	printf("\nNhap co so can chuyen(2, 8, 16:  ");
	scanf("%d",&cosocandoi);

	Chuyen_So_So(s, cosocandoi, hethapphan);
	printf("\nKET QUA SAU KHI DOI:");
	XuatStack(s);
	system("pause");
	return 0;
}
