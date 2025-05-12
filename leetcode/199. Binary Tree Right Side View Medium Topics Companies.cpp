class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*> q;
        if(root==NULL)
        return ans;
        q.push(root);
        while(1)
        {
            int size=q.size();
            if(size==0)
            return ans;
            vector<int> data;
            while(size--)
            {
                TreeNode* temp=q.front();
                q.pop();
                data.push_back(temp->val);
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            ans.push_back(data.back());
        }
    }
};
