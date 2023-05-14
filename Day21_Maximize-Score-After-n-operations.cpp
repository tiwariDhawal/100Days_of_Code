class Solution {
public:
    unordered_map<int,int>lookup;
    int dp(int a , int mask,vector<int>& nums,int m){
        if(mask == 0)return 0;
        int key = a + mask * 10;
        if(lookup.find(key) == lookup.end()){
            int maxVal = 0;
            for(int i = 0;i< m;i++){
                if(mask&(1<<i)){
                    for(int j = i + 1;j < m;j++){
                        if(mask&(1<<j)){
                            maxVal = max(maxVal,a*__gcd(nums[i],nums[j])+dp(a+1,mask^(1<<i)^(1<<j),nums,m));
                        }
                    }
                }
            }
            lookup[key] = maxVal;
        }
        return lookup[key];
    }
    int maxScore(vector<int>& nums) {
        //(a,mask) max a * gcd(i,j) + (a+1,submask)
        //n * 2^(2 * n) * (2 * n) * (2 * n) = (n ^ 3) * (2 ^ (2 * n))
        int m = nums.size();
        return dp(1,(1<<m)-1,nums,m);
        
    }
};
