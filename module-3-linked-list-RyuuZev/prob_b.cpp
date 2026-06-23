#include "double_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    if (!(cin >> n >> r)) return 0;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        list.add_back(c);
    }

    Node* alpha = list.head;
    Node* beta = list.tail;

    for (int i = 0; i < r; ++i) {
        long long x, y;
        cin >> x >> y;

        if (list.size == 0) continue; 

        long long eff_x = x % list.size;
        long long eff_y = y % list.size;

        for (long long j = 0; j < eff_x; ++j) {
            alpha = alpha->next;
        }

        for (long long j = 0; j < eff_y; ++j) {
            beta = beta->prev;
        }

        if (alpha == beta) {
            Node* target = alpha;
            
            Node* next_for_alpha = target->next;
            Node* prev_for_beta = target->prev;

            if (list.size == 1) {
                delete target;
                list.head = list.tail = nullptr;
                list.size = 0;
                alpha = beta = nullptr;
            } else {
                target->prev->next = target->next;
                target->next->prev = target->prev;
                
                if (target == list.head) list.head = next_for_alpha;
                if (target == list.tail) list.tail = prev_for_beta;
                
                delete target;
                list.size--;
                
                alpha = next_for_alpha;
                beta = prev_for_beta;
            }
        }
        else if (alpha->next == beta || alpha->prev == beta) {
            bool is_boundary = (alpha == list.head && beta == list.tail) || 
                               (alpha == list.tail && beta == list.head);
            
            if (!(is_boundary && list.size > 2)) {
                char temp = alpha->data;
                alpha->data = beta->data;
                beta->data = temp;
            }
        }
    }

    if (list.size == 0) {
        cout << "EMPTY\n";
    } else {
        Node* curr = list.head;
        for (int i = 0; i < list.size; ++i) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << "\n";
    }

    list.clear();
    
    return 0;
}