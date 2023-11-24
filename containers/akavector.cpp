#include <sstream>
#include <string>

template<typename T>
Akavector<T>::Akavector()
    : m_size(0)
    , capacity(10) {
  values = new T[capacity];
}

template<typename T>
Akavector<T>::Akavector(const Akavector<T> &other) {
  m_size = other.m_size;
  values = new T[m_size];
  for (size_t i = 0; i < m_size; i++) {
    values[i] = other.values[i];
  }
}

template<typename T>
Akavector<T>::Akavector(Akavector<T> &&other) {
  m_size = other.m_size;
  values = other.values;
  for (size_t i = 0; i < m_size; i++) {
    other.values = nullptr;
    other.values++;
  }
  other.m_size = 0;
}

template<typename T>
Akavector<T> &Akavector<T>::operator=(const Akavector<T> &other) {
  delete[] values;
  m_size = other.m_size;
  values = new T[m_size];
  for (size_t i = 0; i < m_size; i++) {
    values[i] = other.values[i];
  }
  return *this;
}

template<typename T>
Akavector<T> &Akavector<T>::operator=(Akavector<T> &&other) {
  delete[] values;
  m_size = other.m_size;
  values = other;
  for (size_t i = 0; i < m_size; i++) {
    other.values = nullptr;
    other.values++;
  }
  other.m_size = 0;
  return *this;
}

template<typename T>
Akavector<T>::~Akavector() {
  delete[] values;
}

template<typename T>
void Akavector<T>::push_back(const T &value) {
  check_capacity();
  values[m_size] = value;
  m_size++;
}

template<typename T>
void Akavector<T>::insert(int pos, const T &value) {
  check_capacity();
  for (int i = m_size; i >= pos; i--) {
    values[i + 1] = values[i];
  }
  values[pos] = value;
  m_size++;
}

template<typename T>
void Akavector<T>::erase(int pos) {
  if (pos < 0 || static_cast<size_t>(pos) >= m_size) {
    exit(0);
  }
  for (size_t i = pos; i < m_size; i++) {
    values[i] = values[i + 1];
  }
  m_size--;
}

template<typename T>
size_t Akavector<T>::size() {
  return m_size;
}

template<typename T>
T Akavector<T>::operator[](int index) {
  if (index < 0 || static_cast<size_t>(index) >= m_size) {
    exit(0);
  }
  return values[index];
}

template<typename T>
std::string Akavector<T>::print() {
  std::ostringstream oss;
  bool is_comma_first = false;
  for (size_t i = 0; i < m_size; i++) {
    if (is_comma_first) {
      oss << ", ";
    }
    oss << values[i];
    is_comma_first = true;
  }
  return oss.str();
}

template<typename T>
void Akavector<T>::check_capacity() {
  if (m_size == capacity) {
    capacity *= 2;
    T *temp = new T[capacity];
    for (size_t i = 0; i < m_size; i++) {
      temp[i] = values[i];
    }
    delete[] values;
    values = temp;
  }
}
