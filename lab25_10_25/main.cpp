#include <iostream>
#include <limits>
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
bool ver_ovfl(unsigned a, unsigned b, unsigned c){
	bool p1 = (min_u() / a) < a && a < (max_u() / a);
	p1 = p1 && ((min_u() / b) < b) && (b < (max_u() / b));
	p1 = p1 && ((min_u() / c) < c) && (c < (max_u() / c));
	if(p1){
		p1 =p1 && ((max_u() - a*a) > b*b) && ((max_u() - b*b) > c*c);
	        p1 = p1 && ((max_u() - a*a) > c*c) && ((max_u() - c*c) > b*b);
	        p1 = p1 && ((max_u() - b*b) > a*a) && ((max_u() - c*c) > a*a);
	}
	return p1;
}

bool isPyth(unsigned a, unsigned b, unsigned c){
	bool p = a*a ==(b*b + c*c);
	p = p || (b*b == c*c + a*a);
	p = p || (c*c == a*a + b*b);
	return p;
}
int main(){
	u_t a = 0, b = 0, c = 0;
	std::cin >> c >> b;
	size_t count = 0;
	while(std::cin >> a){
		if(ver_ovfl(a,b,c)){
			count+=isPyth(a,b,c) ? 1 : 0;
			c = b;
			b = a;
		}
		else {
			std::cerr << "Overflowing was detected\n";
			return 2;
		}
	}
	if(std::cin.eof()){
		std::cout << count << "\n";
	}
	else if(std::cin.fail()){
		std::cerr << "Input end\n";
		return 1;
	}
	return 0;
}
