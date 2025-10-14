/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  Node* merge2LL(Node* l1, Node* l2){
      Node* dummyNode = new Node(-1);
      Node* temp = dummyNode;
      while(l1 && l2){
      if(l1->data<=l2->data){
         temp->bottom = l1;
         l1 = l1->bottom;
      }
      else{
          temp->bottom = l2;
          l2 = l2->bottom;
      }
      temp = temp->bottom;
      }
      if(l1) temp->bottom = l1;
      if(l2) temp->bottom = l2;
      
      return dummyNode->bottom;
      
      
  }
    Node *flatten(Node *root) {
        // code here
        Node* temp = root;
        Node* mergeLL = root;
        temp = temp->next;
        
        while(temp){
            Node* nexNode = temp->next;
            mergeLL = merge2LL(mergeLL, temp);
            temp = nexNode;
            
        }
        return mergeLL;
        
    }
};