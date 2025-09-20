#include "cpp-template.h"

// Problem: <Problem Name> - LeetCode #
/*
Approach:
- Pattern: <two-pointers / sliding-window / dp / binary-search / etc.>
- Idea: <Brief 3-line explanation>
- Complexity: Time O(...), Space O(...)
*/

class Solution {
public:
    // Main solution function
    int solve(vector<int>& nums) {
        // Implementation here
        return 0;
    }
};

// Alternative approaches (if applicable)
class SolutionAlternative {
public:
    int solve(vector<int>& nums) {
        // Alternative implementation
        return 0;
    }
};

// Local test harness for quick runs
int main() {
    // Example input parsing
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution sol;
    cout << sol.solve(nums) << "\n";
    
    return 0;
}

/*
Test Cases:
Input: [1, 2, 3, 4, 5]
Output: <expected output>

Input: [5, 4, 3, 2, 1]
Output: <expected output>

Edge Cases:
- Empty array: []
- Single element: [1]
- All same elements: [1, 1, 1, 1]
- Large numbers: [1000000, 999999, ...]
*/
