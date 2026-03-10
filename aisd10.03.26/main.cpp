#include <iostream>
template<class T> struct List {
  T val;
  List<T>* next, * prev; 
};
template<class T> struct MList {
  T val;
  MList<T>* next, * prev, * ref; 
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
/*в списке с дополнительными связями проверить, что все дополнительные связи указывают в тот же список или не ссылаются никуда вовсе*/
template< class T> 
bool selfRefed(List<T>* h) {
  List<T>* it = tohead(h);
  List<T>* head = it;
  while(it) {
    if (it->ref != tohead(it->next)) {
      return false;
    }
    it = it->next;
  }
  return true;
}
template< class T>
bool hasRef(const MList<T>* h) {
  MList<T>* head = tohead(h);
  while(head) {
    if(head->ref && head->ref == h) {
      return true;
    }
    head = head->next;
  }
  return false;
}
/*в спсике с дополнительными связями найти узлы, на которые нет доп ссылок в других узлах. Вернуть список из таких узлов*/
template< class T>
List< const MList<T>* >* noRefs(const MList<T>* h) {
  const MList<T>* head = tohead(h);
  List< const MList<T>* >* prevM = nullptr;
  List< const MList<T>* >* hRef = nullptr;
  while(head) {
    if (!(hasRef(head))) {
      List<const MList<T>* >* href
      href->val = head;
      href->prev = prevM;
      href->next = nullptr;
      head = head->next;
    }
  }
}
