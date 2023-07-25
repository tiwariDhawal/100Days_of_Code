//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string S, int K) {
        // code here
        vector<int>mapping(26,0);
        
        int i = 0;
        int j = 0;
        int n = S.size();
        int maxLen = INT_MIN;
        int mostFreqChar = 0;
        while(j < n){
            mapping[S[j] - 'A']++;
            mostFreqChar = max(mostFreqChar,mapping[S[j] - 'A']);
            int charsToChange = (j - i + 1) - mostFreqChar;
            if(charsToChange <= K){
                maxLen = max(maxLen, j - i + 1);
            }
            else{
                mapping[S[i] - 'A']--;
                i++;
            }
            j++;
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends