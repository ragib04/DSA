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
bool solve(TreeNode* root, long long mi, long long mx){
    if(root == NULL) return true;
    if(root->val>mi && root->val<mx){
        bool left = solve(root->left, mi, root->val);
        bool right = solve(root->right, root->val, mx);
        return left && right;
    }
    return false;
}
    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
        return solve(root, INT_MIN, INT_MAX);
    }
};