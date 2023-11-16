#pragma once

template<typename T>
class Akavector {
public:
 Akavector();
 ~Akavector();
 void push_back(T value);
 void insert(int pos, T value);
 void erase(int element);
 int size();
 T operator[](int index);
 void info();
 void print();
private:
  int m_size;
  int capacity;
  T *values;
  void check_capacity();
};
#include "akavector.cpp"
