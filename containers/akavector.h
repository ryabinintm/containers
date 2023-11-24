#pragma once

#include <cstddef>
#include "container.h"

template<typename T>
class Akavector final : public Container<T> {
public:
 Akavector();
 ~Akavector();
 void push_back(T value) override;
 void insert(int pos, T value) override;
 void erase(int pos) override;
 size_t size() override;
 T operator[](int index) override;
 void print() override;
private:
  size_t m_size;
  size_t capacity;
  T *values;
  void check_capacity();
};

#include "akavector.cpp"
