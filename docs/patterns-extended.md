# Extended Algorithmic Patterns - Deep Dive

## Pattern #1: Two Pointers - Detailed Variants

### Case 1: Order Neutral (Basic Two Pointers)
**When to Use**: Array manipulation, palindrome checking, basic pair finding

**Template**:
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process elements at left and right
    if (condition) {
        left++;
    } else {
        right--;
    }
}
```

**Example**: Valid Palindrome
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

### Case 2: Sorted Array (Sum-based)
**When to Use**: Finding pairs/triplets with specific sum in sorted arrays

**Template**:
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) return {left, right};
    else if (sum < target) left++;
    else right--;
}
```

**Example**: Two Sum (Sorted Array)
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left, right};
        else if (sum < target) left++;
        else right--;
    }
    return {};
}
```

### Case 3: Three Pointers (Dutch Flag)
**When to Use**: Partitioning arrays into three sections

**Template**:
```cpp
int low = 0, mid = 0, high = n - 1;
while (mid <= high) {
    if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
    else if (nums[mid] == 1) mid++;
    else swap(nums[mid], nums[high--]);
}
```

**Example**: Sort Colors
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}
```

### Case 4: Fast-Slow Pointers (Cycle Detection)
**When to Use**: Detect cycles, find middle element, detect duplicates

**Template**:
```cpp
int slow = 0, fast = 0;
while (fast < n && fast + 1 < n) {
    slow++;
    fast += 2;
    if (condition) break;
}
```

**Example**: Find Middle of Linked List
```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### Case 5: Three Sum (Advanced)
**When to Use**: Finding triplets with specific sum

**Template**:
```cpp
for (int i = 0; i < n - 2; i++) {
    if (i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
    int left = i + 1, right = n - 1;
    while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == target) {
            // Found triplet
            left++;
            right--;
            // Skip duplicates
            while (left < right && nums[left] == nums[left-1]) left++;
            while (left < right && nums[right] == nums[right+1]) right--;
        } else if (sum < target) left++;
        else right--;
    }
}
```

## Pattern #2: Sliding Window - Detailed Variants

### Case 1: Fixed Window Size (Order Neutral)
**When to Use**: Subarray problems with constant window size

**Template**:
```cpp
int windowSum = 0;
for (int i = 0; i < k; i++) windowSum += nums[i];
int maxSum = windowSum;

for (int i = k; i < n; i++) {
    windowSum += nums[i] - nums[i - k];
    maxSum = max(maxSum, windowSum);
}
```

**Example**: Maximum Sum Subarray of Size K
```cpp
int maxSumSubarray(vector<int>& nums, int k) {
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += nums[i];
    int maxSum = windowSum;
    
    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
```

### Case 2: Variable Window Size (Character Frequency)
**When to Use**: Substring problems with character constraints

**Template**:
```cpp
unordered_map<char, int> charCount;
int left = 0, maxLen = 0;

for (int right = 0; right < s.length(); right++) {
    charCount[s[right]]++;
    
    while (windowInvalid(charCount)) {
        charCount[s[left]]--;
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
}
```

**Example**: Longest Substring Without Repeating Characters
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charCount;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;
        
        while (charCount[s[right]] > 1) {
            charCount[s[left]]--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

### Case 3: Two Pointers (Independent Movement)
**When to Use**: Subarray problems with independent left/right movement

**Template**:
```cpp
int left = 0, right = 0;
int sum = 0, minLen = INT_MAX;

while (right < n) {
    sum += nums[right];
    
    while (sum >= target) {
        minLen = min(minLen, right - left + 1);
        sum -= nums[left];
        left++;
    }
    right++;
}
```

**Example**: Minimum Size Subarray Sum
```cpp
int minSubArrayLen(int target, vector<int>& nums) {
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
    return minLen == INT_MAX ? 0 : minLen;
}
```

### Case 4: Prefix Sum (Subarray Count)
**When to Use**: Count subarrays with specific sum

**Template**:
```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
int prefixSum = 0, count = 0;

for (int right = 0; right < n; right++) {
    prefixSum += nums[right];
    if (prefixCount.find(prefixSum - target) != prefixCount.end()) {
        count += prefixCount[prefixSum - target];
    }
    prefixCount[prefixSum]++;
}
```

**Example**: Subarray Sum Equals K
```cpp
int subarraySum(vector<int>& nums, int k) {
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
    return count;
}
```

### Case 5: Character Replacement (Advanced)
**When to Use**: Substring problems with character replacement

**Template**:
```cpp
unordered_map<char, int> charCount;
int left = 0, maxCount = 0, maxLen = 0;

for (int right = 0; right < s.length(); right++) {
    charCount[s[right]]++;
    maxCount = max(maxCount, charCount[s[right]]);
    
    while (right - left + 1 - maxCount > k) {
        charCount[s[left]]--;
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
}
```

**Example**: Longest Repeating Character Replacement
```cpp
int characterReplacement(string s, int k) {
    unordered_map<char, int> charCount;
    int left = 0, maxCount = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        charCount[s[right]]++;
        maxCount = max(maxCount, charCount[s[right]]);
        
        while (right - left + 1 - maxCount > k) {
            charCount[s[left]]--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

## Pattern #3: Hash Map - Detailed Variants

### Case 1: Frequency Counting (Order Neutral)
**When to Use**: Count occurrences of elements

**Template**:
```cpp
unordered_map<int, int> freq;
for (int num : nums) {
    freq[num]++;
}
```

**Example**: Count Elements
```cpp
int countElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    int count = 0;
    for (int num : nums) {
        if (freq.find(num + 1) != freq.end()) count++;
    }
    return count;
}
```

### Case 2: Complement Searching
**When to Use**: Find pairs that sum to target

**Template**:
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

**Example**: Two Sum
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {i, mp[complement]};
        }
        mp[nums[i]] = i;
    }
    return {};
}
```

### Case 3: Grouping and Categorization
**When to Use**: Group elements by key

**Template**:
```cpp
unordered_map<string, vector<string>> groups;
for (string str : strings) {
    string key = getKey(str);
    groups[key].push_back(str);
}
```

**Example**: Group Anagrams
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        groups[key].push_back(str);
    }
    
    vector<vector<string>> result;
    for (auto& pair : groups) {
        result.push_back(pair.second);
    }
    return result;
}
```

### Case 4: Caching and Memoization
**When to Use**: Store computed results

**Template**:
```cpp
unordered_map<int, int> cache;
int solve(int n) {
    if (cache.find(n) != cache.end()) return cache[n];
    int result = compute(n);
    cache[n] = result;
    return result;
}
```

**Example**: Fibonacci with Memoization
```cpp
unordered_map<int, int> cache;
int fibonacci(int n) {
    if (n <= 1) return n;
    if (cache.find(n) != cache.end()) return cache[n];
    int result = fibonacci(n-1) + fibonacci(n-2);
    cache[n] = result;
    return result;
}
```

### Case 5: Index Mapping (Advanced)
**When to Use**: Map values to their indices

**Template**:
```cpp
unordered_map<int, vector<int>> indexMap;
for (int i = 0; i < n; i++) {
    indexMap[nums[i]].push_back(i);
}
```

**Example**: Find All Anagrams
```cpp
vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> pCount;
    for (char c : p) pCount[c]++;
    
    vector<int> result;
    int left = 0, right = 0;
    unordered_map<char, int> windowCount;
    
    while (right < s.length()) {
        windowCount[s[right]]++;
        
        if (right - left + 1 == p.length()) {
            if (windowCount == pCount) {
                result.push_back(left);
            }
            windowCount[s[left]]--;
            if (windowCount[s[left]] == 0) {
                windowCount.erase(s[left]);
            }
            left++;
        }
        right++;
    }
    return result;
}
```

## Pattern #4: Binary Search - Detailed Variants

### Case 1: Standard Search (Order Neutral)
**When to Use**: Find exact match in sorted array

**Template**:
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

**Example**: Binary Search
```cpp
int search(vector<int>& nums, int target) {
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

### Case 2: Lower Bound (First Occurrence)
**When to Use**: Find first occurrence or insertion position

**Template**:
```cpp
int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) left = mid + 1;
    else right = mid;
}
return left;
```

**Example**: Search Insert Position
```cpp
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}
```

### Case 3: Upper Bound (Last Occurrence)
**When to Use**: Find last occurrence

**Template**:
```cpp
int left = 0, right = n;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= target) left = mid + 1;
    else right = mid;
}
return left - 1;
```

**Example**: Find Last Position
```cpp
int findLast(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left - 1;
}
```

### Case 4: Rotated Array Search
**When to Use**: Search in rotated sorted array

**Template**:
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

**Example**: Search in Rotated Sorted Array
```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}
```

### Case 5: Answer Space Binary Search
**When to Use**: Find optimal value in search space

**Template**:
```cpp
int left = minVal, right = maxVal;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (isValid(mid)) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
return left;
```

**Example**: Find Peak Element
```cpp
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

## Pattern #5: Dynamic Programming - Detailed Variants

### Case 1: 1D DP (Order Neutral)
**When to Use**: Single dimension state problems

**Template**:
```cpp
vector<int> dp(n + 1);
dp[0] = baseCase;
for (int i = 1; i <= n; i++) {
    dp[i] = compute(dp[i-1], ...);
}
```

**Example**: Climbing Stairs
```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

### Case 2: 2D DP (Matrix)
**When to Use**: Two dimension state problems

**Template**:
```cpp
vector<vector<int>> dp(m + 1, vector<int>(n + 1));
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        dp[i][j] = compute(dp[i-1][j], dp[i][j-1], ...);
    }
}
```

**Example**: Unique Paths
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
```

### Case 3: State Machine DP
**When to Use**: Multiple states with transitions

**Template**:
```cpp
vector<vector<int>> dp(n + 1, vector<int>(states));
dp[0][initialState] = 1;
for (int i = 1; i <= n; i++) {
    for (int state = 0; state < states; state++) {
        dp[i][state] = compute(dp[i-1][prevState], ...);
    }
}
```

**Example**: House Robber
```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}
```

### Case 4: Interval DP
**When to Use**: Range-based problems

**Template**:
```cpp
vector<vector<int>> dp(n, vector<int>(n));
for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1;
        dp[i][j] = compute(dp[i][k], dp[k+1][j], ...);
    }
}
```

**Example**: Matrix Chain Multiplication
```cpp
int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n));
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j+1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}
```

### Case 5: Memoization (Top-Down)
**When to Use**: Recursive problems with overlapping subproblems

**Template**:
```cpp
unordered_map<int, int> memo;
int solve(int n) {
    if (memo.find(n) != memo.end()) return memo[n];
    int result = compute(solve(n-1), solve(n-2), ...);
    memo[n] = result;
    return result;
}
```

**Example**: Fibonacci with Memoization
```cpp
unordered_map<int, int> memo;
int fibonacci(int n) {
    if (n <= 1) return n;
    if (memo.find(n) != memo.end()) return memo[n];
    int result = fibonacci(n-1) + fibonacci(n-2);
    memo[n] = result;
    return result;
}
```

## Pattern Selection Matrix

| Problem Characteristics | Primary Pattern | Secondary Pattern | Case |
|------------------------|----------------|-------------------|------|
| Sorted array, find pairs | **Pattern #1** | - | Case 2 |
| Substring with constraints | **Pattern #2** | - | Case 2 |
| Find exact match | **Pattern #4** | - | Case 1 |
| Count frequencies | **Pattern #3** | - | Case 1 |
| Optimization problem | **Pattern #5** | - | Case 1 |
| Rotated array search | **Pattern #4** | - | Case 4 |
| Three-way partitioning | **Pattern #1** | - | Case 3 |
| Variable window size | **Pattern #2** | - | Case 2 |
| Group by key | **Pattern #3** | - | Case 3 |
| Range queries | **Pattern #5** | - | Case 4 |

## Mastery Checklist

### Pattern #1: Two Pointers
- [ ] Case 1: Order neutral (palindrome, basic manipulation)
- [ ] Case 2: Sorted array (sum-based problems)
- [ ] Case 3: Three pointers (Dutch flag, partitioning)
- [ ] Case 4: Fast-slow pointers (cycle detection)
- [ ] Case 5: Three sum (advanced pair finding)

### Pattern #2: Sliding Window
- [ ] Case 1: Fixed window size (subarray problems)
- [ ] Case 2: Variable window size (substring problems)
- [ ] Case 3: Two pointers (independent movement)
- [ ] Case 4: Prefix sum (subarray counting)
- [ ] Case 5: Character replacement (advanced constraints)

### Pattern #3: Hash Map
- [ ] Case 1: Frequency counting (occurrence tracking)
- [ ] Case 2: Complement searching (pair finding)
- [ ] Case 3: Grouping (categorization)
- [ ] Case 4: Caching (memoization)
- [ ] Case 5: Index mapping (advanced lookups)

### Pattern #4: Binary Search
- [ ] Case 1: Standard search (exact match)
- [ ] Case 2: Lower bound (first occurrence)
- [ ] Case 3: Upper bound (last occurrence)
- [ ] Case 4: Rotated array (modified comparison)
- [ ] Case 5: Answer space (optimal value)

### Pattern #5: Dynamic Programming
- [ ] Case 1: 1D DP (single dimension)
- [ ] Case 2: 2D DP (matrix problems)
- [ ] Case 3: State machine (multiple states)
- [ ] Case 4: Interval DP (range problems)
- [ ] Case 5: Memoization (top-down)

## Next Steps
1. Master each case within each pattern
2. Practice pattern combinations
3. Focus on pattern recognition speed
4. Implement optimizations for each case
5. Build intuition for pattern selection
