#include <bits/stdc++.h>
using namespace std;

class NoRepeatSubstring {
public:
    static int noRepeatSubstring(string s) {
        int windowStart = 0;
        int maxLength = INT_MIN;
        map<char, int> indexMap;
        if(s.size() == 0) return 0;
        
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char currChar = s[windowEnd];
            if(indexMap.find(currChar) != indexMap.end()) {
                windowStart = max(windowStart, indexMap[currChar] + 1);
            }
            indexMap[currChar] = windowEnd;
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    } 
};

int main() {
    string s = "abcabcbb";
    cout << NoRepeatSubstring::noRepeatSubstring(s) << endl;
}
