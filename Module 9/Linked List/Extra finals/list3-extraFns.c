//
//  list3-extraFns.c
//  
//
//  Created by Jennivine on 11/5/18.
//

#include "list3.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

list newList (void){
    list new = malloc( sizeof (*new));
    assert(new != NULL);
    new->head = NULL;

    return new;
}

// delete the first node
void deleteHead (list l){
    assert (l != NULL);
    
    link toFree = l->head;
    l->head = l->head->next;
    
    free(toFree);
}

// delete the end node
void deleteLast (list l){
    assert (l != NULL);
    link current = l->head;
    
    if (current->next == NULL){
        // There is only one element in the list
        // so in this case, deleting the last is equivelent to deteling the first
        deleteHead(l);
    } else {
        while (current->next != NULL){
            if (current->next->next == NULL){
                break;
            }
            current = current->next;
        }
        
        link toFree = current->next;
        current->next = NULL;
        
        free(toFree);
    }
}

// join two lists
// move all the elements from the second list to the end of
// the first list (in order).  this leaves the second list
// empty and all the elements in the first list.
void concatenate (list to, list from){
    if (to->head == NULL){
        // if the 'to' list is currently empty just make it same as old list
        to->head = from->head;
    } else {
        // finding the end of the list you are concatenating to
        link current = to->head;
        assert (current != NULL);
        while (current->next != NULL) {
            assert (current !=NULL);
            current = current->next;
        }
        
        // attaching the start of the 'from' list to the end of the 'to' list
        assert (current !=NULL);
        current->next = from->head;
    }
    // clear the 'from' list
    from->head = NULL;
}

// count the number of nodes containing 42
int count42s (list l){
    assert (l != NULL);
    
    link current = l->head;
    int counter = 0;
    
    while (current != NULL){
        if (current->value == 42){
            counter ++;
        }
        current = current->next;
    }
    
    return counter;
}
