class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>size(n,1);
        vector<int>ways(n,1);

        int maxi = 1;
        for(int i = 1;i< n;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j] && size[j] + 1 > size[i]){
                    size[i] = size[j] + 1;
                    ways[i] = ways[j];
                }
                else if(nums[i] > nums[j] && size[j] + 1 == size[i]){
                    ways[i] += ways[j];
                }
                maxi = max(maxi,size[i]);
            }
        }
        int result = 0;
        for(int i = 0;i< n;i++){
            if(size[i] == maxi){
                result += ways[i];
            }
        }
        return result;
    }
};
