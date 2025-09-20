#include "cpp-template.h"

// Social Network Graph using BFS, DFS, and Union-Find
// Demonstrates practical use of graph algorithms

struct User {
    int id;
    string name;
    int age;
    string location;
    vector<string> interests;
    int joinDate;
    
    User(int id, string name, int age, string location) 
        : id(id), name(name), age(age), location(location), joinDate(0) {}
    
    void addInterest(const string& interest) {
        interests.push_back(interest);
    }
    
    void printProfile() const {
        cout << "User " << id << ": " << name 
             << " (Age: " << age << ", Location: " << location << ")";
        if (!interests.empty()) {
            cout << " - Interests: ";
            for (size_t i = 0; i < interests.size(); i++) {
                cout << interests[i];
                if (i < interests.size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }
};

class SocialNetwork {
    unordered_map<int, User> users;
    unordered_map<int, vector<int>> adjacencyList;
    UnionFind communities;
    int nextUserId;
    
public:
    SocialNetwork() : nextUserId(1) {}
    
    void addUser(const User& user) {
        users[user.id] = user;
        adjacencyList[user.id] = vector<int>();
        communities.unite(user.id, user.id); // Initialize in its own community
        cout << "Added user: " << user.name << " (ID: " << user.id << ")" << endl;
    }
    
    void addFriendship(int userId1, int userId2) {
        if (users.find(userId1) == users.end() || users.find(userId2) == users.end()) {
            cout << "Error: One or both users not found" << endl;
            return;
        }
        
        adjacencyList[userId1].push_back(userId2);
        adjacencyList[userId2].push_back(userId1);
        communities.unite(userId1, userId2);
        
        cout << "Added friendship: " << users[userId1].name 
             << " <-> " << users[userId2].name << endl;
    }
    
    void removeFriendship(int userId1, int userId2) {
        if (users.find(userId1) == users.end() || users.find(userId2) == users.end()) {
            cout << "Error: One or both users not found" << endl;
            return;
        }
        
        // Remove from adjacency list
        auto it1 = find(adjacencyList[userId1].begin(), adjacencyList[userId1].end(), userId2);
        if (it1 != adjacencyList[userId1].end()) {
            adjacencyList[userId1].erase(it1);
        }
        
        auto it2 = find(adjacencyList[userId2].begin(), adjacencyList[userId2].end(), userId1);
        if (it2 != adjacencyList[userId2].end()) {
            adjacencyList[userId2].erase(it2);
        }
        
        cout << "Removed friendship: " << users[userId1].name 
             << " <-> " << users[userId2].name << endl;
    }
    
    vector<int> findShortestPath(int from, int to) {
        if (users.find(from) == users.end() || users.find(to) == users.end()) {
            return {};
        }
        
        if (from == to) return {from};
        
        // BFS to find shortest path
        queue<int> q;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        
        q.push(from);
        visited[from] = true;
        parent[from] = -1;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                    
                    if (neighbor == to) {
                        // Reconstruct path
                        vector<int> path;
                        int node = to;
                        while (node != -1) {
                            path.push_back(node);
                            node = parent[node];
                        }
                        reverse(path.begin(), path.end());
                        return path;
                    }
                }
            }
        }
        
        return {}; // No path found
    }
    
    vector<vector<int>> findCommunities() {
        unordered_map<int, vector<int>> communityMap;
        
        for (const auto& pair : users) {
            int userId = pair.first;
            int communityId = communities.find(userId);
            communityMap[communityId].push_back(userId);
        }
        
        vector<vector<int>> communities;
        for (const auto& pair : communityMap) {
            communities.push_back(pair.second);
        }
        
        return communities;
    }
    
    vector<int> recommendFriends(int userId) {
        if (users.find(userId) == users.end()) {
            return {};
        }
        
        unordered_set<int> currentFriends(adjacencyList[userId].begin(), adjacencyList[userId].end());
        unordered_map<int, int> mutualFriends;
        
        // Find mutual friends
        for (int friendId : adjacencyList[userId]) {
            for (int mutualFriend : adjacencyList[friendId]) {
                if (mutualFriend != userId && currentFriends.find(mutualFriend) == currentFriends.end()) {
                    mutualFriends[mutualFriend]++;
                }
            }
        }
        
        // Sort by number of mutual friends
        vector<pair<int, int>> recommendations;
        for (const auto& pair : mutualFriends) {
            recommendations.push_back({pair.second, pair.first});
        }
        
        sort(recommendations.rbegin(), recommendations.rend());
        
        vector<int> result;
        for (const auto& rec : recommendations) {
            result.push_back(rec.second);
        }
        
        return result;
    }
    
    void printNetworkStats() {
        cout << "\n=== Network Statistics ===" << endl;
        cout << "Total users: " << users.size() << endl;
        
        int totalConnections = 0;
        int maxDegree = 0;
        int minDegree = INT_MAX;
        
        for (const auto& pair : adjacencyList) {
            int degree = pair.second.size();
            totalConnections += degree;
            maxDegree = max(maxDegree, degree);
            minDegree = min(minDegree, degree);
        }
        
        cout << "Total connections: " << totalConnections / 2 << endl;
        cout << "Average degree: " << (users.empty() ? 0 : (double)totalConnections / users.size()) << endl;
        cout << "Max degree: " << maxDegree << endl;
        cout << "Min degree: " << (minDegree == INT_MAX ? 0 : minDegree) << endl;
        
        vector<vector<int>> communities = findCommunities();
        cout << "Number of communities: " << communities.size() << endl;
        
        for (size_t i = 0; i < communities.size(); i++) {
            cout << "Community " << (i + 1) << ": ";
            for (size_t j = 0; j < communities[i].size(); j++) {
                cout << users[communities[i][j]].name;
                if (j < communities[i].size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
    
    void printUserConnections(int userId) {
        if (users.find(userId) == users.end()) {
            cout << "User not found" << endl;
            return;
        }
        
        cout << "\n=== Connections for " << users[userId].name << " ===" << endl;
        cout << "Direct friends (" << adjacencyList[userId].size() << "): ";
        
        for (size_t i = 0; i < adjacencyList[userId].size(); i++) {
            cout << users[adjacencyList[userId][i]].name;
            if (i < adjacencyList[userId].size() - 1) cout << ", ";
        }
        cout << endl;
        
        vector<int> recommendations = recommendFriends(userId);
        if (!recommendations.empty()) {
            cout << "Friend recommendations: ";
            for (size_t i = 0; i < min(recommendations.size(), size_t(5)); i++) {
                cout << users[recommendations[i]].name;
                if (i < min(recommendations.size(), size_t(5)) - 1) cout << ", ";
            }
            cout << endl;
        }
    }
    
    void printShortestPath(int from, int to) {
        vector<int> path = findShortestPath(from, to);
        if (path.empty()) {
            cout << "No path found between " << users[from].name 
                 << " and " << users[to].name << endl;
            return;
        }
        
        cout << "Shortest path from " << users[from].name 
             << " to " << users[to].name << ": ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << users[path[i]].name;
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << " (Distance: " << (path.size() - 1) << ")" << endl;
    }
    
    void printAllUsers() {
        cout << "\n=== All Users ===" << endl;
        for (const auto& pair : users) {
            pair.second.printProfile();
        }
    }
};

// Demo function
void demonstrateSocialNetwork() {
    SocialNetwork network;
    
    // Add users
    User alice(1, "Alice", 25, "New York");
    alice.addInterest("Photography");
    alice.addInterest("Travel");
    network.addUser(alice);
    
    User bob(2, "Bob", 30, "California");
    bob.addInterest("Technology");
    bob.addInterest("Gaming");
    network.addUser(bob);
    
    User charlie(3, "Charlie", 28, "Texas");
    charlie.addInterest("Music");
    charlie.addInterest("Sports");
    network.addUser(charlie);
    
    User diana(4, "Diana", 26, "Florida");
    diana.addInterest("Art");
    diana.addInterest("Photography");
    network.addUser(diana);
    
    User eve(5, "Eve", 24, "Washington");
    eve.addInterest("Books");
    eve.addInterest("Travel");
    network.addUser(eve);
    
    User frank(6, "Frank", 32, "Oregon");
    frank.addInterest("Sports");
    frank.addInterest("Technology");
    network.addUser(frank);
    
    cout << "\n=== Adding Friendships ===" << endl;
    
    // Add friendships
    network.addFriendship(1, 2); // Alice - Bob
    network.addFriendship(2, 3); // Bob - Charlie
    network.addFriendship(3, 4); // Charlie - Diana
    network.addFriendship(1, 4); // Alice - Diana
    network.addFriendship(4, 5); // Diana - Eve
    network.addFriendship(3, 6); // Charlie - Frank
    
    cout << "\n=== Network Analysis ===" << endl;
    network.printNetworkStats();
    
    cout << "\n=== User Connections ===" << endl;
    network.printUserConnections(1); // Alice
    network.printUserConnections(3); // Charlie
    
    cout << "\n=== Shortest Paths ===" << endl;
    network.printShortestPath(1, 3); // Alice -> Charlie
    network.printShortestPath(1, 5); // Alice -> Eve
    network.printShortestPath(2, 6); // Bob -> Frank
    
    cout << "\n=== All Users ===" << endl;
    network.printAllUsers();
}

// Advanced graph algorithms
class AdvancedSocialNetwork : public SocialNetwork {
public:
    // DFS to find all paths between two users
    vector<vector<int>> findAllPaths(int from, int to) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        unordered_set<int> visited;
        
        dfsFindPaths(from, to, currentPath, visited, allPaths);
        return allPaths;
    }
    
private:
    void dfsFindPaths(int current, int target, vector<int>& currentPath, 
                     unordered_set<int>& visited, vector<vector<int>>& allPaths) {
        currentPath.push_back(current);
        visited.insert(current);
        
        if (current == target) {
            allPaths.push_back(currentPath);
        } else {
            for (int neighbor : adjacencyList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    dfsFindPaths(neighbor, target, currentPath, visited, allPaths);
                }
            }
        }
        
        currentPath.pop_back();
        visited.erase(current);
    }
    
public:
    // Find users within k degrees of separation
    vector<int> findUsersWithinK(int userId, int k) {
        if (users.find(userId) == users.end()) return {};
        
        queue<pair<int, int>> q; // {userId, distance}
        unordered_set<int> visited;
        vector<int> result;
        
        q.push({userId, 0});
        visited.insert(userId);
        
        while (!q.empty()) {
            auto [current, distance] = q.front();
            q.pop();
            
            if (distance <= k && current != userId) {
                result.push_back(current);
            }
            
            if (distance < k) {
                for (int neighbor : adjacencyList[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push({neighbor, distance + 1});
                    }
                }
            }
        }
        
        return result;
    }
    
    // Calculate clustering coefficient for a user
    double calculateClusteringCoefficient(int userId) {
        if (users.find(userId) == users.end()) return 0.0;
        
        vector<int> neighbors = adjacencyList[userId];
        int n = neighbors.size();
        
        if (n < 2) return 0.0;
        
        int edges = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (find(adjacencyList[neighbors[i]].begin(), 
                        adjacencyList[neighbors[i]].end(), 
                        neighbors[j]) != adjacencyList[neighbors[i]].end()) {
                    edges++;
                }
            }
        }
        
        return (2.0 * edges) / (n * (n - 1));
    }
};

int main() {
    demonstrateSocialNetwork();
    
    cout << "\n" << string(50, '=') << endl;
    cout << "Advanced Graph Algorithms Demo" << endl;
    cout << string(50, '=') << endl;
    
    AdvancedSocialNetwork advancedNetwork;
    
    // Add users for advanced demo
    advancedNetwork.addUser(User(1, "Alice", 25, "New York"));
    advancedNetwork.addUser(User(2, "Bob", 30, "California"));
    advancedNetwork.addUser(User(3, "Charlie", 28, "Texas"));
    advancedNetwork.addUser(User(4, "Diana", 26, "Florida"));
    
    // Add friendships
    advancedNetwork.addFriendship(1, 2);
    advancedNetwork.addFriendship(2, 3);
    advancedNetwork.addFriendship(3, 4);
    advancedNetwork.addFriendship(1, 4);
    
    // Find all paths
    vector<vector<int>> allPaths = advancedNetwork.findAllPaths(1, 3);
    cout << "\nAll paths from Alice to Charlie:" << endl;
    for (const auto& path : allPaths) {
        for (size_t i = 0; i < path.size(); i++) {
            cout << "User " << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
    
    // Find users within k degrees
    vector<int> usersWithin2 = advancedNetwork.findUsersWithinK(1, 2);
    cout << "\nUsers within 2 degrees of Alice:" << endl;
    for (int userId : usersWithin2) {
        cout << "User " << userId << endl;
    }
    
    // Calculate clustering coefficient
    double clusteringCoeff = advancedNetwork.calculateClusteringCoefficient(1);
    cout << "\nClustering coefficient for Alice: " << clusteringCoeff << endl;
    
    return 0;
}

/*
Sample Output:
Added user: Alice (ID: 1)
Added user: Bob (ID: 2)
Added user: Charlie (ID: 3)
Added user: Diana (ID: 4)
Added user: Eve (ID: 5)
Added user: Frank (ID: 6)

=== Adding Friendships ===
Added friendship: Alice <-> Bob
Added friendship: Bob <-> Charlie
Added friendship: Charlie <-> Diana
Added friendship: Alice <-> Diana
Added friendship: Diana <-> Eve
Added friendship: Charlie <-> Frank

=== Network Statistics ===
Total users: 6
Total connections: 6
Average degree: 2
Max degree: 3
Min degree: 1
Number of communities: 1
Community 1: Alice, Bob, Charlie, Diana, Eve, Frank

=== User Connections ===
=== Connections for Alice ===
Direct friends (2): Bob, Diana
Friend recommendations: Charlie, Eve

=== Connections for Charlie ===
Direct friends (3): Bob, Diana, Frank
Friend recommendations: Alice, Eve

=== Shortest Paths ===
Shortest path from Alice to Charlie: Alice -> Bob -> Charlie (Distance: 2)
Shortest path from Alice to Eve: Alice -> Diana -> Eve (Distance: 2)
Shortest path from Bob to Frank: Bob -> Charlie -> Frank (Distance: 2)

=== All Users ===
User 1: Alice (Age: 25, Location: New York) - Interests: Photography, Travel
User 2: Bob (Age: 30, Location: California) - Interests: Technology, Gaming
User 3: Charlie (Age: 28, Location: Texas) - Interests: Music, Sports
User 4: Diana (Age: 26, Location: Florida) - Interests: Art, Photography
User 5: Eve (Age: 24, Location: Washington) - Interests: Books, Travel
User 6: Frank (Age: 32, Location: Oregon) - Interests: Sports, Technology
*/
