# Data Structures Cheat Sheet

## Core Data Structures Overview

This document provides a comprehensive reference for the most important data structures used in competitive programming and technical interviews.

## 1. Arrays

### Basic Operations
```cpp
vector<int> arr(n);           // Initialize with size n
vector<int> arr(n, val);      // Initialize with size n and value val
arr.push_back(val);           // Add element at end
arr.pop_back();               // Remove last element
arr.size();                   // Get size
arr.empty();                  // Check if empty
arr[i];                       // Access element at index i
```

### Time Complexity
- Access: O(1)
- Search: O(n)
- Insertion: O(1) at end, O(n) at beginning
- Deletion: O(1) at end, O(n) at beginning

### Common Patterns
- Two pointers
- Sliding window
- Prefix sums
- Sorting

## 2. Strings

### Basic Operations
```cpp
string s = "hello";
s.length();                    // Get length
s.size();                      // Get size
s[i];                          // Access character at index i
s.substr(start, len);          // Get substring
s.find(substr);                // Find substring
s.push_back(c);                // Add character at end
s.pop_back();                  // Remove last character
```

### Time Complexity
- Access: O(1)
- Search: O(n)
- Concatenation: O(n)
- Substring: O(n)

### Common Patterns
- Two pointers
- Sliding window
- Pattern matching
- String manipulation

## 3. Hash Maps (unordered_map)

### Basic Operations
```cpp
unordered_map<int, int> mp;
mp[key] = value;               // Insert/update
mp.find(key);                  // Find key
mp.count(key);                 // Count occurrences
mp.erase(key);                 // Remove key
mp.size();                     // Get size
mp.empty();                    // Check if empty
```

### Time Complexity
- Access: O(1) average, O(n) worst case
- Search: O(1) average, O(n) worst case
- Insertion: O(1) average, O(n) worst case
- Deletion: O(1) average, O(n) worst case

### Common Patterns
- Frequency counting
- Complement searching
- Caching
- Grouping

## 4. Sets (unordered_set)

### Basic Operations
```cpp
unordered_set<int> s;
s.insert(val);                 // Insert value
s.find(val);                   // Find value
s.count(val);                  // Count occurrences
s.erase(val);                  // Remove value
s.size();                      // Get size
s.empty();                     // Check if empty
```

### Time Complexity
- Access: O(1) average, O(n) worst case
- Search: O(1) average, O(n) worst case
- Insertion: O(1) average, O(n) worst case
- Deletion: O(1) average, O(n) worst case

### Common Patterns
- Duplicate detection
- Set operations
- Lookup optimization
- Unique element tracking

## 5. Stacks

### Basic Operations
```cpp
stack<int> st;
st.push(val);                  // Push element
st.pop();                      // Remove top element
st.top();                      // Get top element
st.size();                     // Get size
st.empty();                    // Check if empty
```

### Time Complexity
- Push: O(1)
- Pop: O(1)
- Top: O(1)
- Search: O(n)

### Common Patterns
- Expression evaluation
- Parentheses matching
- Monotonic stack
- Next greater/smaller element

## 6. Queues

### Basic Operations
```cpp
queue<int> q;
q.push(val);                   // Push element
q.pop();                       // Remove front element
q.front();                     // Get front element
q.back();                      // Get back element
q.size();                      // Get size
q.empty();                     // Check if empty
```

### Time Complexity
- Push: O(1)
- Pop: O(1)
- Front: O(1)
- Search: O(n)

### Common Patterns
- BFS traversal
- Level-order traversal
- Sliding window
- Process scheduling

## 7. Priority Queues (Heaps)

### Basic Operations
```cpp
priority_queue<int> pq;        // Max heap
priority_queue<int, vector<int>, greater<int>> pq; // Min heap
pq.push(val);                  // Insert element
pq.pop();                      // Remove top element
pq.top();                      // Get top element
pq.size();                     // Get size
pq.empty();                    // Check if empty
```

### Time Complexity
- Insert: O(log n)
- Extract: O(log n)
- Peek: O(1)
- Search: O(n)

### Common Patterns
- Top K elements
- Median finding
- Dijkstra's algorithm
- Merge K sorted lists

## 8. Linked Lists

### Basic Operations
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->val;                     // Access value
head->next;                    // Access next node
```

### Time Complexity
- Access: O(n)
- Search: O(n)
- Insertion: O(1) at known position
- Deletion: O(1) at known position

### Common Patterns
- Two pointers
- Cycle detection
- Reversal
- Merge operations

## 9. Trees

### Binary Tree Structure
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### Traversal Patterns
```cpp
// Preorder: Root -> Left -> Right
void preorder(TreeNode* root) {
    if (!root) return;
    // Process root
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    // Process root
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    // Process root
}

// Level Order (BFS)
void levelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // Process node
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

### Time Complexity
- Traversal: O(n)
- Search: O(log n) for BST, O(n) for general tree
- Insertion: O(log n) for BST, O(1) for general tree
- Deletion: O(log n) for BST, O(1) for general tree

## 10. Graphs

### Adjacency List Representation
```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v);          // Add edge u->v
adj[u].size();                // Get degree of vertex u
```

### Adjacency Matrix Representation
```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = 1;                // Add edge u->v
adj[u][v];                    // Check if edge exists
```

### Traversal Algorithms
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

### Time Complexity
- Traversal: O(V + E)
- Search: O(V + E)
- Shortest Path: O(V + E) for unweighted, O((V + E) log V) for weighted

## 11. Advanced Data Structures

### Union-Find (Disjoint Set)
```cpp
class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
    }
};
```

### Trie (Prefix Tree)
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }
};
```

## Complexity Comparison

| Data Structure | Access | Search | Insertion | Deletion | Space |
|----------------|--------|--------|-----------|----------|-------|
| Array | O(1) | O(n) | O(1) | O(1) | O(n) |
| Linked List | O(n) | O(n) | O(1) | O(1) | O(n) |
| Stack | O(n) | O(n) | O(1) | O(1) | O(n) |
| Queue | O(n) | O(n) | O(1) | O(1) | O(n) |
| Hash Map | O(1) | O(1) | O(1) | O(1) | O(n) |
| Tree | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |
| Heap | O(n) | O(n) | O(log n) | O(log n) | O(n) |

## Common Operations Cheat Sheet

### Sorting
```cpp
sort(arr.begin(), arr.end());                    // Ascending
sort(arr.begin(), arr.end(), greater<int>());    // Descending
sort(arr.begin(), arr.end(), [](int a, int b) {   // Custom comparator
    return a < b;
});
```

### Binary Search
```cpp
binary_search(arr.begin(), arr.end(), target);   // Check existence
lower_bound(arr.begin(), arr.end(), target);     // First position
upper_bound(arr.begin(), arr.end(), target);     // Last position
```

### Set Operations
```cpp
set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin());
set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
set_difference(a.begin(), a.end(), b.begin(), b.end(), result.begin());
```

### Numeric Operations
```cpp
accumulate(arr.begin(), arr.end(), 0);            // Sum
max_element(arr.begin(), arr.end());              // Max element
min_element(arr.begin(), arr.end());              // Min element
count(arr.begin(), arr.end(), value);             // Count occurrences
```

## Memory Management Tips

1. **Use references** when possible to avoid copying
2. **Reserve space** for vectors when you know the size
3. **Use emplace_back** instead of push_back for efficiency
4. **Clear containers** when done to free memory
5. **Use smart pointers** for dynamic memory management

## Performance Optimization

1. **Choose the right data structure** for your use case
2. **Use const references** for function parameters
3. **Avoid unnecessary copying** of large objects
4. **Use move semantics** when possible
5. **Profile your code** to identify bottlenecks
