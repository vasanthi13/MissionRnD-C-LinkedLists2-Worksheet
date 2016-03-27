/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if(head==NULL) 
		return -1;
	struct node *temp = NULL;
	int median,i = 0, c = 1, flag = 0;
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->next->next != NULL)
		{
			temp = temp->next->next;
			c++;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	temp = head;
	while (i < c - 1)
	{
		temp = temp->next;
		i++;
	}
	if (flag == 0)
		median = temp->num;
	else
		median = (temp->num + temp->next->num) / 2;
	return median;
}
