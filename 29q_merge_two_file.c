/*29. File IO: Two files are on disk. One file has integers and the other has words/text. 
	Write a program to merge the two files into a single file. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *file1,*file2;
	int size1=0,size2=0;
	char *buff1=NULL;
	//file1 open in append + mode
	file1=fopen("file1.txt","a+");
	//if file pointer is NULL THEN file1 not present 
	if(file1==NULL)
	{
		printf("file1 not exist\n");
		return 0;
	}
	//file2 open in append + mode
	file2=fopen("file2.txt","a+");
	//if file pointer is NULL THEN file2 not present 
	if(file2==NULL)
	{
		printf("file2 not exist\n");
		return 0;
	}
	//calculating the size of file1 
	fseek(file1,0,2);
	size1=ftell(file1);
	//rewinding the file2
	rewind(file1);
	
	//memory alloction to buff1
	buff1=calloc(size1,1);
	//appending file1 data to file2 
	while(!feof(file1))
	{
		fgets(buff1,size1,file1);
		fprintf(file2,"%s",buff1);
	}
	rewind(file2);
	//after appending file2 is
	while(!feof(file2))
	{
		fgets(buff1,size1,file2);
		printf("%s",buff1);
	}
	fclose(file1);
	fclose(file2);
}




