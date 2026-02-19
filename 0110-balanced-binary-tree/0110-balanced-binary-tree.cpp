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

    /*
    is Balanced Tree? :- left && right && diff -> 1
    if abs diff of left and right subtree is <=1 then return true otherwise false
    also check the root is balanced or not
    */

public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        int diff = abs(height(root->left) - height(root->right));

        if(left && right && diff<=1) return true;
        else return false;
    }

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left, right) + 1;

        return ans;


    }
};