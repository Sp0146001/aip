#include <iostream>
template< class T> struct  List
{
  T val;
  List < T >* next;
};
template< class T>
void clear(List<T>* h, List<T>* t) {
  while(h!=t) {
    List<T>* n = h->next;
    delete[] h;
    h = n;
  }
}
template< class T>
List< T >* convert(const T* data, size_t s) {
  List<T>* r = (!s) ? nullptr : new List<T>{data[0], nullptr};
  List<T>* t = r;
  try {
    for (size_t i = 1; i < s; ++i) {
      List<T>* n = new List<T>{data[i], nullptr};//new - исключение, утечка с предыдущим new
      t->next = n;
      t = n;
    }
  } catch (...) {
    clear(r, nullptr);
    throw std::exception("err\n");
  }
  return r;
}

