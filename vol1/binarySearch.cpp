#include <iostream>
#include <vector>

/*
This program is designed to work with a sorted list of numbers and helps find the position(s) of a specific number (called the "key") in that list.

There are three main search functions:

1. binSearch: Finds just one position where the key exists in the list (if it's there).
2. searchLeft: Finds the very first place (from the left) where the key appears.
3. searchRight: Finds the last place (from the right) where the key appears.

In the main part of the program, it creates a list that contains multiple copies of the number 8 (along with other numbers).
It then looks for the number 8 in that list and prints out the first and last positions where 8 appears.

This is useful if you want to find the full range of where a number exists, not just one spot.
*/

int binSearch(std::vector<int> &arr, int key) {
  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
      return mid;
    } else if (arr[mid] > key) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

int searchRight(std::vector<int> &arr, int key) {
  int left = 0;
  int right = arr.size() - 1;

  int res = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
      res = mid;
      left = mid + 1;
    } else if (arr[mid] > key) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}

int searchLeft(std::vector<int> &arr, int key) {
  int left = 0;
  int right = arr.size() - 1;

  int res = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
      res = mid;
      right = mid - 1;
    } else if (arr[mid] > key) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}
int main() {

  std::vector<int> arr = {2,4,5,6,7,8,8,8,8,8,8,8,9,21,52,56};

  int key = 8;

  std::cout << searchLeft(arr,key) << " -> " << searchRight(arr,key) << std::endl;


  return 0;
}
