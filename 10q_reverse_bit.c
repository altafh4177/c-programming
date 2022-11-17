//10. Reverse bits in a given integer

#include<stdio.h>
int main()
{
	int num,bit,i,j;
	printf("enter the number: ");
	scanf("%d",&num);
	//before reverse number and binary representation
	printf("before reverse number is %d\n",num); 
	for(bit=31;bit>=0;bit--)
	{
		printf("%d",(num>>bit)&1);
		if(bit%8==0)
			printf(" ");
	}
	//reverse logic
	for(i=0,j=31;i<j;i++,j--) 
	{
		if(((num>>i)&1)!=((num>>j)&1))
		{
			num=num^(1<<i);
			num=num^(1<<j);
		}
	}
	//after reverse number and boinary representation
	printf("\nafter reverse number is %d\n",num); 

	for(bit=31;bit>=0;bit--)
	{
		printf("%d",(num>>bit)&1);
		if(bit%8==0)
			printf(" ");
	}
}
