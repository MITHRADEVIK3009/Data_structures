# DSA Glossary & Terminologies

## A

### Algorithm
A step-by-step procedure for solving a problem or completing a task. In computer science, algorithms are used to process data, perform calculations, and solve computational problems.

### Array
A data structure that stores elements of the same type in contiguous memory locations. Elements are accessed using indices.

### Asymptotic Analysis
The mathematical analysis of algorithms that describes the limiting behavior of a function when the argument tends towards a particular value or infinity. Used to analyze time and space complexity.

### Adjacency List
A graph representation where each vertex has a list of its adjacent vertices. Space complexity: O(V + E).

### Adjacency Matrix
A 2D array representation of a graph where matrix[i][j] indicates if there's an edge between vertices i and j. Space complexity: O(V²).

## B

### Big O Notation
A mathematical notation that describes the limiting behavior of a function when the argument tends towards infinity. Used to express the worst-case time complexity of algorithms.

### Binary Search
A search algorithm that finds the position of a target value within a sorted array by repeatedly dividing the search interval in half.

### Binary Tree
A tree data structure where each node has at most two children, referred to as the left child and right child.

### Breadth-First Search (BFS)
A graph traversal algorithm that explores all vertices at the present depth level before moving on to vertices at the next depth level.

### Backtracking
A general algorithm for finding all solutions to computational problems by incrementally building candidates and abandoning partial candidates that cannot lead to a valid solution.

## C

### Complexity
The measure of the amount of time (time complexity) or space (space complexity) required by an algorithm to solve a problem.

### Connected Component
A subset of vertices in a graph where every pair of vertices is connected by a path, and no vertex is connected to any vertex outside the subset.

### Cycle
In a graph, a path that starts and ends at the same vertex without repeating any edges.

### Cache
A hardware or software component that stores data so that future requests for that data can be served faster.

### Collision
In hash tables, when two different keys hash to the same index. Handled by collision resolution techniques like chaining or open addressing.

## D

### Data Structure
A way of organizing and storing data in a computer so that it can be accessed and modified efficiently.

### Depth-First Search (DFS)
A graph traversal algorithm that explores as far as possible along each branch before backtracking.

### Dynamic Programming (DP)
A method for solving complex problems by breaking them down into simpler subproblems and storing the results of these subproblems to avoid redundant calculations.

### Divide and Conquer
An algorithm design paradigm that works by recursively breaking down a problem into two or more subproblems of the same or related type.

### Dijkstra's Algorithm
An algorithm for finding the shortest paths between nodes in a graph with non-negative edge weights.

## E

### Edge
A connection between two vertices in a graph.

### Exponential Time
Time complexity where the running time grows exponentially with the input size. Examples: O(2ⁿ), O(3ⁿ).

### Extensible Hash Table
A hash table that can grow and shrink dynamically as the number of elements changes.

## F

### Fibonacci Sequence
A sequence where each number is the sum of the two preceding ones: 0, 1, 1, 2, 3, 5, 8, 13, ...

### First In, First Out (FIFO)
A method for organizing and manipulating data where the first element added is the first one to be removed. Implemented by queues.

### Flood Fill
An algorithm that determines the area connected to a given node in a multi-dimensional array.

## G

### Graph
A data structure consisting of vertices (nodes) and edges that connect pairs of vertices.

### Greedy Algorithm
An algorithmic paradigm that makes the locally optimal choice at each stage with the hope of finding a global optimum.

### Graph Traversal
The process of visiting all vertices in a graph in a systematic way.

## H

### Hash Function
A function that maps data of arbitrary size to fixed-size values. Used in hash tables for fast data retrieval.

### Hash Table
A data structure that implements an associative array abstract data type, using a hash function to compute an index into an array of buckets.

### Heap
A specialized tree-based data structure that satisfies the heap property. Can be a max-heap or min-heap.

### Hash Collision
When two different keys produce the same hash value. Resolved using techniques like chaining or open addressing.

## I

### In-Place Algorithm
An algorithm that transforms input using no auxiliary data structure. However, a small amount of extra storage space is allowed for variables.

### Index
A numerical position in an array or list, typically starting from 0.

### Iteration
The repetition of a process in order to generate a sequence of outcomes. In programming, often implemented using loops.

### Inorder Traversal
A tree traversal method that visits nodes in the order: left subtree, root, right subtree.

## J

### Java Collections Framework
A unified architecture for representing and manipulating collections in Java.

## K

### K-ary Tree
A tree data structure where each node has at most k children.

### Knapsack Problem
A combinatorial optimization problem where items with given weights and values must be packed into a knapsack with a maximum weight capacity.

## L

### Last In, First Out (LIFO)
A method for organizing and manipulating data where the last element added is the first one to be removed. Implemented by stacks.

### Linked List
A linear data structure where elements are stored in nodes, and each node points to the next node in the sequence.

### Logarithmic Time
Time complexity where the running time grows logarithmically with the input size. Example: O(log n).

### Longest Common Subsequence (LCS)
A classic dynamic programming problem that finds the longest subsequence common to two sequences.

## M

### Memoization
An optimization technique used primarily to speed up computer programs by storing the results of expensive function calls and returning the cached result when the same inputs occur again.

### Merge Sort
A divide-and-conquer sorting algorithm that divides the array into two halves, sorts them separately, and then merges them.

### Minimum Spanning Tree (MST)
A subset of the edges of a connected, edge-weighted graph that connects all the vertices together with the minimum possible total edge weight.

### Monotonic Stack
A stack that maintains elements in either increasing or decreasing order.

## N

### Node
A basic unit of a data structure, such as a linked list or tree, that contains data and links to other nodes.

### NP-Complete
A class of decision problems that are both in NP and NP-hard. These are the hardest problems in NP.

### Null Pointer
A pointer that does not point to any valid memory location. Often used to indicate the end of a data structure.

## O

### Object-Oriented Programming (OOP)
A programming paradigm based on the concept of objects, which contain data and code to manipulate that data.

### Open Addressing
A method for handling hash collisions by finding another slot in the hash table when a collision occurs.

### Order of Growth
The rate at which the running time of an algorithm increases as the input size increases.

## P

### Palindrome
A sequence that reads the same backward as forward. Examples: "racecar", "madam".

### Path
A sequence of vertices in a graph where each adjacent pair of vertices is connected by an edge.

### Postorder Traversal
A tree traversal method that visits nodes in the order: left subtree, right subtree, root.

### Preorder Traversal
A tree traversal method that visits nodes in the order: root, left subtree, right subtree.

### Priority Queue
A data structure where each element has a priority, and elements are served based on priority rather than order of arrival.

## Q

### Queue
A linear data structure that follows the FIFO (First In, First Out) principle.

### Quick Sort
A divide-and-conquer sorting algorithm that picks a pivot element and partitions the array around the pivot.

## R

### Recursion
A programming technique where a function calls itself to solve smaller instances of the same problem.

### Red-Black Tree
A self-balancing binary search tree where each node has a color (red or black) and follows specific rules to maintain balance.

### Root
The topmost node in a tree data structure.

### Runtime
The time during which a program is executing, as opposed to compile time.

## S

### Stack
A linear data structure that follows the LIFO (Last In, First Out) principle.

### Sorting Algorithm
An algorithm that arranges elements in a particular order, typically numerical or lexicographical.

### Space Complexity
The amount of memory space required by an algorithm to solve a problem as a function of the input size.

### String
A sequence of characters. In many programming languages, strings are implemented as arrays of characters.

### Subarray
A contiguous part of an array.

### Subsequence
A sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

## T

### Time Complexity
The amount of time required by an algorithm to solve a problem as a function of the input size.

### Tree
A hierarchical data structure consisting of nodes connected by edges, with one root node and no cycles.

### Topological Sort
A linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering.

### Trie
A tree-like data structure used to store a dynamic set of strings, where the keys are usually strings.

## U

### Union-Find
A data structure that tracks a set of elements partitioned into disjoint subsets. Also known as Disjoint Set Union (DSU).

### Undirected Graph
A graph where edges have no direction, meaning the edge (u, v) is the same as the edge (v, u).

## V

### Vertex
A fundamental unit of a graph. Also called a node.

### Vector
A dynamic array that can resize itself automatically when elements are added or removed.

## W

### Weighted Graph
A graph where edges have associated weights or costs.

### Worst-Case Analysis
The analysis of an algorithm's performance under the worst possible input conditions.

## X

### XOR
A logical operation that outputs true only when inputs differ. Used in bit manipulation and hashing.

## Y

### Yield
In Python, a keyword that is used to return a generator instead of a normal value.

## Z

### Zero-Based Indexing
A method of numbering where the first element is at index 0, the second at index 1, and so on.

## Common Abbreviations

### Complexity Classes
- **O(1)**: Constant time
- **O(log n)**: Logarithmic time
- **O(n)**: Linear time
- **O(n log n)**: Linearithmic time
- **O(n²)**: Quadratic time
- **O(2ⁿ)**: Exponential time
- **O(n!)**: Factorial time

### Data Structures
- **BST**: Binary Search Tree
- **AVL**: Adelson-Velsky and Landis tree
- **B-Tree**: Balanced tree
- **DSU**: Disjoint Set Union
- **Fenwick Tree**: Binary Indexed Tree
- **Segment Tree**: Range query tree

### Algorithms
- **BFS**: Breadth-First Search
- **DFS**: Depth-First Search
- **DP**: Dynamic Programming
- **Dijkstra**: Shortest path algorithm
- **Kruskal**: Minimum spanning tree algorithm
- **Prim**: Minimum spanning tree algorithm
- **Floyd-Warshall**: All-pairs shortest path algorithm

### Programming Concepts
- **API**: Application Programming Interface
- **CRUD**: Create, Read, Update, Delete
- **FIFO**: First In, First Out
- **LIFO**: Last In, First Out
- **LRU**: Least Recently Used
- **LFU**: Least Frequently Used

## Pattern-Specific Terms

### Two Pointers
- **Left Pointer**: Pointer starting from the beginning
- **Right Pointer**: Pointer starting from the end
- **Fast Pointer**: Pointer that moves faster (usually 2x speed)
- **Slow Pointer**: Pointer that moves slower (usually 1x speed)

### Sliding Window
- **Window Size**: Number of elements in the current window
- **Window Expansion**: Increasing the window size
- **Window Contraction**: Decreasing the window size
- **Fixed Window**: Window with constant size
- **Variable Window**: Window with changing size

### Binary Search
- **Search Space**: The range of possible answers
- **Midpoint**: The middle element in the current search space
- **Lower Bound**: First position where element can be inserted
- **Upper Bound**: Last position where element can be inserted
- **Search Space Reduction**: Halving the search space each iteration

### Dynamic Programming
- **State**: The current situation in the problem
- **Transition**: Moving from one state to another
- **Base Case**: The simplest case that can be solved directly
- **Memoization**: Storing results of subproblems
- **Tabulation**: Building solutions bottom-up

### Graph Algorithms
- **Adjacency**: Two vertices connected by an edge
- **Path**: Sequence of vertices connected by edges
- **Cycle**: Path that starts and ends at the same vertex
- **Connected Component**: Set of vertices reachable from each other
- **Shortest Path**: Path with minimum total weight

## Mathematical Notations

### Set Theory
- **∈**: Element of
- **∉**: Not an element of
- **⊆**: Subset of
- **∪**: Union
- **∩**: Intersection
- **∅**: Empty set

### Logic
- **∧**: Logical AND
- **∨**: Logical OR
- **¬**: Logical NOT
- **→**: Implies
- **↔**: If and only if

### Functions
- **f(n)**: Function of n
- **O(f(n))**: Big O notation
- **Ω(f(n))**: Big Omega notation
- **Θ(f(n))**: Big Theta notation
- **⌊x⌋**: Floor function
- **⌈x⌉**: Ceiling function

## Problem-Solving Terms

### Problem Types
- **Optimization**: Finding the best solution
- **Decision**: Yes/No problems
- **Search**: Finding a specific element
- **Sorting**: Arranging elements in order
- **Counting**: Counting occurrences or combinations

### Solution Approaches
- **Brute Force**: Trying all possible solutions
- **Greedy**: Making locally optimal choices
- **Divide and Conquer**: Breaking problem into subproblems
- **Dynamic Programming**: Solving subproblems once
- **Backtracking**: Exploring all possible solutions

### Analysis
- **Time Complexity**: How runtime scales with input
- **Space Complexity**: How memory usage scales with input
- **Best Case**: Minimum time/space required
- **Average Case**: Expected time/space required
- **Worst Case**: Maximum time/space required

This glossary provides a comprehensive reference for all the terms and concepts you'll encounter in your DSA learning journey. Keep it handy as a quick reference while studying and solving problems!
