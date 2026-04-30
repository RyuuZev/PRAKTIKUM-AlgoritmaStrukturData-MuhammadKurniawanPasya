#include "single_linked_list.h"
#include <stdio.h>

// init

void SingleLinkedList::init() {
    head == nullptr;
    tail == nullptr;
}

bool SingleLinkedList::is_empty() {
    return head == nullptr;
}

// insert

void SingleLinkedList::add_front(int val) {
    Node* newNode = new Node{val, nullptr};

    if (is_empty()) {
        head = tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = newNode;
        head = newNode;
    }
}

void SingleLinkedList::add_back(int val) {
    Node* newNode = new Node{val, nullptr};

    if (is_empty()) {
        head = tail = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx <= 0 || is_empty()) {
        add_front(val);
        return;
    }

    Node* temp = head;
    int i = 0;

    while (i < idx - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp == tail) {
        add_back(val);
        return;
    }

    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;

}

// delete

void SingleLinkedList::delete_front() {
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}

void SingleLinkedList::delete_back() {
    if (is_empty()) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = head;
        delete tail;
        tail = temp;
    }
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty()) return;

    if (idx <= 0) {
        delete_front();
        return;
    }

    Node* temp = head;
    int i = 0;

    while (i < idx - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    Node* target = temp->next;

    if (target == head) {
        delete_front();
    } else if (target == tail) {
        delete_back();
    } else {
        temp->next = target->next;
        delete target;
    }
}

// access

void SingleLinkedList::display() {
    if (is_empty()) return;

    Node* temp = head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int SingleLinkedList::get(int idx) {
    if (is_empty()) return -1;

    Node* temp = head;
    int i = 0;

    do {
        if(i == idx) return temp->data;
        temp = temp->next;
        i++;
    } while (temp != head);

    return -1;
}

int SingleLinkedList::set(int idx) {
    if (is_empty()) return -1;

    Node* temp = head;
    int i = 0;

    do {
        if (i == idx) {
            temp->data = 0;
            return 1;
        }
        temp = temp->next;
        i++;
    } while (temp != head);

    return -1;
} 