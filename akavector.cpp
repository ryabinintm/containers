#include "akavector.h"

template<typename T>
Akavector<T>::Akavector()
    : m_size(0)
    , capacity(10) {
  values = new T[capacity];
}


template<typename T>
void Akavector<T>::push_back(T value) {
  values[m_size] = value;
  m_size++;
}

template<typename T>
void Akavector<T>::insert(int pos, T value) {
  
}

template<typename T>
void Akavector<T>::erase(int pos, T value) {

}

template<typename T>
int Akavector<T>::size() {
  return m_size;
}

template<typename T>
T Akavector<T>::operator[](int index) {
  return values[index];
}
