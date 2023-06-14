//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int ans=INT_MAX;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x || a[i]==y)
            {
                if(last!=-1 && a[last]!=a[i]) {
                    
                    ans=min(ans,i-last);
                }
                last=i;
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends