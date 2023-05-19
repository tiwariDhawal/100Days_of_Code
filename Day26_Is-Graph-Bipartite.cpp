class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n<2)return true;
        vector<int> adj[n];
        vector<int> setColor(n,0);   
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++)
            adj[i].push_back(graph[i][j]);     
        }
       for(int i=0;i<n;i++){
           if(setColor[i]==0){
           queue<int>q1;
           q1.push(i);
           setColor[i]=1;
               while(!q1.empty()){
               int cur=q1.front();
               q1.pop();
               for(auto j:adj[cur]){
                   if(setColor[j]==0){
                       q1.push(j);
                       setColor[j]=-setColor[cur];
                   }
                   else{
                       if(setColor[j]==setColor[cur])return false;
                   }
               }
             }
           }
          
       }
        return true;  
    }
};
