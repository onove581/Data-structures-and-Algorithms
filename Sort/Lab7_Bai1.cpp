#include<stdio.h>
#include<conio.h>
#include<string.h>
struct ngaysinh{
	int ngay;
	int nam;
};

struct canbo
 {
 	char MSNV[10];
 char ho[100];
 char ten[100];

 float heso;
 float luong;
 struct ngaysinh birday;

 };
 void nhap(struct canbo cb[],int n)
{
 for(int i=0; i<n; i++)
 {
 	fflush(stdin);
 	printf("\n Nhap ma so nhan vien");
 	gets(cb[i].MSNV);
 fflush(stdin);
 printf("\n Nhap ho:");
 gets(cb[i].ho);
 printf("\n Nhap ten:");
 fflush(stdin);
 gets(cb[i].ten);
printf("\n Nhap he so:");
 scanf("%f",&cb[i].heso);
 printf("\n Nhap ngay nhan vien vao lam:");
 scanf("%d",&cb[i].birday.ngay);
 printf("\n Nhap nam nhan vien vao lam:");
 scanf("%d",&cb[i].birday.nam);
 
}
}

void tinhluong(struct canbo cb[], int n)
 {
 for(int i=0; i<n; i++)
 {
 cb[i].luong = cb[i].heso * 1050000;
 printf("\n Luong cua %s la %f",cb[i].ten,cb[i].luong);
 }
 }
void sapxep(struct canbo cb[], int n)
 {
 struct canbo temp;
 char ten[100];
 //float ten;
 for(int i=0; i<n-1; i++)
 for(int j=i+1; j<n;j++)
 {
 if(strcmp(cb[i].ten,cb[j].ten)>0)
 {
 temp=cb[i];
 cb[i]=cb[j];
 cb[j]=temp;
 }
 }
 }

 
 void incb(struct canbo cb[], int n)
 {
 for(int i=0; i<n; i++){
 	printf("\n Ma nhan vien: %s",cb[i].MSNV);
 printf("\n Ho ten la: %s",cb[i].ten);

 printf("\n Luong la: %f",cb[i].luong);
 }
 }
 void timkiem(struct canbo cb[],int n, char ten[100])
 {
 for(int i=0; i<n; i++){
 if(strcmp(cb[i].ten,ten)==0)
{
printf("\n Nhan vien can tim kiem la %s",cb[i].ten);

 printf("\n Luong la: %f",cb[i].luong);
}
 }
}
void tinhsonam(struct canbo cb[], int n)
{
	for(int i=0;i<n;i++)
	{
	int nht=2020-cb[i].birday.nam;
	if(nht>=10){
	
		printf("\n Ma nhan vien: %s",cb[i].MSNV);
		printf("\n Ho ten la: %s",cb[i].ten);
		printf("\n So tuoi hien tai cac thanh vien : %d",nht);
	}
	}
	 
}
 int main()
{
 int n;
 int chon=1;
 struct canbo cb[50];
 struct ngaysinh;
 char addflag;
 char tenKiem[100];
 printf("\n Nhap vao so nhan vien:");
 scanf("%d",&n);
 printf("\n Nhap vao so luong nhan vien:");
 while(chon!=10)
 {
 printf("\nSelect from Menu\n1. Nhap vao nhan vien\n2. Sap xep nhan vien\n3. In thong tin nhan vien\n4.Tinh Luong nhan vien\n5. Tim kiem nhan vien\n 6. Cac nhan vien lam tren 10 nam\n 7.  Ket thuc\n\nEnter choice: ");
 scanf("%d",&chon);
 if(chon==1)
 {
 nhap(cb,n);
 }
 else if(chon==2)
 {
 sapxep(cb,n);
 }
 else if(chon==3)
 {
 incb(cb,n);
 }
 else if(chon==4)
 {
 tinhluong(cb,n);
 }
 else if(chon==5)
 {
 printf("\n Nhap ten can tim");
 fflush(stdin);
 gets(tenKiem);
 fflush(stdin);
 timkiem(cb,n,tenKiem);
 }
 else if(chon==6)
 {
 	tinhsonam(cb,n);
 }

 }
}
 
