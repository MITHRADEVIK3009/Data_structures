---
title: "Two Sum"
leetcode: 1
tags: [array, hashmap, two-pointers]
difficulty: Easy
pattern: hash-map
attempts: 2
total_time_min: 45
solved_date: 2024-01-15
---

# Two Sum

**LeetCode Link**: [Problem #1](https://leetcode.com/problems/two-sum/)

## Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Examples

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

## Constraints

- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

## Approach

### Pattern: Hash Map

The key insight is to use a hash map to store the complement of each number we've seen so far. For each number, we calculate what number we need to add to it to get the target, then check if we've seen that complement before.

### Algorithm Steps

1. Create an empty hash map to store numbers and their indices
2. Iterate through the array
3. For each number, calculate the complement (target - current number)
4. Check if the complement exists in the hash map
5. If it exists, return the indices
6. If not, add the current number and its index to the hash map

### Time Complexity
**O(n)**

We iterate through the array once, and each hash map operation (insertion and lookup) takes O(1) time on average.

### Space Complexity
**O(n)**

In the worst case, we might need to store all n elements in the hash map.

## Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (mp.find(complement) != mp.end()) {
                return {i, mp[complement]};
            }
            
            mp[nums[i]] = i;
        }
        
        return {}; // Should never reach here given problem constraints
    }
};
```

## Alternative Approaches

### Approach 2: Two Pointers (Sorted Array)
If the array were sorted, we could use two pointers approach:

```cpp
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};
}
```

## Test Cases

| Input | Target | Output | Explanation |
|-------|--------|--------|-------------|
| `[2,7,11,15]` | `9` | `[0,1]` | `2 + 7 = 9` |
| `[3,2,4]` | `6` | `[1,2]` | `2 + 4 = 6` |
| `[3,3]` | `6` | `[0,1]` | `3 + 3 = 6` |

## Edge Cases

- Array with exactly 2 elements
- Array with duplicate elements
- Target that requires the same element twice (handled by problem constraints)
- Large numbers (within constraint limits)

## Common Mistakes

1. **Using the same element twice**: Make sure to check if the complement index is different from current index
2. **Returning indices in wrong order**: The problem allows any order, but be consistent
3. **Not handling the case where no solution exists**: Though problem guarantees exactly one solution

## Learning Notes

- Hash maps are excellent for complement searching problems
- The key insight is to store what we need (complement) rather than what we have
- This pattern is fundamental to many array problems
- Time-space trade-off: O(n) space for O(n) time vs O(1) space for O(n²) time

## Related Problems

- [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- [3Sum](https://leetcode.com/problems/3sum/)
- [4Sum](https://leetcode.com/problems/4sum/)

## Time Log

| Date | Sprint (min) | Phase | Progress | Notes |
|------|--------------|-------|----------|-------|
| 2024-01-15 | 25 | learn | solved | Read problem, identified hash map pattern |
| 2024-01-15 | 20 | implement | solved | Coded solution, handled edge cases |

## Metrics

- **Attempts**: 2
- **Total Time**: 45 minutes
- **Pattern Mastery**: Yes
- **Company Frequency**: High
- **Difficulty Rating**: 2/5
