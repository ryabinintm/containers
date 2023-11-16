#pragma once

template<typename T>
class Container {
public:
 virtual ~Container() {}
 virtual void push_back(T value) = 0;
 virtual void insert(int pos, T value) = 0;
 virtual void erase(int pos) = 0;
 virtual int size() = 0;
 virtual void print() = 0;
};
