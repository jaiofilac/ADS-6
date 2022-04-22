// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include "alg.cpp"

template<typename T, int size>
class TPQueue {
 private:
  T arr[size];
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

#endif  // INCLUDE_TPQUEUE_H_
