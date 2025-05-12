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
    //time complexity: O(n)
    //time complexity: O(n): due to recursive stack(directly proportional to 'height of tree')

    //declaring a 'global sum variable'(so that the value of 'sum' does not change in each recursive call)
    int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        //if root==NULL, then return 0
        if(root==NULL)
            return 0;

        //check the given condition and calculate the 'sum'
        if((root->val >= low) && (root->val <= high))
            sum=sum+(root->val);
        
        //recursively call the 'left subtree' and calculate the 'sum'
        rangeSumBST(root->left,low,high);
        //recursively call the 'right subtree' and calculate the 'sum'
        rangeSumBST(root->right,low,high);

        //return the 'sum'
        return sum;
    }
};
