#include <iostream>
namespace topit {
  struct p_t { int x, y; };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct f_t { p_t aa, bb; };
  size_t rows(f_t);
  size_t cols(f_t);

  struct IDraw {
    virtual ~IDraw() = default;
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
  };

  struct Dot: IDraw {
    Dot(int x, int y);
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
  };
  struct VLine: IDraw{
    VLine(p_t s, p_t e);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t start, end;
    };

  void extend(p_t** pts, size_t s, p_t p);
  size_t points(const IDraw& d, p_t** pts, size_t s);
  f_t frame(const p_t* pts, size_t s);
  char * canvas(f_t fr, char fill);
  void paint(char* cnv, f_t fr, p_t p, char fill);
  void flush(std::ostream& os, const char* cnv, f_t fr);
}
int main() {
  using topit::IDraw;
  using topit::Dot;
  using topit::f_t;
  using topit::p_t;
  int err = 0;
  IDraw* shps[3] = {};
  p_t * pts = nullptr;
  size_t s = 0;
  try {
    shps[0] = new Dot(100, 1);
    shps[1] = new Dot(-100, 30);
    shps[2] = new topit::VLine({2, 2}, {2, 20});
    shps[2] = new topit::VLine({0,0}, {0, 20});
    for (size_t i = 0; i < 3; ++i) {
      s += points(*(shps[i]), &pts, s);
    }
    f_t fr = frame(pts, s);
    char * cnv = canvas(fr, '.');
    for (size_t i = 0; i < s; ++i) {
      paint(cnv, fr, pts[i], '#');
    }
    flush(std::cout, cnv, fr);
    delete [] cnv;
  } catch (...) {
    err = 2;
    std::cerr << "Bad drawing\n";
  }
  delete [] pts;
  delete shps[0];
  delete shps[1];
  delete shps[2];
  return err;
}
topit::Dot::Dot(p_t dd):
 IDraw(),
 d{dd}
{}
topit::Dot::Dot(int x, int y):
 IDraw(),
 d{x, y}
{}
topit::p_t topit::Dot::begin() const {
  return d;
}
topit::p_t topit::Dot::next(p_t prev) const {
  if (prev != begin()) {
    throw std::logic_error("bad impl");
  }
  return d;
}
bool topit::operator==(p_t a, p_t b) {
  return a.x == b.x && a.y == b.y;
}
bool topit::operator!=(p_t a, p_t b) {
  return !(a == b);
}
void topit::extend(p_t** pts, size_t s, p_t p) {
  p_t* e = new p_t[s+1];
  for (size_t i = 0; i < s; ++i){
  e[i] = (*pts)[i];
  }
  e[s] = p;
  delete[] *pts;
  *pts = e;
}
size_t topit::points(const IDraw& d, p_t** pts, size_t s) {
  size_t r = 1;
  p_t p = d.begin();
  extend(pts, s + 0, p);
  
  while (true) {
    p_t next_p = d.next(p);
    if (next_p == d.begin()) break;
    extend(pts, s + r, next_p);
    ++r;
    p = next_p;
  }
  return r;
}
size_t topit::rows(f_t fr) {
  return fr.bb.y - fr.aa.y + 1;
}
size_t topit::cols(f_t fr) {
  return fr.bb.x - fr.aa.x + 1;
}
topit::f_t topit::frame(const p_t* pts, size_t s) {
  if (!s) {
   throw std::logic_error("no pts");
  }
  int minx = pts[0].x, maxx = minx;
  int miny = pts[0].y, maxy = miny;
  for (size_t i = 0; i < s; ++i) {
  minx = std::min(minx, pts[i].x);
  maxx = std::max(maxx, pts[i].x);
  miny = std::min(miny, pts[i].y);
  maxy = std::max(maxy, pts[i].y);
  }
  p_t aa = {minx, miny};
  p_t bb = {maxx, maxy};
  return {aa, bb};
}

char * topit::canvas(f_t fr, char fill) {
  char* cnv = new char[rows(fr) * cols(fr)];
  for (size_t i = 0; i < rows(fr) * cols(fr); ++i) {
    cnv[i] = fill;
  }
  return cnv;

}
void topit::paint(char* cnv, f_t fr, p_t p, char fill) {
  size_t dy = fr.bb.y - p.y;
  size_t dx = p.x - fr.aa.x;
  cnv[dy * cols(fr) + dx] = fill;
}

void topit::flush(std::ostream& os, const char* cnv, f_t fr) {
  for (size_t i = 0; i < rows(fr); ++i) {
    for (size_t j = 0; j < cols(fr); ++j) {
      os << cnv[i * cols(fr) + j];
    }
    os << '\n';
  }
}
topit::VLine::VLine(p_t s, p_t e):
    IDraw(),
    start(s),
    end(e)
{}

topit::p_t topit::VLine::begin() const{
    return start;
}

topit::p_t topit::VLine::next(p_t prev) const{
    if(prev == end){
        return start;
    }
    if(prev.x == start.x && start.y <= prev.y && prev.y < end.y){
        return {prev.x, prev.y + 1};
    }
    throw std::logic_error("bad impl");
}


