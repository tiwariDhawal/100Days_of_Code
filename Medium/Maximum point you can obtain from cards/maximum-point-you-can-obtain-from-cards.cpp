//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &arr, int N, int k) {
        // code here
        long long ans = 0;
        
        for(int i=0;i<k;i++)
            ans += arr[i];
        
        long long curr = ans;
        int j = N-1;
        for(int i=k-1;i>=0;i--){
            curr = curr-arr[i]+arr[j--];
            ans = max(ans,curr);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends