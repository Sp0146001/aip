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
template< class T, class C >//разделение списка на два с условием cond(class C).
List<T>* split(List<T>** head, C cond) {
  List<T>* redH = nullptr, *blueH = nullptr;
  List<T>* H = head;

}
template< class T, class C >
size_t count(const List<T>* head, C cond, List< const List<T>* >** chead, List< const List<T>* >** ctail) {
  size_t res = 0;
  bool fgHead = false;
  bool fgTail = false;
  while(head) {
    try {}//снизу исключение
    if(cond(head->val)) {
      res++;
      List< const
    }
    head = head->next;
  }
  *chead = h;
  *ctail = t;
  return res;
}
//test
