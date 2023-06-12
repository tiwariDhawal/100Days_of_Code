//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int len1 = m - l + 1;
         int len2 = r - m;
         
         int *first = new int[len1];
         int *second = new int[len2];
         
         int k = l;
         for(int i = 0;i< len1;i++){
             first[i] = arr[k++];
         }
         k = m + 1;
         for(int i = 0;i< len2;i++){
             second[i] = arr[k++];
         }
         
         
        
         
         //merge 2 sorted array
         int i = 0;
         int j = 0;
         
         int startingIndex = l;
         while(i <len1 && j < len2){
             if(first[i] < second[j]){
                 arr[startingIndex++] = first[i++];
             }
             else{
                 arr[startingIndex++] = second[j++];
             }
         }
         while(i < len1){
             arr[startingIndex++] = first[i++];
         }
         while(j  < len2){
             arr[startingIndex++] = second[j++];
         }
         
         delete[] first;
         delete[] second;
        

         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        //Step 1:Giving the values of mergesort 
        //l = start
        //r = end
        //base case
        if(l >= r){
            return;
        }
        int mid = l + (r-l)/2;
        
        
        
        //Step 2:Second value of the merge sort
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends