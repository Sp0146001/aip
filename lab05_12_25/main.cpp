#include <iostream>
namespace top {
  struct p_t { int x, y; };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct f_t { p_t aa, bb; };
  struct Idrow {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
    virtual ~Idrow() = default;
  };
  struct Dot: Idrow {
    p_t begin() const override;
    p_t next() const override;
  };
}
int main() {
  using namespace top;
  p_t a{1, 0}, b{0, 1};
  std::cout << (a==b) << '\n';
}
bool top::operator==(p_t a, p_t b) {
  return a.x == b.x && a.y == b.y;
}
bool top::operator!=(p_t a, p_t b) {
  return !(a==b);
}
