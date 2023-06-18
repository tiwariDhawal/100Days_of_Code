//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        int i = N- 1;
        int j = 1;
        vector<int>ans;
        int carry = 0;
        while(i>= 0 && j >= 0){
            int val1 = arr[i];
            int val2 = j;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
            j--;
        }
        while(i >= 0){
            int val1 = arr[i];
            int sum = val1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
        }
        while(carry != 0){
            int sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends