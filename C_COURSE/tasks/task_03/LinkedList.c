#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
#include "LinkedList.h"


void LinkedList_insertAfter(node_t** head_ref, node_t *before_ref, u32 data) {
	node_t* new_node_ref;
	new_node_ref = (node_t*) malloc(sizeof(node_t));
	new_node_ref->data = data;
	if (NULL_PTR != *head_ref) {
        new_node_ref->next = before_ref->next;
        before_ref->next = new_node_ref;
    }
	else {
		*head_ref = new_node_ref;
		new_node_ref->next = NULL_PTR;
	}
}

void LinkedList_insertBefore(node_t** head_ref, node_t *after_ref, u32 data) {
	node_t* new_node_ref;
	node_t* node_ref = *head_ref;
	new_node_ref = (node_t*) malloc(sizeof(node_t));
	new_node_ref->data = data;
	if (*head_ref != after_ref) {
		while (1) {
			if (node_ref->next == after_ref) {
				new_node_ref->next = node_ref->next;
				node_ref->next = new_node_ref;
				break;
			}
			node_ref = node_ref->next;
		}
	}
	else {
		new_node_ref->next = *head_ref;
		*head_ref = new_node_ref;
	}
}

void LinkedList_push(node_t **head_ref, u32 data) {
	node_t* new_node_ref;
	new_node_ref = (node_t*) malloc(sizeof(node_t));
	new_node_ref->data = data;
	new_node_ref->next = *head_ref;
	*head_ref = new_node_ref;
}

void LinkedList_append(node_t **head_ref, u32 data) {
    node_t* new_node_ref;
    new_node_ref = (node_t*) malloc(sizeof(node_t));
    new_node_ref->data = data;
    new_node_ref->next = NULL_PTR;
    if (NULL_PTR == *head_ref) {
        *head_ref = new_node_ref;
    }
    else {
        node_t* last = *head_ref;
        while (1) {
            if (NULL_PTR == last->next) {
                last->next = new_node_ref;
                break;
            }
            last = last->next;
        }
    }
}

void LinkedList_insertAtIndex(node_t **head_ref, u32 data, u8 index) {
    node_t* new_node_ref;
    node_t* node_ref = *head_ref;
    new_node_ref = (node_t*) malloc(sizeof(node_t));
	u8 i;
    new_node_ref->data = data;
	if (0 != index) {
		for (i=0; i<index-1; i++) {
			if (NULL_PTR == node_ref->next) {
				break;
			}
			node_ref = node_ref->next;
		}
		new_node_ref->next = node_ref->next;
		node_ref->next = new_node_ref;
	}
	else {
		new_node_ref->next = *head_ref;
		*head_ref = new_node_ref;
	}
	

}

void LinkedList_deleteNode(node_t **head_ref, node_t *node_ref) {
	
	if (node_ref != *head_ref) {
		node_t *last = *head_ref;
		while (1) {
			if (last->next == node_ref) {
				last->next = node_ref->next;
				break;
			}
			last = last->next;
		}
	}
	else {
		*head_ref = (*head_ref)->next;
	}
	free(node_ref);
}

void LinkedList_deleteAll(node_t **head_ref) {
    node_t *node_ref;
	while (NULL_PTR != *head_ref) {
		node_ref = *head_ref;
		*head_ref = (*head_ref)->next;
		free(node_ref);
	}
}

void LinkedList_print(node_t *head_ref) {
    if (NULL_PTR == head_ref) {
        printf("Linked List Is Empty\n");
    }
    else {
        node_t* node_ref = head_ref;
        while (NULL_PTR != node_ref) {
            printf("%d ", node_ref->data);
            node_ref = node_ref->next;
        }
        printf("\n");
    }
}
