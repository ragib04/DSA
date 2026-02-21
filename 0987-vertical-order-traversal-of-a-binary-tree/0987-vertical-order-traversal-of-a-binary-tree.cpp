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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> node;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            node[hd][lvl].insert(frontNode->val);

            if(frontNode->left){
                q.push({frontNode->left, {hd-1, lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right, {hd+1, lvl+1}});
            }
        }
        for(auto i : node){
        vector<int> col;
        for(auto j : i.second){
            col.insert(col.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(col);
      }
      return ans;
    }
};