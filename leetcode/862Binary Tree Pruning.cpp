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
    // bool solve(TreeNode* &root) {
    //     // bc
    //     if (!root) return false;

    //     bool left = solve(root->left);
    //     bool right = solve(root->right);

    //     // remove curr left child
    //     if (left) {
    //         TreeNode* toDelete = root->left;
    //         // isolate
    //         root->left = NULL;
    //         // delete
    //         delete toDelete;
    //     }
    //     if (right) {
    //         TreeNode* toDelete = root->right;
    //         root->right = NULL;
    //         delete toDelete;
    //     }

    //     // for currnode become leaf node
    //     if (root->val == 0 && !root->left && !root->right) {
    //         return true;
    //     }

    //     return false;
    // }

    // IMPORTANT**** - yhi bhool jaunga
    // upar me maine existing tree me se node ko hi delete maar di
    // aur jab leetcode khud memory free kr rha yaa access kr rha apne liye 
    // to use wo memory nhi mil rhi kyunki wo delete ho rakhi hai

    bool solve(TreeNode* &root) {
        // empty node prunable
        if (!root) return true;

        bool left = solve(root->left);
        bool right = solve(root->right);

        // isolate child if prune found
        if (left) {
            root->left = NULL;
        }
        if (right) {
            root->right = NULL;
        }

        // if curr become leaf node with val = 0
        return (root->val == 0 && !root->left && !root->right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        
        // if curr become leaf node with val = 0
        if (solve(root)) {
            return NULL;
        }

        return root;
    }
};
