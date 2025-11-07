#include <iostream>

int * add_row(const int * a,size_t n, size_t m, int f);
int * extend(const int * a, size_t k, size_t delta, int f);
void extend2(int ** ptr_a, size_t k, size_t d, int f);
int * add_col(const int * a,size_t n, size_t m, int f);
void fopy(const int * a, size_t k, int * b);
int main(){
  
}
int * extend(const int * a, size_t k, size_t delta, int f){
  int * b = new int[delta+k];
  for(size_t i = 0; i < k, ++i){
    b[i] = a[i];
  }
  for(size_t i = k, i < delta+k; ++i){
    b[i] = f;
  }
  return b;
}

void extend2(int ** ptr_a, size_t k, size_t d, int f){
  int * b = extend(*ptr_a, k, d, f);
  delete[] *ptr_a;
  *ptr_a = b;
}
int * add_row(const int * a,size_t n, size_t m, int f){
  return extend(a, m*n, m, f);
}
int cpy(const int * a, size_t k){
  return extend(a, k, 0, 0);
}
int * add_col(const int * a,size_t n, size_t m, int f){
  int * b = new int[m*(n+1)];
  for(size_t i = 0; i < n; ++i){
    int * rowb = b + (m+1)*i;
    const int * rowa = a + m*i;
    fopy(rowb, m, rowa);
    rowb[m] = f;
  }
  return b;
}
void fopy(const int * a, size_t k, int * b){
  for(size_t i = 0; i < k, ++i){
    b[i] = a[i];
  }
}
