/* 22. Write a function to suppress a given character in the provided string. 
char * suppress_in_string(char *str, char c); */

#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
char *my_string();
void suppress_in_string(char *str, char c);
int main()
{
	char *str=NULL,c,*temp=NULL,*ptr;
	int i,size;
	puts("enter the string:");
	//function call for user define my string
	str=my_string();
	puts("enter the character for suppress");
	__fpurge(stdin);
	c=getchar();
	suppress_in_string(str,c);
	printf("after suppres--> %c string is %s\n",c,str);
}

//function defination for suppressing the character
void suppress_in_string(char *str, char c)
{
	char *ptr;
	ptr=str;
	while(ptr=strchr(ptr,c))
	{
		//suppress logic
		memmove(ptr,ptr+1,strlen(ptr+1)+1);
	}
}

// user define my string funtion defination
char *my_string()
{
	char *ptr=NULL;
	int i=0;
	do{
		ptr=realloc(ptr,i+1);
		ptr[i]=getchar();
	}while(ptr[i++]!='\n');
	ptr[i]='\0';
	return ptr;
}


