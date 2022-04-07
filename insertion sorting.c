//insertion sorting
#include<stdio.h>
int main()
{
	int i,j,temp;
	int a[]={4,2,1,5,3};
	printf("Before sorting\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	for(i=1;i<5;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 && temp<a[j];j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
	printf("After sorting\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
