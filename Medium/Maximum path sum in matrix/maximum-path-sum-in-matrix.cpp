//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j,vector<vector<int>>& Matrix, vector<vector<int>>& dp,int n){
        if(i==0) return Matrix[i][j];
        if(j<0 || j>=n) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int down = Matrix[i][j] + solve(i-1,j,Matrix,dp,n);
        int downright = Matrix[i][j]  + solve(i-1,j+1,Matrix,dp,n);
        int downleft = Matrix[i][j]  + solve(i-1,j-1,Matrix,dp,n);
        //int maxel = max(down,downright);

        return dp[i][j] = max(down,max(downright,downleft));

    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
       
       vector<vector<int>> dp(N,vector<int> (N,0));
       int n = N;
       int m = N;
       for(int j = 0;j < m;j++)dp[0][j] = Matrix[0][j];
       for(int i = 1;i< n;i++){
           for(int j = 0;j < m;j++){
               int u = Matrix[i][j] + dp[i-1][j];
               int ld = Matrix[i][j];
               if(j - 1 >= 0)ld = ld + dp[i-1][j-1];
               else ld += -1e9;
               int rd = Matrix[i][j];
               if(j + 1 < m)rd = rd + dp[i-1][j+1];
               else rd += -1e9;
               dp[i][j] = max(u,max(ld,rd));
           }
       }
       int maxi = -1e9;
       for(int j = 0;j < m;j++){
           maxi = max(maxi,dp[n-1][j]);
       }
    //   vector<vector<int>> dp(N,vector<int> (N,-1));
    //   int maxi = -1e9;
    //     for(int j=0; j<N;j++){
    //           int ans = solve(N-1,j,Matrix,dp,N);
    //           maxi = max(maxi,ans);
    //     }
    //     return maxi;
      return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends