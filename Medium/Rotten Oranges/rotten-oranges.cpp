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
        int countFresh = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int timer = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j< m;j++){
                
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                    
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1 ){
                    countFresh++;
                }
            }
        }
        int count = 0;
   
        int delR[] = {-1,0,+1,0};
        int delC[] = {0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            timer = max(tm,timer);
            
            for(int i = 0;i< 4;i++){
                int nrow = row + delR[i];
                int ncol = col + delC[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},tm + 1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }
        if(count != countFresh)return -1;
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