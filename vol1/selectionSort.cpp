#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr) {

  for (int i = 0; i < arr.size(); i++) {
    int minIndex = i;

    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(arr[i], arr[minIndex]);
  }
}

int main() {
  std::vector<int> arr = {6, 2, 4, 1};

  selectionSort(arr);
  for (auto num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
