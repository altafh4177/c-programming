// 9.Highest frequency of a character in a given string

#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],ch_var,*ptr;
	int freq_ch=0;
	//scaning the string
	puts("enter the string");
	gets(str);
	//scaning the character
	puts("enter the character");
	ch_var=getchar();

	ptr=str;
	//checking the character in string
	while(ptr=strchr(ptr,ch_var))
	{
		freq_ch++;
		ptr++;
	}
	printf("highest freq of character %c is %d\n",ch_var,freq_ch);
}


