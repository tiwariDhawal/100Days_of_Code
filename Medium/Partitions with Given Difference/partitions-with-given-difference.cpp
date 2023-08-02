//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int const mod=1e9+7;
    int helper(vector<int>arr,int idx,int sum,vector<vector<int>>&dp){
        if(idx==0){
            if(arr[0]==0 && sum==0)return 2;
            if(sum==0 || arr[0]==sum)return 1;
            return 0;
        }
       
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int notpick=helper(arr,idx-1,sum,dp);
        int pick=0;
        if(arr[idx]<=sum)pick=helper(arr,idx-1,sum-arr[idx],dp);
        return dp[idx][sum]=(pick+notpick)%mod;
    }
      
     int findWays(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        
        //base case
        if(nums[0] == 0)dp[0][0] = 2;
        
        else dp[0][0] = 1;
        //nums[0] = 0
        if(nums[0] != 0 && nums[0] <= k)dp[0][nums[0]] = 1;
        
        int mod = (int)(1e9 + 7);
        for(int i=1; i<n; i++) {
            for(int sum=0; sum<=k; sum++) {
                int notTake = dp[i-1][sum];
                
                int take = 0;
                if(nums[i] <= sum)
                take = dp[i-1][sum-nums[i]];
                
                dp[i][sum] = (notTake+take)%mod;
            }
        }
        return dp[n-1][k];
    }
    int findWaysSpace(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>prev(k+1,0),curr(k+1,0);
        
        //base case
        if(nums[0] == 0)prev[0] = 2;
        
        else prev[0] = 1;
        //nums[0] = 0
        if(nums[0] != 0 && nums[0] <= k)prev[nums[0]] = 1;
        
        int mod = (int)(1e9 + 7);
        for(int i=1; i<n; i++) {
            for(int sum=0; sum<=k; sum++) {
                int notTake = prev[sum];
                
                int take = 0;
                if(nums[i] <= sum)
                take = prev[sum-nums[i]];
                
                curr[sum] = (notTake+take)%mod;
            }
            prev = curr;
        }
        return prev[k];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalSum = 0;
        for(auto &it : arr)totalSum = totalSum + it;
        if(totalSum - d < 0 || (totalSum - d) % 2){
            return 0;
        }
        int s2 = (totalSum - d)/2;
        // vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        // return helper(arr,n-1,s2,dp);
        // return findWays(arr,s2);
        return findWaysSpace(arr,s2);
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends