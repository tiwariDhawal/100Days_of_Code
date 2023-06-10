//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        //Step 1: Converting the code in the binary format 
        long long n = X;
        vector<int>ans;
        while(n != 0){
            int digit = n % 2;
            ans.push_back(digit);
            n = n / 2;
        }
        //Step 2: Fill in the extra bits with the 0
        while(ans.size() != 32){
            ans.push_back(0);
        }
        
        //Step 3: Reverse the values
        reverse(ans.begin(),ans.end());
        
        long long val = 0;
        //Defining the initial integer variable to be output
        
        
        //Method of converting binary to decimal
        for(int i = 0;i< 32;i++){
            val = val + pow(2,i) * ans[i];
        }
        return val;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends