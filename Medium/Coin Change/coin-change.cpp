//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int ind,int target,int coins[],vector<vector<long long>>&dp){
        if(ind == 0){
            if(target % coins[0] == 0)return 1;
            return 0;
        }
        if(dp[ind][target] != -1)return dp[ind][target];
        long long  notTake = f(ind - 1, target,coins,dp);
        long long take = 0;
        if(coins[ind] <= target){
            take = f(ind, target - coins[ind],coins,dp);
        }
        return dp[ind][target] = take + notTake;
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        // vector<vector<long long >>dp(N+1,vector<long long>(sum+1,-1));
        // return f(N-1,sum,coins,dp);
        //tabulation
        
        vector<vector<long long>>dp(N+1,vector<long long>(sum+1,0));
        for(int T= 0;T<= sum;T++){
            dp[0][T] = (T % coins[0] == 0);
        }
        for(int ind = 1;ind < N;ind++){
            for(int T = 0;T <= sum;T++){
                long long  notTake = dp[ind - 1][T];
                long long take = 0;
                if(coins[ind] <= T){
                    take = dp[ind][T - coins[ind]];
                }
                dp[ind][T] = take + notTake;
            }
        }
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends