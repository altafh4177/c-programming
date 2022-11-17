/*17. Insert node in a given linked list.

  20. Write a function to find Mth-to-last node of a singly linked list. 
  strcut node * find_mth_node_from_last(struct node *root, int n);

  21. Write a function to delete n-th node from reverse of a singly linked list. 
  struct node * delete_nth_node(struct node *root, int n); */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<unistd.h>
struct node
{
	char name[50];
	int roll;
	struct node *link;
};

// all funtion declaration
int total_node_cnt=0;
struct node *add_first(struct node *root);
void display(struct node *root);
struct node *add_last(struct node *root);
struct node* insert(struct node *root);
struct node *delete_nth_node_from_reverse(struct node *root,int nth);
void mth_to_last_node(struct node *root,int n);

//main funtion
int main()
{
	struct node *head=NULL;
	int choice,mth,nth;
	while(1)
	{
		printf("#### MENU #####\n");
		// choice the number to call the particular funtion 
		printf("1.add_first\n2.display\n3.add_last\n4.insert\n5.quit\n6.delete nth node from reverse\n7.mth_to_last_node\n");
		printf("enter the choice: ");
		__fpurge(stdin);
		scanf("%d",&choice);
		switch(choice)
		{
			// function call for adding the data at first
			case 1:head=add_first(head);
			       break;
			// display funtion call
			case 2:display(head);
			       break;
			//function call for adding the data at last
			case 3:head=add_last(head);
			       break;
			//function for inserting the data
			case 4:head=insert(head);
			       break;
			case 5:return 0;
			//function for deleting the data from the reverse 
			case 6:printf("enter the nth node to be delete from reverse\n");
			       scanf("%d",&nth);
			       head=delete_nth_node_from_reverse(head,nth);
			       break;
			// function call for printing the fron mth node
			case 7:printf("enter the mth node\n");
			       scanf("%d",&mth);
			       mth_to_last_node(head,mth);
			       break;
			default:printf("invalid choice\n");
		}
	}
}

//function defination for adding the data at first
struct node *add_first(struct node *root)
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
		//adding the data in new node
		printf("enter name\n");
		__fpurge(stdin);
		gets(newnode->name);
		printf("enter the roll\n");
		scanf("%d",&newnode->roll);
		newnode->link=root;
		root=newnode;
		total_node_cnt++;
		printf("total node in list=%d\n",total_node_cnt);
	}

	return root;
}

// function defination for display
void display(struct node *root)
{
	printf("total node in list=%d\n",total_node_cnt);
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

//function defination for adding the data at last
struct node *add_last(struct node *root)
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
		//adding the data to last
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
			while(temp->link)
			{
				temp=temp->link;
			}
			temp->link=newnode;
		}

		total_node_cnt++;
		printf("total node in list=%d\n",total_node_cnt);
	}
	return root;
}

//function defination for deleting nth node from reverse
struct node *delete_nth_node_from_reverse(struct node *root,int nth)
{
	struct node *prev_ptr=NULL,*curr_ptr=NULL,*next_ptr=NULL,*temp=NULL;
	next_ptr=root;
	if(root==NULL)
		printf("list is empty\n");
	else if(root->link==NULL)
		printf("list contain one node only\n");
	else
	{
		int temp_cnt=0;
		while(next_ptr)
		{
			temp_cnt++;
			//node checking which is to be deleted
			if(nth==temp_cnt)
				// if found then store the adderss to temp 
				temp=next_ptr;
			next_ptr=next_ptr->link;
		}
		next_ptr=root;
		//reversing the list
		while(next_ptr)
		{
			prev_ptr=curr_ptr;
			curr_ptr=next_ptr;
			next_ptr=next_ptr->link;
			curr_ptr->link=prev_ptr;
		}
		root=curr_ptr;
		printf("*********reverse done now call display function*********\n");
		display(root);
		next_ptr=root;
		prev_ptr=NULL;
		curr_ptr=NULL;
		//after reverse comparing the temp to deleting node
		while(next_ptr)
		{
			prev_ptr=curr_ptr;
			curr_ptr=next_ptr;
			// if found then delete
			if(next_ptr==temp)
			{
				prev_ptr->link=curr_ptr->link;
				free(next_ptr);
				curr_ptr=NULL;
				next_ptr=NULL;
				total_node_cnt--;
				break;
			}
			next_ptr=next_ptr->link;
		}

		printf("*********deleting done calling display function**********\n");
		sleep(5);
		display(root);

	}
	return root;
}

//function defination for inserting the node
struct node * insert(struct node *root)
{
	struct node *next=NULL,*newnode=NULL,*prev=NULL,*curr=NULL;
	int index,cnt=0;
	//creating the new node
	newnode=calloc(1,sizeof(struct node));
	if(newnode==NULL)
		printf("not enough memory\n");
	else
	{
		//adding data to new node
		printf("enter name\n");
		__fpurge(stdin);
		gets(newnode->name);
		printf("enter the roll\n");
		scanf("%d",&newnode->roll);
		if(root==NULL)
			root=newnode;
		else
		{
			input:printf("enter index to insert\n");
			scanf("%d",&index);
			if(index < 1 || index > total_node_cnt)
			{
				printf("invalid index enter valid index\n");
				goto input;
			}

			next=root;
			// inserting the node at specific index
			while(next)
			{
				cnt++;
				prev=curr;
				curr=next;
				if(cnt==index)
				{
					prev->link=newnode;
					newnode->link=curr;
					break;
				}
				next=next->link;
			}
		}
		total_node_cnt++;
		printf("cnt=%d\n",total_node_cnt);
	}
	return root;
}

//function defination for printing mth node 
void mth_to_last_node(struct node *root,int n)
{
	struct node *temp;
	int temp_cnt=0;
	if(root==NULL)
		printf("list is empty");
	else
	{
		temp=root;
		while(temp)
		{
			temp_cnt++;
			//searching the count if found then display
			if(n==temp_cnt)
			{
				display(temp);
				break;
			}
			temp=temp->link;
		}
		printf("envalid mth node\n");
	}

}












