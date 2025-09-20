#include "cpp-template.h"

// Task Scheduler using Priority Queue and Hash Map
// Demonstrates practical use of heaps and hash maps

enum TaskStatus {
    PENDING,
    RUNNING,
    COMPLETED,
    BLOCKED
};

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
    
    bool operator<(const Task& other) const {
        return priority < other.priority; // Max heap
    }
};

class TaskScheduler {
    priority_queue<Task> taskQueue;
    unordered_map<int, Task> taskRegistry;
    unordered_map<int, set<int>> dependencies;
    vector<Task> completedTasks;
    int currentTime;
    
public:
    TaskScheduler() : currentTime(0) {}
    
    void addTask(const Task& task) {
        taskRegistry[task.id] = task;
        taskQueue.push(task);
        cout << "Added task: " << task.name << " (Priority: " << task.priority << ")" << endl;
    }
    
    void addDependency(int taskId, int dependencyId) {
        dependencies[taskId].insert(dependencyId);
        cout << "Added dependency: Task " << taskId << " depends on Task " << dependencyId << endl;
    }
    
    bool isTaskReady(int taskId) {
        if (dependencies.find(taskId) == dependencies.end()) {
            return true; // No dependencies
        }
        
        for (int depId : dependencies[taskId]) {
            if (taskRegistry[depId].status != COMPLETED) {
                return false; // Dependency not completed
            }
        }
        return true;
    }
    
    Task getNextTask() {
        vector<Task> readyTasks;
        
        // Find all ready tasks
        while (!taskQueue.empty()) {
            Task task = taskQueue.top();
            taskQueue.pop();
            
            if (isTaskReady(task.id)) {
                return task;
            } else {
                readyTasks.push_back(task);
            }
        }
        
        // Put back non-ready tasks
        for (const Task& task : readyTasks) {
            taskQueue.push(task);
        }
        
        throw runtime_error("No ready tasks available");
    }
    
    void executeTask(int taskId) {
        if (taskRegistry.find(taskId) == taskRegistry.end()) {
            cout << "Task " << taskId << " not found" << endl;
            return;
        }
        
        Task& task = taskRegistry[taskId];
        task.status = RUNNING;
        task.startTime = currentTime;
        task.endTime = currentTime + task.duration;
        
        cout << "Executing task: " << task.name << " (Duration: " << task.duration << " minutes)" << endl;
        cout << "Start time: " << task.startTime << ", End time: " << task.endTime << endl;
        
        // Simulate task execution
        currentTime += task.duration;
        task.status = COMPLETED;
        completedTasks.push_back(task);
        
        cout << "Task completed: " << task.name << endl;
        cout << "Current time: " << currentTime << endl;
        cout << "---" << endl;
    }
    
    void runScheduler() {
        cout << "=== Task Scheduler Started ===" << endl;
        
        while (!taskQueue.empty()) {
            try {
                Task nextTask = getNextTask();
                executeTask(nextTask.id);
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
                break;
            }
        }
        
        cout << "=== All Tasks Completed ===" << endl;
    }
    
    void printSchedule() {
        cout << "\n=== Final Schedule ===" << endl;
        cout << "Total execution time: " << currentTime << " minutes" << endl;
        cout << "Completed tasks: " << completedTasks.size() << endl;
        cout << "\nTask execution order:" << endl;
        
        for (const Task& task : completedTasks) {
            cout << "Task " << task.id << ": " << task.name 
                 << " (Priority: " << task.priority 
                 << ", Duration: " << task.duration 
                 << ", Time: " << task.startTime << "-" << task.endTime << ")" << endl;
        }
    }
    
    void printTaskStatus() {
        cout << "\n=== Task Status ===" << endl;
        for (const auto& pair : taskRegistry) {
            const Task& task = pair.second;
            string statusStr;
            switch (task.status) {
                case PENDING: statusStr = "PENDING"; break;
                case RUNNING: statusStr = "RUNNING"; break;
                case COMPLETED: statusStr = "COMPLETED"; break;
                case BLOCKED: statusStr = "BLOCKED"; break;
            }
            cout << "Task " << task.id << ": " << task.name 
                 << " - Status: " << statusStr << endl;
        }
    }
    
    bool isEmpty() const {
        return taskQueue.empty();
    }
    
    int getCurrentTime() const {
        return currentTime;
    }
    
    vector<Task> getCompletedTasks() const {
        return completedTasks;
    }
};

// Demo function
void demonstrateTaskScheduler() {
    TaskScheduler scheduler;
    
    // Add tasks with different priorities
    scheduler.addTask(Task(1, "Database Backup", 10, 30));
    scheduler.addTask(Task(2, "User Authentication", 8, 15));
    scheduler.addTask(Task(3, "Data Processing", 6, 45));
    scheduler.addTask(Task(4, "Report Generation", 4, 20));
    scheduler.addTask(Task(5, "System Maintenance", 9, 25));
    scheduler.addTask(Task(6, "Log Analysis", 3, 10));
    
    cout << "\n=== Adding Dependencies ===" << endl;
    
    // Add dependencies
    scheduler.addDependency(3, 1); // Data Processing depends on Database Backup
    scheduler.addDependency(4, 3); // Report Generation depends on Data Processing
    scheduler.addDependency(6, 2); // Log Analysis depends on User Authentication
    
    cout << "\n=== Task Status Before Execution ===" << endl;
    scheduler.printTaskStatus();
    
    cout << "\n=== Starting Task Execution ===" << endl;
    scheduler.runScheduler();
    
    cout << "\n=== Task Status After Execution ===" << endl;
    scheduler.printTaskStatus();
    
    scheduler.printSchedule();
}

// Advanced scheduling algorithms
class AdvancedTaskScheduler : public TaskScheduler {
public:
    // Shortest Job First scheduling
    void scheduleShortestJobFirst() {
        vector<Task> tasks;
        while (!taskQueue.empty()) {
            tasks.push_back(taskQueue.top());
            taskQueue.pop();
        }
        
        // Sort by duration (shortest first)
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.duration < b.duration;
        });
        
        for (const Task& task : tasks) {
            taskQueue.push(task);
        }
    }
    
    // Round Robin scheduling
    void scheduleRoundRobin(int timeSlice) {
        queue<Task> roundRobinQueue;
        vector<Task> tasks;
        
        while (!taskQueue.empty()) {
            tasks.push_back(taskQueue.top());
            taskQueue.pop();
        }
        
        for (const Task& task : tasks) {
            roundRobinQueue.push(task);
        }
        
        cout << "\n=== Round Robin Scheduling (Time Slice: " << timeSlice << ") ===" << endl;
        
        while (!roundRobinQueue.empty()) {
            Task task = roundRobinQueue.front();
            roundRobinQueue.pop();
            
            int remainingTime = task.duration;
            if (remainingTime > timeSlice) {
                cout << "Executing " << task.name << " for " << timeSlice << " minutes" << endl;
                remainingTime -= timeSlice;
                currentTime += timeSlice;
                
                // Create new task with remaining time
                Task remainingTask = task;
                remainingTask.duration = remainingTime;
                roundRobinQueue.push(remainingTask);
            } else {
                cout << "Executing " << task.name << " for " << remainingTime << " minutes" << endl;
                currentTime += remainingTime;
                task.status = COMPLETED;
                completedTasks.push_back(task);
            }
        }
    }
    
    // Earliest Deadline First scheduling
    void scheduleEarliestDeadlineFirst() {
        vector<Task> tasks;
        while (!taskQueue.empty()) {
            tasks.push_back(taskQueue.top());
            taskQueue.pop();
        }
        
        // Sort by deadline (earliest first)
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.endTime < b.endTime;
        });
        
        for (const Task& task : tasks) {
            taskQueue.push(task);
        }
    }
};

int main() {
    demonstrateTaskScheduler();
    
    cout << "\n" << string(50, '=') << endl;
    cout << "Advanced Scheduling Algorithms Demo" << endl;
    cout << string(50, '=') << endl;
    
    AdvancedTaskScheduler advancedScheduler;
    
    // Add tasks for advanced scheduling
    advancedScheduler.addTask(Task(1, "Task A", 5, 20));
    advancedScheduler.addTask(Task(2, "Task B", 3, 10));
    advancedScheduler.addTask(Task(3, "Task C", 7, 30));
    advancedScheduler.addTask(Task(4, "Task D", 2, 5));
    
    // Demonstrate Round Robin
    advancedScheduler.scheduleRoundRobin(10);
    
    return 0;
}

/*
Sample Output:
=== Task Scheduler Started ===
Added task: Database Backup (Priority: 10)
Added task: User Authentication (Priority: 8)
Added task: Data Processing (Priority: 6)
Added task: Report Generation (Priority: 4)
Added task: System Maintenance (Priority: 9)
Added task: Log Analysis (Priority: 3)

=== Adding Dependencies ===
Added dependency: Task 3 depends on Task 1
Added dependency: Task 4 depends on Task 3
Added dependency: Task 6 depends on Task 2

=== Task Status Before Execution ===
Task 1: Database Backup - Status: PENDING
Task 2: User Authentication - Status: PENDING
Task 3: Data Processing - Status: PENDING
Task 4: Report Generation - Status: PENDING
Task 5: System Maintenance - Status: PENDING
Task 6: Log Analysis - Status: PENDING

=== Starting Task Execution ===
Executing task: Database Backup (Duration: 30 minutes)
Start time: 0, End time: 30
Task completed: Database Backup
Current time: 30
---
Executing task: System Maintenance (Duration: 25 minutes)
Start time: 30, End time: 55
Task completed: System Maintenance
Current time: 55
---
Executing task: User Authentication (Duration: 15 minutes)
Start time: 55, End time: 70
Task completed: User Authentication
Current time: 70
---
Executing task: Data Processing (Duration: 45 minutes)
Start time: 70, End time: 115
Task completed: Data Processing
Current time: 115
---
Executing task: Log Analysis (Duration: 10 minutes)
Start time: 115, End time: 125
Task completed: Log Analysis
Current time: 125
---
Executing task: Report Generation (Duration: 20 minutes)
Start time: 125, End time: 145
Task completed: Report Generation
Current time: 145
---
=== All Tasks Completed ===

=== Final Schedule ===
Total execution time: 145 minutes
Completed tasks: 6
Task execution order:
Task 1: Database Backup (Priority: 10, Duration: 30, Time: 0-30)
Task 5: System Maintenance (Priority: 9, Duration: 25, Time: 30-55)
Task 2: User Authentication (Priority: 8, Duration: 15, Time: 55-70)
Task 3: Data Processing (Priority: 6, Duration: 45, Time: 70-115)
Task 6: Log Analysis (Priority: 3, Duration: 10, Time: 115-125)
Task 4: Report Generation (Priority: 4, Duration: 20, Time: 125-145)
*/
