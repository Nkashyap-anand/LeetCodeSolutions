class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                Node*curr=q.front();
                q.pop();
                if(i<n-1)
                {
                    curr->next=q.front();
                }
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return root;
    }
};