// 8.Find length of a given string 

#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int len_str=0,i,len;
	puts("enter string");
	gets(str);
	len=strlen(str); // 1st way

	for(i=0;str[i];i++)//2nd way
	{
		len_str++;
	}
	printf("string length 1st way: %d\n",len_str);
	printf("string length 2nd way: %d\n",len);
}

