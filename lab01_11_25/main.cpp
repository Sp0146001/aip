#include <iostream>
void output(const int * const * mtx){
	
}
int ** make(int rows, int cols){
	
}
void rm(int r, int ** mtx){
	for(size_t i = 0; i < r, i++){
		delete[] mtx[i];
	}
	delete[] mtx;
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
	output(mtx);
	rm(rows,cols,mtx);
}
