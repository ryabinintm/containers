#pragma once

#include "container.h"

template<typename T>
class Akavector : public Container<T> {
public:
 Akavector();
 ~Akavector();
 void push_back(T value) override;
 void insert(int pos, T value) override;
 void erase(int pos) override;
 int size() override;
 T operator[](int index);
 void print() override;
private:
  int m_size;
  int capacity;
  T *values;
  void check_capacity();
};

#include "akavector.cpp"
