//selection sorting
#include<stdio.h>
int main()
{
	int i,j,temp;
	int a[5]={30,50,20,10,40};
	printf("Before sorting\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(a[i]>a[j])
			{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}
	printf("After sorting\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
}
