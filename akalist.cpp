#include <iostream>

template<typename T>
Akalist<T>::Akalist()
    : m_size(0) {
}

template<typename T>
Akalist<T>::~Akalist() {

}

template<typename T>
void Akalist<T>::push_back(T value) {

  m_size++;
}

template<typename T>
void Akalist<T>::insert(int pos, T value) {

  m_size++;
}

template<typename T>
void Akalist<T>::erase(int pos) {

  m_size--;
}

template<typename T>
int Akalist<T>::size() {
  return m_size;
}

template<typename T>
T Akalist<T>::operator[](int index) {
  return 0;
}

template<typename T>
void Akalist<T>::print() {
  bool is_common_first = false;

    if (is_common_first) {
      std::cout << ", ";
    }

    is_common_first = true;
  std::cout << std::endl;
}
