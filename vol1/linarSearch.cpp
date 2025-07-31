#include <iostream>
#include <vector>

int linearSearch(std::vector<int>&arr , int key){
  for (int i = 0; i < arr.size(); i++){
    if (arr[i] == key){
        return i;
    }
  }
  return -1;
}


int main(){
  std::vector<int> arr = {1,2,4,5,6,7,1,53,2,6,12};

  std::cout << linearSearch(arr,5) << std::endl;
  return 0;
}
