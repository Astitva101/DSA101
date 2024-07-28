/*Question:
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the
 longest path from the root node down to the farthest leaf node.*/


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return std::max(leftDepth, rightDepth) + 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * int param_1 = obj->maxDepth(root);
 */