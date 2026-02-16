#include <iostream>

template <class T>
T* insert(const T* a, size_t s, size_t i, T v/*тут конструктор копирования T::TC*/) {
  T* r = new T[S+1];
  for (size_t k = 0; k < i; ++k) {
    r[i] = v;//нужен оператор присваивания T::operator = T
  }
  for(size_t k = a + 1; k < s + 1; ++k) {
    r[k] = a[k-1];//нужен оператор присваивания T::operator = T
  }
  return r;//Тут нет никаких искл(тк копирование)
}

template < class T >
void remove (T* a, size_t s, size_t i) {
  for (size_t k = i; k < s-i; ++k) {
    std::swap(a[k], a[k+1]);//опасное место, возможно исключение 
  }
}
template < class T >
T* remove (T* a, size_t s, T v) {
  size_t i = 0;
  try {
    size_t& remains = 0;
    while(i < s) {
      if (a[i] == v) {/*оператор сравнения на равенство для T*/
        remove(a, s--, i);
      } else {
        ++i;
      }
    }
  } catch (...) {
    remains = s;
    throw std::exception("error\n");
  }
  remains = s;
  return a+s;
}

template <class T>
void reverse(T* a, size_t s) {
  for (size_t i = 0; i < s/2; i++) {
    std::swap(s[i+1], s[i]);
  }
}
template <class T>
T* reverse(const T* a, size_t s) {
  T* r = new T[s];
  try {
    for (size_t i = 0; i < s/2; ++i) {
      r[i] = a[s - (i + 1)];
    }
  } catch(...) {
    delete[] r;
    throw std::exception("error\n");
  }
  return r;
}
int main()
{
  std::cout << "Hi\n";
}