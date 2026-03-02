include <iostream>
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
