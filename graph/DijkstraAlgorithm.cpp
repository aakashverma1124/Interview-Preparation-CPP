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
            for(int i = 0; i <= v; i++) {
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
            vector<int> distance(v + 1, INT_MAX);
            vector<bool> visited(v + 1, false);
            
            minHeap.push(make_pair(src, 0));
            distance[src] = 0;

            while(!minHeap.empty()) {
                pair<int, int> node = minHeap.top();
                minHeap.pop();
                int currNode = node.first;
                if(visited[currNode]) continue;
                visited[currNode] = true;
                int currDistance = node.second;

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

int main(int argc, char const *argv[]){
    /* code */
    int v = 5;
    vector<vector<int>> edges{{1, 2, 6}, {1, 3, 3}, {1, 4, 15}, {2, 4, 4}, {2, 5, 5}, {3, 5, 6}};
    int src = 1;
    vector<int> ans = DijkstraAlgorithm::dijkstraAlgorithm(v, edges, src);
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
