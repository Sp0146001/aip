#include <iostream>

struct p_t { int x, y; };
struct Idrow {
  virtual p_t begin() const = 0;
  virtual p_t next() const = 0;
  virtual ~Idrow();
};

int main() {
}
