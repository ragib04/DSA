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

 /*
 lvl order so we need que

 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = false;

        while (!q.empty()) {
            int n = q.size();
            vector<int> ans;  

            for (int i = 0; i < n; i++) {
                TreeNode* frontNode = q.front();
                q.pop();

              
                // int index = leftToRight ? i : n - i - 1;
                 //ans[index] = frontNode->val;

                ans.push_back(frontNode->val);

                
                if (frontNode->left) q.push(frontNode->left);
                if (frontNode->right) q.push(frontNode->right);
            }

            if(leftToRight){
                reverse(ans.begin(), ans.end());
            }
            res.push_back(ans);

       
            leftToRight = !leftToRight;
        }

        return res;
    }
};
