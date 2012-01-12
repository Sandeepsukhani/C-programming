#include<stdio.h>
#include<conio.h>
struct employee
{
 int no;
 char name[20];
 float bpay;
}emp;
void link_emu()
{
 float b=0,*a;
 a=&b;
 b=*a;
}
void read(FILE *fp);
void modify(FILE *fp);
void del(FILE *fp);
void main()
{
 FILE *fp1,*fp2;
 int no,ch;
 char cont='y',name1[]="C:/emp.dat",name2[]="C:/tmp.dat";
 clrscr();
 fp1=fopen(name1,"w+");
 printf("Enter records:\n");
 while(cont=='y' || cont=='Y')
 {
	printf("Enter registration number:");
	scanf("%d",&emp.no);
	printf("Enter name:");
	fflush(stdin);
	gets(emp.name);
	printf("Enter basic pay:");
	scanf("%f",&emp.bpay);
	fwrite(&emp,sizeof(emp),1,fp1);
	printf("\nDo you want to continue?");
	fflush(stdin);
	cont=getchar();
	printf("\n");
 }
 cont='y';
 while(cont=='y' || cont=='Y')
 {
	clrscr();
	printf("---------------MENU-------------");
	printf("\n1.Read");
	printf("\n2.Modify");
	printf("\n3.Delete");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			read(fp1);
			break;
		case 2:
			modify(fp1);
			break;
		case 3:
			fp2=fopen(name2,"w+");
			del(fp1);
			break;
	}
	printf("\n\nDo you want to continue?");
	fflush(stdin);
	cont=getchar();
 }
 getch();
}

void read(FILE *fp)
{
 rewind(fp);
 while((fread(&emp,sizeof(emp),1,fp))!=0)
 {
	printf("\nRegistration number=%d",emp.no);
	printf("\nName=%s",emp.name);
	printf("\nBasic pay=%.2f\n",emp.bpay);
 }
}

void modify(FILE *fp)
{
 int no,flag=0;
 long int sk=sizeof(emp);
 printf("Enter employee number:");
 scanf("%d",&no);
 rewind(fp);
 while((fread(&emp,sizeof(emp),1,fp))==1)
 {
	if(emp.no==no)
	{
		flag++;
		break;
	}
 }
 if(flag==0)
	printf("No such employee found");
 else
 {
	fseek(fp,-sk,1);
	printf("Enter new name:");
	fflush(stdin);
	gets(emp.name);
	printf("Enter new basic pay:");
	scanf("%f",&emp.bpay);
	fwrite(&emp,sizeof(emp),1,fp);
 }
 printf("Record modified successfully");
}

void del(FILE *fp)
{
  FILE *fp1;
  int no,flag=0;
  char name1[]="C:/emp.dat",name2[]="C:/tmp.dat";
  fp1=fopen(name2,"w+");
  printf("Enter employee number:");
  scanf("%d",&no);
  rewind(fp);
  while((fread(&emp,sizeof(emp),1,fp))!=0)
  {
	if(emp.no==no)
	{
		flag++;
		//printf("sfgs");
		break;
	}
  }
  if(flag==0)
	printf("\nNo such employee found");
  else
  {
	rewind(fp);
	while((fread(&emp,sizeof(emp),1,fp))!=0)
	{
		if(emp.no==no)
			continue;
		fwrite(&emp,sizeof(emp),1,fp1);
	}
  }
  printf("Record deleted successfully");
  fclose(fp);
  fclose(fp1);
  if((remove(name1))==0)
  if((rename(name2,name1))==0)
  fp=fopen(name1,"r+");
}