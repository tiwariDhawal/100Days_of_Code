//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    void bfs(vector<int>&ans,unordered_map<int,bool>&visited,vector<int> adj[],int node){
        //Making the first node to be true as its now visited 
        //Making the queue for the traversal of others 
        queue<int>q;
        q.push(node);
        visited[node] = 1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            ans.push_back(frontNode);
            
            for(auto neighbours : adj[frontNode]){
                if(!visited[neighbours]){
                    q.push(neighbours);
                    visited[neighbours] = 1;
                }
            }
        }
        
        
        
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //Algo to solve the problem of bfs is to make just the 
        //1> Adj list 
        //2> Having the visited map or array 
        //3> Saving the series in some list or something 
        
        //Here adj list is already givenn so 
        vector<int>ans;
        // vector<int>visited(V,0);
        unordered_map<int,bool>visited;
        
        //4> If the question is different we have too check for every unvisited node but here we just have to search for 0
        bfs(ans,visited,adj,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends