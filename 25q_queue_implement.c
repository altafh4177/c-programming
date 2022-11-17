// 25. Implement queue in C 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct queue
{
        int data;
        struct queue *link;
};

//function declarations
void enq(int);
int deq();

//global variable
struct queue *rear,*front;

int main()
{
        int val,choice;
        while(1)
        {
                printf("1.Enq 2.deq 3.qiut\n");
                printf("enter the choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
			//function call for adding the data from rear end
                        case 1:printf("enter the data\n");
                               scanf("%d",&val);
                               enq(val);
                               break;
                        case 2: if(front==NULL)
                                        printf("queue is empty\n");
                                else
					//function call for deleting the data from the rear end
                                        printf("data deleted is %d\n",deq());
                                break;
                        case 3: return 0;
                        default:printf("invalid input\n");
                }
        }
}

// funtion for adding the data 
void enq(int val)
{
        struct queue *newnode=NULL;
	//creating newnode
        newnode=calloc(1,sizeof(struct queue));
        if(newnode==NULL)
                printf("not enough memory\n");
        else
        {
                newnode->data=val;
		if(front==NULL)
			front=newnode;
		else
			rear->link=newnode;
                rear=newnode;
        }
}

//function for deleteing the data from rear
int deq()
{
        struct queue *temp=NULL;
        int d;
        temp=front;
        front=front->link;
	if(front==NULL)
		rear=NULL;
        d=temp->data;
        free(temp);
        temp=NULL;
        return d;
}
