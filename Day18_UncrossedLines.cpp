class Solution {
public:

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        vector<vector<int>>dp(len1 + 1,vector<int>(len2 + 1));

        for(int i = 0;i<= len1;i++){
            for(int j = 0;j <= len2;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }

};
