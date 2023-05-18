//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        set<int>s;

        vector<int>v;

        for(int i =n-1;i>=0;i--)

        {

            s.insert(arr[i]);

            auto it = s.find(arr[i]);

            it++;

            if(it==s.end())

            {

                v.push_back(-1);

            }

            else

            {

                v.push_back(*it);

            }

        }

        

        reverse(v.begin(),v.end());

        return v;
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
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends