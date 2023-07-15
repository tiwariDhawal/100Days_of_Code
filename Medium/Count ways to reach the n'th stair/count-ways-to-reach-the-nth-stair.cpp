//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = 1e9 + 7;
    int countWays(int n)
    {
        // your code here
        if(n <= 2){
            return n;
            
        }
        int i1 = 1;
        int i2 = 2;
        int i3;
        for(int i = 3;i<=n;i++){
            i3 = (i1 + i2)%mod;
            i1 = i2;
            i2 = i3;
        }
        return i3 % mod;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends