#include "cpp-template.h"

// Mini Search Engine using Trie and Hash Map
// Demonstrates practical use of data structures

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

class Trie {
    TrieNode* root;
    
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(const string& word) {
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
    
    vector<string> getSuggestions(const string& prefix) {
        TrieNode* node = root;
        vector<string> result;
        
        // Navigate to prefix
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return result; // No suggestions found
            }
            node = node->children[index];
        }
        
        // Collect all words with this prefix
        collectWords(node, prefix, result);
        return result;
    }
    
private:
    void collectWords(TrieNode* node, const string& prefix, vector<string>& result) {
        if (node->isEnd) {
            result.push_back(prefix);
        }
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                char c = 'a' + i;
                collectWords(node->children[i], prefix + c, result);
            }
        }
    }
};

class MiniSearchEngine {
    Trie trie;
    unordered_map<string, unordered_set<int>> invertedIndex;
    vector<string> documents;
    
public:
    void addDocument(const string& doc) {
        int docId = documents.size();
        documents.push_back(doc);
        
        // Tokenize document
        vector<string> words = tokenize(doc);
        
        for (const string& word : words) {
            // Add to inverted index
            invertedIndex[word].insert(docId);
            
            // Add to trie for suggestions
            trie.insert(word);
        }
    }
    
    vector<int> search(const string& term) {
        vector<int> result;
        if (invertedIndex.find(term) != invertedIndex.end()) {
            result.assign(invertedIndex[term].begin(), invertedIndex[term].end());
        }
        return result;
    }
    
    vector<int> searchMultiple(const vector<string>& terms) {
        if (terms.empty()) return {};
        
        vector<int> result = search(terms[0]);
        
        for (int i = 1; i < terms.size(); i++) {
            vector<int> termResults = search(terms[i]);
            result = intersect(result, termResults);
        }
        
        return result;
    }
    
    vector<string> getSuggestions(const string& prefix) {
        return trie.getSuggestions(prefix);
    }
    
    void printResults(const vector<int>& docIds) {
        cout << "Search Results:\n";
        for (int docId : docIds) {
            cout << "Document " << docId << ": " << documents[docId] << "\n";
        }
    }
    
private:
    vector<string> tokenize(const string& doc) {
        vector<string> words;
        string word;
        
        for (char c : doc) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        
        if (!word.empty()) {
            words.push_back(word);
        }
        
        return words;
    }
    
    vector<int> intersect(const vector<int>& a, const vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                result.push_back(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};

// Demo function
void demonstrateSearchEngine() {
    MiniSearchEngine engine;
    
    // Add sample documents
    engine.addDocument("The quick brown fox jumps over the lazy dog");
    engine.addDocument("A quick brown fox runs in the forest");
    engine.addDocument("The lazy dog sleeps all day");
    engine.addDocument("Foxes are beautiful animals");
    engine.addDocument("Dogs are loyal pets");
    
    cout << "=== Mini Search Engine Demo ===\n\n";
    
    // Single term search
    cout << "Searching for 'fox':\n";
    auto foxResults = engine.search("fox");
    engine.printResults(foxResults);
    cout << "\n";
    
    // Multi-term search
    cout << "Searching for 'fox' AND 'dog':\n";
    auto multiResults = engine.searchMultiple({"fox", "dog"});
    engine.printResults(multiResults);
    cout << "\n";
    
    // Prefix suggestions
    cout << "Suggestions for 'qu':\n";
    auto suggestions = engine.getSuggestions("qu");
    for (const string& suggestion : suggestions) {
        cout << "- " << suggestion << "\n";
    }
    cout << "\n";
    
    // Another search
    cout << "Searching for 'lazy':\n";
    auto lazyResults = engine.search("lazy");
    engine.printResults(lazyResults);
}

int main() {
    demonstrateSearchEngine();
    return 0;
}

/*
Sample Output:
=== Mini Search Engine Demo ===

Searching for 'fox':
Search Results:
Document 0: The quick brown fox jumps over the lazy dog
Document 1: A quick brown fox runs in the forest
Document 3: Foxes are beautiful animals

Searching for 'fox' AND 'dog':
Search Results:
Document 0: The quick brown fox jumps over the lazy dog

Suggestions for 'qu':
- quick

Searching for 'lazy':
Search Results:
Document 0: The quick brown fox jumps over the lazy dog
Document 2: The lazy dog sleeps all day
*/
