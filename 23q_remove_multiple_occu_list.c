// 23. How to remove the multiple occurrence of numbers in a list? 

#include<stdio.h>
#include<stdlib.h>
//#include<stdio_ext.h>

struct node
{
	int number;
	struct node *link;
};

// function declations
struct node *add(struct node *root);
void remove_multiple(struct node *root);
void display(struct node *root);

int main()
{
	struct node *head=NULL;
	int choice;
	while(1)
	{
		printf("1.add\n2.display\n3.remove_duplicate\n4:quit\n");
		printf("enter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			//function call for adding the data
			case 1:head=add(head);
			       break;
			//function call for display
			case 2:display(head);
			       break;
			//function call for removing multi occurrence
			case 3:remove_multiple(head);
			       break;
			case 4:return 0;
			default:printf("invalid choice\n");
		}
	}
}

//function defination for adding the data
struct node *add(struct node *root)
{
        struct node *newnode=NULL,*temp=NULL;
	//creating the new node
        newnode=calloc(1,sizeof(struct node));
        if(newnode==NULL)
        {
                printf("not enough memory\n");
        }
        else
        {
		//adding the data to new node
                printf("enter the number\n");
                scanf("%d",&newnode->number);
                if(root==NULL)
                        root=newnode;
                else
                {
                        temp=root;
			//assiging the new node to next node link
                        while(temp->link)
                        {
                                temp=temp->link;
                        }
                        temp->link=newnode;
                }

        }
        return root;
}

//function defination for removing multi occurrence
void remove_multiple(struct node *root)
{
	struct node *next=NULL,*temp=NULL,*dup;
	next=root;
	//loop iteration
	while(next && next->link)
	{
		temp=next;
		while(temp->link)
		{
			//checking the multi data
			if(next->number == temp->link->number)
			{
				//logic for deleting the node if found
				dup=temp->link;
				temp->link=temp->link->link;
				free(dup);
			}
			else
				temp=temp->link;
		}
		next=next->link;
	}
}

//function defination for dispaly
void display(struct node* root)
{
	if(root==NULL)
	{
		printf("lint is empty\n");
	}
	else
	{
		while(root)
		{
			printf("%d\n",root->number);
			root=root->link;
		}
	}
}
