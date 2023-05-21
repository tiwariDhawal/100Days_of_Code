//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int nums[], int n, int X)
    {
        //Your Code Here
        int sum = 0;
        sort(nums,nums+n);
        
        // int m = nums.size();
        for(int i = 0;i< n;i++){
            int start = i+1;
            int end = n - 1;
            while( start < end){
                sum = nums[i] + nums[start] + nums[end];
                if(sum == X){
                    return true;
                    start++;
                    end--;
                }
                else if(sum > X){
                    end--;
                }
                else{
                    start++;
                }
            }

        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends