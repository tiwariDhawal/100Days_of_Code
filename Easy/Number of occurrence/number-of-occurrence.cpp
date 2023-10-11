//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lastOccurence(int arr[],int n,int x){
	    int s = 0;
	    int e = n - 1;
	    int mid = s + (e-s)/2;
	    int ans = -1;
	    while(s <= e){
	        
         if(arr[mid] == x){
           ans = mid;
           s = mid + 1;
         }
         else if(arr[mid] > x){
             e = mid - 1;
         }
         else if(arr[mid] < x){
             s = mid + 1;
         }
	     mid = s + (e-s)/2;
	    }
	    return ans;
	}
	int firstOccurence(int arr[],int n,int x){
	    int s = 0;
	    int e = n - 1;
	    int mid = s + (e-s)/2;
	    int ans = -1;
	    while(s <= e){
	        
         if(arr[mid] == x){
           ans = mid;
           e = mid - 1;
         }
         else if(arr[mid] > x){
             e = mid - 1;
         }
         else if(arr[mid] < x){
             s = mid + 1;
         }
	     mid = s + (e-s)/2;
	    }
	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	    // code here
	    int ans1 = firstOccurence(arr,n,x);
	    int ans2 = lastOccurence(arr,n,x);
	    if(ans1 == -1){
	        
	        return 0;
	    }
	    else if(ans1 == ans2){
	        return 1;
	    }
	    return (lastOccurence(arr,n,x) - firstOccurence(arr,n,x)) + 1;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends