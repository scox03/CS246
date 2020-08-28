#include <iostream>
#include <string>

using namespace std; 

bool HasDuplicates(double arr[], int size) {
  for(int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j < size; j++){
      if(arr[i] == arr[j]) {
        return true;
      } else {
        return false;
      }
    } 
  }
  return 0;
}

int main() {
  cout << HasDuplicates(numbers, 4);
  return 0;
}


void TrimEnds(string word) {
  string str = word;
  int space = 0;
  for(int i = 0; i < str.length() - 1; i++) {
    if(str[i] == ' ') {
      str[i] = str[space++];
    }
    space++;
  }
  cout << str;
}

int main() 
{ 
    string str = " hello world "; 
    TrimEnds(str);  
    return 0; 
} 
