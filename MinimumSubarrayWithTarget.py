#include<bits/stdc++.h>
using namespace std;

int MinimumSubarrayWithTarget(vector<int>vect,int target,int minlen) {

        int windowStart = 0;
        int windowSum = 0;
        for(int windowEnd = 0; windowEnd < vect.size(); windowEnd++) {
            windowSum += vect[windowEnd];
            while(windowSum>=target){
                int windowlength= windowStart-windowEnd+1;
                minlen=min(minlen,windowlength);
                windowSum -=vect[windowStart];
                windowStart += 1;
            }
        }
        return minlen;
    }

    int main() {
        vector<int>vect={3,4,7,1,9,2,12,1};
        int n=vect.size();
        int target=14;
        int minlen=INT_MAX;
        int ans = MinimumSubarrayWithTarget(vect,target,minlen);
        cout<<abs(ans);
       
    return 0;
    }
