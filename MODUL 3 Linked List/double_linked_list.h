#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

struct Node {
    char data;
    Node * next;
    Node * prev;
};

struct DoubleLinkedList {
    Node *head, *tail;

    void init();
    bool is_empty();
    
    void add_front(int val);
    void add_back(int val);
    void add_idx(int val, int idx);

    void delete_front();
    void delete_back();
    void delete_idx(int idx);

    void display();
    int get(int idx);
    int set(int idx);

    void clear();
};


#endif