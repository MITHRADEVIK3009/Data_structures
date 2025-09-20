#pragma once
#include <bits/stdc++.h>
using namespace std;

// Type definitions for convenience
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;

// Fast I/O optimization
static auto _io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Useful macros
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); i--)

// Common constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

// Debugging macros (remove in production)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(x) cerr << #x << " = "; for (auto i : x) cerr << i << " "; cerr << endl
#else
#define debug(x)
#define debugv(x)
#endif

// Common utility functions
template<typename T>
void print(const T& container) {
    for (const auto& item : container) {
        cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void print2D(const vector<vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
}

// Custom hash for unordered_map with pairs
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

// Custom comparator for priority queue (min heap)
struct min_heap {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

// Union-Find (Disjoint Set Union)
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
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// Segment Tree (for range queries)
class SegmentTree {
    vector<int> tree;
    int n;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) + 
               query(2*node+1, mid+1, end, l, r);
    }
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n-1);
    }
    
    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
    
    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};

// Fenwick Tree (Binary Indexed Tree)
class FenwickTree {
    vector<int> tree;
    int n;
    
public:
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}
    
    void update(int idx, int delta) {
        for (int i = idx; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }
    
    int query(int idx) {
        int sum = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
    
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

// Trie Node
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// Trie Class
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
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) return false;
            node = node->children[index];
        }
        return true;
    }
};

// Common algorithms
namespace algo {
    // Binary search
    int binarySearch(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
    
    // Lower bound
    int lowerBound(vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    // Upper bound
    int upperBound(vector<int>& arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    
    // GCD
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    // LCM
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    // Power with mod
    ll power(ll base, ll exp, ll mod = MOD) {
        ll result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    // Prime check
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    // Sieve of Eratosthenes
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
}
