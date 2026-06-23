#include "single_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    
    if (!(cin >> n >> k)) return 0;

    long long k_initial = k;

    SingleLinkedList list;
    list.init();

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        list.add_back(a);
    }

    int idx = 0;

    while (list.size > 1) {
        long long steps = (k - 1) % list.size;
        
        idx = (idx + steps) % list.size;

        int val = list.get(idx);
        
        list.delete_idx(idx);

        idx %= list.size;

        if (val % 2 == 0) {
            k++; 
        } else {
            k--; 
        }

        if (k <= 0) {
            k = k_initial;
        }
    }

    if (!list.is_empty()) {
        cout << list.get(0) << "\n";
    }

    list.clear();

    return 0;
}