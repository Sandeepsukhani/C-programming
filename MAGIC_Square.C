#include<stdio.h>

int main()
{
 int mat[20][20],i=1,n,size,r,c,r1,c1,upr,lwr;
 printf("Enter size of matrix:");
 scanf("%d",&size);
 if(size%2==0 && size%4!=0)
 {
	printf("Size should be in multiple of 4 or it should be odd");
	return 1;
 }
 printf("\nMagic square of size %d*%d is:\n",size,size);
 n=size*size;
 for(r=0;r<size;r++)
 {
	for(c=0;c<size;c++)
		mat[r][c]=0;
 }
 if(size%2==0)
 {
	r=0;
	c=0;
	lwr=size/4;
	upr=size-lwr;
	for(r=0;r<size;r++)
	{
		for(c=0;c<size;c++)
		{
			if((r<lwr && c<lwr) || (c>=upr && r<lwr) || (r>=upr && c<lwr) || (r>=upr && c>=upr) )
				mat[r][c]=i;
			if((r>=lwr && c>=lwr) && (r<upr && c<upr))
				mat[r][c]=i;
			i++;
			n--;
		}
	}
	i=1;
	for(r=size-1;r>=0;r--)
	{
		for(c=size-1;c>=0;c--)
		{
			if(mat[r][c]==0)
				mat[r][c]=i;
			i++;
		}
	}
 }
 else
 {
	r=0;
	c=size/2;
	while(n)
	{
		mat[r][c]=i;
		r1=r;
		c1=c;
		if(r==0)
			r=size-1;
		else
			r--;
		if(c==size-1)
			c=0;
		else
			c++;
		if(mat[r][c]!=0)
		{
			r=r1;
			c=c1;
			r++;
		}
		n--;
		i++;
	}
 }
 for(r=0;r<size;r++)
 {
	for(c=0;c<size;c++)
	{
		if(mat[r][c]<10)
			printf(" %d ",mat[r][c]);
		else
			printf("%d ",mat[r][c]);
	}
	printf("\n");
 }
 return 0;
}



