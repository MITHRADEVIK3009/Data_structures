#include "cpp-template.h"

// Problem: Two Sum - LeetCode #1
/*
Approach:
- Pattern: hash-map
- Idea: Use hash map to store complements. For each number, check if its complement exists.
- Complexity: Time O(n), Space O(n)
*/

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

// Alternative approach for sorted array (two pointers)
class SolutionAlternative {
public:
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
};

// Local test harness for quick runs
int main() {
    // Example input parsing
    int n, target;
    if (!(cin >> n >> target)) return 0;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
    
    return 0;
}

/*
Test Cases:
Input: 4 9
       2 7 11 15
Output: [0,1]

Input: 3 6
       3 2 4
Output: [1,2]

Input: 2 6
       3 3
Output: [0,1]

Edge Cases:
- Array with exactly 2 elements: [1,2], target=3
- Array with duplicate elements: [3,3], target=6
- Large numbers: [1000000000,999999999], target=1999999999
*/
