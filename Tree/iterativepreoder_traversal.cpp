/*
Given a binary tree, return the preorder traversal of its nodes’ values.
*/
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans; //iterative version
    stack<TreeNode*> s;
    while(1)
    {
        while(A)
        {
            ans.push_back(A->val);
            s.push(A);
            A=A->left;
        }
        if(s.empty())
            break;
        A=s.top();
        s.pop();
        A=A->right;
    }
    return ans;
}
