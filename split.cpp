/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

void split(Node*& in, Node*& odds, Node*& evens) {
    // Base case: if input list is empty, nothing to do
    if (in == NULL) {
        return;
    }
    
    // Store current node we're processing
    Node* current = in;
    
    // Move input pointer to next node
    in = in->next;
    
    // Disconnect current node from original list
    current->next = NULL;
    
    // Check if current node's value is odd or even
    if (current->value % 2 == 1) {
        // Odd value: add to front of odds list
        current->next = odds;
        odds = current;
    } else {
        // Even value: add to front of evens list
        current->next = evens;
        evens = current;
    }
    
    // Recursively process the rest of the list
    split(in, odds, evens);
}