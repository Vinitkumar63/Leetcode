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
    private:
    TreeNode* build(vector<int>& postorder, int & postindex, int start, int end, unordered_map<int,int>& mp){

        // base case
        if(start>end){
            return NULL;
        }
        int rootvalue= postorder[postindex--];
        TreeNode* root= new TreeNode(rootvalue);
         int rootindex=mp[rootvalue];
    // first in postorder we need to write the right part
        root->right= build(postorder, postindex,rootindex+1,end,mp);

        root->left=build(postorder, postindex,start, rootindex-1, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int postindex=postorder.size()-1;

        return build(postorder, postindex,0, inorder.size()-1,mp);
    }
};