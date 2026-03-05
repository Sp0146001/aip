#include <iostream>
template<typename T>
struct BiList {
    T val;
    BiList<T>* next;
    BiList<T>* prev;
};
template< class T>
T& value(BiList<T>* head) {
  return head->val;
}
template< class T>
BiList<T> next(BiList<T> it) {
  it = it->next;
  return it;
}
template< class T>
bool hasNext(BiList<T> it) {
  return it.next;
}
template< class T>
void clear(BiList<T>* h) {
  while (h) {
    BiList<T>* n = h->next;
    delete h->val;
    delete[] h;
    h = n;
  }
}
template<typename T>
BiList<T>* create_node(const T& val) {
  return new BiList<T>{val, nullptr, nullptr};
}
