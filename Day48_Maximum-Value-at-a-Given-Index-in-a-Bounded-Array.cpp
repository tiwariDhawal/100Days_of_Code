#define ll long long 
class Solution {
public:
    //sum for the left elements 
    ll sum(ll elements,ll x){
        return x * elements - (elements * (elements+1))/2;

    }
    int maxValue(int n, int index, int maxSum) {
        //for 10^9 we will prefer more binary search then the linear search 
        //doing it for the right side using binary search 
        ll e = INT_MAX;
        // int s = max(index,n-index-1);
        ll s = 0;
        ll ans = 0;
        while(s <= e){
            ll mid  = s + (e-s)/2;
            ll l = sum(min((ll)index,mid-1),mid);
            l += max((ll)0,index-mid+1);
            ll r = sum(min((ll)n-index-1,mid-1),mid);
            r += max((ll)0,n-index-1-mid+1);
            if(l + r + mid <= maxSum){
                ans = max(ans,mid);
                s = mid+1;
            }
            else {
                e = mid - 1;
            }


        }
        return ans;
    }
};
