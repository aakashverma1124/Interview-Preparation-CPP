#include<bits/stdc++.h>
using namespace std;

class CountNodesInDisconnectedComponents {
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

    static int dfs(int node, vector<bool> &visited, vector<vector<int>> &graph) {
        visited[node] = true;
        int c = 1;

        for(auto nbr : graph[node]) {
            if(!visited[nbr]) {
                c += dfs(nbr, visited, graph);
            }
        }
        return c;
    }

    static vector<int> disconnectedComponents(int v, vector<vector<int>> edges) {
        vector<vector<int>> graph = buildGraph(v, edges);
        vector<bool> visited(v + 1, false);
        
        vector<int> components;

        for(int i = 1; i <= v; i++) {
            if(!visited[i]) {
                int c = dfs(i, visited, graph);    
                components.push_back(c);
            }
        }
        return components;
    }
    
};

int main(int argc, char const *argv[]) {
    int v = 12;
    vector<vector<int>> edges{{1, 2}, {1, 5}, {1, 7}, {2, 3}, {3, 7}, {4, 6}, {4, 7}, {5, 6}, {6, 7}, {8, 9}, {10, 11}, {11, 12}};
    vector<int> components = CountNodesInDisconnectedComponents::disconnectedComponents(v, edges);
    for(auto component : components) {
        cout << component << endl;
    }
    return 0;
}

