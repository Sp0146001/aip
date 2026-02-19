#include <iostream>

template< size_t N >
struct Fib {
	enum {
		value = N * Fib < N - 1 >::value
	};
};

template < >
struct Fib< 0 > {
	enum {
		value = 0
	};
};
template < >
struct Fib< 1 > {
	enum {
		value = 1
	};
};
int main() {
	std::cout << Fib< 10 >::value << '\n';
}
