//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
	    if(ind == 0){
	        if(target % arr[ind] == 0){
	            return target/arr[ind];
	        }
	        return 1e9;
	    }
	    if(dp[ind][target] != -1)return dp[ind][target];
	    int notTake = 0 + f(ind - 1, target,arr,dp);
	    int take = INT_MAX;
	    if(arr[ind] <= target){
	        take = 1 + f(ind,target - arr[ind],arr,dp);
	    }
	    return dp[ind][target] = min(take,notTake);
	}
	
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    //Space Optimization
	    int n = nums.size();
	    vector<int>prev(amount+1,0),curr(amount+1,0);
	    for(int T = 0;T<= amount;T++){
	        if(T %nums[0] == 0)prev[T] = T/ nums[0];
	        else prev[T] = 1e9;
	    }
	    for(int ind = 1;ind < n;ind++){
	        for(int T = 0;T <= amount;T++){
	            int notTake = 0  + prev[T];
	            int take = INT_MAX;
	            if(nums[ind] <= T){
	                take = 1 + curr[T - nums[ind]];
	            }
	            curr[T] = min(take,notTake);
	        }
	        prev = curr;
	    }
	    int ans = prev[amount];
	    if(ans >= 1e9)return -1;
	    return ans;
	    //Tabulation
	   // int n = nums.size();
	   // vector<vector<int>>dp(n,vector<int>(amount+1,0));
	   // for(int T = 0;T<= amount;T++){
	   //     if(T %nums[0] == 0)dp[0][T] = T/ nums[0];
	   //     else dp[0][T] = 1e9;
	   // }
	   // for(int ind = 1;ind < n;ind++){
	   //     for(int T = 0;T <= amount;T++){
	   //         int notTake = 0  + dp[ind-1][T];
	   //         int take = INT_MAX;
	   //         if(nums[ind] <= amount){
	   //             take = 1 + dp[ind][T - nums[ind]];
	   //         }
	   //         dp[ind][T] = min(take,notTake);
	   //     }
	   // }
	   // int ans = dp[n-1][amount];
	   // if(ans >= 1e9)return -1;
	   // return ans;
	   
	   //Memo
	   // int n = nums.size();
	   // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
	   // int ans = f(n-1,amount,nums,dp);
	   // if(ans >= 1e9)return -1;
	   // return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends