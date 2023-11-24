#pragma once

#include <cstddef>
#include "container.h"

template<typename T>
class Akalist final : public Container<T> {
public:
  Akalist();
  ~Akalist();
  void push_back(T value) override;
  void insert(int pos, T value) override;
  void erase(int pos) override;
  size_t size() override;
  T operator[](int index) override;
  void print() override;
private:
  struct Node {
    T data;
    Node *next;
    Node(T d) : data(d), next(nullptr) {
    }
  };
  Node *head;
  size_t m_size;
};

#include "akalist.cpp"
