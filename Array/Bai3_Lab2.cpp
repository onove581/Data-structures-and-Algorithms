#include <stdio.h>
 #include <string.h>

 void dem(char dem[]) {
   
   int i = 0;
   int songuyenam = 0;            
   int sophuam = -1;       
      
   while(dem[i++] != '\0') {
      if(dem[i] == 'a' || dem[i] == 'e' || dem[i] == 'i' || dem[i] == 'o' || dem[i] == 'u' )
         songuyenam++;
      else
         sophuam++;
   }
  
   printf("Chuoi  co chua: %d nguyen am va %d phu am.\n", songuyenam, sophuam);

  
}
void demkitu(char *s)
{
    int a[100],n=0;
    for(int i=0;i<(int)strlen(s);i++)
    {
        int d=1;
        for(int j=i+1;j<(int)strlen(s);j++)
            if(s[i]==s[j])
            {    d++;
                for(int k=j;k<(int)strlen(s);k++)
                    s[k]=s[k+1];
                        j--;
            
            }
            a[n++]=d;
   
    }
    for(int i=0;i<(int)strlen(s);i++)
    printf("ky tu %c xuat hien %d lan\n",s[i],a[i]);


}
void daochuoi(char s[])
{
	printf("\nChuoi dao nguoc: %s", strrev(s));
}
int main()
{
    char s[100];
    printf("\nNhap chuoi: ");
    fgets(s, 100, stdin); 
    daochuoi(s);
    printf("\n");
    dem(s);
    demkitu(s);
	    return 0;
}
