#include <vector>
#include <cstdlib>

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

std::vector<int> gazaSort(std::vector<int> arr) {
    while (!isSorted(arr)) {
        arr.erase(arr.begin() + rand() % arr.size());
    }
    return arr;
}
