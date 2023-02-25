#include<bits/stdc++.h>
using namespace std;

class CourseSchedule {
public:
    static void buildGraph(int v, vector<vector<int>> edges, vector<vector<int>>& graph, unordered_map<int, int>& indegree) {
        
        for(int i = 0; i < v; i++) {
            vector<int> v;
            graph.push_back(v);
            indegree[i] = 0;
        }
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]] += 1;
        }
    }

    static bool canBeDone(int v, vector<vector<int>> edges) {
        vector<vector<int>> graph;
        unordered_map<int, int> indegree;
        CourseSchedule::buildGraph(v, edges, graph, indegree);
        
        queue<int> q;
        for(auto pair : indegree) {
            if(pair.second == 0) {
                q.push(pair.first);
            }
        }

        vector<int> sortedOrder;
        while(!q.empty()) {
            int currNode = q.front();
            sortedOrder.push_back(currNode);
            q.pop();
            for(auto nbr : graph[currNode]) {
                indegree[nbr] -= 1;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if(sortedOrder.size() == v) return true;
        else return false;
    }
};


int main() {
    int v = 7;
    vector<vector<int>> edges{{5, 1}, {5, 2}, {6, 2}, {6, 3}, {1, 4}, {2, 0}, {3, 0}, {0, 3}};
    cout << CourseSchedule::canBeDone(v, edges);
    return 0;
}        