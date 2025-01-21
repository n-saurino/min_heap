#include "MinHeap.hpp"

MinHeap::MinHeap(int capacity): capacity_{capacity}, size_{0}, 
                                heap_vec_(capacity_){

}

MinHeap::~MinHeap(){
    
}

// return value of parent
int MinHeap::Parent(int curr_idx){
    if((curr_idx - 1)/2 < 0){
        throw std::logic_error("No parent. Must be at root.");
    }
    return heap_vec_[(curr_idx-1)/2];
}

// return index of parent
int MinHeap::GetParentIdx(int curr_idx){
    return (curr_idx-1)/2;
}

// return value of left child
int MinHeap::LeftChild(int curr_idx){
    if(curr_idx*2+1 >= size_){
        throw std::logic_error("No left child.");    
    }
    return heap_vec_[curr_idx*2 + 1];    
}

// return index of left child
int MinHeap::GetLeftChildIdx(int curr_idx){
    return curr_idx*2+1;
}

// return value of right child
int MinHeap::RightChild(int curr_idx){
    if(curr_idx*2+2 >= size_){
        throw std::logic_error("No right child.");
    }
    return heap_vec_[curr_idx*2 + 2];
}

// return index of right child
int MinHeap::GetRightChildIdx(int curr_idx){
    return curr_idx*2 + 2;
}

// heapify up (bubble value up from bottom of tree)
void MinHeap::HeapifyUp(){
    int idx{size_-1};
    while(idx != 0 && IsValidIdx(GetParentIdx(idx))){
        if(heap_vec_[idx] < Parent(idx)){
            Swap(idx, GetParentIdx(idx));    
        }
        idx = GetParentIdx(idx);
    }
}

// heapify down (push value down to its correct place in heap)
void MinHeap::HeapifyDown(){
    int idx{0};
    while(IsValidIdx(GetLeftChildIdx(idx))){
        int smallest_child_idx{GetLeftChildIdx(idx)}; 
        if(IsValidIdx(GetRightChildIdx(idx))){
            if(LeftChild(idx) > RightChild(idx)){
               smallest_child_idx = GetRightChildIdx(idx); 
            }
        }
        
        if(heap_vec_[idx] > heap_vec_[smallest_child_idx]){
            Swap(idx, smallest_child_idx);
        }
        
        idx = smallest_child_idx;
    }
}

// insert a value into the heap
void MinHeap::Insert(int value){
    // check to make sure the size of the heap != capacity
    Full(); 
    // insert at size_
    heap_vec_[size_] = value; 
    // then HeapifyUp to make sure it ends up in the correct spot
    ++size_;
    HeapifyUp();
}

// extract minimum value from the heap
int MinHeap::ExtractMin(){
    if(!size_){
        throw std::logic_error("Heap is empty");
    }
    int min_val{heap_vec_[0]};
    --size_;
    if(size_){
        heap_vec_[0] = heap_vec_[size_];
        HeapifyDown();         
    }
       
    return min_val;
}

// peak to see the min value in the heap
int MinHeap::Peek(){
    if(!size_){
        throw std::logic_error("Heap is empty.");
    }
    return heap_vec_[0];
}

// remove a specific value from the heap
// bool Remove(int value);

// check if index is inbounds
bool MinHeap::IsValidIdx(int idx){
    if(idx > -1 && idx < size_) return true;
    return false;
}

// swap values at the indices
void MinHeap::Swap(int idx1, int idx2){
    int temp{heap_vec_[idx1]};
    heap_vec_[idx1] = heap_vec_[idx2];
    heap_vec_[idx2] = temp;
}

// check if heap is full
bool MinHeap::Full(){
    if(size_ < capacity_) return false;
    capacity_ *= 2;
    heap_vec_.resize(capacity_);
    return false;
}

int MinHeap::Size(){
    return size_;
}

int MinHeap::Capacity(){
    return capacity_;
}