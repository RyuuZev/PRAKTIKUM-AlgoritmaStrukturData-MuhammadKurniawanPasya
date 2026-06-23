#include "single_linked_list.h"
#include <iostream>

[[nodiscard]] static Node* make_node(int val) noexcept {
    Node* n = new Node;   
    n->data = val;
    n->next = nullptr;
    return n;
}

void SingleLinkedList::init() {
    head = tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return size == 0;
}

void SingleLinkedList::add_front(int val) {
    Node* n = make_node(val);
    if (is_empty()) {
        head = tail = n;
        n->next = head; 
    } else {
        n->next = head;
        head = n;
        tail->next = head; 
    }
    ++size;
}

void SingleLinkedList::add_back(int val) {
    Node* n = make_node(val);
    if (is_empty()) {
        head = tail = n;
        n->next = head;
    } else {
        tail->next = n;
        tail = n;
        tail->next = head; 
    }
    ++size;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Invalid index");
    if (idx == 0) { add_front(val); return; }
    if (idx == size) { add_back(val); return; }

    Node* prev = head;
    for (int i = 0; i < idx - 1; ++i)
        prev = prev->next;

    Node* n    = make_node(val);
    n->next    = prev->next;
    prev->next = n;
    ++size;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw std::out_of_range("Empty");
    Node* tmp = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head; 
    }
    delete tmp;
    --size;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw std::out_of_range("Empty");
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* prev = head;
        while (prev->next != tail)
            prev = prev->next;

        delete tail;
        tail = prev;
        tail->next = head; 
    }
    --size;
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty() || idx < 0 || idx >= size) throw std::out_of_range("Invalid index");    if (idx == 0)        { delete_front(); return ; }
    if (idx == size - 1) { delete_back(); return ; }

    Node* prev = head;
    for (int i = 0; i < idx - 1; ++i)
        prev = prev->next;

    Node* target = prev->next;
    prev->next   = target->next;   
    delete target;
    --size;
}

void SingleLinkedList::display() {
    if (is_empty()) {
        std::cout << "[ ]\n";
        return;
    }

    Node* cur = head;
    std::cout << "[ ";
    
    for (int i = 0; i < size; ++i) {
        std::cout << cur->data;
        
        if (i < size - 1) {
            std::cout << " -> ";
        }
        
        cur = cur->next;
    }
    
    std::cout << " ]\n";
}

int SingleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Invalid index");
    Node* cur = head;
    for (int i = 0; i < idx; ++i)
        cur = cur->next;
    return cur->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Invalid index");
    Node* cur = head;
    for (int i = 0; i < idx; ++i)
        cur = cur->next;
    cur->data = val;
}

void SingleLinkedList::clear() {
    if (is_empty()) return;
    Node* cur = head;
    for (int i = 0; i < size; ++i) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }
    head = tail = nullptr;
    size = 0;
}