//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    private:
    Node* reverse(Node *head){
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    public:
    void insertAtTail(Node *&head,Node *&tail,int data){
        Node *temp = new Node(data);
        if(head==NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail ->next = temp;
            tail = temp;
        }
    }
    Node *add(Node* first, Node* second){
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        while(first!= NULL || second != NULL || carry!= 0){
            int val1 = 0;
            if(first!= NULL){
                val1 = first -> data;
            }
            int val2 = 0;
            if(second!= NULL){
                val2 = second-> data;
            }
            
            int sum = carry + val1 +val2;
            int digit = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10;
            
            if(first!=NULL){
                
              first = first->next;
            }
            if(second!=NULL){
                
              second = second->next;
            }
        }
        return ansHead;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        //reverse the linked list
        head = reverse(head);
        
        Node *second = new Node(1);
        second = reverse(second);
        
        //add both the numbers
        Node *ans = add(head,second);
        
        ans = reverse(ans);
        return ans;
        
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
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends