#include<bits/stdc++.h>
using namespace std;

class KruskalsAlgo {
    public:

        static int find(int u, vector<int>& parent) {
            if(u == parent[u]) return u;
            return find(parent[u], parent);
        }

        static void unionDSU(int u, int v, vector<int>& parent) {
            int p1 = find(u, parent);
            int p2 = find(v, parent);
            parent[p2] = p1;
        }

        static int mst(int n, vector<vector<int>>& edges) {
            sort(edges.begin(), edges.end(), 
            [](const vector<int> &x, const vector<int> &y) { return x[2] < y[2]; });

            vector<int> parent;
            for(int i = 0; i < n; i++) {
                parent.push_back(i);
            }
            int ans = 0;
            for(auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int cost = edge[2];

                int p1 = find(u, parent);
                int p2 = find(v, parent);

                if(p1 != p2) {
                    unionDSU(p1, p2, parent);
                    ans += cost;
                }
            }
            return ans;
        }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> edges{{0, 1, 8}, {0, 2, 2}, {1, 4, 1}, {1, 5, 3}, {2, 3, 6}, {2, 4, 3}, {3, 5, 4}, {4, 5, 2}};
    int n = 6;
    int ans = KruskalsAlgo::mst(n, edges);
    cout << ans << endl;
    return 0;
}
