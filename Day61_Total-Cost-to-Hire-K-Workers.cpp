class Solution {
public:
    //TC - O(nlogk)
    struct comparator{
        bool operator()(const pair<int,int>&p1,const pair<int,int> &p2){
        if(p1.first != p2.first){
            return p1.first  > p2.first;
        }
        else{
            return p1.second > p2.second;
        }

      }
    };
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comparator>pq;
        int i = 0;
        int j = costs.size() - 1;

        if(i == j){
            return costs[0];
        }

        while(i < j && candidates > 0){
            candidates--;
            pq.push({costs[i],i});
            pq.push({costs[j],j});
            i++;
            j--;
        }
        long long ans = 0;
        while(k > 0 && i <= j){
            k--;
            pair<int,int>p = pq.top();
            pq.pop();
            ans = ans + p.first;
            if(p.second < i){
                pq.push({costs[i],i});
                i++;
            }
            else{
                pq.push({costs[j],j});
                j--;
            }

        }
        while(k > 0 && !pq.empty()){
            ans = ans + pq.top().first;
            pq.pop();
            k--;
        }
        return ans;
    }
};
