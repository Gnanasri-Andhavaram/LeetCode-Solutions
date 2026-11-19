class Solution {
public:
    int minDepth(TreeNode* root) {
        // Base case: if the tree is empty, the depth is 0
        if (!root) return 0;

        // If the left subtree is null, we must recur down the right subtree
        // (since a leaf node must have no children)
        if (!root->left) return 1 + minDepth(root->right);

        // If the right subtree is null, we must recur down the left subtree
        if (!root->right) return 1 + minDepth(root->left);

        // If both children exist, return 1 plus the minimum depth of both subtrees
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
