class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mapping;
        for(int i = 0;i< nums.size();i++){
            mapping[nums[i]]++;
        }
        for(auto it:mapping){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
    }
};
