//26. How much stack is consumed in a given function

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<unistd.h>
#pragma pack(1)
struct node
{
        char name[50];
        int roll;
        struct node *link;
};

//function declarations
void display(struct node *root);
struct node *add_node(struct node *root);

//global variable
int total_size=0;

int main()
{
        struct node str,*head=NULL;
        int choice,n;
/*	printf("size=%d\n",sizeof(struct node));
	printf("size=%d\n",sizeof(str));
	printf("size=%d\n",sizeof(str.name));
	printf("size=%d\n",sizeof(str.roll));
	printf("size=%d\n",sizeof(str.link));*/

        while(1)
        {
                printf("#### MENU #####\n");
                printf("1.add_node\n2.display\n3.total_size_of_stack\n4.quit\n");
                printf("enter the choice: ");
                __fpurge(stdin);
                scanf("%d",&choice);
                switch(choice)
                {
			//function call for adding the data
                        case 1:head=add_node(head);
                               break;
			//function call for display
                        case 2:display(head);
                               break;
			//printing the total size consumed
			case 3:printf("********* total stack consumed is %d *********\n",total_size);
			       break;
                        case 4:return 0;
                        default:printf("invalid choice\n");
                }
        }
}

//function defination for adding the data
struct node *add_node(struct node *root)
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
		//calcuting size
                total_size=total_size+sizeof(struct node);
		//adding the data
                printf("enter name\n");
                __fpurge(stdin);
                gets(newnode->name);
                printf("enter the roll\n");
                scanf("%d",&newnode->roll);
                if(root==NULL)
                        root=newnode;
                else
                {
                        temp=root;
			//loop for connecting the new node to old node
                        while(temp->link)
                        {
                                temp=temp->link;
                        }
                        temp->link=newnode;
                }

        }
        return root;
}

//function defination for display
void display(struct node *root)
{
        if(root==NULL)
                printf("list is empty\n");
        else
        {
                printf("**********output display*********\n");
                while(root)
                {
                        printf("%d %s\n",root->roll,root->name);
                        root=root->link;
                }
        }
}


