//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        vector<int>ans;
        set<int>mainAns;
        unordered_map<int,int>mapping;
        for(int i = 0;i< n;i++){
            mapping[arr[i]]++;
        }
        for(auto it:mapping){
            ans.push_back(it.second);
            mainAns.insert(it.second);
            
        }
        if(mainAns.size() < ans.size()){
            return false;
        }
        return true;
       
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends