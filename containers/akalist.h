#pragma once

#include "container.h"

template<typename T>
class Akalist : public Container<T> {
public:
  Akalist();
  ~Akalist();
  void push_back(T value) override;
  void insert(int pos, T value) override;
  void erase(int pos) override;
  int size() override;
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
  int m_size;
};

#include "akalist.cpp"
