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
    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted_elements = inorderTraversal(root);
        int left = 0, right = sorted_elements.size() - 1;
                                        
        while (left < right) {
            int current_sum = sorted_elements[left] + sorted_elements[right];
            if (current_sum == k) {
                return true;
            } else if (current_sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
    private:
    vector<int> inorderTraversal(TreeNode* node) {
        vector<int> elements;
        inorderHelper(node, elements);
        return elements;
    }

    void inorderHelper(TreeNode* node, vector<int>& elements) {
        if (!node) return;
        inorderHelper(node->left, elements);
        elements.push_back(node->val);
        inorderHelper(node->right, elements);
    }
};