//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int start,int V,vector<int>&vis,vector<int>adj[],vector<int>&ans){
        vis[start] = 1;
        
        ans.push_back(start);
        
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(it,V,vis,adj,ans);
                vis[it]  =1;
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //Step1:We have to travel to the very last 
        vector<int>vis(V,0);
        vector<int>ans;
        
        //Step2:We will travel one by one to every node and mark them visited in order 
        int start = 0;
        dfs(start,V,vis,adj,ans);
        //Step3:We will use recursion for the whole traversal 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends