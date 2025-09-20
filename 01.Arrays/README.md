# Arrays Implementation Guide

## Common Implementation Issues & Solutions

### 🚨 Critical Issues to Avoid

1. **Index Out of Bounds**
   - **Issue**: Accessing `arr[n]` when array size is `n`
   - **Solution**: Always check `i < arr.size()` before access
   - **Pattern**: Use in **Pattern #1 (Two Pointers)** and **Pattern #2 (Sliding Window)**

2. **Off-by-One Errors**
   - **Issue**: Incorrect loop boundaries causing missed elements
   - **Solution**: Use `i < n` instead of `i <= n` for 0-indexed arrays
   - **Pattern**: Critical in **Pattern #4 (Binary Search)**

3. **Memory Management**
   - **Issue**: Not handling empty arrays or single elements
   - **Solution**: Add early returns for edge cases
   - **Pattern**: Essential in all patterns

4. **In-Place Modification**
   - **Issue**: Modifying array while iterating
   - **Solution**: Use separate pointers or iterate backwards
   - **Pattern**: Common in **Pattern #1 (Two Pointers)**

## Pattern-Based Problem Analysis

### Pattern #1: Two Pointers
**Focus Areas**: Array manipulation, palindrome checking, pair finding

#### Problem: Two Sum (Sorted Array)
**Input Array**: `[2, 7, 11, 15]`, Target: `9`
**Output Array**: `[0, 1]` (indices)

**Iteration Table**:
| Step | Left | Right | Sum | Action |
|------|------|-------|-----|--------|
| 1    | 0    | 3     | 17  | Sum > 9, move right-- |
| 2    | 0    | 2     | 13  | Sum > 9, move right-- |
| 3    | 0    | 1     | 9   | Found! Return [0,1] |

**Implementation Focus**:
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) return {left, right};
    else if (sum < target) left++;
    else right--;
}
```

#### Problem: Sort Colors (Dutch Flag)
**Input Array**: `[2, 0, 2, 1, 1, 0]`
**Output Array**: `[0, 0, 1, 1, 2, 2]`

**Iteration Table**:
| Step | Low | Mid | High | Array State | Action |
|------|-----|-----|------|-------------|--------|
| 1    | 0   | 0   | 5    | [2,0,2,1,1,0] | nums[mid]=2, swap with high-- |
| 2    | 0   | 0   | 4    | [0,0,2,1,1,2] | nums[mid]=0, swap with low++, mid++ |
| 3    | 1   | 1   | 4    | [0,0,2,1,1,2] | nums[mid]=0, swap with low++, mid++ |
| 4    | 2   | 2   | 4    | [0,0,2,1,1,2] | nums[mid]=2, swap with high-- |
| 5    | 2   | 2   | 3    | [0,0,1,1,2,2] | nums[mid]=1, mid++ |
| 6    | 2   | 3   | 3    | [0,0,1,1,2,2] | mid > high, done |

**Implementation Focus**:
```cpp
int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
    else if (nums[mid] == 1) mid++;
    else swap(nums[mid], nums[high--]);
}
```

### Pattern #2: Sliding Window
**Focus Areas**: Subarray problems, substring optimization

#### Problem: Maximum Sum Subarray of Size K
**Input Array**: `[2, 1, 5, 1, 3, 2]`, K = 3
**Output**: `9` (subarray [5, 1, 3])

**Iteration Table**:
| Step | Window | Sum | Max Sum | Action |
|------|--------|-----|---------|--------|
| 1    | [2,1,5] | 8   | 8       | Initial window |
| 2    | [1,5,1] | 7   | 8       | Slide window |
| 3    | [5,1,3] | 9   | 9       | Update max |
| 4    | [1,3,2] | 6   | 9       | Final window |

**Implementation Focus**:
```cpp
int windowSum = 0, maxSum = 0;
for (int i = 0; i < k; i++) windowSum += nums[i];
maxSum = windowSum;

for (int i = k; i < n; i++) {
    windowSum += nums[i] - nums[i - k];
    maxSum = max(maxSum, windowSum);
}
```

### Pattern #3: Hash Map
**Focus Areas**: Frequency counting, complement searching

#### Problem: Two Sum (Unsorted Array)
**Input Array**: `[3, 2, 4]`, Target: `6`
**Output Array**: `[1, 2]` (indices)

**Iteration Table**:
| Step | Element | Complement | Map State | Action |
|------|---------|------------|-----------|--------|
| 1    | 3       | 3          | {3:0}     | Add to map |
| 2    | 2       | 4          | {3:0,2:1} | Add to map |
| 3    | 4       | 2          | Found!    | Return [1,2] |

**Implementation Focus**:
```cpp
unordered_map<int, int> mp;
for (int i = 0; i < n; i++) {
    int complement = target - nums[i];
    if (mp.find(complement) != mp.end()) {
        return {i, mp[complement]};
    }
    mp[nums[i]] = i;
}
```

### Pattern #4: Binary Search
**Focus Areas**: Search space reduction, rotated arrays

#### Problem: Search in Rotated Sorted Array
**Input Array**: `[4, 5, 6, 7, 0, 1, 2]`, Target: `0`
**Output**: `4` (index)

**Iteration Table**:
| Step | Left | Right | Mid | nums[mid] | Action |
|------|------|-------|-----|-----------|--------|
| 1    | 0    | 6     | 3   | 7         | 7 > 0, check which half is sorted |
| 2    | 4    | 6     | 5   | 1         | 1 > 0, check right half |
| 3    | 4    | 4     | 4   | 0         | Found! |

**Implementation Focus**:
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    
    if (nums[left] <= nums[mid]) { // Left half is sorted
        if (target >= nums[left] && target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    } else { // Right half is sorted
        if (target > nums[mid] && target <= nums[right]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}
```

## Advanced Array Patterns

### Pattern #5: Prefix Sum
**Focus Areas**: Range sum queries, subarray problems

#### Problem: Subarray Sum Equals K
**Input Array**: `[1, 1, 1]`, K = `2`
**Output**: `2` (number of subarrays)

**Iteration Table**:
| Step | Element | Prefix Sum | Count | Map State |
|------|---------|------------|-------|-----------|
| 1    | 1       | 1          | 0     | {0:1, 1:1} |
| 2    | 1       | 2          | 1     | {0:1, 1:1, 2:1} |
| 3    | 1       | 3          | 2     | {0:1, 1:1, 2:1, 3:1} |

**Implementation Focus**:
```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
int prefixSum = 0, count = 0;

for (int num : nums) {
    prefixSum += num;
    if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
        count += prefixCount[prefixSum - k];
    }
    prefixCount[prefixSum]++;
}
```

## Problem-Specific Focus Areas

### Easy Problems (Focus on Pattern Recognition)
1. **Largest Element**: Basic iteration, no extra space
2. **Second Largest**: Two-pointer approach, handle duplicates
3. **Remove Duplicates**: Two pointers, in-place modification
4. **Rotate Array**: Reverse technique, handle edge cases

### Medium Problems (Pattern Combination)
1. **2 Sum**: Hash map + complement searching
2. **Sort 0 1 2**: Three pointers (Dutch Flag)
3. **Majority Element**: Boyer-Moore voting algorithm
4. **Kadane's Algorithm**: Dynamic programming approach

### Hard Problems (Advanced Pattern Usage)
1. **3 Sum**: Two pointers + sorting
2. **4 Sum**: Two pointers + hash map
3. **Largest Subarray with 0 Sum**: Prefix sum + hash map
4. **Maximum Product Subarray**: Dynamic programming

## Implementation Checklist

### Before Coding
- [ ] Identify the primary pattern
- [ ] Check for edge cases (empty array, single element)
- [ ] Plan the iteration strategy
- [ ] Consider space complexity constraints

### During Coding
- [ ] Use appropriate loop boundaries
- [ ] Handle index out of bounds
- [ ] Implement pattern-specific optimizations
- [ ] Add necessary boundary checks

### After Coding
- [ ] Test with edge cases
- [ ] Verify time/space complexity
- [ ] Check for off-by-one errors
- [ ] Optimize if possible

## Common Debugging Tips

1. **Print Array State**: Use `debugv(nums)` to see array changes
2. **Track Pointers**: Print left/right/mid values in loops
3. **Check Boundaries**: Verify loop conditions and array access
4. **Test Edge Cases**: Empty array, single element, all same elements

## Pattern Selection Guide

| Problem Type | Primary Pattern | Secondary Pattern |
|--------------|----------------|-------------------|
| Find pairs/triplets | **Pattern #1** (Two Pointers) | **Pattern #3** (Hash Map) |
| Subarray/substring | **Pattern #2** (Sliding Window) | **Pattern #5** (Prefix Sum) |
| Search in sorted | **Pattern #4** (Binary Search) | - |
| Frequency problems | **Pattern #3** (Hash Map) | - |
| Range queries | **Pattern #5** (Prefix Sum) | - |

## Next Steps
- Practice each pattern with 5+ problems
- Focus on pattern recognition speed (< 2 minutes)
- Master edge case handling
- Optimize for time/space complexity
