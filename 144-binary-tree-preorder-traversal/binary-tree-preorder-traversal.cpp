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
    void preorder(TreeNode* root, vector<int>& input){
    if(root==NULL){
    return;}
    input.push_back(root->val);
    preorder(root->left, input);
    preorder(root->right, input);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> input;
    preorder(root, input);
    return input;
}
};