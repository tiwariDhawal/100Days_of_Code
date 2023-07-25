//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int i = 0;
        int j = 0;
        int size = s.length();
        // map<char,int>mapping;
        int mapping[26] = {0};
        int maxi = 0;
        while(j < size){
            mapping[s[j] - 'a']++;
            if(mapping[s[j] - 'a'] == 1){
                maxi = max(maxi,j- i + 1);
                j++;
            }
            else if(mapping[s[j] - 'a'] > 1){
                while(mapping[s[j] - 'a'] > 1){
                    mapping[s[i] - 'a']--;
                    // if(mapping[s[i]] == 0){
                    //     mapping.erase(s[i]);
                    // }
                    i++;
                }
                j++;
            }
        }
        if(maxi != 0)return maxi;
        return 0;
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends