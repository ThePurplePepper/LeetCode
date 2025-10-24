//
// Created by yoavy on 23/10/2025.
//

#pragma once
#include <vector>

template <typename T>
int binarySearch(const std::vector<T>& vec, const T& target, int left, int right) {
    while (right > left) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) {
            return mid;
        }
        if (vec[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
