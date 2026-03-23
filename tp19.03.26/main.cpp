#include  "top-it-vector.hpp"
#include <iostream>

bool testDefaultVector() {
  topit::Vector< int >* v;
  return !v->isEmpty();
}
bool testVectorWithValue() {
  topit::Vector<int> v;
  v.pushBack(1);
  return !v.isEmpty();
}
bool testVectorConstructor() {
  topit::Vector<int> v;
  v.pushBack(1);
  topit::Vector<int> yav = v;
}
bool testElementAssert() {
  topit::Vector<int> v;
  v.pushBack(1);
  v.pushBack(2);
  return v[0] == 1 && v[1] == 2;
}
bool testCopyConstructor() {
  topit::Vector<int> v;
  v.pushBack(1);
  topit::Vector<int> yav = v;
  bool isAllEqual = v.getSize() == yav.getSize();
  for (size_t i = 0; isAllEqual && i < v.getSize(); ++i) {

  }
}
int main() {
  using test_t = bool(*)();
  using pair_t = std::pair<const char*, test_t >;
  pair_t tests[] = {
    {"test def vector ", testDefaultVector},
    {"sec test", testVectorWithValue},
    {"", testVectorConstructor},
    {"", testElementAssert},
    {"", testCopyConstructor}
  };
  const size_t count = sizeof(tests)/sizeof(pair_t);
  std::cout << std::boolalpha;
  for (size_t i = 0; i < count; ++i) {
    bool res = tests[i].second;
    std::cout << res << tests[i].first << '\n';
  }
}