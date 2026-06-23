#include "double_linked_list.h"
#include <cstdio>
#include <stdexcept>

static Node* make_node(char data) {
    Node* n = new Node;
    n->data = data;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}

static Node* node_at(DoubleLinkedList& l, int idx) {
    if (idx < 0 || idx >= l.size) return nullptr;
    
    Node* cur;
    if (idx <= l.size / 2) {
        cur = l.head;
        for (int i = 0; i < idx; ++i) cur = cur->next;
    } else {
        cur = l.tail;
        for (int i = l.size - 1; i > idx; --i) cur = cur->prev;
    }
    return cur;
}

static void unlink(DoubleLinkedList& l, Node* n) {
    if (!n || l.size == 0) return;

    if (l.size == 1) {
        l.head = l.tail = nullptr;
    } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;

        if (n == l.head) l.head = n->next;
        if (n == l.tail) l.tail = n->prev;
    }
    
    delete n;
    --l.size;
}

void DoubleLinkedList::init() {
    head = tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::clear() {
    if (is_empty()) return;

    tail->next = nullptr;
    head->prev = nullptr;

    Node* cur = head;
    while (cur != nullptr) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = tail = nullptr;
    size = 0;
}

void DoubleLinkedList::add_front(char val) {
    Node* n = make_node(val);
    if (is_empty()) {
        head = tail = n;
        n->next = n;
        n->prev = n;
    } else {
        n->next = head;
        n->prev = tail;
        head->prev = n;
        tail->next = n;
        head = n;
    }
    ++size;
}

void DoubleLinkedList::add_back(char val) {
    Node* n = make_node(val);
    if (is_empty()) {
        head = tail = n;
        n->next = n;
        n->prev = n;
    } else {
        n->prev = tail;
        n->next = head;
        tail->next = n;
        head->prev = n;
        tail = n;
    }
    ++size;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return; 
    
    if (idx == 0) { 
        add_front(val); 
        return; 
    }
    if (idx == size) { 
        add_back(val); 
        return; 
    }

    Node* succ = node_at(*this, idx);
    if (!succ) return;
    
    Node* pred = succ->prev;
    Node* n = make_node(val);

    n->prev = pred;
    n->next = succ;
    pred->next = n;
    succ->prev = n;
    ++size;
}

void DoubleLinkedList::delete_front() {
    unlink(*this, head);
}

void DoubleLinkedList::delete_back() {
    unlink(*this, tail);
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) return; 

    Node* target = node_at(*this, idx);
    if (target) unlink(*this, target);
}

char DoubleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of bounds");
    } 
    
    Node* n = node_at(*this, idx);
    return n->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of bounds"); 
    }

    Node* n = node_at(*this, idx);
    if (n) n->data = val;
}

void DoubleLinkedList::display() {
    if (is_empty()) {
        std::puts("[]\n");
        return;
    }

    std::printf("[");
    Node* cur = head;
    for (int i = 0; i < size; ++i) {
        std::printf("%c", cur->data);
        if (i < size - 1) std::printf(" ");
        cur = cur->next; 
    }
    std::printf("]\n");
}