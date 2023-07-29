//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    Node *temp = head;
    vector<int>ans;
    while(temp != NULL){
        ans.push_back(temp-> data);
        temp = temp -> next;
    }
    int count = 0;
    for(int i = 0;i< ans.size();i++){
        // sort(ans.begin(),ans.end());
        int start = i+1;
        int end = ans.size() - 1;
        while(start < end){
            int sum = ans[start] + ans[end] + ans[i];
            if(sum == x){
                count++;
                start++;
                end--;
            }
            else if(sum > x){
                end--;
                
            }
            else if(sum < x){
                start++;
            }
            
        }
    }
    return count;
} 