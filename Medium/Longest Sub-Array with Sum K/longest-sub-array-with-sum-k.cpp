//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
       unordered_map<int,int> map;
        int i = 0, j = 0;
        int result = 0,sum = 0;
        while(j<N){
           sum += A[j];
           if(sum == K){
            result = max(result,j - i + 1);
           }
           if(map.find(sum) == map.end()){
               map[sum] = j;
           }
           if(map.find(sum - K) != map.end()){
               result = max(result,j - map[sum-K]);
           }
            
            j++;
        }
        return result;
        
    }

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends