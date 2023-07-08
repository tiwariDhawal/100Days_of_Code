class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1){
            return 0;
        }
        vector<long long>ans;
        for(int i = 1;i< weights.size();i++){
            ans.push_back(weights[i-1] + weights[i]);

        }
        sort(ans.begin(),ans.end());
        long long start = 0;
        long long end = 0;
        for(int i = 0;i+1<k;i++){
            start = start + ans[i];
            end = end + ans[ans.size() - 1 - i];

        }
        return (end - start);
    }
};
