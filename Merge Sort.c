#include<stdio.h>
int length=8,arr[100]={23,17,53,6,-9,42,71,61}, ary[100];
void merge(int lb,int mid,int ub)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	while(i<=mid && j<=ub)
	{
		if(arr[i]<=arr[j])
			ary[k]=arr[i++];
		else
			ary[k]=arr[j++];
		k++;	
	}
	while(i<=mid)
	{
	   ary[k++]=arr[i++];
	}
	while(j<=ub)
	{
	   ary[k++]=arr[j++];
	}
	for(k=lb;k<=ub;k++)
	{
		arr[k]=ary[k];
	}
}
void mergesort(int lb,int ub)
{
    int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(lb,mid);
		mergesort(mid+1,ub);
		merge(lb,mid,ub);
	}	
}
int main()
{

    /*printf("Enter Array Length:");
	scanf("%d",&length);
	printf("Unsorted Element\n");
	for(int i=0;i<length;i++)
	{
		scanf("%d",&arr[i]);
	}*/
	mergesort(0,length-1);
	printf("Sorted Element\n");
	for(int i=0;i<length;i++)
	{
		printf("%5d",arr[i]);
	}
	
}