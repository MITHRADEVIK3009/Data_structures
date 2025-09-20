# YAML Workflow & Tool Usage Guide

## Overview

This document explains how the YAML-based workflow and automation tools work together to manage your LeetCode learning journey efficiently.

## YAML File Structure

### Problem Metrics (metrics.yml)
Each problem folder contains a `metrics.yml` file that tracks:

```yaml
problem_id: 1
title: "Two Sum"
leetcode_url: "https://leetcode.com/problems/two-sum/"
tags: [array, hashmap, two-pointers]
difficulty: Easy
pattern: hash-map
company_frequency: High
attempts: 2
total_time_min: 45
solved_date: "2024-01-15"
pattern_mastery: true
difficulty_rating: 2

sprints:
  - date: "2024-01-15"
    duration_min: 25
    phase: "learn"
    progress: "solved"
    notes: "Read problem, identified hash map pattern"
  - date: "2024-01-15"
    duration_min: 20
    phase: "implement"
    progress: "solved"
    notes: "Coded solution, handled edge cases"

complexity:
  time: "O(n)"
  space: "O(n)"
  explanation: "Single pass through array, hash map operations are O(1)"

approach_summary: "Use hash map to store complements. For each number, check if its complement exists."

key_insights:
  - "Hash maps are excellent for complement searching"
  - "Store what we need (complement) rather than what we have"
  - "Fundamental pattern for many array problems"

alternative_approaches:
  - name: "Two Pointers (Sorted Array)"
    complexity: "O(n log n) time, O(1) space"
    notes: "Requires sorting first, then two pointers from ends"

edge_cases_handled:
  - "Array with exactly 2 elements"
  - "Array with duplicate elements"
  - "Large numbers within constraints"

common_mistakes:
  - "Using same element twice"
  - "Returning indices in wrong order"
  - "Not handling no solution case"

related_problems:
  - problem_id: 167
    title: "Two Sum II - Input Array Is Sorted"
    url: "https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/"
  - problem_id: 15
    title: "3Sum"
    url: "https://leetcode.com/problems/3sum/"
```

## Tool Workflow

### 1. Problem Creation Workflow

#### Step 1: Create New Problem
```bash
python tools/create-problem.py 123 "Problem Title" Medium sliding-window --tags array string
```

**What it does**:
- Creates folder: `problems/0123-problem-title/`
- Generates `readme.md` with template
- Creates `solution.cpp` with C++ template
- Initializes `metrics.yml` with default values

#### Step 2: Solve Problem
1. **Learning Phase**: Read problem, identify pattern
2. **Implementation Phase**: Code solution
3. **Review Phase**: Test, optimize, document

#### Step 3: Update Metrics
```bash
python tools/update-metrics.py --problem-id 123 --attempts 2 --time 45 --pattern-mastery
```

**What it does**:
- Updates `metrics.yml` with new data
- Records sprint information
- Tracks pattern mastery status

### 2. Progress Tracking Workflow

#### Daily Workflow
```bash
# Morning: Review yesterday's progress
python tools/export-metrics.py --analyze --output daily-report.html

# Problem solving session
python tools/create-problem.py 124 "New Problem" Easy two-pointers
# ... solve problem ...
python tools/update-metrics.py --problem-id 124 --attempts 1 --time 30

# Evening: Update progress
python tools/export-metrics.py --problems-dir problems --output metrics.csv
```

#### Weekly Workflow
```bash
# Generate weekly report
python tools/weekly-report.py --input metrics.csv --output weekly-report.html

# Pattern analysis
python tools/pattern-analysis.py --input metrics.csv --output pattern-report.html

# Update mastery checklist
python tools/update-checklist.py --input metrics.csv --output checklist.md
```

### 3. Analysis and Reporting Workflow

#### Export Metrics
```bash
python tools/export-metrics.py --problems-dir problems --output metrics.csv --analyze
```

**Output**:
- CSV file with all problem metrics
- Analysis report with statistics
- Pattern mastery progress
- Time analysis and trends

#### Generate Reports
```bash
# Pattern frequency analysis
python tools/pattern-analysis.py --input metrics.csv --output pattern-report.html

# Learning curve analysis
python tools/learning-curve.py --input metrics.csv --output learning-curve.png

# Company-specific analysis
python tools/company-analysis.py --input metrics.csv --output company-report.html
```

## YAML Schema Validation

### Required Fields
```yaml
problem_id: int          # LeetCode problem ID
title: string            # Problem title
difficulty: string       # Easy/Medium/Hard
pattern: string          # Primary pattern used
attempts: int            # Number of attempts
total_time_min: int      # Total time spent
solved_date: string      # Date solved (YYYY-MM-DD)
```

### Optional Fields
```yaml
leetcode_url: string     # LeetCode URL
tags: [string]           # Problem tags
company_frequency: string # High/Medium/Low
pattern_mastery: bool    # Whether pattern is mastered
difficulty_rating: int   # Personal difficulty rating (1-5)
sprints: [object]        # Sprint information
complexity: object       # Time/space complexity
approach_summary: string # Brief approach description
key_insights: [string]   # Key learning points
alternative_approaches: [object] # Alternative solutions
edge_cases_handled: [string] # Edge cases considered
common_mistakes: [string] # Common mistakes to avoid
related_problems: [object] # Related problems
```

## Automation Scripts

### 1. create-problem.py
**Purpose**: Create new problem folders with templates

**Usage**:
```bash
python tools/create-problem.py <problem_id> <title> <difficulty> <pattern> [--tags]
```

**Example**:
```bash
python tools/create-problem.py 123 "Two Sum" Easy hash-map --tags array two-pointers
```

**Output**:
- Creates `problems/0123-two-sum/` folder
- Generates template files
- Initializes metrics.yml

### 2. export-metrics.py
**Purpose**: Export problem metrics to CSV and generate analysis

**Usage**:
```bash
python tools/export-metrics.py [--problems-dir] [--output] [--analyze]
```

**Example**:
```bash
python tools/export-metrics.py --problems-dir problems --output metrics.csv --analyze
```

**Output**:
- CSV file with all metrics
- Analysis report (if --analyze flag used)
- Statistics and trends

### 3. update-metrics.py
**Purpose**: Update metrics for existing problems

**Usage**:
```bash
python tools/update-metrics.py --problem-id <id> [options]
```

**Options**:
- `--attempts <n>`: Update number of attempts
- `--time <minutes>`: Update total time
- `--pattern-mastery`: Mark pattern as mastered
- `--sprint <duration>`: Add new sprint
- `--notes <text>`: Add notes

**Example**:
```bash
python tools/update-metrics.py --problem-id 123 --attempts 2 --time 45 --pattern-mastery --sprint 30 --notes "Solved with hash map approach"
```

### 4. pattern-analysis.py
**Purpose**: Analyze pattern usage and mastery

**Usage**:
```bash
python tools/pattern-analysis.py --input <csv> --output <html>
```

**Output**:
- Pattern frequency chart
- Mastery progress
- Time analysis per pattern
- Recommendations

### 5. learning-curve.py
**Purpose**: Generate learning curve visualization

**Usage**:
```bash
python tools/learning-curve.py --input <csv> --output <png>
```

**Output**:
- Learning curve chart
- Time per problem trend
- Difficulty progression
- Pattern mastery timeline

## Data Flow

### 1. Problem Creation Flow
```
User Input → create-problem.py → YAML Template → Problem Folder
```

### 2. Problem Solving Flow
```
Problem Folder → User Solves → update-metrics.py → Updated YAML
```

### 3. Analysis Flow
```
YAML Files → export-metrics.py → CSV Data → Analysis Scripts → Reports
```

### 4. Reporting Flow
```
CSV Data → Analysis Scripts → HTML/PNG Reports → User Review
```

## Integration with Web App

### Data API
The YAML files can be consumed by a web application:

```javascript
// Fetch problem data
fetch('/api/problems/123/metrics')
  .then(response => response.json())
  .then(data => {
    // Display problem metrics
    displayProblemMetrics(data);
  });

// Update metrics
fetch('/api/problems/123/metrics', {
  method: 'PUT',
  headers: { 'Content-Type': 'application/json' },
  body: JSON.stringify({
    attempts: 2,
    total_time_min: 45,
    pattern_mastery: true
  })
});
```

### Real-time Updates
```javascript
// WebSocket for real-time updates
const ws = new WebSocket('ws://localhost:8080/metrics');
ws.onmessage = (event) => {
  const data = JSON.parse(event.data);
  updateDashboard(data);
};
```

## Best Practices

### 1. YAML File Management
- Keep YAML files in sync with code changes
- Use consistent field names and formats
- Validate YAML syntax before committing
- Backup YAML files regularly

### 2. Tool Usage
- Run tools in the correct order
- Use descriptive commit messages
- Keep tool outputs organized
- Document custom tool modifications

### 3. Data Consistency
- Ensure problem IDs are unique
- Use consistent date formats
- Validate pattern names against master list
- Keep difficulty ratings consistent

### 4. Automation
- Set up automated daily reports
- Use cron jobs for regular exports
- Implement error handling in scripts
- Monitor tool performance

## Troubleshooting

### Common Issues

#### 1. YAML Syntax Errors
```bash
# Validate YAML syntax
python -c "import yaml; yaml.safe_load(open('metrics.yml'))"
```

#### 2. Missing Dependencies
```bash
# Install required packages
pip install pyyaml pandas matplotlib seaborn
```

#### 3. File Permission Issues
```bash
# Fix file permissions
chmod +x tools/*.py
```

#### 4. Data Inconsistency
```bash
# Validate data consistency
python tools/validate-data.py --problems-dir problems
```

### Error Handling
- Always validate input data
- Use try-catch blocks in scripts
- Log errors for debugging
- Provide meaningful error messages

## Future Enhancements

### Planned Features
1. **Web Interface**: Browser-based problem management
2. **Mobile App**: On-the-go problem solving
3. **AI Integration**: Automated pattern recognition
4. **Collaboration**: Team-based learning
5. **Gamification**: Points, badges, leaderboards

### Technical Improvements
1. **Database Integration**: SQLite/PostgreSQL backend
2. **API Development**: RESTful API for data access
3. **Real-time Sync**: WebSocket-based updates
4. **Cloud Storage**: AWS S3 integration
5. **Analytics**: Advanced data analysis

## Conclusion

The YAML workflow provides a structured, automated approach to managing your LeetCode learning journey. By following the established patterns and using the provided tools, you can:

- Track progress systematically
- Identify learning patterns
- Optimize study time
- Measure improvement
- Generate insights

This system scales from individual learning to team collaboration and provides the foundation for advanced features like web applications and mobile apps.
