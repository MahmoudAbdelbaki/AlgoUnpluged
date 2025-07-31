#include <iostream>
#include <vector>
/*
binSearch:
This function uses binary search to find **any one position** where the key
exists. It doesn't guarantee the first or last occurrence—just any match.
Returns the index if found, otherwise -1.
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

/*
searchRight:
This function finds the **last (rightmost) position** where the key appears in
the list. It's useful when the key appears multiple times and you want the last
one. Returns the index if found, otherwise -1.
*/
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

/*
searchLeft:
This function finds the **first (leftmost) position** where the key appears in
the list. It's useful when the key appears more than once and you want the
earliest occurrence. Returns the index if found, otherwise -1.
*/
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

/*
binarySearchHelper:
This is a **recursive version** of binary search.
It keeps calling itself on a smaller portion of the array until it finds the key
or runs out of space. Returns the index of the key if found, otherwise -1. This
function is usually not called directly—used by nbiarySerch().
*/
int binarySearchHelper(std::vector<int> &arr, int key, int left, int right) {
  int mid = left + (right - left) / 2;

  if (left > right)
    return -1; // Base Case

  if (arr[mid] == key)
    return mid;
  else if (arr[mid] > key)
    return binarySearchHelper(arr, key, left, mid - 1);
  else
    return binarySearchHelper(arr, key, mid + 1, right);
}

/*
nbiarySerch:
This is just a **wrapper function** to make recursive binary search easier to
use. It sets up the initial left and right bounds and calls the helper.
*/
int nbiarySerch(std::vector<int> &arr, int key) {
  int left = 0;
  int right = arr.size() - 1;

  return binarySearchHelper(arr, key, left, right);
}

int main() {

  std::vector<int> arr = {2, 4, 5, 6, 7, 8, 9, 21, 52, 56};

  int key = 6;

  std::cout << nbiarySerch(arr, key) << std::endl;
  return 0;
}
