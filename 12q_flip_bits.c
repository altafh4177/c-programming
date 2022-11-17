//12. Flip bits of a given integer 

#include<stdio.h>
#include<string.h>
int main()
{
	int num,bit;
	puts("enter the number");
	scanf("%d",&num);
	//before flip binary representation
	puts("before flip");
	for(bit=31;bit>=0;bit--)
	{
		printf("%d",(num>>bit)&1);
		if(bit%8==0)
			printf(" ");
	}
	// logic for fliping
	for(bit=31;bit>=0;bit--)

	{
		num=num^(1<<bit);
	}
	puts("\nafter flip");
	// after flip binary representation
	for(bit=31;bit>=0;bit--)
	{
		printf("%d",(num>>bit)&1);
		if(bit%8==0)
			printf(" ");
	}
}

