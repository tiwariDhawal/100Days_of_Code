class Solution {
public:

    bool f(int ind, string &s, vector<int> &dp, vector<string> &wordDict) {
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind ; i < s.size() ; i++) {
            string v = s.substr(ind, i-ind+1);
            if(find(wordDict.begin(), wordDict.end(), v) != wordDict.end()) {
                if(f(i+1, s, dp, wordDict)) return dp[ind] = true;
            }
            
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return f(0,s, dp, wordDict);
    }
};
