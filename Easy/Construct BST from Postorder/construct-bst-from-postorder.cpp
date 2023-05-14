//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/

Node*solv(int post[],int mini,int maxi,int &i){
    if(i<0){
        return NULL;
    }
    if(post[i]<=mini || post[i]>=maxi){
        return NULL;
    }
    
    Node*root=new Node(post[i--]);
    root->right=solv(post,root->data,maxi,i);
    root->left=solv(post,mini,root->data,i);
    
    return root;
}

Node *constructTree (int post[], int size)
{
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=size-1;
    return solv(post,mini,maxi,i);
}