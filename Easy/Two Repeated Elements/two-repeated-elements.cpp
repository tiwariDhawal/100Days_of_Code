//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int N) {
        // Your code here
        vector<int>ans;
        vector<int>mapping(100000,0);
        for(int i = 0;i< N+2;i++){
            mapping[arr[i]]++;
            if(mapping[arr[i]] == 2){
                ans.push_back(arr[i]);
            }
        }
        // for(auto it:mapping){
        //     if(it.second > 1){
        //         ans.push_back(it.first);
        //     }
        // }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends