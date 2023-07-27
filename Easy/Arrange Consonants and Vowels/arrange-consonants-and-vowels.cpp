//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
struct Node* arrange(Node *head)
{
   //Code here
        Node *curr=head ;
        Node *vow = new Node('a');
        Node *t1=vow;
        Node *con = new Node('a');
        Node *t2=con;
        
        while(curr != NULL)
        {
            if(curr->data =='a' || curr->data =='e' || curr->data =='i' || curr->data =='o' ||curr->data =='u')
            //if there are vowels storing them in ll;
            {
                Node *t = new Node(curr->data);
                t1->next=t;
                t1=t1->next;
                curr=curr->next;
                
            }
            else
            {
                //if it is not vowel storing into another ll
                  Node *t = new Node(curr->data);
                   t2->next=t;
                   t2=t2->next;
                  curr=curr->next;
                
            }
        }
        //while loop ends means ll are finished
        //now we eii joined our both ll
        t1->next=con->next;
        return vow->next;
}
