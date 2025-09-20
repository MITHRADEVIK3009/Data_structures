#!/usr/bin/env python3
"""
Create a new problem folder with template files.
"""

import os
import argparse
from pathlib import Path
import yaml
from datetime import datetime

def create_problem_folder(problem_id, title, difficulty, pattern, tags):
    """Create a new problem folder with template files."""
    
    # Create folder name
    folder_name = f"{problem_id:04d}-{title.lower().replace(' ', '-')}"
    problem_dir = Path("problems") / folder_name
    
    # Create directory
    problem_dir.mkdir(parents=True, exist_ok=True)
    
    # Create metrics.yml
    metrics = {
        'problem_id': problem_id,
        'title': title,
        'leetcode_url': f"https://leetcode.com/problems/{title.lower().replace(' ', '-')}/",
        'tags': tags,
        'difficulty': difficulty,
        'pattern': pattern,
        'company_frequency': 'Medium',  # Default, can be updated later
        'attempts': 0,
        'total_time_min': 0,
        'solved_date': '',
        'pattern_mastery': False,
        'difficulty_rating': 0,
        'sprints': [],
        'complexity': {
            'time': '',
            'space': '',
            'explanation': ''
        },
        'approach_summary': '',
        'key_insights': [],
        'alternative_approaches': [],
        'edge_cases_handled': [],
        'common_mistakes': [],
        'related_problems': []
    }
    
    with open(problem_dir / "metrics.yml", 'w') as f:
        yaml.dump(metrics, f, default_flow_style=False, sort_keys=False)
    
    # Create readme.md template
    readme_content = f"""---
title: "{title}"
leetcode: {problem_id}
tags: {tags}
difficulty: {difficulty}
pattern: {pattern}
attempts: 0
total_time_min: 0
solved_date: ""
---

# {title}

**LeetCode Link**: [Problem #{problem_id}](https://leetcode.com/problems/{title.lower().replace(' ', '-')}/)

## Problem Statement

<Copy the problem statement here>

## Examples

```
Input: <example input>
Output: <example output>
Explanation: <explanation>
```

## Constraints

- <constraint 1>
- <constraint 2>
- <constraint 3>

## Approach

### Pattern: {pattern}

<Detailed explanation of the approach>

### Algorithm Steps

1. <Step 1>
2. <Step 2>
3. <Step 3>

### Time Complexity
**O(<complexity>)**

<Explanation of time complexity>

### Space Complexity
**O(<complexity>)**

<Explanation of space complexity>

## Solution

```cpp
<Solution code here>
```

## Alternative Approaches

### Approach 2: <Alternative Pattern>
<Brief description>

```cpp
<Alternative code here>
```

## Test Cases

| Input | Output | Explanation |
|-------|--------|-------------|
| `<input1>` | `<output1>` | `<explanation1>` |
| `<input2>` | `<output2>` | `<explanation2>` |

## Edge Cases

- <Edge case 1>
- <Edge case 2>
- <Edge case 3>

## Common Mistakes

1. <Mistake 1>
2. <Mistake 2>
3. <Mistake 3>

## Learning Notes

- <Key insight 1>
- <Key insight 2>
- <Key insight 3>

## Related Problems

- [Related Problem 1](link)
- [Related Problem 2](link)
- [Related Problem 3](link)

## Time Log

| Date | Sprint (min) | Phase | Progress | Notes |
|------|--------------|-------|----------|-------|
| <YYYY-MM-DD> | <duration> | <learn/implement/review> | <stuck/partial/solved> | <notes> |

## Metrics

- **Attempts**: 0
- **Total Time**: 0 minutes
- **Pattern Mastery**: No
- **Company Frequency**: Medium
- **Difficulty Rating**: 0/5
"""
    
    with open(problem_dir / "readme.md", 'w') as f:
        f.write(readme_content)
    
    # Create solution.cpp template
    solution_content = f"""#include "cpp-template.h"

// Problem: {title} - LeetCode #{problem_id}
/*
Approach:
- Pattern: {pattern}
- Idea: <Brief 3-line explanation>
- Complexity: Time O(...), Space O(...)
*/

class Solution {{
public:
    // Main solution function
    int solve(vector<int>& nums) {{
        // Implementation here
        return 0;
    }}
}};

// Alternative approaches (if applicable)
class SolutionAlternative {{
public:
    int solve(vector<int>& nums) {{
        // Alternative implementation
        return 0;
    }}
}};

// Local test harness for quick runs
int main() {{
    // Example input parsing
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {{
        cin >> nums[i];
    }}
    
    Solution sol;
    cout << sol.solve(nums) << "\\n";
    
    return 0;
}}

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
"""
    
    with open(problem_dir / "solution.cpp", 'w') as f:
        f.write(solution_content)
    
    print(f"Created problem folder: {problem_dir}")
    print(f"Files created:")
    print(f"  - {problem_dir}/readme.md")
    print(f"  - {problem_dir}/solution.cpp")
    print(f"  - {problem_dir}/metrics.yml")

def main():
    parser = argparse.ArgumentParser(description='Create a new problem folder with templates')
    parser.add_argument('problem_id', type=int, help='LeetCode problem ID')
    parser.add_argument('title', help='Problem title')
    parser.add_argument('difficulty', choices=['Easy', 'Medium', 'Hard'], help='Problem difficulty')
    parser.add_argument('pattern', help='Primary algorithmic pattern')
    parser.add_argument('--tags', nargs='+', default=[], help='Problem tags')
    
    args = parser.parse_args()
    
    create_problem_folder(
        args.problem_id,
        args.title,
        args.difficulty,
        args.pattern,
        args.tags
    )

if __name__ == "__main__":
    main()
