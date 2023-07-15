//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int ans = INT_MAX;
        unordered_map<char,int>mapping;
        // for(int i = 0;i<S.length();i++){
        //     mapping[S[i]]++;
        // }
        int i = 0;
        int j = 0;
        // unordered_map<char,int>temp;
        while(j < S.length()){
            mapping[S[j]]++;
            
            if(mapping.size() == 3){
                ans = min(ans,j-i+1);
                while( mapping.size() == 3){
                    
                    mapping[S[i]]--;
                    if(mapping[S[i]] == 0){
                        mapping.erase(S[i]);
                    }
                    i++;
                    if(mapping.size() == 3){
                        ans = min(ans,j-i+1);
                    }
                
                }
            }
            j++;
        }
        return ans == INT_MAX?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends