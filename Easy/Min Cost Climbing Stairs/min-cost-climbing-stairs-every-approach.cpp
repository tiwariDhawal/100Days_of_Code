//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>&cost , int n){
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost,n-1),solve(cost,n-2));
        return ans;
    }
    //recursion and memonization - tc - o(n) and sc - o(n) + o(n)
    int solve2(vector<int>&cost,int n,vector<int>&dp){
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        //step3
        if(dp[n] != -1){
            return dp[n];
        }
        //Step2
        dp[n] = cost[n] + min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return dp[n];
    }
    //Tabulation - tc - o(n) and sc - o(n)
    int solve3(vector<int>&cost, int n){
        //Step1:creation of array
        vector<int>dp(n+1);
        //Step2:base case analyse 
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        //Step3:
        for(int i = 2;i< n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    //Space optimization - tc - o(n) and sc - o(1)
    int solve4(vector<int>&cost , int n){
        int prev2 = cost[0];
        int prev1 = cost[1];
        
        for(int i = 2;i<n;i++){
            int curr = cost[i] + min(prev1,prev2);
            prev2 = prev1;
            prev1 = curr;
            
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        // int n = cost.size();
        // int ans = min(solve(cost,n-1),solve(cost,n-2));
        // return ans;
        
        // int n = cost.size();
        // //Step1:
        // vector<int>dp(N+1,-1);
        // int ans = min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        // return ans;
        
        // int n = cost.size();
        // return solve3(cost,n);
        
        int n = cost.size();
        return solve4(cost,n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
