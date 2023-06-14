// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    // int firstOcc(int arr[],int n,int k){
    //     int s = 0;
    //     int e = n-1;
    //     int mid = s + (e-s)/2;
    //     while(s<=e){
    //         if(arr[mid] == k){
    //             ans = mid;
    //             e = mid -1;
    //         }
    //         else if(arr[mid]<k){
    //             s = mid + 1;
    //         }
    //         else{
    //             e = mid -1;
    //         }
    //     }
    //     return ans;
    // }
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        map<int,int>m;
        
        for(int i=0;i<n;i++){
           m[a[i]]++;
           
           if(m[a[i]]==k)
           return a[i];
        }
        return -1;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}  // } Driver Code Ends