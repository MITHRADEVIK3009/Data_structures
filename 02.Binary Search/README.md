# Binary Search Implementation Guide

## Common Implementation Issues & Solutions

### 🚨 Critical Issues to Avoid

1. **Integer Overflow**
   - **Issue**: `(left + right) / 2` can overflow for large numbers
   - **Solution**: Use `left + (right - left) / 2`
   - **Pattern**: Essential in **Pattern #4 (Binary Search)**

2. **Infinite Loop**
   - **Issue**: Using `while (left < right)` with `right = mid` can cause infinite loops
   - **Solution**: Use `while (left <= right)` or adjust boundary conditions
   - **Pattern**: Critical in **Pattern #4 (Binary Search)**

3. **Boundary Conditions**
   - **Issue**: Incorrect handling of left/right boundaries
   - **Solution**: Understand when to use `left = mid + 1` vs `left = mid`
   - **Pattern**: Fundamental in **Pattern #4 (Binary Search)**

4. **Search Space Definition**
   - **Issue**: Incorrect search space initialization
   - **Solution**: Define search space based on problem constraints
   - **Pattern**: Key in **Pattern #4 (Binary Search)**

## Pattern-Based Problem Analysis

### Pattern #4: Binary Search (Standard)
**Focus Areas**: Search in sorted arrays, find exact matches

#### Problem: Binary Search
**Input Array**: `[-1, 0, 3, 5, 9, 12]`, Target: `9`
**Output**: `4` (index)

**Iteration Table**:
| Step | Left | Right | Mid | nums[mid] | Action |
|------|------|-------|-----|-----------|--------|
| 1    | 0    | 5     | 2   | 3         | 3 < 9, left = mid + 1 |
| 2    | 3    | 5     | 4   | 9         | 9 == 9, found! |

**Implementation Focus**:
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### Pattern #4: Binary Search (Lower Bound)
**Focus Areas**: Find first occurrence, insertion position

#### Problem: Search Insert Position
**Input Array**: `[1, 3, 5, 6]`, Target: `5`
**Output**: `2` (index)

**Iteration Table**:
| Step | Left | Right | Mid | nums[mid] | Action |
|------|------|-------|-----|-----------|--------|
| 1    | 0    | 3     | 1   | 3         | 3 < 5, left = mid + 1 |
| 2    | 2    | 3     | 2   | 5         | 5 >= 5, right = mid |
| 3    | 2    | 2     | 2   | 5         | left == right, return 2 |

**Implementation Focus**:
```cpp
int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) left = mid + 1;
    else right = mid;
}
return left;
```

### Pattern #4: Binary Search (Upper Bound)
**Focus Areas**: Find last occurrence, range queries

#### Problem: Find Last Position of Element
**Input Array**: `[5, 7, 7, 8, 8, 10]`, Target: `8`
**Output**: `4` (last index)

**Iteration Table**:
| Step | Left | Right | Mid | nums[mid] | Action |
|------|------|-------|-----|-----------|--------|
| 1    | 0    | 5     | 2   | 7         | 7 <= 8, left = mid + 1 |
| 2    | 3    | 5     | 4   | 8         | 8 <= 8, left = mid + 1 |
| 3    | 5    | 5     | 5   | 10        | 10 > 8, right = mid - 1 |
| 4    | 5    | 4     | -   | -         | left > right, return 4 |

**Implementation Focus**:
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= target) left = mid + 1;
    else right = mid - 1;
}
return right;
```

### Pattern #4: Binary Search (Rotated Array)
**Focus Areas**: Search in rotated sorted arrays

#### Problem: Search in Rotated Sorted Array
**Input Array**: `[4, 5, 6, 7, 0, 1, 2]`, Target: `0`
**Output**: `4` (index)

**Iteration Table**:
| Step | Left | Right | Mid | nums[mid] | nums[left] | Action |
|------|------|-------|-----|-----------|------------|--------|
| 1    | 0    | 6     | 3   | 7         | 4          | Left sorted, 0 not in [4,7], left = 4 |
| 2    | 4    | 6     | 5   | 1         | 0          | Right sorted, 0 in [0,2], right = 5 |
| 3    | 4    | 5     | 4   | 0         | 0          | Found! |

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

### Pattern #4: Binary Search (2D Matrix)
**Focus Areas**: Search in 2D sorted matrices

#### Problem: Search in 2D Matrix
**Input Matrix**: `[[1,4,7,11],[2,5,8,12],[3,6,9,16]]`, Target: `5`
**Output**: `true`

**Iteration Table**:
| Step | Row | Col | Matrix[row][col] | Action |
|------|-----|-----|------------------|--------|
| 1    | 0   | 3   | 11               | 11 > 5, col-- |
| 2    | 0   | 2   | 7                | 7 > 5, col-- |
| 3    | 0   | 1   | 4                | 4 < 5, row++ |
| 4    | 1   | 1   | 5                | Found! |

**Implementation Focus**:
```cpp
int row = 0, col = matrix[0].size() - 1;
while (row < matrix.size() && col >= 0) {
    if (matrix[row][col] == target) return true;
    else if (matrix[row][col] > target) col--;
    else row++;
}
```

### Pattern #4: Binary Search (Answer Space)
**Focus Areas**: Find optimal value in search space

#### Problem: Find Peak Element
**Input Array**: `[1, 2, 3, 1]`
**Output**: `2` (index of peak)

**Iteration Table**:
| Step | Left | Right | Mid | nums[mid] | nums[mid+1] | Action |
|------|------|-------|-----|-----------|-------------|--------|
| 1    | 0    | 3     | 1   | 2         | 3           | 2 < 3, left = 2 |
| 2    | 2    | 3     | 2   | 3         | 1           | 3 > 1, right = 2 |
| 3    | 2    | 2     | 2   | 3         | -           | left == right, return 2 |

**Implementation Focus**:
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[mid + 1]) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
return left;
```

## Advanced Binary Search Patterns

### Pattern #4: Binary Search (Range Queries)
**Focus Areas**: Find range of elements

#### Problem: Find First and Last Position
**Input Array**: `[5, 7, 7, 8, 8, 10]`, Target: `8`
**Output**: `[3, 4]` (first and last indices)

**Implementation Strategy**:
1. Find first occurrence (lower bound)
2. Find last occurrence (upper bound)

**First Occurrence Table**:
| Step | Left | Right | Mid | nums[mid] | Action |
|------|------|-------|-----|-----------|--------|
| 1    | 0    | 5     | 2   | 7         | 7 < 8, left = 3 |
| 2    | 3    | 5     | 4   | 8         | 8 >= 8, right = 4 |
| 3    | 3    | 4     | 3   | 8         | 8 >= 8, right = 3 |
| 4    | 3    | 3     | 3   | 8         | left == right, return 3 |

**Last Occurrence Table**:
| Step | Left | Right | Mid | nums[mid] | Action |
|------|------|-------|-----|-----------|--------|
| 1    | 0    | 5     | 2   | 7         | 7 <= 8, left = 3 |
| 2    | 3    | 5     | 4   | 8         | 8 <= 8, left = 5 |
| 3    | 5    | 5     | 5   | 10        | 10 > 8, right = 4 |
| 4    | 5    | 4     | -   | -         | left > right, return 4 |

**Implementation Focus**:
```cpp
// Find first occurrence
int first = findFirst(nums, target);
// Find last occurrence  
int last = findLast(nums, target);
return {first, last};
```

## Problem-Specific Focus Areas

### 1D Array Problems
1. **Standard Search**: Exact match in sorted array
2. **Insert Position**: Find where to insert element
3. **Range Queries**: Find first/last occurrence
4. **Rotated Array**: Search in rotated sorted array
5. **Peak Element**: Find local maximum

### 2D Array Problems
1. **Row-wise Sorted**: Search in each row
2. **Column-wise Sorted**: Search in each column
3. **Fully Sorted**: Search in 2D sorted matrix
4. **Peak in 2D**: Find peak element in 2D

### Search Space Problems
1. **Square Root**: Find integer square root
2. **Capacity**: Find minimum capacity
3. **Kth Smallest**: Find kth smallest element
4. **Median**: Find median in two sorted arrays

## Implementation Checklist

### Before Coding
- [ ] Identify search space (array indices, value range)
- [ ] Determine comparison condition
- [ ] Choose boundary conditions (left <= right vs left < right)
- [ ] Plan for edge cases (empty array, single element)

### During Coding
- [ ] Use `left + (right - left) / 2` to avoid overflow
- [ ] Handle boundary updates correctly
- [ ] Implement proper termination condition
- [ ] Add necessary boundary checks

### After Coding
- [ ] Test with edge cases
- [ ] Verify time complexity O(log n)
- [ ] Check for infinite loops
- [ ] Validate return values

## Common Debugging Tips

1. **Print Search Space**: Track left, right, mid values
2. **Check Comparison**: Verify comparison logic
3. **Boundary Updates**: Ensure correct left/right updates
4. **Termination**: Verify loop termination condition

## Pattern Selection Guide

| Problem Type | Binary Search Variant | Key Insight |
|--------------|----------------------|-------------|
| Exact match | Standard | `nums[mid] == target` |
| Insert position | Lower bound | `nums[mid] >= target` |
| Last occurrence | Upper bound | `nums[mid] <= target` |
| Rotated array | Modified comparison | Check which half is sorted |
| 2D matrix | Row/column elimination | Start from corner |
| Answer space | Custom condition | Define search space |

## Binary Search Templates

### Template 1: Standard Search
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### Template 2: Lower Bound
```cpp
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}
```

### Template 3: Upper Bound
```cpp
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left - 1;
}
```

## Next Steps
- Master the three main templates
- Practice rotated array problems
- Learn 2D matrix search techniques
- Understand answer space binary search
