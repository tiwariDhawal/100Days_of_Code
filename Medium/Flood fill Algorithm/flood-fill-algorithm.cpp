//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int iniColor,int row,int col,int delRow[],int delCol[],vector<vector<int>>&ans,
    int newColor,vector<vector<int>>&image){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for(int i = 0;i< 4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] != newColor && 
            image[nrow][ncol] == iniColor){
                dfs(iniColor,nrow,ncol,delRow,delCol,ans,newColor,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int iniColor = image[sr][sc];
        vector<vector<int>>ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(iniColor,sr,sc,delRow,delCol,ans,newColor,image);
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends