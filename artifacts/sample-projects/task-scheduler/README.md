# Task Scheduler - Priority Queue & Heap Implementation

A demonstration of practical data structure usage in building a task scheduling system using Priority Queues, Heaps, and Hash Maps.

## Overview

This project implements a task scheduling system that can:
- Schedule tasks with different priorities
- Handle task dependencies
- Manage resource allocation
- Provide optimal scheduling algorithms
- Handle real-time task updates

## Data Structures Used

### 1. Priority Queue (Max Heap)
- **Purpose**: Schedule tasks by priority
- **Operations**: Insert, Extract Max, Peek
- **Time Complexity**: O(log n) for insert/extract, O(1) for peek
- **Space Complexity**: O(n) where n is number of tasks

### 2. Hash Map (Task Registry)
- **Purpose**: Map task IDs to task objects
- **Operations**: Insert, Find, Update, Delete
- **Time Complexity**: O(1) average case
- **Space Complexity**: O(n) where n is number of tasks

### 3. Queue (Task Queue)
- **Purpose**: FIFO task processing
- **Operations**: Enqueue, Dequeue, Front
- **Time Complexity**: O(1) for all operations
- **Space Complexity**: O(n)

### 4. Set (Dependency Tracking)
- **Purpose**: Track task dependencies
- **Operations**: Insert, Find, Delete
- **Time Complexity**: O(log n) for all operations
- **Space Complexity**: O(n)

## Implementation

### Task Structure
```cpp
struct Task {
    int id;
    string name;
    int priority;
    int duration;
    vector<int> dependencies;
    TaskStatus status;
    int startTime;
    int endTime;
    
    Task(int id, string name, int priority, int duration) 
        : id(id), name(name), priority(priority), duration(duration), 
          status(PENDING), startTime(0), endTime(0) {}
};
```

### Priority Queue Comparator
```cpp
struct TaskComparator {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority; // Max heap
    }
};
```

### Task Scheduler Class
```cpp
class TaskScheduler {
    priority_queue<Task, vector<Task>, TaskComparator> taskQueue;
    unordered_map<int, Task> taskRegistry;
    unordered_map<int, set<int>> dependencies;
    int currentTime;
    
public:
    void addTask(const Task& task);
    void addDependency(int taskId, int dependencyId);
    Task getNextTask();
    void executeTask(int taskId);
    vector<Task> getCompletedTasks();
    void printSchedule();
};
```

## Features

1. **Priority Scheduling**: Tasks scheduled by priority (highest first)
2. **Dependency Management**: Handle task dependencies
3. **Resource Allocation**: Manage system resources
4. **Real-time Updates**: Update task status in real-time
5. **Schedule Optimization**: Optimize task execution order

## Usage Example

```cpp
TaskScheduler scheduler;

// Add tasks
scheduler.addTask(Task(1, "Database Backup", 10, 30));
scheduler.addTask(Task(2, "User Authentication", 8, 15));
scheduler.addTask(Task(3, "Data Processing", 6, 45));
scheduler.addTask(Task(4, "Report Generation", 4, 20));

// Add dependencies
scheduler.addDependency(3, 1); // Data Processing depends on Database Backup
scheduler.addDependency(4, 3); // Report Generation depends on Data Processing

// Execute tasks
while (!scheduler.isEmpty()) {
    Task nextTask = scheduler.getNextTask();
    scheduler.executeTask(nextTask.id);
}

// Print final schedule
scheduler.printSchedule();
```

## Scheduling Algorithms

### 1. Priority Scheduling
- Tasks executed in priority order
- Higher priority tasks preempt lower priority ones
- Suitable for real-time systems

### 2. Round Robin
- Tasks executed in time slices
- Fair scheduling for equal priority tasks
- Prevents starvation

### 3. Shortest Job First
- Tasks with shorter duration executed first
- Minimizes average waiting time
- Optimal for batch processing

### 4. Earliest Deadline First
- Tasks with earliest deadline executed first
- Suitable for real-time systems
- Minimizes deadline misses

## Performance Analysis

### Scheduling Performance
- **Time**: O(n log n) for priority scheduling
- **Space**: O(n) for task storage
- **Memory**: O(n) for dependency tracking

### Task Execution Performance
- **Insertion**: O(log n) for priority queue
- **Extraction**: O(log n) for priority queue
- **Dependency Check**: O(log n) for set operations

## Learning Objectives

1. **Heap Operations**: Understand priority queue implementation
2. **Hash Map Efficiency**: See the power of hash maps for fast lookups
3. **Dependency Management**: Learn to handle complex relationships
4. **Scheduling Algorithms**: Understand different scheduling strategies
5. **System Design**: Learn basic operating system concepts

## Extensions

1. **Multi-threading**: Support for concurrent task execution
2. **Resource Management**: Handle limited system resources
3. **Load Balancing**: Distribute tasks across multiple processors
4. **Fault Tolerance**: Handle task failures and recovery
5. **Monitoring**: Real-time task monitoring and metrics

## Related LeetCode Problems

- [Task Scheduler](https://leetcode.com/problems/task-scheduler/)
- [Course Schedule](https://leetcode.com/problems/course-schedule/)
- [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/)
- [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
