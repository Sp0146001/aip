#include <iostream>

template< class T>
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c) {
  size_t i = 0, j = 0;
  while (i < sa && j < sb) {
    if (a[i] < b[i]) {
      c[i+j] = a[i++];
    } else {
      c[i+j] = b[j++];
    }
  }
  while (i < sa) {
    c[i + j] = a[i++];
  }
  while (j < sb) {
    c[i + j] = b[i++];
  }
  return c;
}
