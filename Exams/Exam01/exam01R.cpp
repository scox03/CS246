template <typename T>
bool Similar(Array<T>& ar1, Array<T>& ar2) {
  if(ar1.size < ar2.size) {
    for(int i = 0; i < ar1.size; i++) {
      if(ar1[i] != ar2[i]) {
        return false;
        break;
      } else {
        return true;
      }
    }
  }

  if(ar1.size > ar2.size) {
    for(int j = 0; j < ar2.size; j++) {
      if(ar1[j] != ar2[j]) {
        return false;
        break;
      } else {
        return true;
      }
    }
  }
}

//An attempt to finish question 3
template <typename T>
void MidAppend(Array<T>& data, Array<T>& addon) {
  data.Resize(data.size + addon.size);
  for(int i = data.size - 1; i < data.Length(); i++) {
    data[i + 1] = data[i];
  }
  for(i = data.Length()/2; i < data.size; i++) {
  }
}
