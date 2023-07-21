//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void reverse(vector<int>&arr){
    int s= 0;
    int e = arr.size() - 1;
    while(s <= e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    
    }
    void transposeInPlace(vector<vector<int>>&arr,int r,int c){
        for(int i = 0;i< r;i++){
            for(int j = i; j< c;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        
    }
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        // int n = matrix.size();
        for(int i = 0;i< n;i++){
            reverse(matrix[i]);
        }
        transposeInPlace(matrix,n,n);
        } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends