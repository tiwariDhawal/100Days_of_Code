class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int k = 0;
                for(; k < n; ++k){
                    if(grid[i][k] != grid[k][j]){
                        break;

                    }
                }
                if(k == n){
                    k = 1;
                }
                else{
                    k = 0;
                }
                count = count + k;
                
            }
        }
        return count;
    }
};
