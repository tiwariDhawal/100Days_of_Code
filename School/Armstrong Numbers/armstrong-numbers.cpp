//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int N){
        // code here
        int digit = 0;
        int sum = 0;
        int n = N;
        while(n > 0){
            digit = n % 10;
            sum = sum + pow(digit,3);
            n = n / 10;
        }
        if(sum == N){
            return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends