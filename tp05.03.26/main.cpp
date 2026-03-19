#include <iostream>
template< class T>
void rp(T* a, size_t k, T* b) {
  for(size_t i = 0; i < k; ++i) {
    T temp = a[i];
    a[i] = b[i];
    b[i] = temp;
  }
}
template< class T>
void swap(T& a, T& b, T& temp, int* err) {
  err = 1;
  temp = a;
  err = 2;
  a = b;
  err = 3;
  b = temp;
  err = 0;
}

int shift_op(int);

void shift(int* a, size_t k) {
  int temp = a[0];
  for(size_t i = 0; i < k - 1; i++) {
    a[i] = shift_op(a[i + 1]);//исключения оператор присваивания, искл-е в ф-ии.
  }
  a[k - 1] = shift_op(temp);
}