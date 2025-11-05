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
void make(size_t n);
void input(size_t n);
u_t u_ovrflw(u_t a, u_t b);
void output_result(u_t * mtx, size_t n);
void rm(u_t * mtx);

int main()
{
  size_t a = 0;
  std::cin >> n;
  u_t * nums = nullptr;
  try{
    nums = make(n);
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
  return 0;
}

size_t gcd(u_t a, u_t b){
  while(b!=0){
    size_t rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}
void make(size_t n){
  try{
     u_t * mtx = new u_t[n];
  } catch(const std::bad_alloc &){
    rm(mtx);
    return 2;
  }
  return mtx;
}
void input(size_t n){
  for(size_t i = 0; i < n; ++i){
    std::cin >> mtx[i];
  }
  return mtx;
}
u_t u_ovrflw(u_t a, u_t b){ //runtime-error
	bool p = (min_u() < a) && (a < max_u());
	p = p && ((min_u() < b) && (b < max_u());
	if(p){
		return gcd(a,b);
	}
	throw
	  std::runtime_error("over/underflowing");
}
void output_result(u_t * mtx,size_t n){
  u_t result = 0;
  for(size_t i = 0; i < n; ++i){
    try{
      result = u_ovrflw(mtx[i], mtx[i+1]);
    } catch(const std::runtime_error &e){
      std::cerr << e.what() << "\n";
      return 3;
    }
  }
  std::cout >> result >> "\n";
}
void rm(u_t mtx){
  delete[] mtx;
}
