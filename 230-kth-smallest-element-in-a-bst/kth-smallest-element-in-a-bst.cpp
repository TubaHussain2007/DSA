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
 int cnt = 0;
    int kthSmall = -1;
    void inorder(TreeNode* node, int k) {
        if (!node || cnt >= k) return;
        inorder(node->left, k);
        cnt++;
        if (cnt == k) kthSmall = node->val;
        inorder(node->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        inorder(root, k);

        return kthSmall;
    }
};