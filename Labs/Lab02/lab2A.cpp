#include <iostream>
#include <string>

using namespace std;

int counter = 0;
int Occurences(double arr[], int a, double b) {
  for(int i = 0; i < a; i++) {
    if(arr[i] == b) {
      counter++;
    }
  }
  return counter;
}