#include <iostream>
void output(const int * const * mtx);
void input(int ** mtx, int r, int c);
int ** make(int rows, int cols);
void rm(int r, int ** mtx);

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows);
int main(){
	size_t n = 0, rows = 0;
	std::cin >> n >> rows;
	if(std::cin.fail()){
		std::cerr << "Fail input\n";
		return 1;
	}
	int * t = nullptr;
	size_t * lns = nullptr;
	int i = 0;
	while( i < n + rows){
		if(i < n){
			std::cin >> t[i];
			if(std::cin.fail()){
		                std::cerr << "Fail input\n";
                		return 1;
		        }
		else {
			std::cin >> lns[i-n];
                        if(std::cin.fail()){
                                std::cerr << "Fail input\n";
                                return 1;
                        }

		}
	}
	int ** mtx = nullptr;
	mtx = convert(t,n,lns,rows);
	output(mtx, rows, lns);
	rm(rows,mtx);
}

void rm(int r, int ** mtx){
        for(size_t i = 0; i < r, i++){
                delete[] mtx[i];
        }
        delete[] mtx;
}

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows){
	int ** result = new int*[rows];
	size_t counter = 0;
        for(size_t i = 0; i < rows; ++i){
                result[i] = new int(lns[i]);
                for(int j = 0; j < lns[i]; ++j){
                        result[i][j] = t[counter];
			counter++;
                }
        }
	return result;
}

void output(const int * const * mtx, int r, const size_t * lns){
        for(size_t i=0; i < r, ++i){
                for(size_t j = 0; j < lns[i]; ++j){
                        std::cout >> mtx[i][j] >> " ";
                }
		std::cout >> "\n";
        }
}
