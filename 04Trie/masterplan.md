🔵 PHASE 1 — TRIE & PREFIX SYSTEM (Core for most of your list)

Covers majority of problems.

1️⃣ What is a Trie (in human terms)

A Trie is just:

A tree where each node is a letter
Each path = a full word or prefix

Use it when:

✅ prefixes
✅ dictionary lookups
✅ auto-complete
✅ replacing words
✅ folder structures
✅ camelcase matching

🔹 Structure of a Trie Node

Each node must store:

• children (map / array of size 26)
• end-of-word flag
• extra info if needed (e.g., sum, count)

🔹 Why Trie is fast?

Searching word → O(length)

Inserting word → O(length)

Independent of dictionary size

✅ Core Problems (in learning order)
Day 1:

648 — Replace Words
677 — Map Sum Pairs

Day 2:

676 — Magic Dictionary
720 — Longest Word

Day 3:

820 — Short Encoding
1023 — Camelcase Matching

Day 4:

1233 — Remove Subfolders
3076 — Shortest Uncommon Substring

🟢 PHASE 2 — BITWISE TRIE (XOR LOGIC)
Core Insight:

XOR wants:

opposite bits maximize value

So build a:

Binary Trie (0/1 tree)
Problems:

421 → Maximum XOR
2932 → Strong Pair XOR I

Mental rule:

If bit = 1 → search 0
If bit = 0 → search 1

🟡 PHASE 3 — HEAPS & FREQUENCY LOGIC

Only one major problem.

Problem:

692 — Top K Frequent Words

Concepts:

HashMap → count
Heap / Sorting → rank
Custom comparator

🟣 PHASE 4 — STRINGS / DP / HASHING
Problem	Technique
792	Indexed subsequence
2261	Sliding window
2707	DP
3291	DP + Trie
3597	Greedy + Hash
✅ STUDY PIPELINE FOR EACH PROBLEM

Don’t jump to code.

Always think in this order:

STEP 1: Pattern detection

Ask:

"Is this prefix, bitwise, DP or sorting?"

STEP 2: Choose weapon

Trie / Binary Trie / Heap / DP / Window

STEP 3: Constraints analysis

Important:

input size

memory limit

time requirement

STEP 4: Write solution skeleton

Only then write code.

✅ TRIE QUICK TEMPLATE (C++)
struct TrieNode {
    TrieNode* child[26] = {};
    bool isEnd = false;
};

✅ BINARY TRIE QUICK TEMPLATE
struct Trie {
    Trie* bit[2] = {};
};
