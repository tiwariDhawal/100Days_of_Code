//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>mapping;
        for(int i = 0;i< str.length();i++){
            mapping[str[i]]++;
        }
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        unordered_map<char,int>temp;
        while(j < str.length()){
            temp[str[j]]++;
            while(temp.size() == mapping.size()){
                ans = min(ans, j - i + 1);
                temp[str[i]]--;
                if(temp[str[i]] == 0){
                    temp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends