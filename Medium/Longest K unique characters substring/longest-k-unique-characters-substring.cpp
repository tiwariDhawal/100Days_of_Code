//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int size = s.length();
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;
        unordered_map<char,int>mapping;
        while(j < size){
            mapping[s[j]]++;
            if(mapping.size() < k){
                j++;
            }
            else if(mapping.size() == k){
                maxi = max(maxi,j- i + 1);
                j++;
            }
            else if(mapping.size() > k){
                while(mapping.size() > k){
                    mapping[s[i]]--;
                    if(mapping[s[i]] == 0){
                        mapping.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(maxi != INT_MIN){
            return maxi;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends