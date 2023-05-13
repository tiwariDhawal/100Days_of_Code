class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9 + 7;
        vector<long>dp(100001);
        dp[0] = 1;
        for(int i = 1;i<= high;i++){
            if(i - zero >= 0){
                dp[i] += dp[i-zero];
            }
            if(i - one >= 0){
                dp[i] += dp[i- one];
            }
            dp[i] %= mod;
        }
        long ans = 0;
        for(int i = low;i<=high;i++){
            ans  += dp[i];
        }
        return (int)(ans % mod);
    }
};
