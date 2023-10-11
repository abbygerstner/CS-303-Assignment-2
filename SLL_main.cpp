// SLL_main.cpp

#include "SingleLinkedList.h"
#include <stdexcept> // for std::runtime_error
#include <iostream>

// Constructor for Node class
Node::Node(const std::string& value) : data(value), next(nullptr) {}

// Constructor for LinkedList class
LinkedList::LinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor for LinkedList class
LinkedList::~LinkedList() {
    // Destructor to clean up memory by deleting all nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add an element to the front of the linked list
void LinkedList::push_front(const std::string& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    num_items++;
}

// Add an element to the back of the linked list
void LinkedList::push_back(const std::string& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

// Remove the element from the front of the linked list
void LinkedList::pop_front() {
    if (!head) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    num_items--;
}

// Remove the element from the back of the linked list
void LinkedList::pop_back() {
    if (!head) {
        throw std::runtime_error("Cannot pop from an empty list");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// Get the value of the element at the front of the linked list
std::string LinkedList::front() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }
    return head->data;
}

// Get the value of the element at the back of the linked list
std::string LinkedList::back() {
    if (!tail) {
        throw std::runtime_error("List is empty");
    }
    return tail->data;
}

// Check if the linked list is empty
bool LinkedList::empty() {
    return head == nullptr;
}

// Insert an element at a specified index in the linked list
void LinkedList::insert(size_t index, const std::string& item) {
    if (index == 0) {
        push_front(item);
    } else {
        Node* newNode = new Node(item);
        Node* current = head;
        for (size_t i = 0; i < index - 1 && current; i++) {
            current = current->next;
        }
        if (current) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            push_back(item);
        }
        num_items++;
    }
}

// Remove an element at a specified index in the linked list
bool LinkedList::remove(size_t index) {
    if (!head || index < 0) {
        return false;
    }

    if (index == 0) {
        pop_front();
        return true;
    }

    Node* current = head;
    Node* prev = nullptr;

    for (size_t i = 0; i < index && current; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return false;
    }

    prev->next = current->next;
    if (current == tail) {
        tail = prev;
    }
    delete current;
    num_items--;
    return true;
}

// Find the index of the first occurrence of a value in the linked list
size_t LinkedList::find(const std::string& item) {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return index; // Return the size of the list if not found
}

// Get the number of elements in the linked list
size_t LinkedList::size() {
    return num_items;
}

// Print the elements of the linked list
void LinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Main function to demonstrate the usage of the LinkedList class
int main() {
    LinkedList list;

    // User interface for interacting with the linked list
    while (true) {
        std::cout << "Choose a function to use (push_front, push_back, pop_front, pop_back, front, back, empty, insert, remove, find, size, print, quit): ";
        std::string choice;
        std::cin >> choice;

        if (choice == "push_front" || choice == "push_back" || choice == "insert") {
            std::cout << "Enter a value: ";
            std::string value;
            std::cin >> value;

            if (choice == "push_front") {
                list.push_front(value);
            } else if (choice == "push_back") {
                list.push_back(value);
            } else if (choice == "insert") {
                std::cout << "Enter an index: ";
                size_t index;
                std::cin >> index;
                list.insert(index, value);
            }
        } else if (choice == "pop_front") {
            list.pop_front();
        } else if (choice == "pop_back") {
            list.pop_back();
        } else if (choice == "front") {
            try {
                std::cout << "Front: " << list.front() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
        } else if (choice == "back") {
            try {
                std::cout << "Back: " << list.back() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
        } else if (choice == "empty") {
            std::cout << "Is empty? " << (list.empty() ? "Yes" : "No") << std::endl;
        } else if (choice == "remove") {
            std::cout << "Enter an index: ";
            size_t index;
            std::cin >> index;
            if (list.remove(index)) {
                std::cout << "Item removed successfully." << std::endl;
            } else {
                std::cout << "Item not found or index is invalid." << std::endl;
            }
        } else if (choice == "find") {
            std::cout << "Enter a value to find: ";
            std::string value;
            std::cin >> value;
            size_t position = list.find(value);
            if (position < list.find("nullptr")) {
                std::cout << "Found at position: " << position << std::endl;
            } else {
                std::cout << "Not found in the list." << std::endl;
            }
        } else if (choice == "size") {
            std::cout << "Size of the list: " << list.size() << std::endl;
        } else if (choice == "print") {
            list.print();
        } else if (choice == "quit") {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
