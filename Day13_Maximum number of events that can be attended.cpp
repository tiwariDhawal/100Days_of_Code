//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        // code here
        vector<pair<int,int>>v;
        unordered_set<int>S;
        //inserting all the meeting in a vector
        for(int i = 0;i< N;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end());
        for(int i =v.size() - 1;i>=0;i--){
            //v[i].second = ending date and v[i].first = starting date
            if(S.find(v[i].second) == S.end()){
                S.insert(v[i].second);
            }
            else{
                int e = v[i].second;
                while(e >= v[i].first){
                    if(S.find(e) == S.end()){
                        S.insert(e);
                        break;
                    }
                    e--;
                }
            }
        }
        return S.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];

        Solution ob;
        cout << ob.maxEvents(start,end,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
