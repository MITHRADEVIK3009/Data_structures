#!/usr/bin/env python3
"""
Export metrics from problem folders to CSV format for analysis.
"""

import os
import yaml
import csv
import pandas as pd
from pathlib import Path
import argparse

def extract_metrics_from_problem(problem_dir):
    """Extract metrics from a single problem directory."""
    metrics_file = problem_dir / "metrics.yml"
    readme_file = problem_dir / "readme.md"
    
    if not metrics_file.exists():
        return None
    
    try:
        with open(metrics_file, 'r') as f:
            metrics = yaml.safe_load(f)
        
        # Extract basic metrics
        result = {
            'problem_id': metrics.get('problem_id', ''),
            'title': metrics.get('title', ''),
            'leetcode_url': metrics.get('leetcode_url', ''),
            'difficulty': metrics.get('difficulty', ''),
            'pattern': metrics.get('pattern', ''),
            'company_frequency': metrics.get('company_frequency', ''),
            'attempts': metrics.get('attempts', 0),
            'total_time_min': metrics.get('total_time_min', 0),
            'solved_date': metrics.get('solved_date', ''),
            'pattern_mastery': metrics.get('pattern_mastery', False),
            'difficulty_rating': metrics.get('difficulty_rating', 0)
        }
        
        # Extract sprint information
        sprints = metrics.get('sprints', [])
        if sprints:
            result['total_sprints'] = len(sprints)
            result['avg_sprint_time'] = sum(s['duration_min'] for s in sprints) / len(sprints)
            result['first_sprint_date'] = sprints[0]['date']
            result['last_sprint_date'] = sprints[-1]['date']
        else:
            result['total_sprints'] = 0
            result['avg_sprint_time'] = 0
            result['first_sprint_date'] = ''
            result['last_sprint_date'] = ''
        
        # Extract complexity information
        complexity = metrics.get('complexity', {})
        result['time_complexity'] = complexity.get('time', '')
        result['space_complexity'] = complexity.get('space', '')
        
        return result
        
    except Exception as e:
        print(f"Error processing {problem_dir}: {e}")
        return None

def export_metrics_to_csv(problems_dir, output_file):
    """Export all problem metrics to CSV."""
    problems_path = Path(problems_dir)
    
    if not problems_path.exists():
        print(f"Problems directory {problems_dir} does not exist")
        return
    
    all_metrics = []
    
    # Iterate through all problem directories
    for problem_dir in problems_path.iterdir():
        if problem_dir.is_dir() and problem_dir.name.startswith('000'):
            metrics = extract_metrics_from_problem(problem_dir)
            if metrics:
                all_metrics.append(metrics)
    
    if not all_metrics:
        print("No metrics found")
        return
    
    # Write to CSV
    fieldnames = [
        'problem_id', 'title', 'leetcode_url', 'difficulty', 'pattern',
        'company_frequency', 'attempts', 'total_time_min', 'solved_date',
        'pattern_mastery', 'difficulty_rating', 'total_sprints',
        'avg_sprint_time', 'first_sprint_date', 'last_sprint_date',
        'time_complexity', 'space_complexity'
    ]
    
    with open(output_file, 'w', newline='') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(all_metrics)
    
    print(f"Exported {len(all_metrics)} problems to {output_file}")

def generate_analysis_report(csv_file):
    """Generate analysis report from CSV data."""
    df = pd.read_csv(csv_file)
    
    print("=== Problem Solving Analysis Report ===\n")
    
    # Basic statistics
    print(f"Total Problems Solved: {len(df)}")
    print(f"Total Time Spent: {df['total_time_min'].sum()} minutes")
    print(f"Average Time per Problem: {df['total_time_min'].mean():.1f} minutes")
    print(f"Total Attempts: {df['attempts'].sum()}")
    print(f"Average Attempts per Problem: {df['attempts'].mean():.1f}\n")
    
    # Difficulty distribution
    print("=== Difficulty Distribution ===")
    difficulty_counts = df['difficulty'].value_counts()
    for difficulty, count in difficulty_counts.items():
        print(f"{difficulty}: {count} problems")
    print()
    
    # Pattern distribution
    print("=== Pattern Distribution ===")
    pattern_counts = df['pattern'].value_counts()
    for pattern, count in pattern_counts.items():
        print(f"{pattern}: {count} problems")
    print()
    
    # Company frequency
    print("=== Company Frequency Distribution ===")
    company_counts = df['company_frequency'].value_counts()
    for company, count in company_counts.items():
        print(f"{company}: {count} problems")
    print()
    
    # Pattern mastery
    print("=== Pattern Mastery ===")
    mastered_patterns = df[df['pattern_mastery'] == True]['pattern'].value_counts()
    total_patterns = df['pattern'].value_counts()
    
    for pattern in total_patterns.index:
        mastered = mastered_patterns.get(pattern, 0)
        total = total_patterns[pattern]
        mastery_rate = (mastered / total) * 100 if total > 0 else 0
        print(f"{pattern}: {mastered}/{total} ({mastery_rate:.1f}%)")
    print()
    
    # Time analysis
    print("=== Time Analysis ===")
    print(f"Fastest solve: {df['total_time_min'].min()} minutes")
    print(f"Slowest solve: {df['total_time_min'].max()} minutes")
    print(f"Median time: {df['total_time_min'].median():.1f} minutes")
    print()
    
    # Recent activity
    print("=== Recent Activity ===")
    df['solved_date'] = pd.to_datetime(df['solved_date'])
    recent_problems = df[df['solved_date'] >= df['solved_date'].max() - pd.Timedelta(days=7)]
    print(f"Problems solved in last 7 days: {len(recent_problems)}")
    
    if len(recent_problems) > 0:
        print("Recent problems:")
        for _, problem in recent_problems.iterrows():
            print(f"  - {problem['title']} ({problem['difficulty']})")

def main():
    parser = argparse.ArgumentParser(description='Export and analyze problem-solving metrics')
    parser.add_argument('--problems-dir', default='problems', help='Directory containing problem folders')
    parser.add_argument('--output', default='metrics.csv', help='Output CSV file')
    parser.add_argument('--analyze', action='store_true', help='Generate analysis report')
    
    args = parser.parse_args()
    
    # Export metrics to CSV
    export_metrics_to_csv(args.problems_dir, args.output)
    
    # Generate analysis report if requested
    if args.analyze:
        generate_analysis_report(args.output)

if __name__ == "__main__":
    main()
