//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string>ans;
	    void printf(int ind,string &s,string res){
	        int n = s.length();
	        if(ind == n){
	            if(res == "")return;
	            ans.push_back(res);
	            return;
	        }
	        
	        res.push_back(s[ind]);
	        printf(ind + 1,s,res);
	        res.pop_back();
	        printf(ind + 1,s,res);
	        
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int size = s.length();
		    printf(0,s,"");
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends