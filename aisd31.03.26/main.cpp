#include <iostream>
template< class Key, class T, class Hash, class Equal >
struct HashTable {
  using Value = std::pair<T, Key>;

  size_t size, capacity;
  Value** slots;
};

template< class K, class T, class Hash, class Equal >
typename HashTable< K, T, Hash, Equal>::Value** find(const HashTable< K, T, Hash, Equal>& table, const K& key) {

}

