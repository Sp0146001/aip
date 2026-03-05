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
/* начало написания функций*/
template< class T>
VecIt<T> begin(VecIt<T> v) {//nachalo
  return {v.data, 0, v.s};
}
template< class T>
VecIt<T> next(VecIt<T> it) {//sledush
  it.i++;
  return it;
}
template< class T> 
bool hasNext(VecIt<T> it) {
  return (i == s);
}
template<class T>
T& value(VecIt<T> it) {
  return it.data[it.i];
}
/* списки, раньше были векторы*/
template< class T>
void clear(List<T>* h) {
  while (h) {
    List<T>* n = h->next;
    delete[] h;
    h = n;
  }
}
template<class T>
size_t size(List<T>* h) {
  size_t count = 0;
  while (h) {
    count++;
    h = h->next;
  }
  return count;
}
/*новые функции для списка из указателей на данные*/
template< class T>
void clear(List<T*>* h) {
  while (h) {
    List<T*>* n = h->next;
    delete h->val;
    delete[] h;
    h = n;
  }
}
template<class T>
size_t size(List<T*>* h) {
  size_t count = 0;
  while (h) {
    count+=(h->val) ? 1 : 0;
    h = h->next;
  }
  return count;
}
/* односвязный список односвязных списков.. список списков*/
template< class T>
void clear2(List< List<T>*>* h) {
  while(h) {
    clear<T>(h->val);
    h = h->next;
  }
  clear<List<T>*>(h);
}
template< class T>
void clear(List < List< T>* >* h) {
  while (h) {
    List< List<T>*> n = h->next;
    clear<T>(h->val);
    delete h;
    n = h;
  }
}
template< class T>
size_t size(const List< const List< T >* >* h) {
  size_t count = 0;
  while (h) {
    count+=size<T>(h->val);
    h = h->next;
  }
  return count;
}
/* вектор списков ЕМАЕ*/
template< class T>
size_t clear(Vec< List<T>* > v) {
  for (size_t i = 0; i < v.s; ++i) {
    clear<T>(v.data[i]);
  }
  delete[] v.data;
}
template< class T>
size_t size(Vec< const List<T>* > v){
  size_t count = 0;
  for (size_t i = 0; i < v.s; ++i) {
    count+=size<T>(v.data[i]);
  }
  return count;
}

int main()
{
}
