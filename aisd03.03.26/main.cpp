#include <iostream>
template<class T> struct List {
  T val;
  List<T>* next; 
};
template<class T> struct Vec
{
  T* data;
  size_t s;
};
template<class T>
void clear(List<Vec<T>>*h){
    if(h){
        return;
    }
    delete[] h->val.data;
    while(h){
        delete[] h->val.data;
        List<Vec<T>> * stub = h;
        h=h->next;
        delete[] stub;
    }
}
template<class T>
Vec<T> copy(const Vec<T> & val){
    Vec<T> result{nullptr, val.s};
    try{
      result.data = new T[result.s];
      for (size_t i = 0; i <  result.s; ++i){
          result.data[i] = val.data[i];
      }
    } catch(...){
        delete[] result.data;
        throw;
    }
    return result;
}

template<class T>  
List< Vec<T> >* copy(List< Vec<T> >* h) {
  if (!h) {
    return h;
  }
  List< Vec<T> >* curr = nullptr;
  List< Vec<T> >* prev = nullptr;
  Vec<T> stub{nullptr, 0};
  try{
    stub = copy(h->val);
    prev = new List< Vec<T> >{stub, nullptr};
    List< Vec<T> >* result = prev;
    h = h->next;
    while(h) {
      curr = new List< Vec<T> >{stub, nullptr};
      prev->next = curr;
      h = h->next;
      prev = prev->next;
    }
  } catch(...){
    clear(result);
    delete[] stub->data;
    throw;
  }

}
