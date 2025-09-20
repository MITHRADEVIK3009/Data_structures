#include "cpp-template.h"

// Problem: Longest Substring Without Repeating Characters - LeetCode #3
/*
Approach:
- Pattern: sliding-window
- Idea: Use sliding window with hash map to track character frequencies. Shrink window when duplicates found.
- Complexity: Time O(n), Space O(min(m,n)) where m is character set size
*/

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

// Optimized approach - jump directly to next position
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

// Local test harness for quick runs
int main() {
    string s;
    if (!(cin >> s)) return 0;
    
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    
    return 0;
}

/*
Test Cases:
Input: abcabcbb
Output: 3

Input: bbbbb
Output: 1

Input: pwwkew
Output: 3

Input: 
Output: 0

Input:  
Output: 1

Edge Cases:
- Empty string: ""
- Single character: "a"
- All same characters: "aaaa"
- All unique characters: "abcdef"
- Very long strings: 50000 characters
*/
