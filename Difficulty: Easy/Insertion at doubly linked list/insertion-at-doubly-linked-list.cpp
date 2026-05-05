/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        //Node* prev = head;
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            if(cnt == p){
                Node* newNode = new Node(x);
                Node* temp1 = temp->next;
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = temp1;
                if(temp1 != NULL) temp1->prev = newNode; 
                break;
            }
            cnt++;
            temp = temp->next;
           // prev = temp;
        }
        return head;
    }
};