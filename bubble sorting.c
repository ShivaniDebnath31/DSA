//bubble sorting
#include<stdio.h>
int main()
{
	int i,j,check,temp;
	int a[]={1,2,4,3,5};
	for(i=0;i<4;i++)
	{
		check=0;
		for(j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				check=1;
			}
		}if(check==0)
		break;	}
		printf("After sorting\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
return 0;
}
