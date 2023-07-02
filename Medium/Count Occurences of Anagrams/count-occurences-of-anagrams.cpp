//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int i=0,j=0;
      int k=pat.length();
      map<char,int>m;
      for(int i=0; i<k; i++){
          m[pat[i]]++;
      }
      int ans=0;
      int count=m.size();
      while(j<txt.size()){
          if(j-i+1<k){
              m[txt[j]]--;
              if(m[txt[j]]==0){
                  count--;
              }
              j++;
          }
          else if(j-i+1==k){
               m[txt[j]]--;
              if(m[txt[j]]==0){
                  count--;
              }
              if(count==0){
                  ans++;
              }
              m[txt[i]]++;
              if(m[txt[i]]==1){
                  count++;
              }
              i++;
              j++;
          }
      }
      return ans;

	}
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends