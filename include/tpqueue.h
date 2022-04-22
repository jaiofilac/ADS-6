// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T *arr;
  int last;
 public:
  TPQueue();
  void push(const T&);
  T pop();
};

struct SYM {
  char ch;
  int prior;
};

template<typename T, int size>
TPQueue<T, size>::TPQueue() : last(-1) { arr = new T[size] }

template<typename T, int size>
T TPQueue <T, size> ::pop() {
  return arr[last--];
}

template<typename T, int size>
void TPQueue<T, size>::push(const T& item) {
  if (last >= 0) {
    for (int i = 0; i <= last; i++) {
      if (arr[i].prior >= item.prior) {
        if (last >= (size - 1)) {
          throw std::string("Full!");
        } else {
          last++;
          for (int j = last; j > i; j--) {
            arr[j] = arr[j - 1];
          }
          arr[i] = item;
        }
        break;
      } else if (i == last) {
        last++;
        arr[last] = item;
        break;
      }
    }
  } else {
    last = 0;
    arr[last] = item;
  }
}
#endif  // INCLUDE_TPQUEUE_H_
