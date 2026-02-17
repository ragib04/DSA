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

void func(TreeNode* root, vector<int> &inorder){
    if(root == NULL) return;
    if(root->left) func(root->left, inorder);
    inorder.push_back(root->val);
    if(root->right) func(root->right, inorder);
}
    vector<int> inorderTraversal(TreeNode* root) {

        // left node right
        vector<int> inorder;
        if(root == NULL) return inorder;
        // stack<TreeNode*> st;
        // TreeNode* node = root;
        

        // while(true){
        //     if(node != NULL){
        //         st.push(node);
        //         node = node->left;
        //     }
        //     else{
        //         if(st.empty() == true) break;

        //         node = st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node = node->right;
        //     }

        // }
        func(root, inorder);
        return inorder;
    }
};