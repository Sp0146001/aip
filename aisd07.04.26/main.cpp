template< class T >
struct BiTree {
  T val;
  BiTree<T>* lt, * rt,* parent;
};
template< class T>
BiTree<T>* fallLeft(BiTree<T>* root) {
  if (!node) {
    return node;
  }
  
}

template< class T, class F >
F traverse(BiTree<T>* root, F f) {
  if (!root) {
    return f;
  }

  BiTree<T>* curr = fallLeft(root);
  while (curr) {
    f(curr->val);
    if (curr->rt) {
      curr = fallLeft(curr->rt);
    } else {
      BiTree<T>* parent = curr->parent;
      while(parent && parent->lt != curr) {

      }
    }
  }
}