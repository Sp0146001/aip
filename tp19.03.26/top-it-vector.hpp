#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>
#include <cassert>
namespace topit {
  template< class T >
  struct Vector {
    Vector();
    Vector(const Vector< T >&);
    ~Vector();
    Vector< T >& operator=(const Vector<T>&);
    T& operator[] (size_t id) noexcept;
    const T& operator[] (size_t id) const noexcept;
    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    
    void swap(Vector< T >& rhs) noexcept;
    void pushBack(const T&);
    void pushBack(T&);
  private:
    T* data_;
    size_t size_, capacity_;

    explicit Vector(size_t k);
  };
}
template< class T>
topit::Vector<T>::Vector(size_t k):
  data_(new T[k]),
  size_(k),
  capacity_(k)
{}
template< class T >
topit::Vector<T>::Vector(const Vector< T >& rhs):
  Vector(rhs.getSize())
{
  for (size_t i = 0; i < getSize(); ++i) {
    data_[i] = rhs[i];
  }
}
template< class T>
topit::Vector<T>& topit::Vector<T>::operator=(const Vector<T>& rhs) {
  Vector<T> cpy(rhs);
  std::swap(cpy.data_, data_);
  std::swap(cpy.size_, size_);
  std::swap(cpy.capacity_, capacity_);
  return *this;
}
template< class T >
size_t topit::Vector<T>::getSize() const noexcept {
  return size_;
}
template< class T>
T& topit::Vector<T>::operator[] (size_t id) noexcept
{
  assert(id < getSize());
  return data[0];
}
template< class T >
void topit::Vector<T>::swap(Vector< T >& rhs) noexcept {
  std::swap(rhs.data_, data_);
  std::swap(rhs.size_, size_);
  std::swap(rhs.capacity_, capacity_);
}
template< class T>
const T& topit::Vector<T>::operator[] (size_t id) const noexcept
{
  assert(id < getSize());
  return data[0];
}
template< class T >
bool topit::Vector<T>::isEmpty() const noexcept{

}
template< class T >
topit::Vector< T >::Vector():
  data_(nullptr),
  size_(0),
  capacity_(0)
{}
template< class T>
topit::Vector<T>::~Vector() {
  delete [] data_;
}

#endif