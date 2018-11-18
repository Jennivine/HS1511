#include <stdio.h>
#include <stdlib.h>

typedef struct _node * nodePtr;

typedef struct _node {
	int value;
	nodePtr next;
} node;

nodePtr backToFront (nodePtr first){
	nodePtr current;
	nodePtr previous;

	if (first == NULL || first->next == NULL){
	    // list is empty or there's only one node
		return first;
	} else {
	
		current = first;
		
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		
		current->next = first;
		previous->next = NULL;
	}
	return current;
}