/*
You are given a tree and you need to do the level order traversal on this tree.
Level order traversal of a tree is breadth-first traversal for the tree.
*/

void levelOrder(Node* node)
{
  //Your code here
    if(node==NULL)
        return;
    queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
   // cout<<endl;
}
