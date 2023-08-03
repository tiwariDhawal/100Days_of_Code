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
	    int n = nums.size();
	    vector<vector<int>>dp(n,vector<int>(amount+1,-1));
	    int ans = f(n-1,amount,nums,dp);
	    if(ans >= 1e9)return -1;
	    return ans;
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