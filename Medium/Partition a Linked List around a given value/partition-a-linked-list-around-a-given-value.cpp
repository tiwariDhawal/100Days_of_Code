//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    Node* p=new Node(0);

    Node* q=new Node(0);

    Node* r=new Node(0);

    Node* a=p;

    Node *b=q;

    Node* c=r;

    while(head!=NULL){

        if(head->data<x){

            a->next=head;

            a=a->next;

        }

        else if(head->data==x){

            b->next=head;

            b=b->next;

            

        }

        else {

            c->next=head;

            c=c->next;

        }

        head=head->next;

        

    }

     if(q->next!=NULL){

         a->next=q->next;

         b->next=r->next;

         c->next=NULL;

     }

     else{

         a->next=r->next;

         c->next=NULL;

     }

     return p->next;

 

    
}