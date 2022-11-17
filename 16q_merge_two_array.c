// 16.Write a program to merge two arrays, use pointers

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int *arr1=NULL,*arr2=NULL,size,i,*ptr,j;
	printf("enter the size: ");
	scanf("%d",&size);
	arr1=calloc(size,4);
	arr2=calloc(size,4);
	srand(getpid());
	//input for array 1
	for(i=0;i<size;i++)
		arr1[i]=rand()%150;
	// input for array 2
	for(i=0;i<size;i++)
		arr2[i]=rand()%150;
	printf("array 1\n");
	//printing array 1
	for(i=0;i<size;i++)
		printf("%d ",arr1[i]);
	printf("\narray 2\n");
	// printing array 2
	for(i=0;i<size;i++)
		printf("%d ",arr2[i]);

	arr1=realloc(arr1,size*sizeof(arr2[0]));
	ptr=arr2;
	//merging of array1 and array2
	for(i=0,j=size;i<size;i++,j++) 
	{
		arr1[j]=*(ptr+i);
	}
	printf("\nafter merge\n"); 
	//after merge
	for(i=0;i<size*2;i++)
		printf("%d ",arr1[i]);
	printf("\n");


}
