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
size_t gcd(u_t a, u_t b);

int main()
{
  u_t a = 0;
  std::cin >> n;
  int * nums = nullptr;
  try{
    nums = new int[n];
  } catch(const std::bad_alloc &){
    return 2;
  }
}
size_t gcd(u_t a, u_t b){
  while(b!=0){
    size_t rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}
