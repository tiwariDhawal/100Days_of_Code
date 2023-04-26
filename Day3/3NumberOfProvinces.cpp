//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
void dfs(int node,unordered_map<int,bool>&visited,vector<int>adj[]){
    visited[node] = 1;
    for(auto neighbours : adj[node]){
        if(!visited[neighbours]){
            dfs(neighbours,visited,adj);
        }
    }
    
}
 public:
    int numProvinces(vector<vector<int>> a, int V) {
        // code here
        vector<int>adj[V];
       
        for(int i=0;i<V;i++){

            for(int j=i;j<V;j++){

                if(a[i][j]){

                    adj[i].push_back(j);

                    adj[j].push_back(i);

                }

            }
        }
        int ans = 0;
        unordered_map<int,bool>visited;
        for(int i = 0;i< V;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                ans++;
                
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends