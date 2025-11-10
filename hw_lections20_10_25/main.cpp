#include <iostream>
#include <limits>
size_t gcd(size_t a, size_t b);
size_t u_ovrflw(size_t a, size_t b);
void rm(size_t* mtx);

int main()
{
  size_t n = 0;
  std::cin >> n;
  size_t* nums = nullptr;
  try{
     nums = new size_t[n];
  } catch(const std::bad_alloc &){
    return 2;
  }
  for(size_t i = 0; i < n; ++i){
    std::cin >> nums[i];
  }
  if(std::cin.fail()){
    std::cerr << "Fail input\n";
    rm(nums);
    return 1;
  }
  size_t result = nums[0];
  for(size_t i = 1; i < n; ++i){
    result = gcd(result, nums[i]);
  }
  std::cout << result << "\n";
  rm(nums);
  return 0;
}

size_t gcd(size_t a, size_t b){
  while(b!=0){
    size_t rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}
void rm(size_t* mtx){
  delete[] mtx;
}
