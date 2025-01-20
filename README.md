Design and implement a Min-Heap (Priority Queue) data structure from scratch. A Min-Heap is a binary tree where the value of each node is smaller than or equal to its children, and the tree is a complete binary tree (all levels are fully filled except possibly the last, which is filled from left to right).

You must implement the following methods:
	1.	insert(value: int) -> None:
	•	Insert a new value into the heap while maintaining the Min-Heap property.
	2.	extract_min() -> int:
	•	Remove and return the smallest value in the heap while maintaining the Min-Heap property.
	•	If the heap is empty, return -1.
	3.	remove(value: int) -> bool:
	•	Remove a specific value from the heap. Return True if the value was successfully removed; otherwise, return False.