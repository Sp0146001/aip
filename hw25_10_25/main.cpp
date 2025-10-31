#include <iostream>
using u_t = unsigned;
size_t gcd(size_t a, size_t  b){
	return gcd(b, a%b);
}
size_t lcm(size_t  a, size_t  b){
	return a*b/(gcd(a,b));
}

int main(){
	size_t  a = 0, b = 0, result_II = 0, result_III = 0;
	std::cin >> b;
	while(std::cin >> a){
		
	}
	if(std::cin.eof()){
		std::cout << result_II << " " << result_III << "\n";
	} else if(std::cin.fail()){
		std::cerr << "Input end\n";
		return 1;
	}
        return 0;
}
