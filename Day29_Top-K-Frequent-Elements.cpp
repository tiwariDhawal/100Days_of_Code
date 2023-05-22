class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mapping;
        for(int i=0;i<nums.size();i++){
            mapping[nums[i]]++;
        }
        //creating minHeap of pairs {freq,value}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        for(auto it: mapping){
            minHeap.push({it.second,it.first}); //inserting pair{value,key} in minHeap
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
