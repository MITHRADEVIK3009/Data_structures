# Sliding Window Implementation Guide

## Common Implementation Issues & Solutions

### 🚨 Critical Issues to Avoid

1. **Window Shrinking Logic**
   - **Issue**: Incorrect window shrinking causing infinite loops or missed solutions
   - **Solution**: Use `while` loop for shrinking, ensure proper boundary updates
   - **Pattern**: Critical in **Pattern #2 (Sliding Window)**

2. **Window Size Management**
   - **Issue**: Not handling fixed vs variable window sizes correctly
   - **Solution**: Distinguish between fixed window (for loop) and variable window (while loop)
   - **Pattern**: Essential in **Pattern #2 (Sliding Window)**

3. **Character Frequency Tracking**
   - **Issue**: Incorrect frequency updates when shrinking window
   - **Solution**: Decrement frequency before moving left pointer
   - **Pattern**: Key in **Pattern #2 (Sliding Window)**

4. **Boundary Conditions**
   - **Issue**: Off-by-one errors in window boundaries
   - **Solution**: Use `right - left + 1` for window size calculation
   - **Pattern**: Fundamental in **Pattern #2 (Sliding Window)**

## Pattern-Based Problem Analysis

### Pattern #2: Sliding Window (Fixed Size)
**Focus Areas**: Subarray problems with fixed window size

#### Problem: Maximum Sum Subarray of Size K
**Input Array**: `[2, 1, 5, 1, 3, 2]`, K = 3
**Output**: `9` (maximum sum)

**Iteration Table**:
| Step | Window | Window Sum | Max Sum | Action |
|------|--------|------------|---------|--------|
| 1    | [2,1,5] | 8          | 8       | Initial window |
| 2    | [1,5,1] | 7          | 8       | Slide window |
| 3    | [5,1,3] | 9          | 9       | Update max |
| 4    | [1,3,2] | 6          | 9       | Final window |

**Implementation Focus**:
```cpp
int windowSum = 0, maxSum = 0;
// Calculate sum of first window
for (int i = 0; i < k; i++) {
    windowSum += nums[i];
}
maxSum = windowSum;

// Slide the window
for (int i = k; i < n; i++) {
    windowSum += nums[i] - nums[i - k];
    maxSum = max(maxSum, windowSum);
}
```

### Pattern #2: Sliding Window (Variable Size)
**Focus Areas**: Substring problems with dynamic window size

#### Problem: Longest Substring Without Repeating Characters
**Input String**: `"abcabcbb"`
**Output**: `3` (length of longest substring)

**Iteration Table**:
| Step | Right | Window | Char Count | Action |
|------|-------|--------|------------|--------|
| 1    | 0     | "a"    | {a:1}      | Expand |
| 2    | 1     | "ab"   | {a:1,b:1}  | Expand |
| 3    | 2     | "abc"  | {a:1,b:1,c:1} | Expand |
| 4    | 3     | "abca" | {a:2,b:1,c:1} | Shrink (a repeated) |
| 5    | 3     | "bca"  | {a:1,b:1,c:1} | Continue |

**Implementation Focus**:
```cpp
unordered_map<char, int> charCount;
int left = 0, maxLen = 0;

for (int right = 0; right < s.length(); right++) {
    charCount[s[right]]++;
    
    // Shrink window if we have duplicates
    while (charCount[s[right]] > 1) {
        charCount[s[left]]--;
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
}
```

### Pattern #2: Sliding Window (Character Frequency)
**Focus Areas**: Substring problems with character constraints

#### Problem: Longest Repeating Character Replacement
**Input String**: `"AABABBA"`, K = 1
**Output**: `4` (length of longest substring)

**Iteration Table**:
| Step | Right | Window | Max Count | Action |
|------|-------|--------|-----------|--------|
| 1    | 0     | "A"    | 1         | Expand |
| 2    | 1     | "AA"   | 2         | Expand |
| 3    | 2     | "AAB"  | 2         | Expand |
| 4    | 3     | "AABA" | 3         | Expand |
| 5    | 4     | "AABAB" | 3         | Shrink (4-3+1 > 1) |
| 6    | 4     | "ABAB" | 2         | Continue |

**Implementation Focus**:
```cpp
unordered_map<char, int> charCount;
int left = 0, maxCount = 0, maxLen = 0;

for (int right = 0; right < s.length(); right++) {
    charCount[s[right]]++;
    maxCount = max(maxCount, charCount[s[right]]);
    
    // Shrink window if we need more than k replacements
    while (right - left + 1 - maxCount > k) {
        charCount[s[left]]--;
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
}
```

### Pattern #2: Sliding Window (Subarray Count)
**Focus Areas**: Count subarrays with specific properties

#### Problem: Binary Subarrays with Sum
**Input Array**: `[1, 0, 1, 0, 1]`, Goal = 2
**Output**: `4` (number of subarrays)

**Iteration Table**:
| Step | Right | Prefix Sum | Count | Map State |
|------|-------|------------|-------|-----------|
| 1    | 0     | 1          | 0     | {0:1, 1:1} |
| 2    | 1     | 1          | 1     | {0:1, 1:2} |
| 3    | 2     | 2          | 1     | {0:1, 1:2, 2:1} |
| 4    | 3     | 2          | 2     | {0:1, 1:2, 2:2} |
| 5    | 4     | 3          | 4     | {0:1, 1:2, 2:2, 3:1} |

**Implementation Focus**:
```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
int prefixSum = 0, count = 0;

for (int right = 0; right < nums.size(); right++) {
    prefixSum += nums[right];
    if (prefixCount.find(prefixSum - goal) != prefixCount.end()) {
        count += prefixCount[prefixSum - goal];
    }
    prefixCount[prefixSum]++;
}
```

### Pattern #2: Sliding Window (Two Pointers)
**Focus Areas**: Subarray problems with two pointer technique

#### Problem: Minimum Window Substring
**Input String**: `"ADOBECODEBANC"`, Target: `"ABC"`
**Output**: `"BANC"` (minimum window)

**Iteration Table**:
| Step | Right | Window | Char Count | Action |
|------|-------|--------|------------|--------|
| 1    | 0     | "A"    | {A:1}      | Expand |
| 2    | 1     | "AD"   | {A:1,D:1}  | Expand |
| 3    | 2     | "ADO"  | {A:1,D:1,O:1} | Expand |
| 4    | 3     | "ADOB" | {A:1,D:1,O:1,B:1} | Expand |
| 5    | 4     | "ADOBE" | {A:1,D:1,O:1,B:1,E:1} | Expand |
| 6    | 5     | "ADOBEC" | {A:1,D:1,O:1,B:1,E:1,C:1} | Valid window found |

**Implementation Focus**:
```cpp
unordered_map<char, int> targetCount, windowCount;
for (char c : t) targetCount[c]++;

int left = 0, right = 0;
int formed = 0, required = targetCount.size();
int minLen = INT_MAX, start = 0;

while (right < s.length()) {
    char c = s[right];
    windowCount[c]++;
    
    if (targetCount.find(c) != targetCount.end() && 
        windowCount[c] == targetCount[c]) {
        formed++;
    }
    
    while (left <= right && formed == required) {
        if (right - left + 1 < minLen) {
            minLen = right - left + 1;
            start = left;
        }
        
        char leftChar = s[left];
        windowCount[leftChar]--;
        if (targetCount.find(leftChar) != targetCount.end() && 
            windowCount[leftChar] < targetCount[leftChar]) {
            formed--;
        }
        left++;
    }
    right++;
}
```

## Advanced Sliding Window Patterns

### Pattern #2: Sliding Window (Prefix Sum)
**Focus Areas**: Subarray sum problems

#### Problem: Subarray Sum Equals K
**Input Array**: `[1, 1, 1]`, K = 2
**Output**: `2` (number of subarrays)

**Iteration Table**:
| Step | Right | Prefix Sum | Count | Map State |
|------|-------|------------|-------|-----------|
| 1    | 0     | 1          | 0     | {0:1, 1:1} |
| 2    | 1     | 2          | 1     | {0:1, 1:1, 2:1} |
| 3    | 2     | 3          | 2     | {0:1, 1:1, 2:1, 3:1} |

**Implementation Focus**:
```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
int prefixSum = 0, count = 0;

for (int right = 0; right < nums.size(); right++) {
    prefixSum += nums[right];
    if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
        count += prefixCount[prefixSum - k];
    }
    prefixCount[prefixSum]++;
}
```

## Problem-Specific Focus Areas

### Fixed Window Problems
1. **Maximum Sum**: Find maximum sum of subarray of size K
2. **Average**: Find maximum average of subarray of size K
3. **Maximum**: Find maximum element in each window of size K
4. **Minimum**: Find minimum element in each window of size K

### Variable Window Problems
1. **Longest Substring**: Without repeating characters
2. **Longest Subarray**: With sum less than or equal to target
3. **Minimum Window**: Substring containing all characters
4. **Longest Substring**: With at most K distinct characters

### Character Frequency Problems
1. **Character Replacement**: Longest substring with K replacements
2. **Anagram**: Find all anagrams in string
3. **Permutation**: Check if string contains permutation
4. **Character Count**: Count substrings with specific character count

## Implementation Checklist

### Before Coding
- [ ] Identify window type (fixed vs variable)
- [ ] Determine shrinking condition
- [ ] Plan character frequency tracking
- [ ] Consider edge cases (empty string, single character)

### During Coding
- [ ] Use appropriate loop structure
- [ ] Handle window shrinking correctly
- [ ] Update frequency maps properly
- [ ] Calculate window size accurately

### After Coding
- [ ] Test with edge cases
- [ ] Verify time complexity O(n)
- [ ] Check for infinite loops
- [ ] Validate window boundaries

## Common Debugging Tips

1. **Print Window State**: Track left, right, window content
2. **Check Frequency Maps**: Verify character counts
3. **Boundary Updates**: Ensure correct left/right updates
4. **Window Size**: Verify window size calculations

## Pattern Selection Guide

| Problem Type | Window Type | Key Technique |
|--------------|-------------|---------------|
| Fixed size subarray | Fixed window | For loop with sliding |
| Variable size substring | Variable window | While loop for shrinking |
| Character frequency | Hash map tracking | Frequency count updates |
| Subarray sum | Prefix sum | Cumulative sum tracking |
| Two pointers | Left/right movement | Independent pointer movement |

## Sliding Window Templates

### Template 1: Fixed Window
```cpp
int fixedWindow(vector<int>& nums, int k) {
    int windowSum = 0;
    // Calculate sum of first window
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    int maxSum = windowSum;
    
    // Slide the window
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
```

### Template 2: Variable Window
```cpp
int variableWindow(string s) {
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;
        
        // Shrink window if condition violated
        while (windowInvalid(charCount)) {
            charCount[s[left]]--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

### Template 3: Two Pointers
```cpp
int twoPointers(vector<int>& nums, int target) {
    int left = 0, right = 0;
    int sum = 0, minLen = INT_MAX;
    
    while (right < nums.size()) {
        sum += nums[right];
        
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return minLen;
}
```

## Next Steps
- Master the three main templates
- Practice character frequency problems
- Learn prefix sum techniques
- Understand two pointer variations
