#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    bool swapped;
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            m.comparisons++;
            
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break; 
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            m.comparisons++;
            
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(data[i], data[min_idx]);
            m.swaps++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            m.comparisons++;
            data[j + 1] = data[j];
            m.shifts++;
            j--;
        }
        if (j >= 0) m.comparisons++; 
        data[j + 1] = key;
        m.shifts++;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void do_merge(std::vector<int>& data, int left, int mid, int right, Metrics& m, std::vector<int>& temp) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        m.comparisons++;
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
            m.array_accesses += 2; 
        } else {
            temp[k++] = data[j++];
            m.array_accesses += 2; 
        }
    }
    while (i <= mid) {
        temp[k++] = data[i++];
        m.array_accesses += 2; 
    }
    while (j <= right) {
        temp[k++] = data[j++];
        m.array_accesses += 2; 
    }
    for (i = left; i <= right; ++i) {
        data[i] = temp[i];
        m.array_accesses += 2; 
    }
}

void do_merge_sort(std::vector<int>& data, int left, int right, Metrics& m, std::vector<int>& temp) {
    m.recursive_calls++;

    if (left < right) {

        int mid = left + (right - left) / 2;

        do_merge_sort(data, left, mid, m, temp);
        do_merge_sort(data, mid + 1, right, m, temp);
        do_merge(data, left, mid, right, m, temp);
    }
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (data.empty()) {
        m.time_ms = 0.0;
        return;
    }
    
    std::vector<int> temp(data.size());

    do_merge_sort(data, 0, data.size() - 1, m, temp);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void do_quick_sort(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;

    if (low >= high) return;

    int mid = low + (high - low) / 2;
    int pivot = data[mid];
    int i = low;
    int j = high;

    while (i <= j) {

        while (true) {
            m.comparisons++;
            if (data[i] < pivot) i++;
            else break;
        }

        while (true) {
            m.comparisons++;
            if (data[j] > pivot) j--;
            else break;
        }

        if (i <= j) {
            std::swap(data[i], data[j]);
            m.swaps++;
            i++;
            j--;
        }
    }

    do_quick_sort(data, low, j, m);
    do_quick_sort(data, i, high, m);
}


void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty()) {
        do_quick_sort(data, 0, data.size() - 1, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}



void count_sort_for_radix(std::vector<int>& data, int exp, Metrics& m) {
    int n = data.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
        m.array_accesses += 2;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        m.array_accesses += 3;
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
        m.array_accesses += 4; 
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
        m.array_accesses += 2; 
    }
}

void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int max_val = data[0];
    for (int i = 1; i < data.size(); i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        count_sort_for_radix(data, exp, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}