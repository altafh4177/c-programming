// 7.Reverse a string 

#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],temp;
	int i,j,str_len;
	puts("enter the string:");
	gets(str);
	//taking total size
	str_len=strlen(str)-1;
	//logic for reverse the string
	for(i=0,j=str_len;i<j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	puts(str);
}
	
