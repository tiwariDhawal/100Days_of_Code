class Solution {
public:
    unordered_map<string,double> mapping;
    int dir[8][8] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

    double findMoves(int n, int moves, int r, int c) {
        //Base case
        if(r<0 || r>=n || c<0 || c>=n)
            return 0;
        
        if(moves == 0)
            return 1;
        //Memoization
        string key = to_string(r) + "dhawal" + to_string(c) + "tiwari" + to_string(moves);
        if(mapping.find(key) != mapping.end())
            return mapping[key];
        
        double probability = 0;
        for(int i=0; i<8; i++)
            probability += findMoves(n,moves-1, r+dir[i][0], c+dir[i][1])/8.0 ;
        
        mapping[key] = probability;
        return mapping[key];
    }

    double knightProbability(int n, int k, int row, int column) {
        return findMoves(n,k,row,column);
    }

};
