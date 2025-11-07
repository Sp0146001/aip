#include <iostream>

int * extend(const int * a, size_t k, size_t d, int filler);

int main(){
  
}
int * extend(const int * a, size_t k, size_t d, int f){
  int * b = new int[d];
  for(size_t i = 0; i < k, ++i){
    b[i] = a[i];
  }
  for(size_t i = k, i < d; ++i){
    b[i] = f;
  }
  return b;
}
