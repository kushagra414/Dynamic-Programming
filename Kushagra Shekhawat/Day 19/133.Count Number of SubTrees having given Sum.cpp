//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Your are required to complete this function
int countSubtreesWithSumX(Node* root, int x);

int main()
{
  int t;
  cin>>t;
  getchar();
  while (t--)
  {
     string s;
     getline(cin,s);
     Node* root = buildTree(s);
     
     int x;
     cin>>x;
     getchar();
     cout << countSubtreesWithSumX(root, x)<<endl;
  }
  return 0;
}

// } Driver Code Ends
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X

int Count =0;

int countSubTree(Node *root, int x){
    if(!root)
        return 0;
    int leftSum = countSubTree(root->left,x);
    int rightSum = countSubTree(root->right,x);
    int sum = leftSum+rightSum+root->data;
    //cout<<"Sum is :"<<sum<<" and leftSum :"<<leftSum<<" and rightSum :"<<rightSum<<"and root :"<<root->data<<endl;
    if(sum==x)
        Count++;
    return sum;
}

int countSubtreesWithSumX(Node* root, int x)
{
    Count =0;
	countSubTree(root,x);
	return Count;
}
