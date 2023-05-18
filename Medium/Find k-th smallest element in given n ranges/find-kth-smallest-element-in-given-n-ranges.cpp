//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
         // Code here
         vector<vector<int>>ans;
         if(in.size()==0)
         return ans;
         
         sort(in.begin(),in.end());
         vector<int>temp=in[0];
         for(auto it:in)
         {
            if(it[0]<=temp[1])
            {
                temp[1]=max(it[1],temp[1]);
            }
            else 
            {
                ans.push_back(temp);
                temp= it;
            }
         }
     ans.push_back(temp);
     return ans;
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        vector<int>ans;
         sort(range.begin(),range.end());
         vector<vector<int>>merged=overlappedInterval(range);
         /*for(auto it:merged)
         {
             cout<< it[0] << endl;
             cout << it[1] << endl;
         }*/
         for(int i=0;i<queries.size();i++)
         {
             int k=queries[i];
             bool flag=false;
             for(int i=0;i<merged.size();i++)
             {
                 int diff=merged[i][1]-merged[i][0]+1;
                 if(diff>=k)
                 {
                     ans.push_back(merged[i][0]+k-1);
                     flag=true;
                     break;
                 }
                 else
                 k-=diff;
             }
             if(flag==true)
             flag=false;
             else
             ans.push_back(-1);
         }
         return ans;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends