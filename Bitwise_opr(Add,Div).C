#include<stdio.h>
#include<conio.h>
void main()
{
 float i,s,div;
 int n1,n2,c,cnt;
 clrscr();
 printf("Enter your choice:\n1.Multiplication\n2.Division\n");
 scanf("%d",&c);
 switch(c)
 {
	case 1:
		printf("\nEnter two numbers:");
		scanf("%d%d",&n1,&n2);
		if(n1<0 || n2<0)
			printf("\nInvalid number:");
		else
		{
			cnt=2;
			s=n2;
			/* Multiplying n2 with 2 till it is multiplyed by largest number of power 2 but <= number n1 */
			while(cnt<=n1)
			{
				n2=n2<<1;
				cnt=cnt*2;
			}
			/* If n2 is multiplyed with actual number then result is printed */
			if(cnt==n1)
				printf("Mul=%d",n2);
			/* If number is not multiplied by actual number then the difference is calculated and added to result */
			else
			{
				cnt=cnt/2;
				cnt=n1-cnt;
				cnt=cnt*s;
				n2=n2+cnt;
				printf("Mul=%d",n2);
			}
		}
		break;
	case 2:
		printf("\nEnter two numbers:");
		scanf("%d%d",&n1,&n2);
		if(n1<0 || n2<0)
			printf("\nInvalid number:");
		else
		{
			cnt=2;
			s=n1;
			/* Dividing n1 with 2 till it is divided by largest number of power 2 but <= number n2 */
			while(cnt<=n2)
			{
				n1=n1>>1;
				cnt=cnt*2;
			}
			/* If n2 is divided with actual number then result is printed */
			cnt=cnt/2;
			if(cnt==n2)
			{
				if(n1%cnt!=0)
				{
					s=s/cnt;
					div=s;
					s=n1+(s-n1);
					printf("Div=%f",s);
				}
				else
					printf("Div=%d",n1);
			}
			/* If number is not divided by actual number then the difference is calculated and substracted from result */
			else
			{
				s=s/cnt;
				div=s;
				s=n1+(s-n1);
				i=n2;
				i=i/(i-cnt);
				s=s/i;
				div=div-s;
				printf("Div=%f",div);
			}
		}
	  	break;
  	default:
		printf("\nInvalid choice");
 }
 getch();
}
