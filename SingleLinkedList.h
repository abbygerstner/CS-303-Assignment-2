// SingleLinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

// Definition of the Node class
class Node {
public:
    std::string data; // Data stored in the node
    Node* next;      // Pointer to the next node in the list

    // Constructor for Node class
    Node(const std::string& value);
};

// Definition of the LinkedList class
class LinkedList {
private:
    Node* head;        // Pointer to the first node in the list
    Node* tail;        // Pointer to the last node in the list
    size_t num_items;  // Number of items in the linked list

public:
    // Constructor for LinkedList class
    LinkedList();

    // Destructor for LinkedList class (to clean up memory)
    ~LinkedList();

    // Function to add an element to the front of the linked list
    void push_front(const std::string& value);

    // Function to add an element to the back of the linked list
    void push_back(const std::string& value);

    // Function to remove the element from the front of the linked list
    void pop_front();

    // Function to remove the element from the back of the linked list
    void pop_back();

    // Function to get the value of the element at the front of the linked list
    std::string front();

    // Function to get the value of the element at the back of the linked list
    std::string back();

    // Function to check if the linked list is empty
    bool empty();

    // Function to insert an element at a specified index in the linked list
    void insert(size_t index, const std::string& item);

    // Function to remove an element at a specified index in the linked list
    bool remove(size_t index);

    // Function to find the index of the first occurrence of a value in the linked list
    size_t find(const std::string& item);

    // Function to get the number of elements in the linked list
    size_t size(); 

    // Function to print the elements of the linked list
    void print();
};

#endif
