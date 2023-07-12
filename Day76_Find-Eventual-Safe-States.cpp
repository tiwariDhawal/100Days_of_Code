class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto &x:graph[i]){
                adj[x].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>safeNodes;
        queue<int>q;
        for(int i = 0 ;i< n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
