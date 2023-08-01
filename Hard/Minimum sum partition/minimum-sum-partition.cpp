//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int target = 0;
        for(int i =0 ; i<n ; i++) target += arr[i];
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        // for target 0 ---> make all i true
        for(int i =0; i<n; i++) dp[i][0] = true;
        if(target >= arr[0]) dp[0][arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int k = 1; k<= target/2 ; k++){
                bool notpick = dp[i-1][k];
                bool pick = false;
                if(k >= arr[i]) pick = dp[i-1][k-arr[i]];
                dp[i][k] = pick | notpick;
            }
        }
        int mini = INT_MAX;
        for(int k = 0; k<= target/2 ; k++){
            if(dp[n-1][k]){
                // int s1 = k;
                // int s2= target -k;
                mini = min(mini, abs(2*k-target));
            }
            
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends