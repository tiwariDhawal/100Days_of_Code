//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int i,int j,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == n - 1)return grid[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        int down = grid[i][j] + f(i + 1,j,n,grid,dp);
        int diagnol = grid[i][j] + f(i+1,j+1,n,grid,dp);
        
        return dp[i][j] = min(down,diagnol);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        // int row = triangle.size();
        // int col = triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,n,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends