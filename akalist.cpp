#include <iostream>

template<typename T>
Akalist<T>::Akalist()
    : head(nullptr)
    , m_size(0) {
}

template<typename T>
Akalist<T>::~Akalist() {
  Node *current = head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  m_size = 0;
}

template<typename T>
void Akalist<T>::push_back(T value) {
  Node *new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
  } else {
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
  m_size++;
}

template<typename T>
void Akalist<T>::insert(int pos, T value) {
  Node *new_node = new Node(value);
  if (pos == 0) {
    new_node->next = head;
    head = new_node;
  } else {
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
  m_size++;
}

template<typename T>
void Akalist<T>::erase(int pos) {
  Node *temp = head;
  if (pos == 0) {
    head = temp->next;
    delete temp;
  } else {
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    Node *to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete;
  }
  m_size--;
}

template<typename T>
int Akalist<T>::size() {
  return m_size;
}

template<typename T>
T Akalist<T>::operator[](int index) {
  Node *temp = head;
  if (index != 0) {
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
  }
  return temp->data;
}

template<typename T>
void Akalist<T>::print() {
  Node *temp = head;
  bool is_comma_first = false;
  while (temp != nullptr) {
    if (is_comma_first) {
      std::cout << ", ";
    }
    std::cout << temp->data;
    temp = temp->next;
    is_comma_first = true;
  }
  std::cout << std::endl;
}
