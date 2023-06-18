//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int start = low;
        int end = high;
        int mid =  start + (end - start)/2;
        while(start < end){
            if(arr[mid] > arr[end]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
            mid = start  + (end - start )/2;
        }
        return arr[start];
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends