#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.h"


int MininumDistance(Array<int>& data) {
  int distance;
  int minimum = 6;
  if(obj.data.size == 0 || obj.data.size == 1) {
    return 0;
  } else { 
    for (int i = 0; i < obj.data.size; i++) {
      distance = data[i + 1] - data[i];
      if (distance < 0) {
        distance = distance * -1;
      }
      if(distance < minimum) {
        distance = minimum;
      }
    }
  return minimum; 
  }
}

template <typename T>
bool Similar(Array<T>& ar1, Array<T>& ar2) {
  for(i = 0; i < ar1.size; i++) {
    for(j = 0; j < ar2.size; j++) {
    }
    if(ar1[i] == ar2[j]) {
      return true;
    } 
  }
  return false;
}

template <typename T>
void MidAppend(Array<T>& data, Array<T>& addon) {
  data.Resize(data.size + 1);
  for(int i = data.size + 1; i > data.Length()/2; i++) {
    data[i] = data[i -1];
  }
  data.Resize(data.size + addon.size)
  for(i = data.Length()/2; i < data.size; i++) {
  }
}

/*
c     t
c1    1
c2    1
c3    1
c4    1
c5    1
c6    1
c7    1
c8    n/2
c9    n
c10   n
c11   n
c12   n-1
c13   1
c14   1
c15   1
c16   1

Runtime = 9 + n + n/2;
*/



int main()
{
	return 0;
}