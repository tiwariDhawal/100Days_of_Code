//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    long long fib(int n,vector<long long>&dp){
         //code here
        if(n == 0 || n == 1){
            return 1;
        }
        
        if(dp[n] != -1)return dp[n];
        dp[n] = fib(n-1,dp) + fib(n-2,dp);
        return dp[n];
    }
    vector<long long> printFibb(int n) 
    {
        //code here
       vector<long long>dp(n+1,-1);
       vector<long long>ans;
       for(int i = 0;i< n;i++){
           ans.push_back(fib(i,dp));
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends