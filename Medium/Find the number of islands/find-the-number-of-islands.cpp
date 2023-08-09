//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>grid){
        int n  = grid.size();
        int m  = grid[0].size();
        vis[i][j] = 1;
        queue<pair<int,int>>q;
        q.push({i,j});
        //Step2:Making the visited array dont alter the given array
        // int delRow[] = {-1,0,1,0};
        // int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = -1;i<=1;i++){
                for(int j = -1;j <= 1;j++){
                    
                    int nrow = row + i;
                    int ncol = col + j;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i< n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
        
        //Step3:Counting the non visited position in the matrix by the following coordinates 
        //Step2:Making the queue for the traversal and using the bfs
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends