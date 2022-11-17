// 5.Write sorting algorithm

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int *arr=NULL,i,j,temp,n;
	printf("enter the n value: "); 
	//no of elements
	scanf("%d",&n);
	arr=calloc(n,4);
	// generate diffrent sequence
	srand(getpid()); 
	//scaning array elements
	for(i=0;i<n;i++)
	{
		//genarate diffrent number
		arr[i]=rand()%150;
	}
	printf("before sorting\n");
	// printing the array before sorting
	for(i=0;i<n;i++)
		printf("%d ",arr[i]); 
	// logic for bubble sorting
	for(i=n-1;i>0;i--) 
	{
		for(j=0;j<i;j++)
		{
			//compairing the elsments
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nafter sorting\n");
	// printing the array after sorting
	for(i=0;i<n;i++)
		printf("%d ",arr[i]); 
}


