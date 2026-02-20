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

/*
check 2 tree are identical or not ;- two trees are considered identical if bot are structurally same and nodes have same value

so trav both with together
*/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL || p != NULL && q == NULL) return false;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        bool value = p->val == q->val;
        if(left && right && value) return true;
        return false;

    }
};