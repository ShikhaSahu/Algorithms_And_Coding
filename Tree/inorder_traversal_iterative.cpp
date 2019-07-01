/*
Given a binary tree, return the inorder traversal of its nodes’ values.
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
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> v;
    stack<TreeNode*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->left;
        }
        if(s.empty())
            break;
         root=s.top();
         v.push_back(root->val);
         s.pop();
         root=root->right;
    }
    return v;
}
