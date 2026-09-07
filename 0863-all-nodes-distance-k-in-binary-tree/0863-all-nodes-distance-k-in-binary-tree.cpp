/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            // store value like parent[5]=3 as node=q.front()
            if (node->left != NULL) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right != NULL) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        markparents(root, parent);
        TreeNode* node = q.front();
        q.push(target);
        // as it will not visited again
        unordered_map<TreeNode*, bool> visited;
        visited[target]=true;
        int distance=0;
        while (!q.empty()) {
            int size = q.size();
            if (distance == k) {
                break;
            }
            distance++;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL && !visited[node->left]){
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right!=NULL && !visited[node->right]){
                    visited[node->right]=true;
                    q.push(node->right);
                }
                // now parent
                if(parent[node]!=NULL && !visited[parent[node]]){
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};