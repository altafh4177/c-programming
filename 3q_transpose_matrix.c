// 3.Write a program to do matrix transpose (2d matrix)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int row,col,i,j;
	printf("enter the row and col:");
	scanf("%d%d",&row,&col);
	int arr[row][col],dup[row][col];
	//srand for diffrent sequence
	srand(getpid()); 
	for(i=0;i<row;i++)
	{
		// scaning array using rand function
		for(j=0;j<col;j++)
			arr[i][j]=rand()%101; 
	}
	for(i=0;i<row;i++)
	{
		//printing the array
		for(j=0;j<col;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}


	for(i=0;i<row;i++)
	{
		//transpose logic
		for(j=0;j<col;j++)
			dup[j][i]=arr[i][j];
	}
	printf("after\n");
	for(i=0;i<row;i++)
	{
		//printing array after transpose
		for(j=0;j<col;j++)
			printf("%3d ",dup[i][j]);
		printf("\n");
	}




}



