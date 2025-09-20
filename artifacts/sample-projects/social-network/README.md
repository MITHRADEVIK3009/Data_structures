# Social Network Graph - Graph Algorithms & BFS/DFS Implementation

A demonstration of practical data structure usage in building a social network system using Graphs, BFS, DFS, and Union-Find.

## Overview

This project implements a social network system that can:
- Manage user connections and friendships
- Find shortest paths between users
- Detect communities and clusters
- Recommend friends based on mutual connections
- Analyze network metrics and statistics

## Data Structures Used

### 1. Graph (Adjacency List)
- **Purpose**: Represent user connections and friendships
- **Operations**: Add edge, Remove edge, Find neighbors
- **Time Complexity**: O(1) for add/remove, O(degree) for neighbors
- **Space Complexity**: O(V + E) where V is vertices, E is edges

### 2. Union-Find (Disjoint Set Union)
- **Purpose**: Detect connected components and communities
- **Operations**: Find, Union, Connected
- **Time Complexity**: O(α(n)) where α is inverse Ackermann function
- **Space Complexity**: O(n)

### 3. Queue (BFS Traversal)
- **Purpose**: Level-order traversal for shortest paths
- **Operations**: Enqueue, Dequeue, Front
- **Time Complexity**: O(1) for all operations
- **Space Complexity**: O(n)

### 4. Stack (DFS Traversal)
- **Purpose**: Depth-first traversal for path finding
- **Operations**: Push, Pop, Top
- **Time Complexity**: O(1) for all operations
- **Space Complexity**: O(n)

### 5. Hash Map (User Registry)
- **Purpose**: Map user IDs to user objects
- **Operations**: Insert, Find, Update, Delete
- **Time Complexity**: O(1) average case
- **Space Complexity**: O(n)

## Implementation

### User Structure
```cpp
struct User {
    int id;
    string name;
    int age;
    string location;
    vector<string> interests;
    int joinDate;
    
    User(int id, string name, int age, string location) 
        : id(id), name(name), age(age), location(location), joinDate(0) {}
};
```

### Social Network Graph
```cpp
class SocialNetwork {
    unordered_map<int, User> users;
    unordered_map<int, vector<int>> adjacencyList;
    UnionFind communities;
    
public:
    void addUser(const User& user);
    void addFriendship(int userId1, int userId2);
    void removeFriendship(int userId1, int userId2);
    vector<int> findShortestPath(int from, int to);
    vector<vector<int>> findCommunities();
    vector<int> recommendFriends(int userId);
    void printNetworkStats();
};
```

## Features

1. **User Management**: Add, remove, and update user profiles
2. **Friendship Management**: Add and remove friendships
3. **Path Finding**: Find shortest paths between users
4. **Community Detection**: Identify connected components
5. **Friend Recommendations**: Suggest friends based on mutual connections
6. **Network Analysis**: Calculate network metrics

## Usage Example

```cpp
SocialNetwork network;

// Add users
network.addUser(User(1, "Alice", 25, "New York"));
network.addUser(User(2, "Bob", 30, "California"));
network.addUser(User(3, "Charlie", 28, "Texas"));
network.addUser(User(4, "Diana", 26, "Florida"));

// Add friendships
network.addFriendship(1, 2); // Alice - Bob
network.addFriendship(2, 3); // Bob - Charlie
network.addFriendship(3, 4); // Charlie - Diana
network.addFriendship(1, 4); // Alice - Diana

// Find shortest path
vector<int> path = network.findShortestPath(1, 3);
// Returns: [1, 2, 3] (Alice -> Bob -> Charlie)

// Find communities
vector<vector<int>> communities = network.findCommunities();

// Recommend friends
vector<int> recommendations = network.recommendFriends(1);
```

## Graph Algorithms

### 1. Breadth-First Search (BFS)
- Find shortest paths between users
- Level-order traversal
- Time Complexity: O(V + E)
- Space Complexity: O(V)

### 2. Depth-First Search (DFS)
- Find all possible paths
- Detect cycles
- Time Complexity: O(V + E)
- Space Complexity: O(V)

### 3. Union-Find
- Detect connected components
- Find communities
- Time Complexity: O(α(n))
- Space Complexity: O(n)

### 4. Dijkstra's Algorithm
- Find shortest paths with weights
- Handle weighted friendships
- Time Complexity: O((V + E) log V)
- Space Complexity: O(V)

## Network Analysis

### 1. Degree Centrality
- Number of connections per user
- Identify influential users
- Calculate average degree

### 2. Clustering Coefficient
- Measure of local clustering
- How well-connected neighbors are
- Global clustering coefficient

### 3. Betweenness Centrality
- Measure of node importance
- How often node appears in shortest paths
- Identify bridge nodes

### 4. Community Detection
- Identify tightly connected groups
- Modularity optimization
- Hierarchical clustering

## Performance Analysis

### Graph Operations
- **Add User**: O(1) average case
- **Add Friendship**: O(1) average case
- **Find Path**: O(V + E) for BFS
- **Community Detection**: O(V + E) for Union-Find

### Memory Usage
- **User Storage**: O(V) for user data
- **Graph Storage**: O(V + E) for adjacency list
- **Algorithm Storage**: O(V) for BFS/DFS

## Learning Objectives

1. **Graph Representation**: Understand adjacency list vs matrix
2. **BFS/DFS**: Master graph traversal algorithms
3. **Union-Find**: Learn connected component detection
4. **Network Analysis**: Understand social network metrics
5. **System Design**: Learn to design social systems

## Extensions

1. **Weighted Graphs**: Handle friendship strength
2. **Directed Graphs**: Support asymmetric relationships
3. **Dynamic Graphs**: Handle real-time updates
4. **Recommendation Engine**: Advanced friend suggestions
5. **Privacy Controls**: User privacy and security

## Related LeetCode Problems

- [Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [Course Schedule](https://leetcode.com/problems/course-schedule/)
- [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- [Clone Graph](https://leetcode.com/problems/clone-graph/)
- [Word Ladder](https://leetcode.com/problems/word-ladder/)
- [Redundant Connection](https://leetcode.com/problems/redundant-connection/)
