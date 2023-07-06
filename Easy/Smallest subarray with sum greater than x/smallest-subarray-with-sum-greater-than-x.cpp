//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i = 0;
        int j = 0;
        int sum= 0;
        int mini = INT_MAX;
        while(j < n){
            sum = sum + arr[j];
            while(sum > x){
                mini = min(mini,j - i + 1);
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends