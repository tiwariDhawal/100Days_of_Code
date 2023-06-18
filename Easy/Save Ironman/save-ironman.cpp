//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

bool saveIronman(string ch);


int main()
{
    int t,b,c,d,e,f,g,h;
    cin>>t;
    char cc;
    cc = getchar();
    
    while(t--)
    {
        string ch;
        getline(cin,ch);
        
        if(saveIronman(ch)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
}

// } Driver Code Ends



bool saveIronman(string ch)
{
    // Complete the function
    string ans = "";
    for(int i = 0;i< ch.length();i++){
        char character = ch[i];
        if(!((character >= 32 && character <= 47) || (character >= 58 && character <= 64) || 
        (character >= 91 && character <= 96) ||(character >= 123 && character <= 126))){
            if(character >= 65 && character <= 90){
                character = character + 32;
                ans.push_back(character);
            }
            else{
                ans.push_back(character);
            }
            
        }
    }
    string ans2 = "";
    for(int i = 0;i< ans.length();i++){
        char character = ans[i];
        ans2.push_back(character);
    }
    reverse(ans.begin(),ans.end());
    if(ans2 == ans){
        return true;
    }
    return false;
    
}
