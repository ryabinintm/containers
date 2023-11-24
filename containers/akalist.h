#pragma once

#include <cstddef>
#include <string>

#include "container.h"

template<typename T>
class Akalist final : public Container<T> {
public:
  Akalist();
  Akalist(const Akalist &other);
  Akalist(Akalist &&other);
  Akalist &operator=(const Akalist &other);
  Akalist &operator=(Akalist &&other);
  ~Akalist();

  void push_back(const T &value) override;
  void insert(int pos, const T &value) override;
  void erase(int pos) override;
  size_t size() override;
  T operator[](int index) override;
  std::string print() override;
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
