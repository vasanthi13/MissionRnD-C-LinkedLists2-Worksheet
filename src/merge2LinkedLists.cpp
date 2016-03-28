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
	struct node *head = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL, *t1 = NULL, *t2 = NULL;
	temp1 = head1;
	temp2 = head2;
	if (temp1->num <= temp2->num)
		head = temp1;
	else
		head = temp2;
	while (1)
	{
		if (temp2->num < temp1->num)
		{
			while (temp2->next != NULL)
			{
				if (temp2->next->num < temp1->num)
				{
					temp2 = temp2->next;
				}
				else
					break;
			}
			if (temp2->next == NULL)
			{
				if (t2 != NULL)
					t1->next = temp2;
				temp2->next = temp1;
				break;
			}
			else
			{
				t2 = temp2;
				temp2 = temp2->next;
				t2->next = temp1;
				if (t1 != NULL)
					t1->next = t2;
				t1 = temp1;
				temp1 = temp1->next;
			}
		}
		if (temp1->num < temp2->num)
		{
			while (temp1->next != NULL)
			{
				if (temp1->next->num < temp2->num)
				{
					temp1 = temp1->next;
				}
				else
					break;
			}
			if (temp1->next == NULL)
			{
				temp1->next = temp2;
				break;
			}
			else
			{
				t1 = temp1;
				temp1 = temp1->next;
				t1->next = temp2;
				t2 = temp2;
				temp2 = temp2->next;
				t2->next = temp1;
				if (temp2 == NULL)
					break;
			}
		}
		if (temp1->num == temp2->num)
		{
			t2 = temp2;
			temp2 = temp2->next;
			t2->next = temp1->next;
			temp1->next = t2;
			temp1 = t2->next;
			if (temp1->next == NULL&&temp2->next == NULL)
			{
				temp1->next = temp2;
				break;
			}
		}
	}
	return head;
}
