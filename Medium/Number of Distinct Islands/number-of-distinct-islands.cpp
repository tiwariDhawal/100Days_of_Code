//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 private:
    void dfs(int row , int col ,set<vector<pair<int,int>>>&st,vector<vector<int>>&visited,
    vector<pair<int,int>>&vec,int row0 , int col0,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        //Step 4: Making the visited array to be true 
        visited[row][col] = 1;
        //Step 5: Subtracting the cordinate with the base and then pushing it into the array 
        vec.push_back({row - row0,col - col0});
        
        //Step6: Making delta row and delta col 
        int delr[] = {-1 , 0 , +1 , 0};
        int delc[] = {0 , +1, 0 , -1};
        
        //Step 7: Now checking for all the sides in up , left , right ,down 
        for(int i = 0;i< 4;i++){
            int nrow = row - delr[i];
            int ncol = col - delc[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,st,visited,vec,row0,col0,grid);
            }
        }
        
        
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        //Step 1: First you have to check the grid 
        int n = grid.size();
        int m = grid[0].size();
        
        //Step2: Now check the visited array 
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        //Step3: Making a set for the list as set only stores unique element not the same element so duplicates will be removed 
        
        set<vector<pair<int,int>>>st;
        
        for(int i = 0;i< n;i++){
            for(int j = 0;j < m;j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,st,visited,vec,i,j,grid);
                    st.insert(vec);
                }
            }
        }
        return st.size();
        
        
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends