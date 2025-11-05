#include <iostream>
using u_t = unsigned;
u_t max_u(){
	using namespace std;
	using u_limit = numeric_limits< u_t >;
	return u_limit::max();
}
u_t min_u(){
        using namespace std;
        using u_limit = numeric_limits< u_t >;
        return u_limit::min();
}
//Код 1, если не удалось считать массив
//Код 2, если не удалось выделить память
//Код 0, если все хорошо + вывод характеристики.
//Рассчитать НОД для всего массива. По желанию - проверка на переполнение беззнаковых, по желанию - если числа знаковые(UB)
u_t gcd(u_t a, u_t b);
void make_input(size_t n);
void rm(u_t mtx);
int main()
{
  size_t a = 0;
  std::cin >> n;
  u_t * nums = nullptr;
  try{
    nums = make_input(n);
  } catch(const std::bad_alloc &){
    return 2;
  }
  nums = input(n);
  if(std::cin.fail()){
    std::cerr << "Fail input\n";
    return 1;
  }
  output_result(nums);
  rm(nums)
}

size_t gcd(u_t a, u_t b){
  while(b!=0){
    size_t rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}
void make_input(size_t n){
  u_t * mtx = new u_t[n];
  for(size_t i = 0; i < n; ++i){
    std::cin >> mtx[i];
  }
  return mtx;
}
void rm(u_t mtx){
  delete[] mtx;
}
