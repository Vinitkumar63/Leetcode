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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;

        if(root==NULL)
        return result;

        // now queue layo
        queue<TreeNode*>q;
        q.push(root);

        bool left_to_right=true;

        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            int index;

            if(left_to_right)
            index=i;
            else
            index=size-i-1;

            level[index]=node->val;
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
            }
        result.push_back(level);

        // this line is used to change the direction of the transversal
        left_to_right=!left_to_right;
        }
    return result;
    }
};