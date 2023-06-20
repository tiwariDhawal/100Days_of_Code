class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int winSize = 2 * k + 1;
        
        long long winSum = 0;
        vector<int> result(n, -1);

        if (n < winSize) {
            return result;
        }

        for (int i = 0; i < n; ++i) {
            //Step1:Add elements to the window sum
            winSum += nums[i]; 

            if (i - winSize >= 0) {
            //step 2:Remove nums[i - windowSize] from the window sum
                winSum = winSum - nums[i - winSize]; 
            }
            //Step 3:Calculate and store the average in the result
            if (i >= winSize - 1) {
                result[i - k] = winSum / winSize; 
            }
        }

        return result;
    }
};
