#include<bits/stdc++.h>
using namespace std;

class DepthFirstSearch {
public:

    static vector<vector<int>> buildGraph(int v, vector<vector<int>> edges) {
        vector<vector<int>> graph;
        for(int i = 0; i <= v; i++) {
            vector<int> v;
            graph.push_back(v);
        }
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); // remove if directed
        }
        return graph;
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
        vector<bool> visited(v + 1, false);

        vector<int> dfsAns;
        for(int i = 1; i <= v; i++) {
            if(!visited[i])
                dfs(i, visited, graph, dfsAns);    
        }
        return dfsAns;
    }
    
};

int main(int argc, char const *argv[]) {
    int v = 9;
    vector<vector<int>> edges{{1, 2}, {1, 5}, {1, 7}, {2, 3}, {3, 7}, {4, 6}, {4, 7}, {5, 6}, {6, 7}, {8, 9}};
    vector<int> dfs = DepthFirstSearch::depthFirstSearch(v, edges, 1);
    for(auto node : dfs) {
        cout << node << " ";
    }
    return 0;
}

