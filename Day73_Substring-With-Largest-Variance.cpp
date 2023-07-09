class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        vector<int> freq(26);
        for(auto ch:s){
            freq[ch - 'a']++;
        }
        for(char i = 'a';i<= 'z';i++){
            for(char j = 'a';j <= 'z';j++){
                if(i == j || !freq[i - 'a'] || !freq[j - 'a']){
                    continue;
                }
                for(int k = 1;k <= 2;k++){
                    int count1 = 0;
                    int count2 = 0;
                    for(auto ch:s){
                        count1 = count1 + (ch == i);
                        count2 = count2 + (ch == j);
                        if(count1 < count2){
                            count1 = count2 = 0;
                        }
                        if(count1 > 0 && count2 > 0){
                            ans = max(ans,count1 - count2);
                        }
                    }
                    reverse(s.begin(),s.end());

                }
            }
        }
        return ans;
    }
};
