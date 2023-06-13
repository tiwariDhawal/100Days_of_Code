//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int maxi = INT_MIN; 
	    int ans = 0;
	    for(int i = 0;i< n;i++){
	        maxi  = max(arr[i],maxi);
	    }
	    int res = INT_MIN;
	    for(int j = 0;j < n;j++){
	        if(arr[j] != maxi){
	            res = max(res,arr[j]);
	        }
	    }
	    
	    if(res == INT_MIN){
	        return -1;
	    }
	    return res;
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends