/*15. Write a function to find endianness (big-endian or little-endian) of CPU. 
bool is_little_endian(); */

#include<stdio.h>
int main()
{
	int var=0x12345678;
	char *p;
	p=&var;
	//compairing lower address one byte data to char pointer p which hold the lower addrerss
	if(*p==0x78) 
		printf("CPU is little endian\n");
	//if not equal than CPU  is big endian
	else
		printf("CPU is big endian");
}
