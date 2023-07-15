//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int i = 0;
        int j = 0;
        int maxi = 0;
        int sum = 0;
        unordered_map<int, int> sumMap;
    
        sumMap[0] = -1; // Initialize map with sum 0 at index -1
    
        while (j < n) {
            sum += arr[j];
            int rem = (sum % k + k) % k; // Calculate modulo with handling negative values
    
            if (sumMap.find(rem) != sumMap.end()) {
                maxi = max(maxi, j - sumMap[rem]);
            } else {
                sumMap[rem] = j;
            }
    
            j++;
        }
    
        return maxi;
    	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends