#include <iostream>
#include <vector>

void sort(std::vector<int> &arr) {

  for(size_t i = 1; i < arr.size(); i++){
      int key = arr[i];
      int j = i - 1;

      while(j >= 0 && arr[j] > key){
          arr[j + 1] = arr[j];
          j--;
      }
      arr[j + 1] = key;
  }
}

int main() {
  std::vector<int> arr = {6,2,4,1};

  sort(arr);
  for (auto num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
