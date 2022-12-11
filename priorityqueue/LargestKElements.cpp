
#include<bits/stdc++.h>
using namespace std;

class Student {

};
class LargestKElements {

	struct comparator {
		bool operator() (int a, int b) {
			return a > b;
		}
	};

	public:
		static vector<int> largestKElements(vector<int> &arr, int k) {
			priority_queue<int, vector<int>, comparator> minHeap;
			for(int i = 0; i < arr.size(); i++) {
				minHeap.push(arr[i]);
				if(minHeap.size() == k + 1) {
					minHeap.pop();
				}
			}
			vector<int> ans;
			while(!minHeap.empty()) {
				ans.push_back(minHeap.top());
				minHeap.pop();
			}
			return ans;
		}
};

int main(int argc, char const *argv[]) {
	vector<int> arr = {1, 4, 5, 3, 7, 8, 6, 10};
	int k = 3;
	vector<int> ans = LargestKElements::largestKElements(arr, k);
	for(auto a : ans) {
	    cout << a << " ";
	}
	return 0;
}