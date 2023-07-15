//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int A[], int n)
    {
        // Your code here
        for(int i=0; i<n; i++){
            if(A[i] == 0)A[i] = -1;
        }
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
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends