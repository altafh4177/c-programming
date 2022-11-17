/* 18. Write a function to convert string to integer, equivalent of atoi(). 
   int my_atoi(char *str);*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *mystring();
int my_atoi(char *str);
int main()
{
	char *str=NULL;
	int num;
	//user define my string
	str=mystring(); 
	// function call atoi and collect in num
	num=my_atoi(str); 
	printf("%d\n",num);
}

//function defination for my string
char *mystring() 
{
	char *ptr=NULL;
	int i=0;
	do{
		// using realloc allocating one byte according to requirement
		ptr=realloc(ptr,i+1); 
		//scaning onre character
		ptr[i]=getchar(); 
		//when hit enter then loop terminates
	}while(ptr[i++]!='\n'); 
	//replace new line witn NULL
	ptr[i]='\0'; 
	return ptr;
}

int my_atoi(char *str)
{
	int i,num=0;
	for(i=0;str[i];i++)
	{
		//checking only numeric other than numeric break
		if(str[i]>='0' && str[i]<='9') 
			//converting numeric character to interger
			num=num*10+str[i]-48; 
		else 
			break;
	}
	return num; 
}



