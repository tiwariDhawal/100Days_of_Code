//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include<bits/stdc++.h>
int maxPalindrome(Node *head)
{
    //Your code here
    Node *temp = head;
    vector<int>arr;
    while(temp != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    int n = arr.size();
    int maxLength = 0;
    int start = 0;
    int end = 0;
    for(int i = 0;i< n;i++){
        int left = i;
        int right = i;
        while(left >= 0 && right < n && arr[left] == arr[right]){
            if(right - left + 1 > maxLength){
                maxLength = right - left + 1;
                
            }
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        while(left >= 0 && right < n && arr[left] == arr[right]){
            if(right - left + 1 > maxLength){
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }
    return maxLength;
    
}