#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"

typedef struct node {
	u32 data;
	struct node* next;
} node_t;
void printList(node_t* head);
void insertAfter (node_t* before_ref, u32 data);
void push (node_t** head_ref, u32 data);
void append (node_t* head_ref, u32 data);
#define NULL_PTR ((void*)0)

int main (void) {
	
	node_t * head = NULL_PTR;
	push(&head, 1);
	append(head, 2);
	printList(head);
	
}

void printList(node_t* head_ref) {
	node_t* node_ref = head_ref;
	while (node_ref != NULL_PTR) {
		printf("%d ", node_ref->data);
		node_ref = node_ref->next;
	}
}




void insertAfter (node_t* before_ref, u32 data) {
	node_t* new_node_ref;
	new_node_ref = (node_t*) malloc(sizeof(node_t));
	
	new_node_ref->next = before_ref->next;
	new_node_ref->data = data;
	
	before_ref->next = new_node_ref;
}



void push (node_t** head_ref, u32 data) {
	node_t* new_node_ref;
	new_node_ref = (node_t*) malloc(sizeof(node_t));
	new_node_ref->data = data;
	new_node_ref->next = *head_ref;
	*head_ref = new_node_ref;

}

void append (node_t* head_ref, u32 data) {
	node_t* last = head_ref;
	
	node_t* new_node_ref;
	new_node_ref = (node_t*) malloc(sizeof(node_t));
	
	new_node_ref->data = data;
	new_node_ref->next = NULL_PTR;
	
	while (1) {
		if (last->next == NULL_PTR) {
			last->next = new_node_ref;
			break;
		}
		last = last->next;
	}
}
