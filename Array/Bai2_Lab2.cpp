#include <stdio.h>

typedef  struct  {
	 int n;      
	 int      phantu[100] ;     
 } list ;
list  L;
void hexa(list &L)
    {
	int i=0,j=0;
    
            while (L.n!=0)
                    {L.phantu[j]=L.n%16;L.n=L.n/16;j++;}
                    for(i=j;i>=0;i--)
                   {
				   if (L.phantu[i]<10) 
				   		printf("%d",L.phantu[i]);
                           else
                   switch (L.phantu[i])
                           {case 10: printf("A");break;
                            case 11: printf("B");break;
                            case 12: printf("C");break;
                            case 13: printf("D");break;
                            case 14: printf("E");break;
                            case 15: printf("F");break;
                           }
                   }
   }
   int main()
   {
   	list L;
  
   tiep:printf("\nBan hay nhap so can chuyen doi: ");
                    scanf("%d",&L.n);
     if (L.n<0) goto tiep;
   printf("\n\nMa Hexa cua so vua nhap la: ");
   printf("\n\n\t\t");
   hexa(L);
  
   
   }
