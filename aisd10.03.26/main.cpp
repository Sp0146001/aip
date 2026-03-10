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
/*задача, првоерить. что указанные списки не имеют общих элеменов*/
template < class T>
bool no_common(const List< const List< T >* >* h) {

}
