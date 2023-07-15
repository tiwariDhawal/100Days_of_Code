//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int N, long long X)
	{
	    // Your code goes here
	    long nearest = 0;
        long sum=0;
        int s = 0, e=0; // start end

        while (s < N) {
           sum +=arr[s++];
           while (sum > X && e < s){
               sum-=arr[e++];
           }
           if (sum <= X){
               nearest = max(sum,nearest);
           }
        }
        return nearest;
	}  

		 

};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends