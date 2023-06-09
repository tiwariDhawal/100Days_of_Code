//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int>ans = {-1};
	    int s = 0;
	    for(int i = 0;i< n;i++){
	        vector<int>v;
	        int sum = 0;
	        while(a[i] >= 0 && i < n){
	            sum = sum + a[i];
	            v.push_back(a[i]);
	            i++;
	        }
	        if(sum == s && ans.size() < v.size()){
	            s = sum;
	            ans = v;
	        }
	        else if(sum > s){
	            s = sum;
	            ans = v;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends