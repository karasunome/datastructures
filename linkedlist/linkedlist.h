#pragma once

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
        int size = 0;
        Node *create_node(int data);

    public:
        int append(int data);
        int insert_head(int data);
        int remove(int data);    
        void disp(void);
        int remove_tail(void);
};