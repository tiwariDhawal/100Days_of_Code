//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
      //Your code here
        if(n == 0)return 0;
        sort(nums,nums+n);
        
        int lastSmaller = INT_MIN;
        int count = 0;
        int longest = 1;
        for(int i = 0;i< n;i++){
            if(nums[i] - 1 == lastSmaller){
                count = count + 1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                count = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest,count);
        }
        return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends