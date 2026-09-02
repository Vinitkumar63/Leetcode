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
void solve(TreeNode* root, int row,int col, 
  map<int, map<int,vector<int>>>&mp){ // we donnot need copy 
       if(root==NULL)
        return;

mp[col][row].push_back(root->val);

// left child
solve(root->left,row+1,col-1,mp);
// right child
solve(root->right,row+1,col+1,mp);
   }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
    map<int,map<int,vector<int>>>mp;
        solve(root,0,0,mp);
        for(auto &colPair:mp){
            vector<int>temp;
            for(auto & rowPair:colPair.second){

                sort(rowPair.second.begin(),rowPair.second.end());

        for(int value:rowPair.second){
        temp.push_back(value);
        }
        
            }
            ans.push_back(temp);
        }
        return ans;
    }
};