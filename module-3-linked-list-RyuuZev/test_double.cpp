#include "double_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    DoubleLinkedList list;
    list.init();

    cout << "=== Uji Coba Circular Double Linked List ===\n\n";

    cout << "1. Menambahkan Data (add_back & add_front)...\n";
    list.add_back('B');
    list.add_back('C');
    list.add_front('A');
    cout << "Isi List: ";
    list.display();

    cout << "\n2. Membuktikan Sifat Melingkar...\n";
    if (!list.is_empty()) {
        cout << "Head saat ini: " << list.head->data << "\n";
        cout << "Tail saat ini: " << list.tail->data << "\n";
        cout << "head->prev (Harusnya ke Tail) : " << list.head->prev->data << "\n";
        cout << "tail->next (Harusnya ke Head) : " << list.tail->next->data << "\n";
    }

    cout << "\n3. Menghapus Data...\n";
    list.delete_front();
    cout << "Setelah delete_front: ";
    list.display(); 

    list.delete_back();
    cout << "Setelah delete_back : ";
    list.display(); 

    cout << "\n4. Menyisipkan Data (add_idx)...\n";
    list.add_idx('X', 1);
    list.add_idx('Y', 2);
    cout << "Setelah add_idx: ";
    list.display();

    cout << "\n5. Membersihkan Memori (clear)...\n";
    list.clear();
    cout << "Isi List setelah clear: ";
    list.display(); 
    cout << "Apakah list kosong? " << (list.is_empty() ? "Ya" : "Tidak") << "\n";

    cout << "\n=== Uji Coba Selesai ===\n";

    return 0;
}