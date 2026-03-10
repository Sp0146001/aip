#include <iostream>
template<class T> struct List {
  T val;
  List<T>* next, * prev; 
};
template<class T> struct Vec
{
  T* data;
  size_t s;
};
template< class T>
const List<T>* tohead(const List<T>* h) {
  while(h->prev) 
  {
    h = h->prev;
  }
  return h;
}
template< class T >
bool hasCommon(const List<T>* h1, const List<T>* h2) {
  return (tohead(h1) == tohead(h2));
}
/*задача, првоерить, что указанные списки не имеют общих элеменов*/
template < class T>
bool no_common(const List< const List< T >* >* h) {
  const List<T>* h1 = h;
  while(h1) {
    const List<T>* h2 = h->next;
    while(h2) {
      if(h1 == h2) {
        break;
      }
      if(hasCommon(h1->val, h2->val)) {
        return :::;
      }
    h2 = h2->next;
    }
    h1 = h1->next;
  }
}

