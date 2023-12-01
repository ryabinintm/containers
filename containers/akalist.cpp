#include <sstream>
#include <string>

template<typename T>
Akalist<T>::Akalist()
    : head(nullptr)
    , m_size(0) {
}

template<typename T>
Akalist<T>::Akalist(const Akalist<T> &other) {
  if (other.head == nullptr) {
    head = nullptr;
    m_size = 0;
  } else {
    head = new Node(other.head->data);
    Node *current = head;
    Node *other_current = other.head->next;
    while (other.current != nullptr) {
      current->next = new Node(other_current->data);
      current = current->next;
      other_current = other_current->next;
    }
    m_size = other.m_size;
  }
}

template<typename T>
Akalist<T>::Akalist(Akalist<T> &&other)
    : head(other.head)
    , m_size(other.m_size) {
  other.head = nullptr;
  other.m_size = 0;
}

template<typename T>
Akalist<T> &Akalist<T>::operator=(const Akalist<T> &other) {
  if (this != &other) {
    Akalist<T> temp(other);
    std::swap(head, temp.head);
  }
  return *this;
}

template<typename T>
Akalist<T> &Akalist<T>::operator=(Akalist<T> &&other) {
  if (this != &other) {
    delete head;
    head = other.head;
    other.head = nullptr;
    m_size = other.m_size;
    other.m_size = 0;
  }
  return *this;
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
void Akalist<T>::push_back(const T &value) {
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
void Akalist<T>::insert(int pos, const T &value) {
  if (pos < 0 || static_cast<size_t>(pos) >= m_size) {
    exit(0);
  }
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
  if (pos< 0 || static_cast<size_t>(pos) >= m_size) {
    exit(0);
  }
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
size_t Akalist<T>::size() {
  return m_size;
}

template<typename T>
T Akalist<T>::operator[](int index) {
  if (index < 0 || static_cast<size_t>(index) >= m_size) {
    exit(0);
  }
  Node *temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->data;
}

template<typename T>
std::string Akalist<T>::print() {
  std::ostringstream oss;
  Node *temp = head;
  bool is_comma_first = false;
  while (temp != nullptr) {
    if (is_comma_first) {
      oss << ", ";
    }
    oss << temp->data;
    temp = temp->next;
    is_comma_first = true;
  }
  return oss.str();
}
