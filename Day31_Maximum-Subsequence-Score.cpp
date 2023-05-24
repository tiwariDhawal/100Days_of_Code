class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>speed = nums1;
        vector<int>efficiency = nums2;
        int n = speed.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = {efficiency[i], speed[i]};
        sort(rbegin(arr), rend(arr));
        long long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for (auto& [e, s] : arr) {
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                res = max(res, sumS * e);
        }
        return res;
    }
};
