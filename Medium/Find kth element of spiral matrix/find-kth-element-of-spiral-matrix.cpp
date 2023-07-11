//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 	    int row = n;
        int col = m;
        int count = 0;
        
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;
        
        int total  = (row * col);
        vector<int>ans;
        
        while(count < total){
            for(int i = startingCol;i<=endingCol && count < total ;i++ ){
                ans.push_back(a[startingRow][i]);
                count++;
                
            }
            startingRow++;
            for(int i = startingRow;i<=endingRow && count < total;i++){
                ans.push_back(a[i][endingCol]);
                count++;
            }
            endingCol--;
            for(int i = endingCol;i>=startingCol && count < total;i--){
                ans.push_back(a[endingRow][i]);
                count++;
            }
            endingRow--;
            for(int i = endingRow;i>=startingRow && count < total;i--){
                ans.push_back(a[i][startingCol]);
                count++;
            }
            startingCol++;
            
            
        }
        // for(int i = 0;i< ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        return ans[k-1];
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends