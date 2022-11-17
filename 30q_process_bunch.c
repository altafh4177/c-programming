//30. Process bunch of inputs arguments and print them

#include<stdio.h>
//command line argument
int main(int argc,char **argv)
{
	printf("total number of argument is %d\n",argc);
	//print each argument
	for(int i=0;i<argc;i++)
	{
		printf("argv[%d] = %s\n",i,argv[i]);
	}
}


