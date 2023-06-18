//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long  rightMostIndex(vector<long long> v,long long x){
        long long ans = -1;
        long start = 0;
        long end = v.size() - 1;
        long mid = start + (end - start)/2;
        while(start <= end){
            if(v[mid] == x){
                ans = mid;
                start = mid + 1;
            
            }
            else if(v[mid] > x){
                end = mid - 1;
    
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
        
    }
    long long  leftMostIndex(vector<long long> v,long long x){
        long long  ans = -1;
        long start = 0;
        long end = v.size() - 1;
        long mid = start + (end - start)/2;
        while(start <= end){
            if(v[mid] == x){
                end = mid - 1;
                ans = mid;
                
            }
            else if(v[mid] > x){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
        
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long leftIndex = leftMostIndex(v,x);
        
        long long rightIndex = rightMostIndex(v,x);
        
        pair<long long,long long> ans;
        ans.first = leftIndex;
        ans.second = rightIndex;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends