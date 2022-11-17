// 2.Print Pascal triangle

#include<stdio.h>
int pascal(int n);
int main()
{
	int row,col,space,num_rows;
	printf("enter the number of rows: ");
	scanf("%d",&num_rows);
	//number of rows
	for(row=0; row<num_rows; row++) 
	{
		//space printing
		for(space=0;space<=(num_rows - row - 2);space++) 
			printf(" ");
		for(col=0; col<=row;col++) 
			// function call
			printf("%d ",pascal(row) / ( pascal(col) * pascal(row-col) ) ); 
		printf("\n");
	}
}

//function defination for calcuating pascal value
int pascal(int n)
{
	int i,mul=1;
	for(i=1;i<=n;i++)
		mul=mul*i;
	return mul;
}


