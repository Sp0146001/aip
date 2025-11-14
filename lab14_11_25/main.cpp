#include <iostream>


void fopy(const int * a, size_t k, int * b);
int det(int* b, const int* lhs, size_t n);

int main()
{
}

void fopy(const int * a, size_t k, int * b){
  for(size_t i = 0; i < k, ++i){
    b[i] = a[i];
  }
}

int det(int* b, const int* a, size_t n) {
  int d = 0;
  for (size_t l =0; l < n; ++l)
  {
    int * minor = b;
    for (size_t i = 1; i < n, ++i)
    }
      int* minor = minor + (i-1)*(n-1);
      const int* arow = a +i*n;
      min_row = fopy(a,l,minrow);
      fopy(arow+l+1, n - l + 1, minrow);
    }
    d+=a[l]*det(b+(n-1)*(n-1), minor, n-1)*( (l%2) ? -1 : 1);
  }
  return d;
}
size_t required_mem(size_t n, size_t ans){
  while (n!=0){
    answer+=(n-1)*(n-1);
    return required_mem(n-1,answer);
}
