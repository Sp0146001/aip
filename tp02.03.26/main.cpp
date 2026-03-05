#include <iostream>
template< class T> struct Vec
{
  T* data;
  size_t s;
};
template< class T> struct VecIt
{
  T* data;
  size_t i, s;
};
template< class T> struct List {
  T val;
  List<T>* next;
};
template< class T> struct ListIt {
  List<T>* curr;
};
template< class T>
struct ListOfVecIt {
  List< Vec<T> >* curr;
  size_t i;
};
/* functions*/
template< class T>
VecIt<T> begin(Vec<T> v) {
  return { v.data, v.s, v.s};
}
template< class T>
T& value(VecIt<T> it) {
  return it.data[it.i-1];
}
template< class T>
VecIt<T> next(VecIt<T> it) {
  --it.i;
  return it;
}
template< class T>
bool Next(VecIt<T> it) {
  return it.i;
}
/*поможет возможно для S1*/
template< class T>
ListIt< T > begin(List< T > h) {
  return {h};
}
template< class T>
T& value(ListIt<T> it) {
  return it.curr->val;
}
template< class T>
ListIt<T> next(ListIt<T> it) {
  it.curr = it.curr->next;
  return it;
}
template< class T>
bool hasNext(ListIt<T> it) {
  return it.curr;
}
/*заново фигачим*/
template< class T>
ListIt<T*> begin(List<T*>* h) {
  while(h) {
    if (h->val) {
      return {h};
    }
    h = h->next;
  }
  return nullptr;
}
template< class T>
ListIt<T*> next(ListIt<T*>* it) {
  return begin(it.curr->next);
}
template< class T>
bool hasNext(ListIt<T*>* it) {
  return it.curr;
}
template< class T>
T& value() {
  return *(it.curr->val);
}x`