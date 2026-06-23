#include "single_linked_list.h"
#include <iostream>

int main() {
    SingleLinkedList list;
    list.init(); 

    std::cout << "--- Pengujian Circular Linked List ---" << std::endl;

    list.add_back(10);
    list.add_back(20);
    list.add_front(5);
    
    std::cout << "Isi list (setelah add): ";
    list.display(); 

    std::cout << "Menambah 15 di indeks 2..." << std::endl;
    list.add_idx(15, 2);
    list.display();

    std::cout << "Data pada indeks 1: " << list.get(1) << std::endl;
    list.set(99, 1);
    std::cout << "Setelah indeks 1 diubah jadi 99: ";
    list.display();

    std::cout << "Menghapus data depan..." << std::endl;
    list.delete_front();
    list.display();

    std::cout << "Menghapus data belakang..." << std::endl;
    list.delete_back();
    list.display();

    std::cout << "Membersihkan list..." << std::endl;
    list.clear();
    list.display();

    return 0;
}