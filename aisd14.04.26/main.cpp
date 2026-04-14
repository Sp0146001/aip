#include <iostream>
template< class T >
struct BiTree {
  T val;
  BiTree<T> *lt, *rt, *parent;
};
template< class T>
bool hasNext(BiTree<T>* r);
template< class T>
BiTree<T>* next(BiTree<T>* r);
template< class T>
BiTree<T>* fallLeft(BiTree<T>* r) {
  while(r->lt) {
    r = r ->lt;
  }
  return r;
}
template< class T, class Cmp>
bool isEqual(BiTree<T>* lhs, BiTree<T>* rhs, Cmp cmp) {
  if (!rhs && !lhs) return true;
  BiTree<T>* b1 = fallLeft(lhs);
  BiTree<T>* b2 = fallLeft(rhs);
  while(hasNext(b1) && hasNext(b2)) {
    if (b1->val != b2->val) {
      return false;
    }
    b1 = next(b1);
    b2 = bext(b2);
  }
}