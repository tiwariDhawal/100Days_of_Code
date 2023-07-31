//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int f(int i , int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i == 0 && j == 0)return grid[i][j];
        if(i < 0 || j < 0)return 1e9;
        if(dp[i][j] != -1)return dp[i][j];
        
        int up = grid[i][j] + f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);
        
        return dp[i][j] = min(up,left);
        
    }
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        // int n = grid.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(n-1,n-1,grid,dp);
        // int n = grid.size();
        // int dp[n][n];
        // for(int i = 0;i< n;i++){
        //     for(int j = 0;j < n;j++){
        //         if(i == 0 && j == 0)dp[0][0] = grid[i][j];
        //         else{
        //             // int up = grid[i][j] + dp[i-1][j];
        //             int up = grid[i][j];
        //             if(i > 0)up += dp[i-1][j];
        //             else{
        //                 up = up + 1e9;
        //             }
                    
        //             // int left = grid[i][j] + dp[i][j-1];
        //             int left = grid[i][j];
        //             if(j > 0)left += dp[i][j-1];
        //             else{
        //                 left = left + 1e9;
        //             }
        //             dp[i][j] = min(up,left);
        //         }
        //     }
        // }
        // return dp[n-1][n-1];
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();
            int a[]={1,-1,0,0};
            int b[]={0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int y1=u+a[i];
                int z1=v+b[i];
                if(y1>=0 && z1>=0 && z1<m && y1<n)
                {
                if(dist[y1][z1]>dist[u][v]+grid[y1][z1])
                {
                    dist[y1][z1]=dist[u][v]+grid[y1][z1];
                    pq.push({dist[y1][z1],{y1,z1}});
                }
                }
            }
        }
        return dist[n-1][m-1];
    
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends