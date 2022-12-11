#include<bits/stdc++.h>
using namespace std;

class SmallestKElements {

	struct comparator {
		bool operator() (int a, int b) {
			return a < b;
		}
	};

	public:
		static vector<int> smallestKElements(vector<int> &arr, int k) {
			priority_queue<int, vector<int>, comparator> maxHeap;
			for(int i = 0; i < arr.size(); i++) {
				maxHeap.push(arr[i]);
				if(maxHeap.size() == k + 1) {
					maxHeap.pop();
				}
			}
			vector<int> ans;
			while(!maxHeap.empty()) {
				ans.push_back(maxHeap.top());
				maxHeap.pop();
			}
			return ans;
		}
};

int main(int argc, char const *argv[]) {
	vector<int> arr = {1, 4, 5, 3, 7, 8, 6, 10};
	int k = 3;
	vector<int> ans = SmallestKElements::smallestKElements(arr, k);
	for(auto a : ans) {
	    cout << a << " ";
	}
	return 0;
}