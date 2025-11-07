#include <iostream>

int * extend(const int * a, size_t k, size_t delta, int fill);
void extend2(int ** ptr_a, size_t k, size_t d, int f);
int main(){
  
}
int * extend(const int * a, size_t k, size_t delta, int fill){
  int * b = new int[delta+k];
  for(size_t i = 0; i < k, ++i){
    b[i] = a[i];
  }
  for(size_t i = k, i < delta+k; ++i){
    b[i] = fill;
  }
  return b;
}

void extend2(int ** ptr_a, size_t k, size_t d, int f){
  int * b = extend(*ptr_a, k, d, f);
  delete[] *ptr_a;
  *ptr_a = b;
