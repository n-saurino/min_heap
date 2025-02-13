# Implement a Min-Heap

## Problem Description

Design and implement a Min-Heap (Priority Queue) data structure from scratch. The implementation must maintain the Min-Heap property where each node's value is smaller than or equal to its children's values, and the tree must be a complete binary tree.

## Core Properties

### Min-Heap Requirements
- Complete binary tree structure
- Parent nodes are smaller than or equal to children
- All levels filled except possibly the last
- Last level filled from left to right

### Core Operations

#### 1. Insert Operation
**Purpose:** Add a new value while maintaining the Min-Heap property

**Implementation Details:**
- Add element at the next available position
- Bubble up the element until Min-Heap property is satisfied
- Handle array resizing if needed
- Time Complexity: O(log n)

**Key Steps:**
1. Add element to end of array
2. Compare with parent
3. Swap if parent is larger
4. Repeat until correctly positioned

#### 2. Extract Minimum Operation
**Purpose:** Remove and return the smallest value

**Implementation Details:**
- Return root element (minimum value)
- Replace root with last element
- Bubble down new root to maintain heap property
- Time Complexity: O(log n)

**Key Steps:**
1. Store root value for return
2. Move last element to root
3. Bubble down comparing with children
4. Swap with smaller child
5. Return stored minimum value

#### 3. Remove Specific Value Operation
**Purpose:** Remove a specified value from anywhere in the heap

**Implementation Details:**
- Find the value in the heap
- Replace with last element
- Bubble up or down as needed
- Time Complexity: O(n) for search + O(log n) for reorganization

**Key Steps:**
1. Search for value
2. Replace found value with last element
3. Determine whether to bubble up or down
4. Reorganize heap accordingly
5. Return success/failure

## Internal Helper Functions

### 1. Bubble Up
- Move element upward until heap property is satisfied
- Compare with parent node
- Swap if parent is larger

### 2. Bubble Down
- Move element downward until heap property is satisfied
- Compare with both children
- Swap with smaller child

### 3. Get Parent/Child Indices
- Parent index: (i - 1) / 2
- Left child: 2i + 1
- Right child: 2i + 2

## Performance Requirements

### Time Complexity
- Insert: O(log n)
- Extract Min: O(log n)
- Remove: O(n)

### Space Complexity
- O(n) for n elements

## Example Usage Scenarios

### 1. Priority Queue
```
insert(5)
insert(3)
insert(7)
extract_min() → returns 3
extract_min() → returns 5
```

### 2. Element Removal
```
insert(4)
insert(8)
insert(6)
remove(8) → returns true
extract_min() → returns 4
```

## Testing Considerations

### Test Cases
1. Basic Operations
   - Insert single element
   - Extract from single element heap
   - Remove existing element
   - Remove non-existent element

2. Edge Cases
   - Empty heap operations
   - Duplicate values
   - Maximum capacity
   - Single element operations

3. Complex Scenarios
   - Multiple insertions and extractions
   - Mixed operations sequence
   - Stress testing with large datasets

## Common Pitfalls

1. Incorrect Index Calculations
   - Parent/child relationships
   - Array bounds

2. Heap Property Violations
   - After insertion
   - After extraction
   - After removal

3. Edge Case Handling
   - Empty heap
   - Single element
   - Full capacity


## Follow-up Questions

1. How would you implement a Max-Heap instead?
2. Can you modify the implementation for generic types?
3. How would you handle duplicate values efficiently?
4. What modifications are needed for thread safety?
5. How would you implement decrease-key operation?
