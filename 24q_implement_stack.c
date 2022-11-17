// 24.Implement stack C

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *link;
};

//function declarations
int pop();
void push(int);
int peek();
void display(struct stack *ptr);

//global variable
struct stack *top;

int main()
{
	int val,choice;
	while(1)
	{
		printf("1.push 2.pop 3.peek 4.display 5.qiut\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			//function call for addinf the data in stack
			case 1:printf("enter the data\n");
			       scanf("%d",&val);
			       push(val);
			       break;
			case 2: if(top==NULL)
					printf("stack is empty\n");
				else
					//function call for deleting the data from the top
					printf("data poped is %d\n",pop());
				break;
			case 3: if(top==NULL)
					printf("stack is empty\n");
				else
					//function call to know where is the current location
					printf("data pointed by top of the stack is %d\n",peek());
				break;
				// function call for display
			case 4: display(top);
				break;
			case 5: return 0;
			default:printf("invalid input\n");
		}
	}
}

// function defination for adding the data from the top
void push(int val)
{
	struct stack *newnode=NULL;
	//creating the new node
	newnode=calloc(1,sizeof(struct stack));
	if(newnode==NULL)
		printf("not enough memory\n");
	else
	{
		//adding the data to new node
		newnode->data=val;
		newnode->link=top;
		top=newnode;
	}
}

//function defination for deleting the data from the top
int pop()
{
	struct stack *temp=NULL;
	int d;
	temp=top;
	top=top->link;
	d=temp->data;
	free(temp);
	temp=NULL;
	return d;
}

int peek()
{
	return top->data;
}

void display(struct stack *ptr)
{
	if(ptr==NULL)
		printf("list is empty\n");
	else
	{
		while(ptr)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}

















