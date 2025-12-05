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
    p_t next(p_t) const override;
    p_t d;
  };
//ЭТО ЕЩЕ НЕ ДОДЕЛАНООООО
  struct Vertical: Idrow {
    p_t start, end;
    Vertical(p_t down, p_t up) :
      start(down), end(up)
    {}
    p_t begin() const override {
      return start;
    }
    p_t next(p_t prev) const override {
      if (prev.x < end.x) {
        return p_t{prev.x, prev.y+1};
      }
      throw std::logic_error("end vertical\n");
    }
  }
  struct Horizontal: Idrow {
    p_t start, end;
    Horizontal(p_t down, p_t up) :
      start(down), end(up)
    {}
    p_t begin() const override {
      return start;
    }
    p_t next(p_t prev) const override {
      if (prev.x < end.x) {
        return p_t{prev.x+1, prev.y};
      }
      throw std::logic_error("end horizontal\n");
    }
  }

  size_t points(const Idrow& d, p_t** pts, size_t& s);
  //
  f_t frame(const p_t* pts, size_t s);
  //построить полотно
  char* canvas(f_t fr, char fill);
  void paint(char* cnv, f_t fr, p_t p, char fill);
  flush(std::ostream& os, const char* cnv, f_t fr);
}
int main() {
  using top::Idrow;
  using top::Dot;
  using top::f_t;
  using top::p_t;
  Idrow* shps[3] = {};
  int err = 0;
  size_t s = 0;
  p_t * pts = nullptr;
  try {
    shps[0] = new Dot{0, 0};
    shps[1] = new Dot{0, 1};
    shps[2] = new Dot{1, 0};
    for (size_t i = 0; i < s; ++i) {
      s+=points(*shps[i], &pts, s);
    }
    f_t fr = frame(pts, s);
    char* cnv = canvas(fr, '.');
    delete[] cnv;
    for (size_t i = 0; i < s; ++i) {
      paint(cnv, fr, pts[i], '#');
    }
    flush(std:cout, cnv, fr);
  } catch (...) {
    err = 2;
    std::cerr << "bad drawing\n";
    delete[] pts;
    delete shps[0];
    delete shps[1];
    delete shps[2];
  }
  p_t a{1, 0}, b{0, 1};
  std::cout << (a==b) << '\n';
}
top::Dot::Dot(p_t d):
  Idrow(),
  d{dd}
{}
top::Dot::Dot(int x, int y):
  Idrow(),
  d{x,y};
{}
top::p_t top::Dot::next(p_t prev) {
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
