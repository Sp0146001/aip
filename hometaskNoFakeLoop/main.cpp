#include <iostream>
template<typename T>
struct BiList {
    T val;
    BiList<T>* next;
    BiList<T>* prev;
};
template<class T>
BiList<T>* createNode(const T& value);
template<class T>
void append(BiList<T>** head, BiList<T>** tail, const T value);

template<class T>
void firstAdd(BiList<T>** head, BiList<T>** tail, const T value);

template<class T>
T popBack(BiList<T>** head, BiList<T>** tail);

template<class T>
T popFront(BiList<T>** head, BiList<T>** tail);

template<class T>
void print(BiList<T>* head, BiList<T>* tail);

template<class T>
void insert(BiList<T>** head, BiList<T>** tail, const T value, BiList<T>* pos);

template<class T>
T erase(BiList<T>** head, BiList<T>** tail, BiList<T>* pos);

template<class T>
void clear(BiList<T>** head, BiList<T>** tail);

template<class T>
void convertation(BiList<T>** head, BiList<T>** tail, const T* a, size_t n);

int main() {

}
template<class T>
BiList<T>* createNode(const T& value) {
  return new BiList<T>{value, nullptr, nullptr};
}

template<class T>
void append(BiList<T>** head, BiList<T>** tail, const T value) {
  BiList<T>* newNode = createNode(value);
  if (*head == nullptr) {
    *head = *tail = newNode;
  } else {
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
  }
}