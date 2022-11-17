/*13. Write a function to return whether n-th bit from right-to-left is set in an integer. 
  bool is_nth_bit_set_from_left(int number, int n_th_bit);*/

#include<stdio.h>
int is_nth_bit_set_from_left(int number,int n_th_bit);
int main()
{
	int number,n_th_bit;
	printf("enter the number: ");
	scanf("%d",&number);
	printf("enter the nth bit: ");
	scanf("%d",&n_th_bit);
	//function call for nth bit set from left
	if(is_nth_bit_set_from_left(number,n_th_bit))
		printf("\nyes nth_bit is set from the right\n");
	else
		printf("\nno nth_bit is set from the right\n");
}

int is_nth_bit_set_from_left(int number,int n_th_bit)
{
	int bit;
	//binary equivalent of number
	for(bit=31;bit>=0;bit--) 
	{
		printf("%d",(number>>bit)&1);
	}
	// perticular bit is set of not 
	if((number>>n_th_bit)&1)
		return 1;
	else 
		return 0;
}


