/* recursive preorder tree traversal*/

void pre(vector<int> &ans,TreeNode *A)
 {
     if(A==NULL)
        return;
    ans.push_back(A->val);
    pre(ans,A->left);
    pre(ans,A->right);
 }
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    pre(ans,A);
    return ans;
}
