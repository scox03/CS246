#include <iostream>

template <typename T>
bool isSorted(T arr[], int size) {
  for(int i = 0; i <= size-1; i++) {
    if(!(arr[i] < arr[i + 1])) {
      return false;
    }
  }
  return true;
}