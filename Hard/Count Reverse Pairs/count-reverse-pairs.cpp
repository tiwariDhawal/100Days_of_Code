//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int count=0;
  public:
  void merge(vector<int>&arr,int low,int mid,int high)
  {
      int right=mid+1;
      int left_dummy=low;
      vector<int>temp;
      while(low<=mid && right<=high)
      {
          if(arr[low]<=arr[right])
          {
              temp.push_back(arr[low++]);
          }
          else
          {
              temp.push_back(arr[right++]);
          }
      }
      while (low<=mid)
      {
          temp.push_back(arr[low++]);
      }
      while(right<=high)
      {
          temp.push_back(arr[right++]);
      }
      int dummy_count=0;
      for(int i=left_dummy;i<=high;i++)
      {
          arr[i]=temp[dummy_count++];
      }
  }
  void fun(vector<int> &arr,int low,int mid,int high)
  {
      int right=mid+1;
      for(int i=low;i<=mid;i++)//for the first array
      {
          while(right<=high && arr[i]>2*arr[right])
          {
              right++;
          }
          count+=right-(mid+1);
      }
  }
  void mergesort(vector<int> &arr,int low,int high)
  {
      if(low==high)
      {
          return;
      }
      int mid=(low+high)/2;
      mergesort(arr,low,mid);//this is left sorted array
      mergesort(arr,mid+1,high);//this is right sorted array
      //now the operation will need to perform
      //okay why merge sort...becaz u need to compare between two sorrted array and merge sort also will give u this
      fun(arr,low,mid,high);
      merge(arr,low,mid,high);
  }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        mergesort(arr,0,n-1);
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends