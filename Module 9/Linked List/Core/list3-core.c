//
//  list3-core.c
//  
//
//  Created by Jennivine on 11/5/18.
//

#include "list3.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void showList (list listToPrint){
    assert (listToPrint != NULL);
    
    link current = listToPrint->head;
    
    while (current != NULL){
        printf("[%d] -> ",current->value);
        current = current->next;
    }
    printf("X\n");
}

// inset item at the front of the list
void frontInsert (list l, int item){
    
    assert (l != NULL);
    
    link newNode = malloc(sizeof (node));
    assert (newNode != NULL);
    newNode->value = item;
    
    // now insert it !
    link oldHead = l->head;
    newNode->next = oldHead;
    l->head = newNode;
}

// count the number of items in the list
int numItems (list l){
    assert (l != NULL);
    
    int counter = 0;
    link current = l->head;
    
    while (current != NULL){
        counter ++;
        current = current->next;
    }
    return counter;
}

// insert at end of list
void append (list l, int value){
    assert (l != NULL);
    
    link newNode = malloc (sizeof (node));
    assert (newNode != NULL);
    newNode->value = value;
    newNode->next  = NULL;
    
    if (l->head == NULL){
        // in case the list is empty, we insert straight away
        l->head = newNode;
    } else {
        // if it's not empty, we first loop to the end of the list, then insert.
        link current = l->head;
        
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position){
    assert (l != NULL);
    assert (position >= 0);
    
    int pos = 0;
    link current = l->head;
    
    while (pos != position){
        pos ++;
        assert (current->next != NULL);
        current = current->next;
    }
    
    assert (current != NULL);
    return current->value;
}
