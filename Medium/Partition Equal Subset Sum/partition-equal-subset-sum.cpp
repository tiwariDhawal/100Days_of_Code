//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int i,int target,int arr[],vector<vector<int>>&dp){
        if(target == 0)return true;
        if(i == 0)return (arr[0] == target);
        if(dp[i][target] != -1)return dp[i][target];
        bool notTake = f(i-1,target,arr,dp);
        bool take = false;
        if(target >= arr[i]){
            take = f(i - 1,target - arr[i],arr,dp);
        }
        return dp[i][target] = take or notTake;
    }
    bool isSubsetSum(int arr[], int sum,int n){
        // code here 
        // int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum + 1,-1));
        return f(n-1,sum,arr,dp);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum = 0;
        for(int i = 0;i< N;i++){
            totalSum = totalSum + arr[i];
        }
        if(totalSum %2 != 0)return false;
        totalSum = totalSum / 2;
        return isSubsetSum(arr,totalSum,N);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends