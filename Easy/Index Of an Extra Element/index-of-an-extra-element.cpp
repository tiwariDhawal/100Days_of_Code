//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        // add code here.
        vector<int> ans;
        for(int i = 0;i < n;i++){
            ans.push_back(a[i]);
        }
        int m = n - 1;
        for(int i = 0;i< m;i++){
            ans.push_back(b[i]);
        }
        int c = 0;
        for(int i = 0;i< ans.size();i++){
            c = c ^ ans[i];
        }
        for(int i = 0;i< n;i++){
            if(a[i] == c){
                return i;
            }        
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        Solution obj;
        cout << obj.findExtra(a, b, n) << endl;
    }
}
// } Driver Code Ends