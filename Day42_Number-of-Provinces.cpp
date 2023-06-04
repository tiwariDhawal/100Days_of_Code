class Solution {
private:
    void dfs(int node, unordered_map<int,bool>&visited,vector<int>adj[]){
        visited[node] = 1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0;i< n;i++){
            for(int j = 0;j< n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        //making the visited array or map 
        int count = 0;
        unordered_map<int,bool>visited;
        for(int i = 0;i< isConnected.size();i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};
