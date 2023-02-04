#include<bits/stdc++.h>
using namespace std;

class AdjacencyList {
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

    static void printGraph(int v, vector<vector<int>> edges) {
        vector<vector<int>> graph = AdjacencyList::buildGraph(v, edges);
        for(int i = 1; i <= v; i++) {
            cout << i << " : ";
            for(auto nbr : graph[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    int v = 5;
    vector<vector<int>> edges{{1, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 5}, {3, 5}};
    AdjacencyList::printGraph(v, edges);
    return 0;
}        
