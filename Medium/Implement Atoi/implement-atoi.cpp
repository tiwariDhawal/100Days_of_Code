//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int number = 0;
        for(int i = 0;i< str.length();i++){
            if(str[i] >= '0' && str[i] <= '9'){
                int digit = (char)str[i] - '0';
    
                number = number * 10 + digit;
            }
            if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'|| str[i+1] == '-'  || str[i+1] == '+'
            || str[i] =='*' || str[i] == '/'){
                return -1;
            }
        }
        if(str[0] == '-'){
            number *= -1;
        }
        
        return number;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends