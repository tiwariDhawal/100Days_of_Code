//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int a[], int n) {
        // code here
        long long ans = 0;
        long long fmx = INT_MIN,smx = INT_MIN,tmx = INT_MIN;
        long long fmn = INT_MAX,smn = INT_MAX;
        for(int i = 0;i< n;i++){
            if(a[i] > fmx){
                tmx = smx;
                smx = fmx;
                fmx = a[i];
            }
            else if(a[i] > smx){
                tmx = smx;
                smx = a[i];
            }
            else if(a[i] > tmx){
                tmx = a[i];
            }
            if(a[i]<fmn){
                smn = fmn;
                fmn = a[i];
            }
            else if(a[i] < smn){
                smn = a[i];
            }
            
        }
        ans = max(fmx*smx*tmx , fmx*fmn*smn);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends