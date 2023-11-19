#include <iostream>

template<typename T>
Akavector<T>::Akavector()
    : m_size(0)
    , capacity(10) {
  values = new T[capacity];
}

template<typename T>
Akavector<T>::~Akavector() {
  delete[] values;
}

template<typename T>
void Akavector<T>::push_back(T value) {
  check_capacity();
  values[m_size] = value;
  m_size++;
}

template<typename T>
void Akavector<T>::insert(int pos, T value) {
  check_capacity();
  for (int i = m_size; i >= pos; i--) {
    values[i + 1] = values[i];
  }
  values[pos] = value;
  m_size++;
}

template<typename T>
void Akavector<T>::erase(int pos) {
  for (int i = pos; i < m_size; i++) {
    values[i] = values[i + 1];
  }
  m_size--;
}

template<typename T>
int Akavector<T>::size() {
  return m_size;
}

template<typename T>
T Akavector<T>::operator[](int index) {
  return values[index];
}

template<typename T>
void Akavector<T>::print() {
  bool is_comma_first = false;
  for (int i = 0; i < m_size; i++) {
    if (is_comma_first) {
      std::cout << ", ";
    }
    std::cout << values[i];
    is_comma_first = true;
  }
  std::cout << std::endl;
}

template<typename T>
void Akavector<T>::check_capacity() {
  if (m_size == capacity) {
    capacity *= 2;
    T *temp = new T[capacity];
    for (int i = 0; i < m_size; i++) {
      temp[i] = values[i];
    }
    delete[] values;
    values = temp;
  }
}