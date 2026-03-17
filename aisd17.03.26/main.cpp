#include <iostream>
template< class T, size_t S > struct Array {
  T data[S];
};
template< class T > struct Vector {
  T* data;
  size_t size, capacity;
};
