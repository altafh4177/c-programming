//11. Set/reset bits of a given integer (particular bit positions)

#include<stdio.h>
#include<string.h>
void binary(int);
int main()
{
	int choice,num,bit_pos;
	puts("enter the number");
	scanf("%d",&num);
	input:puts("enter the bit position you want to clear or reset");
	scanf("%d",&bit_pos);
	if(bit_pos<0 || bit_pos>31)
	{
		printf("enter valid bit position between(0 to 31)\n");
		goto input;
	}
       	//enter the choice 1 for clear and 2 for reset
	printf("1.clear_bit 2.reset_bit 3.quit\n");
	puts("enter the choice");
	scanf("%d",&choice);
	switch(choice)
	{
		       //logic for clear the bit
		case 1:printf("number and binary_eq before clear is %d\n",num);
		       binary(num);
		       num=num&(~(1<<bit_pos));
		       printf("\nnumber and binary_eq after clear is %d\n",num);
		       binary(num);
		       break;
		       //logic for reset the bit
		case 2:printf("number and binary before reset is %d\n",num);
		       binary(num);
		       num=num|(1<<bit_pos);
		       printf("number and binary after reset is %d\n",num);
		       binary(num);
		       break;
		default:puts("invalid choice");
	}

}


void binary(int num)
{
	int bit;
	for(bit=31;bit>=0;bit--)
		printf("%d",(num>>bit)&1);
	printf("\n");
}

