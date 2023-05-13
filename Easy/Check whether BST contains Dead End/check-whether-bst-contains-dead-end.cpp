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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_set<int>map1;
    unordered_set<int>map2;
    map1.insert(0);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *front = q.front();
        q.pop();
        map1.insert(front -> data);
        if(front -> left == NULL && front -> right == NULL){
            map2.insert(front -> data);
        }
        
        if(front -> left){
            q.push(front -> left);
        }
        if(front -> right){
            q.push(front -> right);
        }
    }
    int count = 0;
    for(auto it : map2){
        if(map1.find(it - 1) != map1.end() && map1.find(it + 1) != map1.end()){
            return true;
        }
        
    }
    
    return false;
}