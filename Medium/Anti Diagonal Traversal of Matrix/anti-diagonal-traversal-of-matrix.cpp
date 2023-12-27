//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> m) 
    {
        // Code here
        int r = m.size(), c = m[0].size();
        map<int,vector<int>>mp;
        for(int i = 0; i< r;++i)
        {
            for(int j=0;j<c;++j)
            {
                mp[i+j].push_back(m[i][j]);
            }
        }
        vector<int>ans;
        for(auto i:mp)
        {
            for(int j=0;j<i.second.size();++j)
             ans.push_back(i.second[j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends