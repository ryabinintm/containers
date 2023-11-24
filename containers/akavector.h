#pragma once

#include <cstddef>
#include <string>

#include "container.h"

template<typename T>
class Akavector final : public Container<T> {
public:
  Akavector();
  Akavector(const Akavector &other);
  Akavector(Akavector &&other);
  Akavector &operator=(const Akavector &other);
  Akavector &operator=(Akavector &&other);
  ~Akavector();

  void push_back(const T &value) override;
  void insert(int pos, const T &value) override;
  void erase(int pos) override;
  size_t size() override;
  T operator[](int index) override;
  std::string print() override;
private:
  size_t m_size;
  size_t capacity;
  T *values;
  void check_capacity();
};

#include "akavector.cpp"
