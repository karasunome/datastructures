#include <iostream>
#include "linkedlist.h"

using namespace std;

Node * LinkedList::create_node(int data) {
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

int LinkedList::append(int data) {
    Node *node;
    if (!head) {
        head = create_node(data);
        tail = head;
        return 0;
    }

    for (node = head; node->next != NULL; node = node->next);

    node->next = create_node(data);
    tail = node->next;
    return 0;
}

int LinkedList::insert_head(int data) {
    Node *node;
    if (!head) {
        head = create_node(data);
        tail = head;
        return 0;
    }

    node = create_node(data);
    node->next = head;
    head = node;
    return 0;    
}

int LinkedList::remove(int data) {
    Node *node;
    Node *next_node;
    for (node = head; node->next != NULL; node = node->next) {
        next_node = node->next;
        if (next_node->data == data) {
            if (tail != next_node) {
                node->next = next_node->next;
                delete next_node;
            } else {
                tail = node;
                node->next = NULL;
                delete next_node;
                break;
            }
        }
    }
    return 0;
}

int LinkedList::remove_tail(void) {
    Node *node;
    for (node = head; node->next != tail; node = node->next);

    node->next = NULL;
    delete tail;
    tail = node;

    return 0;
}

void LinkedList::disp(void) {
    Node *node;
    for (node = head; node != NULL; node = node->next) {
        cout << "[" << node->data << "] ";
    }
    cout << "tail => " << tail->data;
    cout << endl;
}


