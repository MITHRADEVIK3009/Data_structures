---
title: "Longest Substring Without Repeating Characters"
leetcode: 3
tags: [string, sliding-window, hashmap]
difficulty: Medium
pattern: sliding-window
attempts: 3
total_time_min: 75
solved_date: 2024-01-16
---

# Longest Substring Without Repeating Characters

**LeetCode Link**: [Problem #3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

## Examples

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

## Constraints

- 0 <= s.length <= 5 * 10^4
- s consists of English letters, digits, symbols and spaces.

## Approach

### Pattern: Sliding Window

The key insight is to maintain a sliding window that contains only unique characters. We use a hash map to track the frequency of characters in the current window and adjust the window size accordingly.

### Algorithm Steps

1. Initialize two pointers: `left` and `right` to track the window boundaries
2. Use a hash map to store character frequencies in the current window
3. Expand the window by moving the `right` pointer
4. If a character repeats, shrink the window from the left until it's unique again
5. Keep track of the maximum window size encountered

### Time Complexity
**O(n)**

Each character is visited at most twice (once by right pointer, once by left pointer).

### Space Complexity
**O(min(m, n))**

Where m is the size of the character set. In the worst case, we store all unique characters.

## Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n <= 1) return n;
        
        unordered_map<char, int> charCount;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            charCount[s[right]]++;
            
            // Shrink window if we have duplicates
            while (charCount[s[right]] > 1) {
                charCount[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
```

## Alternative Approaches

### Approach 2: Optimized Sliding Window
Instead of moving left pointer one by one, we can jump directly to the next position:

```cpp
class SolutionOptimized {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charIndex.find(s[right]) != charIndex.end()) {
                left = max(left, charIndex[s[right]] + 1);
            }
            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
```

## Test Cases

| Input | Output | Explanation |
|-------|--------|-------------|
| `"abcabcbb"` | `3` | `"abc"` is the longest unique substring |
| `"bbbbb"` | `1` | `"b"` is the only unique character |
| `"pwwkew"` | `3` | `"wke"` is the longest unique substring |
| `""` | `0` | Empty string |
| `" "` | `1` | Single space character |

## Edge Cases

- Empty string
- Single character string
- All characters are the same
- String with all unique characters
- Very long strings

## Common Mistakes

1. **Confusing substring with subsequence**: Substring must be contiguous
2. **Not handling empty string**: Return 0 for empty string
3. **Incorrect window shrinking**: Make sure to shrink until window is valid
4. **Off-by-one errors**: Be careful with array indices and window boundaries

## Learning Notes

- Sliding window is perfect for substring problems
- Hash map helps track character frequencies efficiently
- Two pointers technique for window management
- This pattern is fundamental for many string problems

## Related Problems

- [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)

## Time Log

| Date | Sprint (min) | Phase | Progress | Notes |
|------|--------------|-------|----------|-------|
| 2024-01-16 | 30 | learn | partial | Understood sliding window concept |
| 2024-01-16 | 25 | implement | stuck | Had issues with window shrinking |
| 2024-01-16 | 20 | review | solved | Fixed implementation after review |

## Metrics

- **Attempts**: 3
- **Total Time**: 75 minutes
- **Pattern Mastery**: Yes
- **Company Frequency**: High
- **Difficulty Rating**: 3/5
