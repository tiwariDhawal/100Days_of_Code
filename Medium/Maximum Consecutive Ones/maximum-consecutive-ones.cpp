//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& arr, int k) {
        // Code here
        int ans = 0;
        int j = -1;
        int count = 0;
        for(int i = 0;i< n;i++){
            if(arr[i] == 0){
                count++;
            }
            while(count> k){
                j++;
                if(arr[j] == 0){
                    count--;
                }
            }
            int len = i - j;
            if(len> ans){
                ans = len;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends