#include <iostream>
int make(int rows, int cols){
	
}
int main(){
	int rows = 0, cols = 0;
	std::cin >> rows >> cols;
	if(std::cin.fail()){
		std::cerr << "Fail input\n";
		return 1;
	}
	int ** mtx = nullptr;
	mtx = make(rows, cols);
	
}
