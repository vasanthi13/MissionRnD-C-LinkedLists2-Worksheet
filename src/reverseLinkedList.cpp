/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
	return NULL;
	struct node *temp = NULL, *t1 = NULL, *t2 = NULL;
	int i = 0, len = 0;
	temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if (len == 1) return head;
	temp = head;
	while (temp->next->next != NULL)
		temp = temp->next;
	t2=temp->next;
	t2->next = temp;
	t1 = temp;
	while (i < len - 2)
	{
		temp = head;
		while (temp->next != t1)
			temp = temp->next;
		t1->next = temp;
		t1 = temp;
		i++;
	}
	head->next = NULL;
	head = t2;
	return head;
}
