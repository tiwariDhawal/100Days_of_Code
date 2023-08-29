//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends




pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    // sort(arr.begin(),arr.end());
     int ceil=-1,floor=-1;

    int mini=INT_MIN,maxa=INT_MAX;

    

    for(int i=0;i<n;i++)

    {

        if(arr[i]<=x && arr[i]>mini)

        {

            mini=arr[i];

            ceil=arr[i];

        }

        if(arr[i]>=x && arr[i]<maxa)

        {

            maxa=arr[i];

            floor=arr[i];

        }

    }

    

    pair<int,int>p;

    p=make_pair(ceil,floor);

    return p;

    


}