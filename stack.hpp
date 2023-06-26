#ifndef BLATT_BDD_STACK
#define BLATT_BDD_STACK

#include <gtest/gtest.h>

#include "board.hpp"

template <typename T> 
class Stack {
public:
  Stack() : size(0), capacity(1), stack(nullptr) {}

  ~Stack() { delete[] stack; }

  // push the element to the stack
  void push(const T &pos);

  // last element added
  T top() const;

  // deletes the last inserted element of the stack
  void pop();

  // checks if the stack is empty
  bool empty() const;

  // resize to match the capacity if required
  void reserve(int n);

  const T operator[](int n) const { return stack[n]; }

  int number_of_elements() const { return size; }

private:
  int size;
  int capacity;
  T *stack;

  FRIEND_TEST(StackTest, pushTest);
};


template <typename T>
void Stack<T>::reserve(int n) {
  if (n <= capacity)
    return;

  capacity = n;
  T *tempStack = new T[capacity];
  for (int i = 0; i < size; ++i)
    tempStack[i] = stack[i];
  delete[] stack;
  stack = tempStack;
}

template <typename T>
void Stack<T>::push(const T &item) {
  if (empty()) {
    capacity = 1;
    stack = new T[capacity];
  } else if (size == capacity) {
    reserve(capacity * 2);
  }

  stack[size] = item;
  size++;
}

template <typename T>
void Stack<T>::pop() {
  if (!empty()) {
    size--;
  }
}

template <typename T>
T Stack<T>::top() const {
  if (!empty()) {
    return stack[size - 1];
  } else {
    assert(false);
    return T();
  }
}

template <typename T>
bool Stack<T>::empty() const {
  return (size == 0);
}

#endif
