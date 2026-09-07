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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l=height_left(root);
        int r=height_right(root);
        if(l==r){
            return (1<<l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int height_left(TreeNode* x){
        int s=0;
        while(x){
            s++;
            x=x->left;
        }
        return s;
    }

    int height_right(TreeNode* x){
        int s=0;
        while(x){
            s++;
            x=x->right;
        }
        return s;
    }
};