// 6.LCM, GCD of ‘n’ numbers (say 5 numbers)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int *arr=NULL,size,j,i,min,cnt=0,gcd,lcm=1;
	printf("enter the size: ");
	scanf("%d",&size);
	// memory allocation
	arr=calloc(size,4);
	srand(getpid());
	//input
	printf("enter the numbers\n"); 
	for(i=0;i<size;i++)
	{
		input:scanf("%d",&arr[i]);
		if(arr[i]<=0)
		{
			printf("wrong number enter again\n");
			goto input;
		}
		//arr[i]=rand()%200;
	}
	//array printing
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	// assigning 0th element in min
	min=arr[0];
	for(i=0;i<size;i++)
	{
		//storing min element of array
		if(arr[i]<min) 
			min=arr[i]; 
	}
	//n numbers gcd finding
	for(i=1;i<=min;i++)
	{
		cnt=0;
		for(j=0;j<size;j++)
		{
			if(arr[j]%i==0)
				cnt++;
			else 
				break;
		}
		if(cnt==size)
			gcd=i;
	}
	//lcm logic
	for(i=0;i<size;i++)
		lcm=lcm*arr[i];
	lcm=lcm/gcd; 
	printf("lcm= %d gcd =%d\n",lcm,gcd);
}


