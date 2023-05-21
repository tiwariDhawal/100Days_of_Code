//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int>negative;
        vector<int>positive;
        
        for(int i=0; i<n; i++){
            if(arr[i]<0) negative.push_back(arr[i]);
            else
            if(arr[i]>0) positive.push_back(arr[i]);
        }
        for(int i=0; i<positive.size(); i++){
            arr[i]=positive[i];
        }
        int index=0;
        for(int i=positive.size(); i<n; i++){
            arr[i]=negative[index++];
        }
        
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends