class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prevNode = new TreeNode(INT_MIN);

    void traverse(TreeNode* root) {
        if (!root) return;

        traverse(root->left);

        if (first == nullptr && root->val < prevNode->val) {
            first = prevNode;
        }
        if (first != nullptr && root->val < prevNode->val) {
            second = root;
        }
        prevNode = root;

        traverse(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
