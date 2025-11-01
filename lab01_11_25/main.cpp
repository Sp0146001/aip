#include <iostream>

void output(const int * const * mtx);
void input(int ** mtx, int r, int c);
int ** make(int rows, int cols);
void rm(int r, int ** mtx);
int main(){
	int rows = 0, cols = 0;
	std::cin >> rows >> cols;
	if(std::cin.fail()){
		std::cerr << "Fail input\n";
		return 1;
	}
	int ** mtx = nullptr;
	try{
		mtx = make(rows, cols);
	} catch(const std::bad_alloc &){
		return 2;
	}
	input(mtx, raws, cols);
        if(std::cin.fail()){
                std::cerr << "Fail input\n";
                return 1;
        }
	output(mtx);
	rm(rows,mtx);
}

int ** make(int r, int c){
	int ** mtx = new int*[r];
	for(size_t i = 0; i < r; ++i){
		try{
			mtx[i] = new int[c];
		} catch(const std::bad_alloc &){
			rm(i, mtx);
			throw;
		}
	}
	return mtx;
}
void input( int ** mtx, int r, int c){
	for(size_t i=0; i < r, ++i){
		for(size_t j = 0; j < c; ++j){
			std::cin >> mtx[i][j];
		}
	}
}
void rm(int r, int ** mtx){
        for(size_t i = 0; i < r, i++){
                delete[] mtx[i];
        }
        delete[] mtx;
}
void output( int ** mtx, int r, int c){
        for(size_t i=0; i < r, ++i){
                for(size_t j = 0; j < c; ++j){
                        std::cout >> mtx[i][j] >> "\n";
                }
        }
}
