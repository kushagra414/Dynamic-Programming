class Solution {
public:
    
    class trie{
        public:
            trie* left;
            trie* right;
            
            trie(){
                left=NULL;
                right=NULL;
            }
    };
    
    void insert(trie* root,int val){
        trie* curr=root;
        for(int i=31;i>=0;i--){
            int b=(val>>i)&1;
            if(b==0){
                if(curr->left==NULL){
                    curr->left=new trie();
                }
                curr=curr->left;
            }
            else{
                if(curr->right==NULL){
                    curr->right=new trie();
                }
                curr=curr->right;
            }
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        trie *root=new trie();
        for(int i=0;i<nums.size();i++){
            insert(root,nums[i]);
        }
        
        int max_xor=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int value=nums[i];
            trie* curr=root;
            int curr_xor=0;
            for(int j=31;j>=0;j--){
                int b=((value>>j)&1);
                
                if(b==0){
                    if(curr->right!=NULL){
                        curr_xor=curr_xor+(1<<j);
                        curr=curr->right;
                    }
                    else{
                        curr=curr->left;
                    }
                }
                else{
                    if(curr->left!=NULL){
                        curr_xor=curr_xor+(1<<j);
                        curr=curr->left;
                    }
                    else{
                        curr=curr->right;
                    }
                }
            }
            if(curr_xor>max_xor){
                max_xor=curr_xor;
            }
        }
        return max_xor;
    }
};