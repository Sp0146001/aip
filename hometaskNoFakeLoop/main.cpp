#include <iostream>
template<typename T>
struct BiList {
    T val;
    BiList<T>* next;
    BiList<T>* prev;
};
template<typename T>
BiList<T>* create_node(const T& value) {
  return new BiList<T>{value, nullptr, nullptr};
}