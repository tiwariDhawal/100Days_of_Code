//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int delR[] = {-1,0,1,0};
        int delC[] = {0,-1,0,1};
        vector<vector<int>>temp = matrix;
        
        for(int i = 0;i< n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){
                    int a = 0;
                    for(int k = 0;k < 4;k++){
                        int x = i + delR[k];
                        int y = j + delC[k];
                        if(x >= 0 && x < n && y >= 0 && y < m){
                            a = a + matrix[x][y];
                            temp[x][y] = 0;
                        }
                    }
                    temp[i][j] = a;
                }
            }
        }
        matrix = temp;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends