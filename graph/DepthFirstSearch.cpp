#include<bits/stdc++.h>
using namespace std;

class DepthFirstSearch {
public:

    static vector<vector<int>> buildGraph(int v, vector<vector<int>>& edges) {
        vector<vector<int>> graph;
        for(int i = 0; i < v; i++) {
            vector<int> v;
            graph.push_back(v);
        }
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); // remove if directed
        }
        return graph;
    }

    static vector<int> bfs(int n, int m, vector<vector<int>>& edges, int src) {
        vector<vector<int>> graph = DepthFirstSearch::buildGraph(n, edges);

        queue<int> q;
        vector<int> distance(n + 1, -1);
        vector<bool> visited(n + 1, false);

        q.push(src);
        distance[src] = 0;
        visited[src] = true;

        while(!q.empty()) {
            int currNode = q.front();
            q.pop();

            for(auto nbr : graph[currNode]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    distance[nbr] = distance[currNode] + 6;
                }
            }
        }
        return distance;
    }

    static void dfs(int node, vector<bool> &visited, vector<vector<int>> &graph, vector<int> &dfsAns) {
        visited[node] = true;
        dfsAns.push_back(node);

        for(auto nbr : graph[node]) {
            if(!visited[nbr]) {
                dfs(nbr, visited, graph, dfsAns);
            }
        }
    }

    static vector<int> depthFirstSearch(int v, vector<vector<int>> edges, int src) {
        vector<vector<int>> graph = buildGraph(v, edges);
        vector<bool> visited(v, false);
        vector<int> dfsAns;
        // for(int i = 1; i <= v; i++) {
        //     if(!visited[i])
                
        // }
        dfs(src, visited, graph, dfsAns);    
        return dfsAns;
    }
    
};

int main(int argc, char const *argv[]) {
    int v = 6;
    vector<vector<int>> edges{{0, 1}, {0, 2}, {0, 5}, {1, 3}, {1, 5}, {2, 3}, {3, 4}, {4, 5}};
    vector<int> dfs = DepthFirstSearch::depthFirstSearch(v, edges, 0);
    for(auto node : dfs) {
        cout << node << " ";
    }
    return 0;
}

