#include<stdio.h>
#include<conio.h>
void main()
{
 int *mat,*mat2,*rmax,*cmin,m,n,i,j,x,y,min,max;
 clrscr();
 printf("Enter the size(m*n) of matrix:");
 scanf("%d%d",&m,&n);
  mat=(int *)malloc((m*n)*sizeof(int));
  rmax=(int *)malloc(m*sizeof(int));
  cmin=(int *)malloc(n*sizeof(int));
  mat2=mat;
  printf("Enter the values of matrix\n");
  for(i=0;i<m;i++)
  {
	y=wherey();
	y++;
	x=1;
	gotoxy(x,y);
	for(j=0;j<n;j++)
	{
		x=x+2;
		gotoxy(x,y);
		scanf("%d",mat);
		mat++;
	}
  }
  /*Assigning first element of every row to row max*/
  for(i=0;i<m;i++)
  {
	*rmax=*(mat2+(i*n));
	rmax++;
  }
  /*Assigning first element of every column to column min*/
  for(i=0;i<n;i++)
  {
	*cmin=*(mat2+i);
	cmin++;
  }
  cmin=cmin-n;
  rmax=rmax-m;
  mat=mat2;
  /*Finding row max*/
  for(i=0;i<m;i++)
  {
  /*Moving pointer to first row element*/
	mat=mat2+(n*i);
	for(j=0;j<n-1;j++)
	{
		mat++;
		if(*mat>*rmax)
			*rmax=*mat;
	}
	rmax++;
  }
  mat=mat2;
  for(i=0;i<n;i++)
  {
  /*Moving pointer to first column element*/
	mat=mat2+i;
	for(j=0;j<m-1;j++)
	{
		mat=mat+n;
		if(*mat<*cmin)
		*cmin=*mat;
	}
	cmin++;
   }
   cmin=cmin-(n);
   rmax=rmax-(m);
   /*Assigning first element of row max to min*/
   min=*rmax;
   /*Assigning first element of column min to max*/
   max=*cmin;
   /*Finding min of row max*/
   for(i=0;i<m-1;i++)
   {
	rmax++;
	if(min>*rmax)
	min=*rmax;
   }
   /*Finding max of column min*/
   for(j=0;j<n-1;j++)
   {
	cmin++;
	if(max<*cmin)
	max=*cmin;
    }
    if(max==min)
	printf("Saddle point=%d",max);
    else
	printf("It has no saddle point");
    getch();
   }
