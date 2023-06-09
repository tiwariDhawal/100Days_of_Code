//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dataTypeSize(string str) {
        // your code here
        int output = 0;
        if(str == "Integer"){
            output =  4;
        }
        else if(str == "Character"){
            output =  1;
        }
        else if(str == "Long"){
            output = 8; 
        }
        else if(str == "Float"){
            output = 4;
        }
        else if(str == "Double"){
            output = 8;
        }
        return output;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends