#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

        int numberOfBoomerangs(vector<vector<int>>& points) {
            int count = 0;
            for(int i = 0; i < points.size(); i++) {
                unordered_map<int, int> m;
                for(int j = 0; j < points.size(); j++) {
                    if(i != j) {
                        int dis = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                        m[dis] += 1;
                    }
                }
                for(auto pair : m) {
                    if(pair.second >= 2) {
                        count += (pair.second * (pair.second - 1));
                    }
                }
            }
            return count;
        }
};
