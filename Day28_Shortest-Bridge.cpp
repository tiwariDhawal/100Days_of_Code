class Solution {
public:
    
      const int dx[4]={-1,1,0,0};
      const int dy[4]={0,0,-1,1};
    //boundary checks
    bool  bound(int i,int j,int r,int c){
          return (i<r && j<c && i>=0 && j>=0);
    }
    
    //change the values from 1 -> 2
    void change_island_type(int i,int j,int r,int c,vector<vector<int>>& grid){
        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]==0 || grid[i][j]==2)return;
        grid[i][j]=2;
        for(int x=0;x<4;++x){
            int new_i=i+dx[x];
            int new_j=j+dy[x];
            change_island_type(new_i,new_j,r,c, grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
  
        int change=0;
        bool ok=false;
        //change the islands
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
               if(grid[i][j]){
                   change_island_type(i,j,r,c,grid);
                   ok=true;
                   break;
               }
            }
            if(ok)break;
        }
      
        //get the new islands in queue
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
               if(grid[i][j]==2){
                q.push({i,j});       
               }
            }
        }
     

        //find the nearest distance to the 1 island from the island 2 
        while(!q.empty()){
            ++change;
         int sz=q.size();
            while(sz--){
               auto node=q.front();
               q.pop();
                //4 directions
               for(int x=0;x<4;++x){
                   int new_i=node.first+dx[x];
                   int new_j=node.second+dy[x];
                   
                   if(bound(new_i,new_j,r,c) ){
                         if( grid[new_i][new_j]==0){
                             grid[new_i][new_j]=2;
                             q.push({new_i,new_j});
                         }
                         if(grid[new_i][new_j]==1)return change-1; 
                   }  
               }     
            }
        }
        
       return 0; 
        
    }
};
