#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>  // for floor

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap

  // constructs a heap with the values from the given vector
  // the type T MUST provide comparison operators <, >, ==
  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};

/*******************************/
// default constructor
/*******************************/

template <typename T>
Heap<T>::Heap() {}

/*******************************/
// constructs a heap with the values in the given vector
// the type T MUST provide comparison operators <, >, ==
/*******************************/

template <typename T>
Heap<T>::Heap(std::vector<T> beginning_values) {
  // copy the values into our heap vector
  for (int i = 0; i < beginning_values.size(); i++) {
    values.push_back(beginning_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int init_parent_pos = floor(values.size() / 2) - 1;
  for (int parent_pos = init_parent_pos; parent_pos >= 0;
       parent_pos--) {
    heapify(parent_pos);
  }
}

/*******************************/
// add values to the heap
/*******************************/

template <typename T>
void Heap<T>::insert(T value) {
  // TODO: TO BE IMPLEMENTED
  values.push_back(value);
  heapify(values.size()/2-1);
}

/*******************************/
/* delete values from the heap */
/*******************************/

template <typename T>
void Heap<T>::remove(T value) {
  // TODO: TO BE IMPLEMENTED
  auto loc = find(begin(values), end(values), value);
  if (loc != end(values)){
    *loc = values.back();
    values.pop_back();
    heapify((loc-begin(values))/2-1);
  }
}

/*******************************/
// find the smallest value in the heap
/*******************************/

template <typename T>
T Heap<T>::getMin() {
  // TODO: TO BE IMPLEMENTED
  return values.front();
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_pos) {
  // if we're outside the index range, return
  if (parent_pos < 0 || parent_pos >= values.size()) return;
  // find children indexes
  int left_child_index = parent_pos * 2 + 1;
  int right_child_index = parent_pos * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_pos;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }
  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }
  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_pos) {
    T temp = values.at(parent_pos);
    values.at(parent_pos) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;
  }
  // move up the 'tree' to grandparent
  heapify(floor(parent_pos / 2) - 1);
}

#endif