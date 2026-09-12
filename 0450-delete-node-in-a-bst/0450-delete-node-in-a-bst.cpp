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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{

            // no left child
            if(root->left==NULL){
                return root->right;
            }
            // no right child
            if(root->right==NULL){
                return root->left;
            }
            // see if their are both child on both side
            TreeNode* succesor= root->right;
            // we see the smallest value
            while(succesor->left!=NULL){
                succesor=succesor->left;
            }
            root->val=succesor->val;
            // this delete the connection
            root->right= deleteNode(root->right, succesor->val);
        }
        return root;

    }
};