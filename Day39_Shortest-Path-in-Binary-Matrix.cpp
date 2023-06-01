class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        
        q.push({{0,0},1});
        if(grid[0][0] == 1){
            return -1;
        }
        //if first cell and last cell also zero 

        if(grid[0][0] == 0 && grid.size() == 1 && grid[0].size()){
            return 1;
        }
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        visited[0][0] = true;
        while(!q.empty()){
            pair<int,int>p = q.front().first;//{0,0}
            int x = p.first;//0
            int y = p.second;//0
            int lengthOfPath = q.front().second;//1
            q.pop();

            vector<pair<int,int>>neighbours = {{0,1},{0,-1},{1,0},{-1,0},
                                            {1,1},{-1,-1},{1,-1},{-1,1}};
            for(pair<int,int>neighbour : neighbours){
                int newX = neighbour.first + x;
                int newY = neighbour.second + y;
                if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid.size() && grid[newX][newY] == 0 && !visited[newX][newY]){
                    q.push({{newX,newY},lengthOfPath + 1});
                    visited[newX][newY] = true;
                    if(newX == grid.size() - 1 && newY == grid[0].size() - 1){
                        return lengthOfPath + 1;

                    }

                }
            } 
        }
        return -1;
    }
};
