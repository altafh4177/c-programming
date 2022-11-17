// 4.Print prime factors of a given number 

#include<stdio.h>
int main()
{
	int i,j,num,flag;
	printf("enter the number: ");
	// scaning number
	scanf("%d",&num);  
	for(i=2;i<=num;i++)
	{
		// logic for checking factors
		if(num%i==0) 
			flag=1;
		// factors which gives zero as remainder but no a factor of integer
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		// if flag is 1 then it is factor
		if(flag==1) 
			printf("%d ",i);
	}
}
