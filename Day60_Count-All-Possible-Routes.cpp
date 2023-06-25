class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {                
        const int MOD = 1000000007;
        int n = locations.size();    
        
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        for (int i = 0; i <= fuel; i++) {
            dp[finish][i] = 1;
        }
        
        // for each fuel, we calculate all cross between cities
        for (int i = 0; i <= fuel; i++) {
            for (int city = 0; city < n; city++) {            
                for (int nextCity = 0; nextCity < n; nextCity++) {               
                    if (nextCity != city && i >= abs(locations[nextCity] - locations[city])) {
                        dp[city][i] = (dp[city][i] + dp[nextCity][i - abs(locations[nextCity] - locations[city])]) % MOD;
                    }
                }
            }            
        }
        return dp[start][fuel];
    }
};
