//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        //Step1:Making the copy of the grid which is visited or not 
        // a> Taking the count of fresh oranges 
        int countFresh = 0;
        for(int i = 0;i< n;i++){
            for(int j = 0;j< m;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 0){
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    countFresh++;
                }
                
            }
        }
        //Step2:Now checking the neighbours for all the directions 
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        //b>Checking for the minimum time to rott all the oranges 
        int timer = 0;
        int count = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            
            timer = max(timer,tm);
            for(int i = 0;i< 4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},tm+1});
                    vis[nrow][ncol]= 1;
                    count++;
                }
            }
        }
        if(count != countFresh){
            return -1;
        }
        return timer;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends