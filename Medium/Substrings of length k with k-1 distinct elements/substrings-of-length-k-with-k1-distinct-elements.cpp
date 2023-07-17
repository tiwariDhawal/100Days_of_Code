//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Temappinglate for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        int i=0; 
        int j=0;
        unordered_map<int,int>mapping; 
        
        
        int count=0;  
        
        while(j<s.length()){
            mapping[s[j]]++;
            
            if(j-i+1 < k){
                j++;
            }
            else if (j-i+1 == k){
              if(mapping.size()==k-1){
                  count++;
              }
              mapping[s[i]]--;
              if(mapping[s[i]]==0){
                  mapping.erase(s[i]);
              }
              i++;
              j++;
                
            }
        } 
    
    return count;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends