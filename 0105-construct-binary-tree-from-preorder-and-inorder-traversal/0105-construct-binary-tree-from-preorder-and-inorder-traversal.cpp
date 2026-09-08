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
    TreeNode* build(vector<int>& preorder, int & preindex, int start,int end, unordered_map<int,int>& mp){
        if(start>end){
            return NULL;
        }
        int rootValue= preorder[preindex++];
        TreeNode* root= new TreeNode(rootValue);
        int rootIndex= mp[rootValue];

        root->left=build(preorder,preindex, start, rootIndex-1,mp);

        root->right=build(preorder,preindex,rootIndex+1,end,mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preindex=0;
        return build(preorder,preindex,0,inorder.size()-1,mp);
    }
};