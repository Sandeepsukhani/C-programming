#include<stdio.h>
int main()
{
 int r,c,r1,c1,a,ch1,i;
 printf("Enter rhe number:");
 scanf("%d",&a);
 r=35;
 c=25;
 a=a*a;
 ch1=0;
 r1=0;
 c1=0;
 gotoxy(r,c);
 printf("%d",a);
 while(a>0)
 {
  if(ch1==1)
  ch1++;
  else
  ch1=1;
  r1++;
  c1++;
 switch(ch1)
 {
  case 1:
	  for(i=0;i<c1;i++)
	  {
	   r=r+2;
	   a--;
	   if(a==0)
	   return 0;
	   gotoxy(r,c);
	   if(a<10)
	   printf("0");
	   printf("%d",a);
	  }
	  for(i=0;i<r1;i++)
	  {
	   c=c-1;
	   a--;
	    if(a==0)
	   return 0;
	   gotoxy(r,c);
	   if(a<10)
	   printf("0");
	   printf("%d",a);
	  }
	  break;
  case 2:
	 for(i=0;i<c1;i++)
	 {
	  r=r-2;
	  a--;
	  if(a==0)
	   return 0;
	 gotoxy(r,c);
	 if(a<10)
	   printf("0");
	   printf("%d",a);
	 }
	 for(i=0;i<r1;i++)
	 {
	 c=c+1;
	 a--;
	 if(a==0)
	 return 0;
	 gotoxy(r,c);
	 if(a<10)
	   printf("0");
	   printf("%d",a);
	 }
	 break;
 }
}

return 0;
}
