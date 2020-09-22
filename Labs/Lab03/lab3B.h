#include <iostream>

template <class T>
class Set {
  private:
  T set[100];
  int size;

  public:
  Set() {
    size = 0;
  }

  Set(const Set& obj) {
    size = obj.size;
  }

  Set& operator = (const Ellipse& rhs) {
    if(this != &rhs) {
      size = rhs.size;
    }
  }

  ~Set() {}

  void Add(const T a) {
    for(int i = 0; i < 100; i++) {
      if(set[i] != a) {
        if(set.size < set.capacity) {
          set[set.size] = a;
          set.size += 1;
        }
      }
    }
  }

  bool IsFull() {
    if(set.size == 100) {
      return true;
    } else {
      return false;
    }
  }

  bool IsEmpty() {
    if(set.size == 0) {
      return true;
    } else {
      return false;
    }
  }

  int Count() {
    return set.size;
  }

  bool Contains(T number) {
    for(int i = 0; i < set.size; i++) {
      if(set[i] == number) {
        return true;
      } else {
        return false;
      }
    }
  }

  string ToString() {
    for(int i = 0; i < set.size(); i++) {
      std::cout << "{" << set[i] << " ";
    }
    std::cout << "}";
  }

  friend ostream& operator << (ostream& out, const Set& obj) {
    out << obj.ToString();
    return out;
  }
}