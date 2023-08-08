#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> removeDuplicates(const std::vector<int>& arr) {
    std::vector<int> uniqueElements;
    for (int element : arr) {
        if (std::find(uniqueElements.begin(), uniqueElements.end(), element) == uniqueElements.end()) {
            uniqueElements.push_back(element);
        }
    }
    return uniqueElements;
}

int main() {
    std::vector<int> inputArray = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> uniqueArray = removeDuplicates(inputArray);

    for (int element : uniqueArray) {
        std::cout << element << " ";
    }

    return 0;
}
