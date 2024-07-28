/*Question:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi]
 indicates that you must take course bi first if you want to take course ai.*/

 #include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> visited(numCourses, 0);

        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (hasCycle(graph, visited, i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool hasCycle(const std::vector<std::vector<int>>& graph, std::vector<int>& visited, int node) {
        if (visited[node] == 1) {
            return true; // Found a cycle
        }
        if (visited[node] == 2) {
            return false; // Already visited node with no cycle
        }

        visited[node] = 1; // Mark node as visiting

        for (int neighbor : graph[node]) {
            if (hasCycle(graph, visited, neighbor)) {
                return true;
            }
        }

        visited[node] = 2; // Mark node as visited with no cycle
        return false;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * bool param_1 = obj->canFinish(numCourses, prerequisites);
 */