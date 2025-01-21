#include "gtest/gtest.h"
#include "MinHeap.hpp"  // Include the header file for your MinHeap class

// Test the constructor
TEST(MinHeapTest, ConstructorTest) {
    MinHeap heap(10);  // Create a MinHeap with capacity 10
    EXPECT_EQ(heap.Full(), false);  // Heap should not be full initially
    EXPECT_EQ(heap.IsValidIdx(0), false);  // No valid indices in an empty heap
}

// Test Insert and Peek
TEST(MinHeapTest, InsertAndPeekTest) {
    MinHeap heap(10);

    heap.Insert(5);
    EXPECT_EQ(heap.Peek(), 5);  // Peek should return the smallest element

    heap.Insert(3);
    EXPECT_EQ(heap.Peek(), 3);  // Peek should return the new smallest element

    heap.Insert(10);
    EXPECT_EQ(heap.Peek(), 3);  // Smallest element should remain unchanged
}

TEST(MinHeapTest, ExtractMinEmptyHeapTest) {
    MinHeap heap(5);

    EXPECT_THROW(heap.ExtractMin(), std::logic_error);  // Expect any exception to be thrown
}

// Test ExtractMin
TEST(MinHeapTest, ExtractMinTest) {
    MinHeap heap(10);

    heap.Insert(5);
    heap.Insert(3);
    heap.Insert(10);

    EXPECT_EQ(heap.ExtractMin(), 3);  // Extract the smallest element
    EXPECT_EQ(heap.Peek(), 5);  // New smallest element

    EXPECT_EQ(heap.ExtractMin(), 5);
    EXPECT_EQ(heap.ExtractMin(), 10);

    // EXPECT_ANY_THROW(heap.ExtractMin());  // Assuming ExtractMin returns -1 if heap is empty
}

// Test HeapifyUp and HeapifyDown (indirectly through Insert and ExtractMin)
TEST(MinHeapTest, HeapifyTest) {
    MinHeap heap(10);

    heap.Insert(10);
    heap.Insert(1);
    heap.Insert(5);
    heap.Insert(3);

    EXPECT_EQ(heap.ExtractMin(), 1);  // HeapifyUp ensures 1 is at the root
    EXPECT_EQ(heap.ExtractMin(), 3);  // HeapifyDown maintains the heap property
    EXPECT_EQ(heap.ExtractMin(), 5);
    EXPECT_EQ(heap.ExtractMin(), 10);
}

// Test IsValidIdx
TEST(MinHeapTest, IsValidIdxTest) {
    MinHeap heap(5);

    heap.Insert(10);
    heap.Insert(5);
    
    EXPECT_EQ(true, heap.IsValidIdx(0));
    EXPECT_EQ(true, heap.IsValidIdx(1));
    EXPECT_EQ(false, heap.IsValidIdx(2));  // Heap size is 2, so index 2 is invalid
}

// Test Swap
TEST(MinHeapTest, SwapTest) {
    MinHeap heap(10);

    heap.Insert(10);
    heap.Insert(5);
    heap.Insert(3);

    heap.Swap(0, 2);  // Swap root with the last element
    EXPECT_EQ(heap.Peek(), 5);  // After swap, 5 should be the root
}

// Test Full
/*
TEST(MinHeapTest, FullTest) {
    MinHeap heap(3);

    heap.Insert(1);
    heap.Insert(2);
    heap.Insert(3);

    EXPECT_TRUE(heap.Full());  // Heap should be full

    heap.ExtractMin();
    EXPECT_FALSE(heap.Full());  // ExtractMin should free up space
}
*/

// Test edge case: Insert into a full heap
TEST(MinHeapTest, InsertIntoFullHeapTest) {
    MinHeap heap(3);

    heap.Insert(1);
    heap.Insert(2);
    heap.Insert(3);

    EXPECT_NO_THROW(heap.Insert(4));  // Insert shouldn't throw an exception 
    // heap size should be 4 
    EXPECT_EQ(heap.Size(), 4);
    // heap capacity should have doubled
    EXPECT_EQ(heap.Capacity(), 6);
}

// Test edge case: ExtractMin from an empty heap
TEST(MinHeapTest, ExtractMinFromEmptyHeapTest) {
    MinHeap heap(5);

    EXPECT_ANY_THROW(heap.ExtractMin());  // Expect a thrown exception 
}

// Test edge case: Peek into an empty heap
TEST(MinHeapTest, PeekEmptyHeapTest) {
    MinHeap heap(5);

    EXPECT_ANY_THROW(heap.Peek());  // Expect a thrown exception 
}