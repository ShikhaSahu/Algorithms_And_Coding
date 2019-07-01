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
vector<int> Solution::postorderTraversal(TreeNode* root)
{
      vector<int> ans;
      TreeNode *prev=NULL;
      stack<TreeNode *> s;
      do{
          while(root!=NULL)
          {
              s.push(root);
              root=root->left;
           }
           while(root==NULL && !s.empty())
           {
                root=s.top();
                if(root->right==NULL || root->right==prev)
                {
                      ans.push_back(root->val);
                      s.pop();
                      prev=root;
                      root=NULL;
                }
                else
                    root=root->right;
           }
      }while(!s.empty());
      return ans;
}
