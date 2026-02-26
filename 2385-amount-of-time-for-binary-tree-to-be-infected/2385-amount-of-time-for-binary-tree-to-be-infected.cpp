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
Intuition:- every node infected with his adjecent Node means left right parent if not visited
step1:- create Node to parent Mapping using map data structure using lvl order trav
step2 - find target node
step3- infect the tree in min time
        in the infection time we take a visited map to track the tree is infected or not
*/
    TreeNode* NodeToparentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &mp){
      TreeNode* tar = NULL;
      queue<TreeNode*> q;
      q.push(root);
      mp[root] = NULL;
      while(!q.empty()){
          TreeNode* front = q.front();
          q.pop();
          if(front->val == target) tar = front;
          if(front->left){
              mp[front->left] = front;
              q.push(front->left);
          }
          if(front->right){
              mp[front->right] = front;
              q.push(front->right);
          }
      }
      return tar;
  }
  int infectedTree(TreeNode* root, map<TreeNode*, TreeNode*> &nodeToparent){
      map<TreeNode*, bool>visited;
      queue<TreeNode*> q;
      q.push(root);
      int ans = 0;
      while(!q.empty()){
          int n = q.size();
          bool flag = false;
          for(int i = 0; i<n; i++){
              TreeNode* front = q.front();
              q.pop();
              visited[front] = 1;
              if(!visited[front->left] && front->left){
                  flag = true;
                  visited[front->left] = 1;
                  q.push(front->left);
              }
              if(front->right && !visited[front->right]){
                  flag = true;
                  visited[front->right] = 1;
                  q.push(front->right);
              }
              if(nodeToparent[front] && !visited[nodeToparent[front]]){
                  flag = true;
                  visited[nodeToparent[front]] = 1;
                  q.push(nodeToparent[front]);
              }
          }
          if(flag == true) ans++;
      }
      return ans;
  }

        
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToparent;
        TreeNode* target = NodeToparentMapping(root, start, nodeToparent);
        return infectedTree(target, nodeToparent);
    }
};