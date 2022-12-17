#include <bits/stdc++.h>
using namespace std;

class ReorganizeString {

	struct comparator {
		bool operator()(pair<char, int> &x, pair<char, int> &y) {
			return y.second > x.second;
		}
	};

public: 
	static string reorganizeString(string &s) {
		map<char, int> hashMap;
		for(char ch : s) {
			hashMap[ch] += 1;
		}

		priority_queue<pair<char, int>, vector<pair<char, int>>, comparator> maxHeap;
		for(auto entry : hashMap) {
			maxHeap.push(entry);
		}

		string ans = "";
		while(maxHeap.size() >= 2) {
			pair<char, int> entry1 = maxHeap.top();
			maxHeap.pop();
			pair<char, int> entry2 = maxHeap.top();
			maxHeap.pop();
			ans += entry1.first;
			ans += entry2.first;
			entry1.second -= 1;
			entry2.second -= 1;
			if(entry1.second > 0) {
				maxHeap.push(entry1);
			}
			if(entry2.second > 0) {
				maxHeap.push(entry2);
			}
			
		}
		
		if(maxHeap.empty()) {
			return ans;
		} else {
			pair<char, int> entry = maxHeap.top();
			maxHeap.pop();
			if(entry.second == 1) {
				ans += entry.first;
				return ans;
			} else {
				return "";
			}
		}
	}

};

int main(int argc, char const *argv[]) {
	string s = "aaabcdddaa";
	string ans = ReorganizeString::reorganizeString(s);
	cout << ans << endl;
	return 0;
}