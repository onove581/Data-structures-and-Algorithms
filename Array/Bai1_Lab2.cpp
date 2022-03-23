#include<stdio.h>
 #include<math.h>
 #include <sstream>

typedef  struct  {
	 int      n ;                //s? ph?n t?
	 int      pt[100] ;     //1D array
 } list ;
list  L;
//nhap mang
void input(list &L)
{
	
	for (int i=0; i<L.n; i++)
        				{
        					printf("\nNhap phan tu thu[%d]: ",i);
        					scanf("%d",&L.pt[i]);
						}
}
//xuat mang
void output(list L)
{
	
	for (int i=0; i<L.n; i++)
	printf("\n PT thu [%d]: %d",i,L.pt[i]);
}
//tinh trung binh cong cac phan tu trong mang
void tbc(list L)
{
	int sum=0;
	for(int i = 0;i < L.n; ++i){
		
		sum+=L.pt[i];
	}
	printf("Gia tri trung binh cac phan tu trong mang la: %f\n",sum/(float)L.n);
}
//tinh tong cac so nguyen to trong mang
void TongNT(list L)
{
	int ngto=0,sum=0;
	for(int i=0;i<L.n;i++)
    {
        ngto=1;
        if(L.pt[i]<2) ngto=0;
        for(int j=2;j<=sqrt(L.pt[i]);j++)
        if(L.pt[i]%j==0) ngto=0;
            if(ngto)
                {
                    
                    sum += L.pt[i];
                }
    }
     printf("Tong cac so nguyen to trong mang: %d",sum);
}
//tich cac phan tu trong mang la so chinh phuong
void tichcp(list L)
{
	int s=1;
	for(int i=0; i<=L.n; i++) {

                int k=((int)sqrt((float)(L.pt[i])));
	if(k*k==L.pt[i])

                                    s = s *L.pt[i];
}
                   

      

          printf("\nTich cac phan tu so chinh phuong la: %d", s);
}

//so luong phan tu la so nguyen to trong mang
void soNT(list L)
{
	int ngto=0,dem=0;
	for(int i=0;i<L.n;i++)
    {
        ngto=1;
        if(L.pt[i]<2) ngto=0;
        for(int j=2;j<=sqrt(L.pt[i]);j++)
        if(L.pt[i]%j==0) ngto=0;
            if(ngto)
                {
                    
                    dem++;
                }
    }
     printf("So luong phan tu la so nguyen to trong mang la: %d",dem);
     
}
//Phan tu duong nho nhat
int NguyenDuongMin(list L) {
 int i,min;
for(i=0; i<L.n; i++) {
if(L.pt[i]>0) {
 min = L.pt[i];
 break;
  }
 }
for(i=0; i<L.n; i++) {
 if(L.pt[i]>0 && L.pt[i]<min)
  min = L.pt[i];
 }
  return min;

}
//Cac phan tu cua mang theo chiue nguoc lai
void daonguocchieu(list&L)  
{
 for(int i=0;i<=L.n/2;i++)
  {
   int temp=L.pt[i];
   L.pt[i]=L.pt[L.n-1-i];
   L.pt[L.n-1-i]=temp;
  }
}
//Sap xep mang tang giam
void SortUp(list &L) {
	for(int i=0;i<L.n-1;i++)
  for(int j=i+1;j<L.n;j++)
   {
    if(L.pt[i]>L.pt[j]) 
     {
       int temp=L.pt[i];
       L.pt[i]=L.pt[j];
      L.pt[j]=temp;
     }
   }
          				
}
void SortDown(list &L) {
	for(int i=0;i<L.n-1;i++)
  for(int j=i+1;j<L.n;j++)
   {
    if(L.pt[i]<L.pt[j]) 
     {
       int temp=L.pt[i];
       L.pt[i]=L.pt[j];
      L.pt[j]=temp;
     }
   }
          				
}
//Kiem tra doi xung
 int KiemTraMangDoiXung(list L)
{
	for(int i = 0; i < L.n/2; i++)
	{
		if(L.pt[i] != L.pt[L.n - i - 1])
		{
			return -1;
			break;
		}
	}
	return 1;
}
//Mang chan le
void tachmang(list L)
{
 int a[10000],b[10000],k=0,q=0;
 for(int i=0;i<L.n;i++)
  if(L.pt[i]%2!=0)
   {
    a[k]=L.pt[i];
    k++;
   }
  else
   {
    b[q]=L.pt[i];
    q++;
   }
printf("=========Mang chan la============");
  for(int j=0;j<q;j++)
   printf("\nPhan tu[%d]: %d\t\n",j,b[j]);
 
   printf("\n");
 printf("========Mang le la==============");
  for(int i=0;i<k;i++)
   printf("\nPhan tu[%d]:%d\t\n",i,a[i]);
 }
 //trung binh cong cac phan tu so chan
  void tbcsochan(list L)
{
	double sum=0,num=0;
	for(int i = 0;i < L.n; ++i){
		if(L.pt[i]%2==0)
		{
		num++;
		sum+=L.pt[i];
	}
	}
	printf("Gia tri trung binh cac phan tu la so chan trong mang la: %f\n",sum/num);
}
//vi tri phan tu X co gia tri cho truoc
int search( list  L, int X){
	int i=0;
	while  ((L.pt[i]!=X)&&(i<=L.n))
   		i++;
	if(i<=L.n) 	return i;
	else 		return -1;
}
//cac phan tu so nguyen to
void phantuNT(list L)
{
	int ngto=0;
	for(int i=0;i<L.n;i++)
    {
        ngto=1;
        if(L.pt[i]<2) ngto=0;
        for(int j=2;j<=sqrt(L.pt[i]);j++)
        if(L.pt[i]%j==0) ngto=0;
            if(ngto)
                {
                    printf("\nPhan tu thu[%d]: %d",i,L.pt[i]);
                    
                }
    }
     
     
}
//xoa phan tu vi tri k cho truoc
void    del(int k, list &L){
	if (k>=0  &&  k < L.n)	{     
          		for (int i=k;   i<L.n;   i++)
		         L.pt[i] = L.pt[i +1];
		 L.n-- ;
       	}
       	
}
//xoa phan tu co gia tri cho truoc
void xoa1phantu(list &L,int vt)
{
     int i;
     for(i=vt;i<L.n-1;i++)
          L.pt[i]=L.pt[i+1];
     L.n--;
}
   
                       
void xoax(list &L,int x)
{
     int i;
     for(i=0;i<L.n;i++)
     if(x==L.pt[i])
     {
                xoa1phantu(L,i);
                i--;
     }
}

int getchoice() {	
	int choice;
   	printf("\n>>>CHon 1 chuc nang ?: ");  scanf("%d",&choice);
    return choice;
}
void menu()
{
	printf("\nBai lam cua Duong Van Bi 19it5");
	printf("\n============================================================");
	printf("\n1.Nhap vao 1 mang so nguyen");
	printf("\n2.Tinh trung binh cong cac phan tu trong mang");
	printf("\n3.Tinh tong cac phan tu la so nguyen to trong mang");
	printf("\n4.Tich cac phan tu trong mang la so chinh phuong");
	printf("\n5.So luong phan tu la so nguyen to trong mang");
	printf("\n6.Phan tu duong nho nhat trong mang");
	printf("\n7.Cac phan tu cua mang theo chieu nguoc lai");
	printf("\n8.Sap xep mang tang dan(giam dan)");
	printf("\n9.Kiem tra tinh doi xung cua mang");
	printf("\n10.Tach mang thanh 2 mang chan-le");
	printf("\n11.Trung binh cong cac phan tu la so chan");
	printf("\n12.Vi tri phan tu X co gia tri cho truoc");
	printf("\n13.Cac phan tu la so nguyen to");
	printf("\n14.Loai bo so nguyen o vi tri k cho truoc");
	printf("\n15.Loai bo so nguyen co gia tri X cho truoc");
	printf("\n============================================================");
}

int main(){
	list L;
	
	int choice;
	menu();
	do {
	 	choice=getchoice();
       		 switch (choice) {
        			case 1:
        				
        				printf("\nNhap so luong phan tu mang:");
        				scanf("%d",&L.n);
        				input(L);
					  	break;
    				case 2: 
    					tbc(L);
						break;
					case 3:
						TongNT(L);
				
						break;
					case 4:
						tichcp(L);
				
						break;
					case 5:
						soNT(L);
						
						break;
					case 6:
						printf("\nSo nguyen duong nho nhat: %d",NguyenDuongMin(L));
						
					
						break;
					case 7:
						printf("\n Cac phan tu theo chieu nguoc lai la: ");
						daonguocchieu(L);
						output(L);
						break;
					case 8:
						printf("\nMang tang dan:");
						SortUp(L);
						output(L);
						
						printf("\nMang giam dan:");
						SortDown(L);
						output(L);
						break;
					case 9:
								
						if(KiemTraMangDoiXung(L) == 1)
							printf("\nMang doi xung ");
 							else printf("\n Mang khong doi xung");
        				break;
        			case 10:
        				tachmang(L);
        				break;
        			case 11:
        				tbcsochan(L);
        				break;
        			case 12:
        				printf("\nMang da nhap:");
        				output(L);
        				int x;
						printf("\nNhap gia tri can tim trong danh sach :");
						scanf("%d",&x);
						printf("\nVi tri phan tu can tim kiem: %d",search(L,x));
        				break;
        			case 13:
        				printf("\nCac phan tu la so nguyen to:");
        				phantuNT(L);
        				break;
        			case 14:
        				int c;
        				printf("\nMang da nhap:");
        				output(L);
						printf("\n Nhap vi tri can xoa:");
						scanf("%d",&c);
						del(c,L);
						printf("So phan tu con lai sau khi xoa:");
						output(L);
			
        				break;
        			case 15:
        				printf("\nMang da nhap:");
        				output(L);
        				 printf("\n Nhap gia tri can xoa trong mang ");
					 	int o;
    					scanf("%d",&o);
    					xoax(L,o);
    					printf("\n  Mang sau khi xoa ");
    					output(L);
        				break;
        				
    			default: printf("Cam on Co da xem bai cua em Bye... \n");
        		}              
   	 } while ((choice>=1) && (choice<=15));	
}



