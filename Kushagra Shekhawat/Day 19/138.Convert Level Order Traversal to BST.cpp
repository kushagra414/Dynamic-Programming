//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function

Node *ArrayToBST(Node *root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data<=root->data)
        root->left = ArrayToBST(root->left,data);
    else
        root->right = ArrayToBST(root->right,data);
        
    return root;
}

Node* constructBst(int arr[], int n)
{
    Node *root = NULL;
    for(int i=0;i<n;i++)
        root = ArrayToBST(root,arr[i]);
    
    return root;
}
