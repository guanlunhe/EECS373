#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	list_t* location;
	list_t* first;
	list_t* temp;
	int counter=0;
	assert(head != NULL);
	assert(new_element != NULL);
	first = head;
	while((head!=NULL)  &&((head -> index) < (new_element->index)))
	{
		counter++;
		if (counter==1)
		{
			temp = first;
		}
		else if ( counter >1)
		{
			temp= temp->next;
		}
		location = head;
		head = head->next;	
		if (head == NULL)
		{
			counter =-1;
		}		
	}
	
	if (counter > 0)
	{
		
		location->next = new_element;
		new_element->next = head;
		head= first;
		
	}
	else if (counter ==0)
	{
		new_element->next = head;
		head= new_element;
	}
	else
	{
		head = first;
		location ->next = new_element;
		new_element->next = NULL;
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	list_t* newhead;
	list_t* temp;
	int counter = 0;
	assert(head != NULL);
	while(head!= NULL)
	{
		if(counter ==0)
		{	
			newhead = head;
			head = head->next;
			newhead -> next = NULL;	
			
		}
		else
		{
			temp= newhead;
			newhead = head;
			head=head->next;
			newhead->next = temp;
					
		}
		counter++;
	}
	head=newhead;
	return head;
}
