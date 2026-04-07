#include <iostream>
template< class Key, class T >
using Value = std::pair<T, Key>;
template< class Key, class T, class Hash, class Equal >
struct HashTable {

  size_t size, capacity;
  Value** slots;
};
template <class K, class T, class HS, class EQ >
size_t psl(const HashTable<K,T,HS,EQ> &table, Value** value) {
  HS hasher;
  size_t home = hasher(*value->first)%table.capacity;
  size_t ind = value - table.slots;
  if (ind >= home) {
    return ind - home;
  }
  return (capacity - (home - ind));
}
template< class K, class T, class Hash, class Equal >
typename HashTable< K, T, Hash, Equal>::Value** find(const HashTable< K, T, Hash, Equal>& table, const K& key) {

}

