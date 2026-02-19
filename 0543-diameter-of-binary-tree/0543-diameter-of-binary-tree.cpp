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
// diameter = max(l+r,diameter);
    int height(TreeNode* root,int& Diameter)
    {   
        if(!root) return 0;

        int l=height(root->left,Diameter);
        int r=height(root->right,Diameter);


        //consider this as a ans
        Diameter = max(Diameter, l+r);
        //finding the height of a tree
        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int Diameter=0;
        height(root,Diameter);

        return Diameter;
    }
};