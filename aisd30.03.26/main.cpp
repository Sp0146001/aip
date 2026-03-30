#include "top-it-vector.hpp"
#include <iostream>
#include <stdexcept>
#include <utility>

bool testDefaultVector()
{
  topit::Vector< int > v;
  return v.isEmpty();
}

bool testVectorWithValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return !v.isEmpty();
}

bool testElementAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  return v[0] == 1 && v[1] == 2;
}

bool testCopyConstructor()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > yav(v);
  bool isAllEqual = v.getSize() == yav.getSize();
  for (size_t i = 0; isAllEqual && i < v.getSize(); ++i)
  {
    isAllEqual = isAllEqual && (v[i] == yav[i]);
  }
  return isAllEqual;
}

bool testSwap()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > r;
  r.pushBack(2);
  v.swap(r);
  return r[0] == 1 && v[0] == 2;
}

bool testPushFront()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushFront(3);
  return v[0] == 3 && v[1] == 1 && v[2] == 2;
}

bool testDoublePushFront()
{
  topit::Vector< int > v;
  v.pushFront(1);
  v.pushFront(2);
  return v[0] == 2 && v[1] == 1;
}

bool testCapacityOfEmpty()
{
  topit::Vector< int > v;
  return v.getCapacity() == 0;
}

bool testCapacityWithValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return v.getCapacity() == 1;
}

bool testCapacityWithMoreValues()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  return v.getCapacity() == 4;
}

bool testSizeOFEmpty()
{
  topit::Vector< int > v;
  return v.getSize() == 0;
}

bool testSizeWithValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return v.getSize() == 1;
}

bool testPopWithEmptyVector()
{
  topit::Vector< int > v;
  try
  {
    v.popBack();
  }
  catch (const std::out_of_range&)
  {
    return true;
  }
  return false;
}

bool testPopWithOneValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.popBack();
  return v.isEmpty();
}

bool testPopWithMoreValues()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.popBack();
  return v.getSize() == 2 && v[0] == 1 && v[1] == 2;
}

bool testElementConstAccess()
{
  topit::Vector< int >& v;
  v.pushBack(1);
  v.pushBack(2);
  const topit::Vector<int>& rv = v;
  return rv[0] == 1 && rv[1] == 2;
}

bool testElementCheckedAccess()
{
  topit::Vector< int > v;
  try {
    v.at(0);
  } catch(const std::out_of_range&) {
    return true;
  } catch (...) {
    return false;
  }
}

bool testElementInboundCheckedAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  const topit::Vector<int>& rv = v;
  try {
    int& val = rv.at(0);
    return val == 1;
  } catch(const std::out_of_range&) {
    return true;
  } catch (...) {
    return false;
  }
}



int main()
{
  using test_t = bool (*)();
  using pair_t = std::pair< const char*, test_t >;
  pair_t tests[] = {
    {"Default vector is empty", testDefaultVector},
    {"Vector with value is not empty", testVectorWithValue},
    {"Element access by index works correctly", testElementAccess},
    {"Copy constructor creates equal vector", testCopyConstructor},
    {"Swap exchanges data between vectors", testSwap},
    {"PushFront adds element at beginning", testPushFront},
    {"Multiple PushFront operations work in correct order", testDoublePushFront},
    {"Empty vector has 0 capacity", testCapacityOfEmpty},
    {"Vector capacity equals 1 after first push", testCapacityWithValue},
    {"Capacity grows correctly when exceeding limit", testCapacityWithMoreValues},
    {"Empty vector has 0 size", testSizeOFEmpty},
    {"Vector size equals number of elements", testSizeWithValue},
    {"PopBack on empty vector throws exception", testPopWithEmptyVector},
    {"PopBack on single-element vector makes it empty", testPopWithOneValue},
    {"PopBack reduces size and preserves remaining elements", testPopWithMoreValues}
  };
  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout << std::boolalpha;
  bool pass = true;
  for (size_t i = 0; i < count; ++i)
  {
    bool res = tests[i].second();
    std::cout << res << ": ";
    std::cout << tests[i].first << '\n';
    pass = pass && res;
  }
  std::cout << "\nOverall result: " << pass << '\n';
  return 0;
}