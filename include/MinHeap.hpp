#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap
{
public:
    MinHeap(int capacity);
    ~MinHeap();
    // return value of parent
    int Parent(int curr_idx);
    // return index of parent
    int GetParentIdx(int curr_idx);
    // return value of left child
    int LeftChild(int curr_idx);
    // return index of left child
    int GetLeftChildIdx(int curr_idx);
    // return value of right child
    int RightChild(int curr_idx);
    // return index of right child
    int GetRightChildIdx(int curr_idx);
    // heapify up (bubble value up from bottom of tree)
    void HeapifyUp();
    // heapify down (push value down to its correct place in heap)
    void HeapifyDown();
    // insert a value into the heap
    void Insert(int value);
    // extract minimum value from the heap
    int ExtractMin();
    // peak to see the min value in the heap
    int Peek();
    // remove a specific value from the heap
    // bool Remove(int value);
    // IsValidIdx to check if the index is inbounds in our heap
    bool IsValidIdx(int curr_idx);

    // swap the values at idx1 & idx2 of the heap
    void Swap(int idx1, int idx2);

    // check if heap is full
    bool Full();

    // return the size of the heap
    int Size();

private:
    std::vector<int> heap_vec_{};
    int capacity_{};
    int size_{};
};
