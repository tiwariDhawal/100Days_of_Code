//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void help(long long int a,long long int b,long long int n){
    if(n==0) return ;
  long long   int c=a*a-b;
    a=b;
    b=c;
    cout<<c<<" ";
    help(a,b,n-1);
}
    void gfSeries(int N)
    {
        // Write Your Code here
       if(N==0) cout<<0<<endl;
       if(N==1) cout<<0<<" "<<1<<endl;
       
       N=N-2;
       long long int k=1ll*N;
       if(N>0) cout<<0<<" "<<1<<" ";
       help(0,1,k);
       cout<<endl;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.gfSeries(N);
    }
    return 0;
}
// } Driver Code Ends