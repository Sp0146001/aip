#include <iostream>
struct Ints {
  Ints()'
  ~Ints();
  Ints(const Ints & w);
  Ints & operator=(const Ints & w);
  Ints(Ints && w);
  Ints & operator=(Ints & w);
  size_t size() const;
  int pet(size_t id) const;
  void set(size_t id, int v);
  Ints append(int v) const;
  Ints append(const Ints & w) const;
};


int main(){}
