/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
	return NULL;
	if (head2 == NULL&&head1 != NULL)
		return head1;
	if (head1 == NULL&&head2 != NULL)
		return head2;
	struct node *head=NULL,*temp = NULL, *temp1 = NULL, *temp2 = NULL, *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	head = newnode;
	temp = newnode;
	temp1 = head1;
	temp2 = head2;
	if (temp1->num < temp2->num)
	{
		newnode->num = temp1->num;
		newnode->next = NULL;
		temp1=temp1->next;
	}
	if (temp1->num > temp2->num)
	{
		newnode->num = temp2->num;
		newnode->next = NULL;
		temp2 = temp2->next;
	}
	if (temp1->num == temp2->num)
	{
		newnode->num = temp1->num;
		newnode->next = NULL;
		temp1 = temp1->next;
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->num = temp2->num;
		newnode->next = NULL;
		temp->next = newnode;
		temp = newnode;
		temp2 = temp2->next;
	}
	while (1)
	{
		if (temp1 == NULL&&temp2 == NULL)
			break;
		if (temp2 == NULL&&temp1->next != NULL)
		{
			while (temp1->next != NULL)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp1->num;
				newnode->next = NULL;
				temp->next = newnode;
				temp = newnode;
				temp1 = temp1->next;
			}
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp1->num;
			newnode->next = NULL;
			temp->next = newnode;
			temp = newnode;
			break;
		}
		if (temp1 == NULL&&temp2->next != NULL)
		{
			while (temp2->next != NULL)
			{
				newnode = (struct node *)malloc(sizeof(struct node));
				newnode->num = temp2->num;
				newnode->next = NULL;
				temp->next = newnode;
				temp = newnode;
				temp2 = temp2->next;
			}
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp2->num;
			newnode->next = NULL;
			temp->next = newnode;
			temp = newnode;
			break;
		}
		if (temp1->num < temp2->num)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp1->num;
			newnode->next = NULL;
			temp->next = newnode;
			temp = newnode;
			temp1 = temp1->next;
		}
		if (temp2->num < temp1->num)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp2->num;
			newnode->next = NULL;
			temp->next = newnode;
			temp = newnode;
			temp2 = temp2->next;
		}
		if (temp1->num == temp2->num)
		{
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp1->num;
			newnode->next = NULL;
			temp1 = temp1->next;
			temp->next = newnode;
			temp = newnode;
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = temp2->num;
			newnode->next = NULL;
			temp->next = newnode;
			temp = newnode;
			temp2 = temp2->next;
		}
	}
	return head;
}
