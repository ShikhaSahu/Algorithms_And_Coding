/*
Given a binary tree, return the postorder traversal of its nodes’ values.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
*/

void pre(vector<int> &v,TreeNode *A)
 {
     if(A==NULL)
        return;
    
    pre(v,A->left);
    pre(v,A->right);
    v.push_back(A->val);
 }
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v;
    pre(v,A);
    return v;
}
