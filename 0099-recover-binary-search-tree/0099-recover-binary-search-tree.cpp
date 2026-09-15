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
TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prev=NULL;
    void recoverTree(TreeNode* root) {
        TreeNode* current=root;
        while(current!=NULL){
            if(current->left==NULL){
            if(prev!=NULL && prev->val> current->val){
                if(first==NULL)
                first=prev;
                second=current;
            }
            prev=current;

            // now move right
            current=current->right;
        }else{
            TreeNode* predecessor=current->left;
            while(predecessor->right!=NULL && predecessor->right!=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==NULL){

                // join karo predecessor->right ko current menas root sa
                predecessor->right=current;

                // now current=current->left;
                current=current->left;
            }else{
                // hama fir predecessor ->right ko NULL karna hoga.
                predecessor->right=NULL;
                if(prev!=NULL && prev->val> current->val){
                    if(first==NULL)
                    first=prev;
                    second=current;
                }

                prev=current;
                current= current->right;
            }
        }
        }
        swap(first->val , second->val);

    }
};