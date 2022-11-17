// Program for calculating difference of read/write duration script

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function declarations
void read_diff(int *read_arr,int j);
void min_max_avg(int *arr,int i);
void write_diff(int *write_arr,int j);

int main(int argc,char **argv)
{
	FILE *fp;
	char read[10]="pcm_read",write[10]="pcm_write";
	char line[200],*ptr=NULL,*qtr=NULL;
	int *read_arr=NULL,*write_arr=NULL;
	int r=0,w=0,read_num=0,write_num=0,j=0,k=0;
	
	//file open in read mode
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("file not exist\n");
		return 0;
	}
	//fetching file line by line
	while(fgets(line,200,fp))
	{
		ptr=line;
		qtr=line;
		r=0;
		w=0;
		//searching pcm_read
		if(ptr=strstr(ptr,read))
		{
			r=1;
		}
		if(r==1)
		{
			ptr=line;
			//searching date
			if(ptr=strstr(ptr,"2022-11-11"))
			{
				ptr=ptr+11;
				read_num=0;
				//converting pcm_read time in integer
				for(int i=0;i<12;i++)
				{
					if(ptr[i]>='0' && ptr[i]<='9')
						read_num=read_num*10+ptr[i]-48;
				}
				// storing time in dynamic allocated array
				read_arr=realloc(read_arr,(j+1)*4);
				read_arr[j++]=read_num;
			}
		}

		// searchin pcm_write
		if(qtr=strstr(qtr,write))
                {
                        w=1;
                }
                if(w==1)
                {
                        qtr=line;
			//searching date
                        if(qtr=strstr(qtr,"2022-11-11"))
                        {
                                qtr=qtr+11;
                                write_num=0;
				//convetring pcm_write date into interger
                                for(int i=0;i<12;i++)
                                {
                                        if(qtr[i]>='0' && qtr[i]<='9')
                                                write_num=write_num*10+qtr[i]-48;
                                }
				// storing time in dynamicall array
                                write_arr=realloc(write_arr,(k+1)*4);
                                write_arr[k++]=write_num;
                        }
               	}
	}
	//file close
	fclose(fp);
	//function call for successive "pcm read"
	printf("\n######### time and difference of pcm read ########\n");
	printf("\n");
	read_diff(read_arr,j);
	//function call for successive "pcm write"
	printf("\n######### time and difference of pcm write ########\n");
	printf("\n");
	write_diff(write_arr,k);
}

//function defination for read difference
void read_diff(int *read_arr,int j)
{
	int i,*diff_read_arr=NULL,n=0,k;
	for(i=0;i<j-1;i++)
	{
		n=0;
		//memory allocting for storing difference
		diff_read_arr=realloc(diff_read_arr,(i+1)*4);
		//calculating difference between two successive "pcm read"
		n=read_arr[i+1]-read_arr[i];
		//difference storing in array
		diff_read_arr[i]=n;
	}
	//printing time and difference
	for(k=0;k<j-1;k++)
	    printf("SL.NO-> %d  pcm_read[%d] = %d---> diff[%d] - diff[%d] = %d\n",k,k,read_arr[k],k+1,k,diff_read_arr[k]);
	printf("SL.NO-> %d  pcm_read[%d] = %d\n",k,k,read_arr[k]);
	// function call for max,min and average "pcm read"
	min_max_avg(diff_read_arr,i);
}

//function defination for write difference
void write_diff(int *write_arr,int j)
{
        int i,*diff_write_arr=NULL,n=0,k;

        for(i=0;i<j-1;i++)
        {
                n=0;
		//memory allocting for storing difference
                diff_write_arr=realloc(diff_write_arr,(i+1)*4);
		//calculating difference between two successive "pcm write"
                n=write_arr[i+1]-write_arr[i];
		//difference storing in array
                diff_write_arr[i]=n;
        }
	//printing time and difference
        for(k=0;k<j-1;k++)
           printf("SL.NO-> %d  pcm_write[%d] = %d---> diff[%d] - diff[%d] = %d\n",k,k,write_arr[k],k+1,k,diff_write_arr[k]);
        printf("SL.NO-> %d  pcm_write[%d] = %d\n",k,k,write_arr[k]);
	// function call for max,min and average of "pcm write"
        min_max_avg(diff_write_arr,i);
	
}

//function defination for min, max and average
void min_max_avg(int *arr,int i)
{
        int min,max,avg=0,total_avg,j;
	//storing first element in min and max
        min=max=arr[0];
        for(j=0;j<i;j++)
        {
		//total sum of all difference for calculating average
                avg=avg+arr[j];
		// logic for maximum
                if(arr[j]>max)
                        max=arr[j];
		//logic for minmum
                if(arr[j]<min)
                        min=arr[j];
        }
	//total average
        total_avg=avg/i;
	// printing min max average and total average
        printf("min=%d max=%d avg=%d total_avg=%d\n",min,max,avg,total_avg);
}

