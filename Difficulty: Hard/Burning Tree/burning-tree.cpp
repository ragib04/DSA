/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


/*
Intuition:- every node burn his adjecent Node means left right parent if not visited
step1:- create Node to parent Mapping using map data structure using lvl order trav
step2 - find target node
step3- burn the tree in min time
        in the burn time we take a visited map to track the tree is burn or not
*/
class Solution {
  public:
  Node* nodeToparentMapping(Node* root, int target, map<Node*, Node*> &mp){
      Node* tar = NULL;
      queue<Node*> q;
      q.push(root);
      mp[root] = NULL;
      while(!q.empty()){
          Node* front = q.front();
          q.pop();
          if(front->data == target) tar = front;
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
  int BurnTree(Node* root, map<Node*, Node*> &nodeToparent){
      map<Node*, bool>visited;
      queue<Node*> q;
      q.push(root);
      int ans = 0;
      while(!q.empty()){
          int n = q.size();
          bool flag = false;
          for(int i = 0; i<n; i++){
              Node* front = q.front();
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
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> nodeToparent;
        Node* targetNode = nodeToparentMapping(root, target, nodeToparent);
        int time = BurnTree(targetNode, nodeToparent);
        return time;
    }
};