# Problem Classification & Pattern Analysis

## Overview

This document classifies all problems from the Striver's A2Z DSA Sheet by algorithmic patterns, data structures, and difficulty levels.

## Pattern Distribution Analysis

### Core Patterns (High Frequency)

#### 1. Two Pointers Pattern
**Frequency**: High (15+ problems)
**Difficulty Distribution**: Easy: 8, Medium: 5, Hard: 2

**Problems**:
- **Arrays**: Largest element, Second largest, Remove duplicates, Rotate array, Move zeros
- **Strings**: Check if array is sorted and rotated
- **Advanced**: Sort 0 1 2 (Dutch Flag), 3 Sum, 4 Sum

**Key Characteristics**:
- Left-right pointer movement
- Fast-slow pointer detection
- Three-pointer variations
- Array manipulation without extra space

#### 2. Sliding Window Pattern
**Frequency**: High (12+ problems)
**Difficulty Distribution**: Easy: 5, Medium: 6, Hard: 1

**Problems**:
- **Arrays**: Max consecutive 1's, Longest subarray with given sum
- **Strings**: Longest substring without repeating characters
- **Advanced**: Binary subarrays with sum, Count nice subarrays

**Key Characteristics**:
- Fixed and variable window sizes
- Substring/subarray optimization
- Character frequency tracking
- Window expansion and contraction

#### 3. Hash Map Pattern
**Frequency**: Very High (20+ problems)
**Difficulty Distribution**: Easy: 10, Medium: 8, Hard: 2

**Problems**:
- **Arrays**: Two sum, Union of sorted arrays, Missing number, Find element present only once
- **Strings**: Group anagrams, First non-repeating character
- **Advanced**: Longest consecutive subsequence, Repeating and missing numbers

**Key Characteristics**:
- Frequency counting
- Complement searching
- Caching and memoization
- Grouping and categorization

#### 4. Binary Search Pattern
**Frequency**: High (15+ problems)
**Difficulty Distribution**: Easy: 5, Medium: 8, Hard: 2

**Problems**:
- **1D Arrays**: Find x in sorted array, Lower/upper bound, Search insert position
- **2D Arrays**: Search in sorted matrix, Peak element in matrix
- **Advanced**: Search in rotated sorted array, Find minimum in rotated array

**Key Characteristics**:
- Search space reduction
- Lower and upper bound finding
- Rotated array handling
- 2D matrix searching

#### 5. Dynamic Programming Pattern
**Frequency**: High (18+ problems)
**Difficulty Distribution**: Easy: 3, Medium: 10, Hard: 5

**Problems**:
- **1D DP**: Climbing stairs, Frog jump, House robber
- **2D DP**: Unique paths, Minimum path sum
- **Advanced**: Longest common subsequence, Edit distance, Stock problems

**Key Characteristics**:
- Overlapping subproblems
- Optimal substructure
- Memoization and tabulation
- State machine optimization

### Secondary Patterns (Medium Frequency)

#### 6. Stack Pattern
**Frequency**: Medium (10+ problems)
**Difficulty Distribution**: Easy: 4, Medium: 5, Hard: 1

**Problems**:
- **Basic**: Valid parentheses, Implement stack using array/queue
- **Advanced**: Next greater element, Largest rectangle in histogram
- **Monotonic**: Daily temperatures, Trapping rain water

**Key Characteristics**:
- Expression evaluation
- Parentheses matching
- Monotonic stack operations
- Next greater/smaller element

#### 7. Tree Traversal Pattern
**Frequency**: Medium (12+ problems)
**Difficulty Distribution**: Easy: 6, Medium: 4, Hard: 2

**Problems**:
- **Traversals**: Preorder, Inorder, Postorder, Level order
- **BST**: Search, Insert, Delete, Validation
- **Advanced**: Tree construction, Serialization

**Key Characteristics**:
- Recursive and iterative approaches
- DFS and BFS variations
- Tree construction and validation
- BST operations

#### 8. Graph Traversal Pattern
**Frequency**: Medium (10+ problems)
**Difficulty Distribution**: Easy: 3, Medium: 5, Hard: 2

**Problems**:
- **Traversals**: BFS, DFS, Topological sort
- **Shortest Path**: Dijkstra, BFS for unweighted
- **Advanced**: MST, Strongly connected components

**Key Characteristics**:
- Adjacency list/matrix representation
- Connected component detection
- Shortest path algorithms
- Cycle detection

#### 9. Greedy Pattern
**Frequency**: Medium (8+ problems)
**Difficulty Distribution**: Easy: 3, Medium: 4, Hard: 1

**Problems**:
- **Scheduling**: Activity selection, Meeting rooms
- **Optimization**: Fractional knapsack, Gas station
- **Advanced**: Minimum number of arrows, Jump game

**Key Characteristics**:
- Local optimal choices
- Sorting-based approaches
- Exchange argument proofs
- Resource allocation

#### 10. Bit Manipulation Pattern
**Frequency**: Low (5+ problems)
**Difficulty Distribution**: Easy: 2, Medium: 2, Hard: 1

**Problems**:
- **Basic**: Single number, Missing number
- **Advanced**: Power of two, Subsets generation
- **Complex**: Bit counting, XOR operations

**Key Characteristics**:
- Bit masking and manipulation
- Set operations
- XOR properties
- Subset generation

## Data Structure Analysis

### Primary Data Structures

#### Arrays (40+ problems)
- **Basic Operations**: Access, insert, delete, search
- **Patterns**: Two pointers, sliding window, prefix sums
- **Difficulty**: Easy: 20, Medium: 15, Hard: 5

#### Strings (15+ problems)
- **Basic Operations**: Concatenation, substring, find
- **Patterns**: Two pointers, sliding window, pattern matching
- **Difficulty**: Easy: 8, Medium: 5, Hard: 2

#### Hash Maps (25+ problems)
- **Basic Operations**: Insert, find, delete
- **Patterns**: Frequency counting, complement searching
- **Difficulty**: Easy: 12, Medium: 10, Hard: 3

#### Trees (20+ problems)
- **Basic Operations**: Insert, delete, search, traverse
- **Patterns**: DFS, BFS, recursive patterns
- **Difficulty**: Easy: 10, Medium: 8, Hard: 2

#### Graphs (15+ problems)
- **Basic Operations**: Add edge, traverse, find path
- **Patterns**: BFS, DFS, shortest path
- **Difficulty**: Easy: 5, Medium: 8, Hard: 2

#### Stacks (12+ problems)
- **Basic Operations**: Push, pop, top, empty
- **Patterns**: Expression evaluation, monotonic stack
- **Difficulty**: Easy: 6, Medium: 5, Hard: 1

#### Queues (8+ problems)
- **Basic Operations**: Enqueue, dequeue, front, empty
- **Patterns**: BFS, sliding window
- **Difficulty**: Easy: 4, Medium: 3, Hard: 1

#### Heaps (10+ problems)
- **Basic Operations**: Insert, extract, peek
- **Patterns**: Priority queue, top K elements
- **Difficulty**: Easy: 3, Medium: 5, Hard: 2

## Difficulty Analysis

### Easy Problems (80+ problems)
**Characteristics**:
- Direct pattern application
- Simple data structure operations
- Clear problem statements
- Straightforward implementations

**Common Patterns**:
- Basic array/string manipulation
- Simple hash map usage
- Basic tree traversals
- Simple stack/queue operations

### Medium Problems (60+ problems)
**Characteristics**:
- Multiple pattern combinations
- Complex data structure operations
- Edge case handling required
- Optimization considerations

**Common Patterns**:
- Two pointers with conditions
- Sliding window variations
- Binary search with modifications
- Dynamic programming basics

### Hard Problems (20+ problems)
**Characteristics**:
- Complex pattern combinations
- Advanced data structure usage
- Multiple edge cases
- Significant optimization required

**Common Patterns**:
- Advanced dynamic programming
- Complex graph algorithms
- Monotonic stack/queue
- Bit manipulation

## Company-Specific Patterns

### Google
**Preferred Patterns**:
- Graph algorithms (BFS, DFS, shortest paths)
- Dynamic programming (complex state machines)
- System design and optimization
- Advanced data structures

**Problem Examples**:
- Number of islands
- Course schedule
- Word ladder
- Clone graph

### Microsoft
**Preferred Patterns**:
- Array manipulation (two pointers, sliding window)
- Tree operations (BST, tree construction)
- String manipulation
- Basic dynamic programming

**Problem Examples**:
- Two sum
- Valid parentheses
- Binary tree traversal
- Longest common subsequence

### Amazon
**Preferred Patterns**:
- Hash map operations (frequency counting)
- Sliding window problems
- Greedy algorithms
- Basic graph algorithms

**Problem Examples**:
- Group anagrams
- Longest substring without repeating characters
- Activity selection
- Gas station

### Meta/Facebook
**Preferred Patterns**:
- Graph algorithms (social networks)
- Dynamic programming
- Array manipulation
- String algorithms

**Problem Examples**:
- Clone graph
- Word ladder
- Longest common subsequence
- Edit distance

## Learning Progression

### Phase 1: Foundation (Weeks 1-2)
**Focus**: Arrays, Strings, Basic Hash Maps
**Problems**: 20 Easy problems
**Patterns**: Two pointers, basic hash map usage

### Phase 2: Core Patterns (Weeks 3-6)
**Focus**: Two pointers, Sliding window, Binary search
**Problems**: 30 Medium problems
**Patterns**: Advanced two pointers, sliding window variations

### Phase 3: Advanced Patterns (Weeks 7-10)
**Focus**: Dynamic programming, Tree traversals, Graph algorithms
**Problems**: 25 Medium-Hard problems
**Patterns**: DP basics, tree operations, graph traversals

### Phase 4: Mastery (Weeks 11-12)
**Focus**: Complex DP, Advanced graphs, Optimization
**Problems**: 15 Hard problems
**Patterns**: Advanced DP, complex graph algorithms

## Pattern Mastery Checklist

### Two Pointers ✅
- [ ] Left-right pointer movement
- [ ] Fast-slow pointer detection
- [ ] Three-pointer variations
- [ ] Array manipulation without extra space
- [ ] Problems solved: 15+

### Sliding Window ✅
- [ ] Fixed window size problems
- [ ] Variable window size problems
- [ ] Character frequency tracking
- [ ] Substring/subarray optimization
- [ ] Problems solved: 12+

### Hash Map ✅
- [ ] Frequency counting
- [ ] Complement searching
- [ ] Caching and memoization
- [ ] Grouping and categorization
- [ ] Problems solved: 20+

### Binary Search ✅
- [ ] Search space reduction
- [ ] Lower and upper bound finding
- [ ] Rotated array handling
- [ ] 2D matrix searching
- [ ] Problems solved: 15+

### Dynamic Programming ✅
- [ ] Overlapping subproblems
- [ ] Optimal substructure
- [ ] Memoization and tabulation
- [ ] State machine optimization
- [ ] Problems solved: 18+

## Success Metrics

### Pattern Recognition
- **Target**: < 2 minutes to identify pattern
- **Current**: Track your progress
- **Goal**: 90% accuracy in pattern identification

### Implementation Speed
- **Target**: < 20 minutes for medium problems
- **Current**: Track your progress
- **Goal**: 80% of problems solved within time limit

### Accuracy
- **Target**: > 90% first-attempt success on easy problems
- **Current**: Track your progress
- **Goal**: Consistent high accuracy across all difficulty levels

### Consistency
- **Target**: Daily practice
- **Current**: Track your progress
- **Goal**: Maintain consistent learning schedule
