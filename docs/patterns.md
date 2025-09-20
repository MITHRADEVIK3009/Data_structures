# Algorithmic Patterns Reference

## Core Patterns Overview

This document provides a comprehensive reference for the most important algorithmic patterns used in competitive programming and technical interviews.

## 1. Two Pointers Pattern

### When to Use
- Array/string problems requiring comparison or manipulation
- Problems with sorted arrays
- Palindrome checking
- Finding pairs/triplets with specific properties

### Template
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process elements at left and right
    if (condition) {
        left++;
    } else {
        right--;
    }
}
```

### Common Variations
- **Left-Right Pointers**: Move towards center
- **Fast-Slow Pointers**: Detect cycles, find middle
- **Three Pointers**: Dutch flag problem, 3-sum

### Example Problems
- Two Sum (sorted array)
- Valid Palindrome
- Container With Most Water
- Sort Colors (Dutch Flag)

## 2. Sliding Window Pattern

### When to Use
- Substring/subarray problems
- Problems with fixed or variable window size
- Finding optimal subarray/substring
- Character frequency problems

### Template
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Expand window
    window.add(nums[right]);
    
    // Shrink window if needed
    while (window.isValid()) {
        // Update result
        window.remove(nums[left]);
        left++;
    }
}
```

### Common Variations
- **Fixed Window**: Window size is constant
- **Variable Window**: Window size changes based on condition
- **Two Pointers**: Left and right pointers move independently

### Example Problems
- Longest Substring Without Repeating Characters
- Maximum Sum Subarray of Size K
- Minimum Window Substring
- Longest Repeating Character Replacement

## 3. Hash Map Pattern

### When to Use
- Frequency counting
- Complement searching
- Caching results
- Grouping elements

### Template
```cpp
unordered_map<int, int> freq;
for (int num : nums) {
    freq[num]++;
    // Process based on frequency
}
```

### Common Variations
- **Frequency Map**: Count occurrences
- **Complement Map**: Find pairs that sum to target
- **Index Map**: Store indices for quick lookup
- **Set**: Check existence without counting

### Example Problems
- Two Sum
- Group Anagrams
- Longest Consecutive Sequence
- First Non-Repeating Character

## 4. Binary Search Pattern

### When to Use
- Search in sorted arrays
- Find insertion position
- Search space reduction
- Optimization problems

### Template
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### Common Variations
- **Standard Search**: Find exact match
- **Lower Bound**: Find first occurrence
- **Upper Bound**: Find last occurrence
- **Search Space**: Find optimal value

### Example Problems
- Binary Search
- Search Insert Position
- Find First and Last Position
- Search in Rotated Sorted Array

## 5. Dynamic Programming Pattern

### When to Use
- Optimization problems
- Problems with overlapping subproblems
- Problems with optimal substructure
- Counting problems

### Template
```cpp
// Memoization
vector<int> dp(n, -1);
int solve(int i) {
    if (i == base_case) return base_value;
    if (dp[i] != -1) return dp[i];
    return dp[i] = solve(i-1) + solve(i-2);
}

// Tabulation
vector<int> dp(n);
dp[0] = base_value;
for (int i = 1; i < n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
}
```

### Common Variations
- **1D DP**: Single dimension state
- **2D DP**: Two dimension state
- **State Machine**: Multiple states
- **Interval DP**: Range-based problems

### Example Problems
- Climbing Stairs
- House Robber
- Longest Common Subsequence
- Edit Distance

## 6. Stack Pattern

### When to Use
- Expression evaluation
- Parentheses matching
- Monotonic stack problems
- Next greater/smaller element

### Template
```cpp
stack<int> st;
for (int num : nums) {
    while (!st.empty() && st.top() < num) {
        // Process stack top
        st.pop();
    }
    st.push(num);
}
```

### Common Variations
- **Monotonic Stack**: Maintain sorted order
- **Expression Stack**: Evaluate expressions
- **Parentheses Stack**: Match brackets
- **Min/Max Stack**: Track extremes

### Example Problems
- Valid Parentheses
- Next Greater Element
- Largest Rectangle in Histogram
- Daily Temperatures

## 7. Tree Traversal Pattern

### When to Use
- Tree problems
- Graph problems (trees are special graphs)
- Hierarchical data processing
- Path finding

### Template
```cpp
// DFS Recursive
void dfs(TreeNode* root) {
    if (!root) return;
    // Process root
    dfs(root->left);
    dfs(root->right);
}

// BFS Iterative
queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    // Process node
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
}
```

### Common Variations
- **Preorder**: Root → Left → Right
- **Inorder**: Left → Root → Right
- **Postorder**: Left → Right → Root
- **Level Order**: BFS traversal

### Example Problems
- Binary Tree Traversal
- Maximum Depth of Binary Tree
- Path Sum
- Binary Tree Level Order Traversal

## 8. Graph Traversal Pattern

### When to Use
- Graph problems
- Connected components
- Shortest path problems
- Cycle detection

### Template
```cpp
// BFS
vector<bool> visited(n, false);
queue<int> q;
q.push(start);
visited[start] = true;
while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}

// DFS
vector<bool> visited(n, false);
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```

### Common Variations
- **BFS**: Level-by-level traversal
- **DFS**: Depth-first exploration
- **Topological Sort**: DAG ordering
- **Shortest Path**: BFS for unweighted, Dijkstra for weighted

### Example Problems
- Number of Islands
- Course Schedule
- Word Ladder
- Clone Graph

## 9. Greedy Pattern

### When to Use
- Optimization problems
- Problems with local optimal choices
- Scheduling problems
- Resource allocation

### Template
```cpp
sort(items.begin(), items.end(), comparator);
for (auto item : items) {
    if (canTake(item)) {
        take(item);
        updateResult();
    }
}
```

### Common Variations
- **Sorting Greedy**: Sort by some criteria
- **Interval Greedy**: Process intervals
- **Exchange Argument**: Prove greedy choice
- **Matroid**: Greedy on matroids

### Example Problems
- Activity Selection
- Fractional Knapsack
- Minimum Number of Arrows
- Gas Station

## 10. Bit Manipulation Pattern

### When to Use
- Problems involving binary operations
- Set operations
- Optimization problems
- Cryptography problems

### Template
```cpp
// Common bit operations
int setBit(int num, int pos) { return num | (1 << pos); }
int clearBit(int num, int pos) { return num & ~(1 << pos); }
int toggleBit(int num, int pos) { return num ^ (1 << pos); }
bool isSet(int num, int pos) { return num & (1 << pos); }
```

### Common Variations
- **Bit Masking**: Use bits to represent sets
- **Bit Counting**: Count set bits
- **Bit Manipulation**: XOR, AND, OR operations
- **Subset Generation**: Generate all subsets

### Example Problems
- Single Number
- Missing Number
- Power of Two
- Subsets

## Pattern Recognition Tips

### Quick Identification
1. **Array/String**: Two Pointers, Sliding Window, Hash Map
2. **Search**: Binary Search
3. **Optimization**: Dynamic Programming, Greedy
4. **Tree/Graph**: DFS, BFS
5. **Expression**: Stack
6. **Frequency**: Hash Map
7. **Subarray/Substring**: Sliding Window
8. **Pairs/Triplets**: Two Pointers, Hash Map

### Common Mistakes
- **Wrong Pattern**: Don't force a pattern that doesn't fit
- **Overcomplicating**: Start with the simplest approach
- **Edge Cases**: Always consider empty arrays, single elements
- **Complexity**: Understand time/space trade-offs
- **Implementation**: Practice the template until it's automatic

## Pattern Mastery Checklist

- [ ] Can identify the pattern within 2 minutes
- [ ] Can implement the template without reference
- [ ] Can handle edge cases correctly
- [ ] Can explain the time/space complexity
- [ ] Can optimize the solution if needed
- [ ] Can solve 5+ problems using this pattern
- [ ] Can teach the pattern to someone else
