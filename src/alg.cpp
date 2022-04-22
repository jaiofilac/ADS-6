// Copyright 2021 NNTU-CS
#include <string>
template<typename T, int size>
TPQueue<T, size>::TPQueue() : last(-1) { }

template<typename T, int size>
T TPQueue <T, size> ::pop() {
  return arr[last--];
}
template<typename T, int size>
void TPQueue<T, size>::push(const T& item) {
  if (last >= 0){
    for (int i = 0; i <= last; i++) {
      if (arr[i].prior >= item.prior) {
        if (last >= (size - 1)) {
          throw std::string("Full!");
        }
        else {
          last++;
          for (int j = last; j > i; j--) {
            arr[j] = arr[j - 1];
          }
          arr[i] = item;
        }
        break;
      }
      else if (i == last) {
        last++;
        arr[last] = item;
        break;
      }
    }
  }
  else {
    last = 0;
    arr[last] = item;
  }
}
