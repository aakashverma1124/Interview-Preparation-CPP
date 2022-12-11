#include<bits/stdc++.h>
using namespace std;

class AverageSubarrayOfSizeK {
    public: 
        static vector<double> averageSubarray(vector<int> &arr, int k) {
            vector<double> ans(arr.size() - k + 1);
            int windowStart = 0;
            int windowSum = 0;
            for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
                windowSum += arr[windowEnd];
                if(windowEnd >= k - 1) {
                    ans[windowStart] = (double) windowSum/k;
                    windowSum -= arr[windowStart];
                    windowStart += 1;
                }
            }
            return ans;
        }
};

int main(int argc, char const *argv[]) {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3;
    vector<double> ans = AverageSubarrayOfSizeK::averageSubarray(arr, k);
    for(auto a : ans) {
        cout << a << " ";
    }
    return 0;
}

