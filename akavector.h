#pragma once
//#include <cstddef>

//namespace Container {
  template<typename T>
  class Akavector {
  public:
   Akavector();
   void push_back(T value);
   void insert(int pos, T value);
   void erase(int pos, T value);
   int size();
   T operator[](int index);
  private:
    int m_size;
    int capacity;
    T *values;
  };
//}


