#pragma once

#include <iostream>

//Single_Linked_List class and all the functions within that class that allow the user to add, remove, check for a number, and check if empty

template<typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    //Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    //Destructor
    ~Single_Linked_List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //Adds number to the front
    void push_front(const Item_Type& item) {
        Node* newNode = new Node(item);
        if (empty()) {
            head = newNode;
            tail = newNode; 
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        ++num_items;
    }

    //Adds number to the back
    void push_back(const Item_Type& item) {
        Node* newNode = new Node(item);
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++num_items;
    }

    //Removes number from the front
    void pop_front() {
        if (!empty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            --num_items;
            if (num_items == 0) {
                tail = nullptr;
            }
        }
    }

    //Removes number from the back
    void pop_back() {
        if (!empty()) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
            --num_items;
        }
    }

    //Returns the front of the lit
    Item_Type front() const {
        if (!empty()) {
            return head->data;
        }
    }

    //Returns the back of the list
    Item_Type back() const {
        if (!empty()) {
            return tail->data;
        }
    }

    //Checks if the list is empty
    bool empty() const {
        return num_items == 0;
    }

    //Inserts a number into the list
    void insert(size_t index, const Item_Type& item) {
        if (index <= num_items) {
            if (index == 0) {
                push_front(item);
            }
            else if (index == num_items) {
                push_back(item);
            }
            else {
                Node* newNode = new Node(item);
                Node* current = head;
                for (size_t i = 0; i < index - 1; ++i) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
                ++num_items;
            }
        }
        else {
            push_back(item);
        }
    }

    //Removes a number from the list at a given index
    bool remove(size_t index) {
        if (index < num_items) {
            if (index == 0) {
                pop_front();
            }
            else if (index == num_items - 1) {
                pop_back();
            }
            else {
                Node* current = head;
                for (size_t i = 0; i < index - 1; ++i) {
                    current = current->next;
                }
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                --num_items;
            }
            return true;
        }
        return false;
    }

    //Finds the index of a number otherwise returns size of the list
    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return num_items;
    }
};
