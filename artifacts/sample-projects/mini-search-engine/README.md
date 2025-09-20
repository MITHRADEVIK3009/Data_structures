  # Mini Search Engine

A demonstration of practical data structure usage in building a simple search engine using Trie and Hash Map.

## Overview

This project implements a basic search engine that can:
- Index documents using inverted index
- Provide prefix suggestions using Trie
- Search for terms across multiple documents
- Rank results by relevance

## Data Structures Used

### 1. Trie (Prefix Tree)
- **Purpose**: Fast prefix matching for search suggestions
- **Operations**: Insert, Search, Prefix Search
- **Time Complexity**: O(m) where m is word length
- **Space Complexity**: O(ALPHABET_SIZE * N * M) where N is number of words

### 2. Hash Map (Inverted Index)
- **Purpose**: Map terms to documents containing them
- **Operations**: Insert, Search, Update
- **Time Complexity**: O(1) average case
- **Space Complexity**: O(T) where T is total terms

### 3. Priority Queue (Heap)
- **Purpose**: Rank search results by relevance
- **Operations**: Insert, Extract Max
- **Time Complexity**: O(log n) for insert/extract
- **Space Complexity**: O(n)

## Implementation

### Trie Structure
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    vector<string> suggestions;
    
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
```

### Inverted Index
```cpp
class InvertedIndex {
    unordered_map<string, unordered_set<int>> index;
    vector<string> documents;
    
public:
    void addDocument(const string& doc);
    vector<int> search(const string& term);
    vector<string> getSuggestions(const string& prefix);
};
```

## Features

1. **Document Indexing**: Add documents to the search engine
2. **Prefix Suggestions**: Get suggestions as user types
3. **Term Search**: Find documents containing specific terms
4. **Relevance Ranking**: Rank results by term frequency
5. **Multi-term Search**: Support for multiple search terms

## Usage Example

```cpp
MiniSearchEngine engine;

// Add documents
engine.addDocument("The quick brown fox jumps over the lazy dog");
engine.addDocument("A quick brown fox runs in the forest");
engine.addDocument("The lazy dog sleeps all day");

// Search for terms
auto results = engine.search("fox");
// Returns: [0, 1] (documents containing "fox")

// Get suggestions
auto suggestions = engine.getSuggestions("qu");
// Returns: ["quick"]

// Multi-term search
auto multiResults = engine.searchMultiple({"fox", "dog"});
// Returns: [0] (document containing both terms)
```

## Performance Analysis

### Indexing Performance
- **Time**: O(N * M) where N is number of documents, M is average document length
- **Space**: O(T) where T is total number of unique terms

### Search Performance
- **Single Term**: O(1) average case
- **Prefix Suggestions**: O(k) where k is number of suggestions
- **Multi-term**: O(n) where n is number of terms

## Learning Objectives

1. **Trie Applications**: Understand how tries are used in real-world applications
2. **Hash Map Efficiency**: See the power of hash maps for fast lookups
3. **Data Structure Combination**: Learn how to combine multiple DS effectively
4. **System Design**: Understand basic search engine architecture
5. **Performance Trade-offs**: Analyze time vs space complexity trade-offs

## Extensions

1. **Ranking Algorithm**: Implement TF-IDF or PageRank
2. **Fuzzy Search**: Add support for approximate matching
3. **Phrase Search**: Support for exact phrase matching
4. **Boolean Queries**: Support for AND, OR, NOT operations
5. **Caching**: Add caching layer for frequently searched terms

## Related LeetCode Problems

- [Implement Trie](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [Word Search II](https://leetcode.com/problems/word-search-ii/)
- [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system/)
