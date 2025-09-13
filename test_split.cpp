/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstddef>

// Helper function to create a new node
Node* createNode(int val) {
    Node* newNode = new Node(val, NULL);  // Use the constructor
    return newNode;
}

// Helper function to print a list
void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to delete a list
void deleteList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case: [1, 2, 3, 4, 5]
    Node* input = createNode(1);
    input->next = createNode(2);
    input->next->next = createNode(3);
    input->next->next->next = createNode(4);
    input->next->next->next->next = createNode(5);
    
    Node* odds = NULL;
    Node* evens = NULL;
    
    std::cout << "Original list: ";
    printList(input);
    
    split(input, odds, evens);
    
    std::cout << "Odds: ";
    printList(odds);
    
    std::cout << "Evens: ";
    printList(evens);
    
    std::cout << "Input after split: ";
    printList(input); // Should be empty
    
    // Clean up
    deleteList(odds);
    deleteList(evens);
    
    return 0;
}