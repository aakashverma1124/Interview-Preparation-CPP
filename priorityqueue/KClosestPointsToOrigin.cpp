#include<bits/stdc++.h>
using namespace std;

class Point {
	
	public:
		int x, y, d;
		Point(int x, int y, int d) {
			this->x = x;
			this->y = y;
			this->d = d;
		}
};

class KClosestPointsToOrigin {
	
	struct comparator {
		bool operator() (Point &a, Point &b) {
			return a.d < b.d;
		}
	};

	public:
		static vector<vector<int>> kClosestPoints(vector<vector<int>> &points, int k) {
			priority_queue<Point, vector<Point>, comparator> maxHeap;
			for(int i = 0; i < points.size(); i++) {
				int x = points[i][0];
				int y = points[i][1];
				int distance = x * x + y * y;
				maxHeap.push(Point(x, y, distance));
				if(maxHeap.size() == k + 1) {
					maxHeap.pop();
				}
			}
			vector<vector<int>> ans;
			while(!maxHeap.empty()) {
				Point point = maxHeap.top();
				vector<int> p;
				p.push_back(point.x);
				p.push_back(point.y);
				ans.push_back(p);
				maxHeap.pop();
			}
			return ans;
		}
};

int main(int argc, char const *argv[]) {
	vector<vector<int>> points = {{-4, 3}, {-1, 1}, {5, 5}, {3, 1}, {-4, -3}, {2, -2}};
	int k = 3;
	vector<vector<int>> ans = KClosestPointsToOrigin::kClosestPoints(points, k);
	for(auto a : ans) {
	    cout << a[0] << " " << a[1] << endl;
	}
	return 0;
}