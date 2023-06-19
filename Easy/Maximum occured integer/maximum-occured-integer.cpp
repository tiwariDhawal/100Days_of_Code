//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        // Your code here
        int *arr = new int[1000000];
        //range  = [2,3,4,5]
        //prefix Sum = 2,5,9,14
        // arr{} = {0,0,1,0,0,0,-1,...,0}
        for(int i = 0;i< n;i++){
            arr[L[i]]++;
            arr[R[i]+1]--;
        }
        for(int i = 1;i<1000000;i++){
            arr[i] = arr[i] + arr[i-1];
        }
        int res = 0;
        for(int i = 0;i< 1000000;i++){
            if(arr[i] > arr[res]){
                res = i;
            }
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    Solution ob;
	    
	    //calling maxOccured() function
	    cout << ob.maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}
// } Driver Code Ends