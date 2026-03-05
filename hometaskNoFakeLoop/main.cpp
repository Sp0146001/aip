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
T popBack(BiList<T>** head, BiList<T>** tail);

template<class T>
T popFront(BiList<T>** head, BiList<T>** tail);

template<class T>
void print(BiList<T>* head);

template<class T>
void insert(BiList<T>** head, BiList<T>** tail, const T value, BiList<T>* pos);

template<class T>
T erase(BiList<T>** head, BiList<T>** tail, BiList<T>* pos);

template<class T>
void clear(BiList<T>** head, BiList<T>** tail);

template<class T>
void convertation(BiList<T>** head, BiList<T>** tail, const T* a, size_t n);

int main()
{
  size_t n = 10;
  int *a = new int[n];
  for (size_t i = 0; i < n; ++i)
  {
    a[i] = i;
  }
  BiList<int> *head = nullptr;
  BiList<int> *tail = nullptr;
  try{
    convertation(&head, &tail, a, n);
  } catch(...) {
    delete[] a;
    clear(&head, &tail);
  }
  print(head);
  delete[] a;
  clear(&head, &tail);
}
template<class T>
BiList<T>* createNode(const T& value) {
  return new BiList<T>{value, nullptr, nullptr};
}

template<class T>
void append(BiList<T>** head, BiList<T>** tail, const T value) {
  BiList<T>* newNode = createNode(value);//T::T()
  if (*head == nullptr) {
    *head = *tail = newNode;
  } else {
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
  }
}

template<class T>
T popBack(BiList<T>** head, BiList<T>** tail) {
  if (*tail == nullptr) {
    return T{};// T::T()
  }
  BiList<T>* toDelete = *tail;
  *tail = (*tail)->prev;
  if (*tail == nullptr) {
    *head = nullptr;
  } else {
    (*tail)->next = nullptr;
  }
  T value = toDelete->val;//T::T(const T&)
  delete toDelete;
  return value;
}

template<class T>
T popFront(BiList<T>** head, BiList<T>** tail) {
  if (*head == nullptr) {
    return T{};//T::T()
  }
  BiList<T>* toDelete = *head;
  *head = (*head)->next;
  if (*head == nullptr) {
    *tail = nullptr;
  } else {
    (*head)->prev = nullptr;
  }
  T value = toDelete->val;//T::T(const T&)
  delete toDelete;
  return value;
}
template<class T>
void print(BiList<T>* head) {
  while (head != nullptr) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << '\n';
}
template<class T>
void insert(BiList<T>** head, BiList<T>** tail, const T value, BiList<T>* pos) {
  BiList<T>* newNode = createNode(value);//T::T()
  newNode->next = pos->next;
  newNode->prev = pos;
  pos->next = newNode;
  if (newNode->next != nullptr) {
    newNode->next->prev = newNode;
  } else {
    *tail = newNode;
  }
}
template<class T>
void clear(BiList<T>** head, BiList<T>** tail) {
  while (*head != nullptr) {
    popBack(head, tail);
  }
  *tail = nullptr;
}
template<class T>
T erase(BiList<T>** head, BiList<T>** tail, BiList<T>* pos) {
  if (*head == nullptr || pos == nullptr) {
    return T{};//T::T()
  }
  if (*head == *tail) {
    if (*head != pos) {
      return T{};
    }
    T value = (*head)->val;//T::T(const T&)
    delete *head;
    *head = *tail = nullptr;
    return value;
  }
  BiList<T>* cur = *head;
  while (cur != nullptr && cur != pos) {
    cur = cur->next;
  }
  if (cur == nullptr) {
    return T{};//T::T()
  }
  if (pos->prev != nullptr) {
    pos->prev->next = pos->next;
  } else {
    *head = pos->next;
  }
  if (pos->next != nullptr) {
    pos->next->prev = pos->prev;
  } else {
    *tail = pos->prev;
  }
  T value = pos->val;//T::T(const T&)
  delete pos;
  return value;
}
template<class T>
void convertation(BiList<T>** head, BiList<T>** tail, const T* a, size_t n) {
  *head = *tail = createNode(a[0]);
  for (size_t i = 1; i < n; ++i) {
    append(head, tail, a[i]);
  }
}