// 14.How much memory is allocated for a given integer array

#include<stdio.h>
int main()
{
	int arr[20],sizeof_one_elem,total_element,total_sizeof_array;
	printf("memory allocated in given integer array is first way %lu\n",sizeof(arr)); //one way

	//it will give total elements in array
	total_element=sizeof(arr)/sizeof(arr[0]); 
       	//it will give one element size of array 
	sizeof_one_elem=sizeof(arr[0]);
       	//it wiil give total memory allocated in the given array
	total_sizeof_array=total_element*sizeof_one_elem;
	printf("memory allocated in given integer array is second way %d\n",total_sizeof_array);
}

