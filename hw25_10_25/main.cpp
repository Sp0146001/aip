#include <iostream>
#include <limits>

size_t max_u(){
	using namespace std;
	using u_limit = numeric_limits< size_t >;
	return u_limit::max();
}
size_t min_u(){
        using namespace std;
        using u_limit = numeric_limits< size_t >;
        return u_limit::min();
}

size_t lcm(size_t  a, size_t  b){
        while(a>0 && b>0){
                if(a>b){
                        a%=b;
                } else {
                        b%=a;
                }
	}
        return a+b;
}

size_t ovrflw(size_t a, size_t b){ //runtime-error
	bool p = (min_u() < a) && (a < max_u()) && (max_u()/a > a);
	p = p && ((min_u() < b) && (b < max_u()) && (max_u()/b > b));
	if(p){
		return lcm(a,b);
	}
	throw
	  std::runtime_error("over/underflowing");
}

int main(){
	size_t a = 0, b = 0;
	size_t result_II = 0, result_III = 0;
	while(std::cin >> a){
		try{
			result_II = ovrflw(a,b);
			result_III+=a*a;
			b = a;
		} catch(const std::runtime_error &e){
			std::cerr << e.what() << "\n";
			return 2;
		}
	}
	if(std::cin.eof()){
		std::cout << result_II << " " << result_III << "\n";
	} else if(std::cin.fail()){
		std::cerr << "Input end\n";
		return 1;
	}
        return 0;
}
