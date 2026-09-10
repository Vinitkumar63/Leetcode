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
    vector<int> inorderTraversal(TreeNode* root) {
        // we are solving this by morris method must remember here the space complexity is 0(1) and time is o(n);
        
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* pred=curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }
                // here we move left
                if(pred->right==NULL){  // this is the last boottom right part of left tree
                    pred->right=curr;
                    
                    curr=curr->left;
                }
                else{
                    pred->right=NULL; // this is the joint which we add at the end so taht we can reach ro the root again
                    ans.push_back(curr->val);
                    curr=curr->right; // because inorder is left root, right
                }
            }
        }
        return ans;
    }
};