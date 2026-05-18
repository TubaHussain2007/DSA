/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *p = NULL, *l = NULL, *m = NULL, *h = NULL;
    bool f = 0;
    void Solve(TreeNode* root) {
        if (root == NULL)
            return;
        Solve(root->left);
        if (p != NULL && p->val > root->val) {
            if (f == 0) {
                l = p;
                m = root;
                f = 1;
            } else {
                h = root;
            }
        }
        p = root;
        Solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        Solve(root);
        if (h == NULL)
            swap(l->val, m->val);
        else
            swap(l->val, h->val);
    }
};