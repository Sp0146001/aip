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
    Dot(int x, int y);
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next() const override;
    p_t d;
  };
}
int main() {
  using namespace top;
  p_t a{1, 0}, b{0, 1};
  std::cout << (a==b) << '\n';
}
top::Dot(int x, int y) {
  Idrow(),
  d{x,y};
}
top::p-t top::Dot::next(p_t prev) {
  if (prev != begin()) {
    throw std::logic_error("bad impl\n");
  }
  return d;
}
top::p_t top::Dot::begin() const {
  return d;
}
bool top::operator==(p_t a, p_t b) {
  return a.x == b.x && a.y == b.y;
}
bool top::operator!=(p_t a, p_t b) {
  return !(a==b);
}
