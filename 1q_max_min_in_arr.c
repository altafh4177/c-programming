// 1.Find max/min in a given array

#include<stdio.h>
#include<string.h>
int main()
{
	int arr[50],max,min,i,n;
	puts("enter the n value");
	scanf("%d",&n);
	puts("enter the elements");
	//taking input 
	for(i=0;i<n;i++) 
	{
		scanf("%d",&arr[i]);
	}
	//assigning first element to max and min varialbe
	max=min=arr[0]; 

	for(i=0;i<n;i++)
	{
		//printing elemnets of array
		printf("%d ",arr[i]);

		//logic for checking maximum
		if(arr[i]>max)  
			max=arr[i];
		// logic for checking minimum
		if(arr[i]<min)  
			min=arr[i];
	}
	printf("\nmax= %d min= %d\n",max,min);
}


