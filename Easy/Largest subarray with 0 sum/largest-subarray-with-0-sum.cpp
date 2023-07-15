//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> sumMap;  // Map to store sum and its index
        int maxLength = 0;
        int sum = 0;
    
        for (int i = 0; i < n; i++) {
            sum += A[i];
    
            // If the current sum is zero, update the maxLength
            if (sum == 0)
                maxLength = i + 1;
    
            // If the current sum exists in the map, update the maxLength
            if (sumMap.find(sum) != sumMap.end())
                maxLength = max(maxLength, i - sumMap[sum]);
    
            // If the current sum doesn't exist in the map, add it
            if (sumMap.find(sum) == sumMap.end())
                sumMap[sum] = i;
        }
    
        return maxLength;

    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends