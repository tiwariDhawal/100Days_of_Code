//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	 int const mod=1e9+7;
    int helper(int *arr,int idx,int sum,vector<vector<int>>&dp){
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
      
    int perfectSum(int arr[], int n, int k)
    {
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return helper(arr,n-1,k,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends