/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        // This code uses the concept of bit vector to count the
        //nodes root to leaf path that gives odd node
        return postOrder(root,0);
    }
    int postOrder(TreeNode *root,int count){
        if(!root)
            return 0;
        count ^= (1<<root->val -1);
        int res = postOrder(root->left,count) +
                  postOrder(root->right,count);
        if(!root->left and !root->right and (count & (count-1)) == 0)
            res++;
        return res;
    }
};