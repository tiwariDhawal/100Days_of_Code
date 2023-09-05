//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m] = {0};
        for(int i = 0;i< n;i++){
            for(int j = 0;j < m;j++){
                //first row,first col , last row , last col
                if(i == 0 || j == 0 || i == n-1 || j == m - 1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j]  = 1;
                        
                    }
                }
            }
        }
        int delR[] = {-1, 0, +1, 0};
        int delC[] = {0, 1, 0, -1}; 
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0;i< 4;i++){
                int nrow = row + delR[i];
                int ncol = col + delC[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && 
                grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                    
                }
            }
            
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)count++;
            }
        }
        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends