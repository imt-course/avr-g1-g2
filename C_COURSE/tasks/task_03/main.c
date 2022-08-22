#include <stdio.h>
#include "std_types.h"
#include "LinkedList.h"


int main (void) {

    node_t* head_ref = NULL_PTR;
    LinkedList_print(head_ref);     // Shall Print: Linked List Is Empty

    LinkedList_append(&head_ref, 5); 
    LinkedList_print(head_ref);     // Shall Print: 5

    LinkedList_push(&head_ref, 7);
    LinkedList_print(head_ref);     // Shall Print: 7 5

    LinkedList_insertAfter(&head_ref, head_ref->next, 8);
    LinkedList_print(head_ref);     // Shall Print: 7 5 8

    LinkedList_insertBefore(&head_ref, head_ref->next, 3);
    LinkedList_print(head_ref);     // Shall Print: 7 3 5 8

    LinkedList_insertAtIndex(&head_ref, 4, 3);
    LinkedList_print(head_ref);     // Shall Print: 7 3 5 4 8

    LinkedList_deleteNode(&head_ref, head_ref->next);
    LinkedList_print(head_ref);     // Shall Print: 7 5 4 8

    LinkedList_deleteNode(&head_ref, head_ref);
    LinkedList_print(head_ref);     // Shall Print: 5 4 8

    LinkedList_deleteAll(&head_ref);
    LinkedList_print(head_ref);     // Shall Print: Linked List Is Empty
}