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
 int maxsum=0;// here we write max sum ;

void solve(TreeNode* root, int & mini,int& maxi,int &sum, bool &isBST ){
    if(root==NULL){
        mini=INT_MAX;
        maxi=INT_MIN;
        sum=0;
        isBST=true;
        return;
    }
    // write for left subtree
    int leftmin,leftmax,leftsum;
    bool leftisBST;
    

    // similarly write for right
    int rightmin,rightmax,rightsum;
     bool rightisBST;

    solve(root->left,leftmin,leftmax,leftsum,leftisBST);

    solve(root->right,rightmin,rightmax,rightsum,rightisBST);

    if(leftisBST && rightisBST && leftmax<root->val && root->val<rightmin){

        // here we check is bst true;
        isBST=true;// this is important
        
        sum= leftsum+root->val+ rightsum;
        mini= min(leftmin,root->val);
        maxi=max(rightmax,root->val);

       
        maxsum=max(maxsum,sum);
    }else{
        isBST=false;
        sum=0;
    }
}
    int maxSumBST(TreeNode* root) {
        int mini,maxi,sum;
         bool isBST;

        solve(root,mini,maxi,sum,isBST);
        return maxsum;
    }
};