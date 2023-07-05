class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int countZero = 0;
        int maxi = 0;
        while(j < n){

            if(nums[j] == 0){
                countZero++;
            }
            while(i < n && countZero == 2){
                if(nums[i] == 0){
                    countZero--;
                }
                i++;
            }
            maxi = max(j - i,maxi);
            j++;
        }
        return maxi;
    }
};
