class Solution {
public:
    void dfs(string s,string d,unordered_map<string,vector<pair<string,double>>>mapping,unordered_map<string,int>&visited,double &ans,double temp){
        if(visited.count(s)){
            return;
        }
        if(s == d){
            ans = temp;
            return;
        }
        visited[s] = 1;
        for(auto x:mapping[s]){
            dfs(x.first,d,mapping,visited,ans,temp * x.second);
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>mapping;
        for(int i = 0;i< equations.size();i++){
            mapping[equations[i][0]].push_back({equations[i][1],values[i]});
            mapping[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }

        vector<double>finalAns;

        for(int i = 0;i < queries.size();i++){
            string source = queries[i][0];
            string dest = queries[i][1];

            unordered_map<string,int>visited;
            double ans = -1.0;
            double temp = 1;
            if(mapping.count(source)){

                dfs(source,dest,mapping,visited,ans,temp);
            }
            finalAns.push_back(ans);


        }
        return finalAns;
        
    }
};
