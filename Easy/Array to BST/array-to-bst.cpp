//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solve(vector<int>&ans,vector<int>&nums,int start, int end){
        if(start > end){
            return;
        }
        int mid = start + (end - start)/2;
        ans.push_back(nums[mid]);
        
        solve(ans,nums,start,mid-1);
        solve(ans,nums,mid+1,end);
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
        solve(ans,nums,0,nums.size() - 1);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends