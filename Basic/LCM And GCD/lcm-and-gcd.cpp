//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
//     long long gcd(long long a, long long b)
// {
//     // Everything divides 0
//     if (a == 0)
//       return b;
//     if (b == 0)
//       return a;
  
//     // base case
//     if (a == b)
//         return a;
  
//     // a is greater
//     if (a > b)
//         return gcd(a-b, b);
//     return gcd(a, b-a);
// }
    long long  gcd(long long  a, long long  b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long ans = gcd(A,B);
        long long  lcm = (A*B)/ans;
        vector<long long> main;
        main.push_back(lcm);
        main.push_back(ans);
        return main;
        
       
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends