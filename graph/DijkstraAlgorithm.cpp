#include<bits/stdc++.h>
using namespace std;

class DijkstraAlgorithm {

    struct comparator {
		bool operator() (pair<int, int> &a, pair<int, int> &b) {
			return a.second > b.second;
		}
	};

    public:

        static vector<vector<pair<int, int>>> buildGraph(int v, vector<vector<int>>& edges) {
            vector<vector<pair<int, int>>> graph;
            for(int i = 0; i < v; i++) {
                vector<pair<int, int>> nbr;
                graph.push_back(nbr);
            }
            for(auto edge : edges) {
                graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
                graph[edge[1]].push_back(make_pair(edge[0], edge[2]));
            }

            return graph;
        }
        static vector<int> dijkstraAlgorithm(int v, vector<vector<int>> edges, int src) {
            vector<vector<pair<int, int>>> graph = DijkstraAlgorithm::buildGraph(v, edges);
            priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> minHeap;
            vector<int> distance(v, INT_MAX);
            vector<bool> visited(v, false);
            
            distance[src] = 0;
            minHeap.push(make_pair(src, 0));

            while(!minHeap.empty()) {
                pair<int, int> node = minHeap.top();
                minHeap.pop();
                int currNode = node.first;
                int currDistance = node.second;
                if(visited[currNode]) continue;
                
                visited[currNode] = true;
            
                for(auto nbrPair : graph[currNode]) {
                    if(visited[nbrPair.first]) continue;
                    int newDistance = currDistance + nbrPair.second;
                    if(newDistance < distance[nbrPair.first]) {
                        distance[nbrPair.first] = newDistance;
                        minHeap.push(make_pair(nbrPair.first, newDistance));
                    }
                }
            }
            return distance;
        }
};

int main(int argc, char const *argv[]) {
    int v = 5;
    vector<vector<int>> edges{{0, 1, 2}, {0, 2, 9}, {0, 3, 8}, {1, 2, 5}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int src = 1;
    vector<int> ans = DijkstraAlgorithm::dijkstraAlgorithm(v, edges, src);
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
