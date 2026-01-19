/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
void insert(ListNode* &head, ListNode* &tail, int val){
    ListNode* newHead = new ListNode(val);
    if(head == NULL){
        head = newHead;
        tail = head;
        return;
    }
    tail->next = newHead;
    tail = newHead;
}
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* temp = head;
        while(temp){
            insert(newHead, newTail, temp->val);
            if(temp->next == NULL) break;
            temp = temp->next->next;
        }
        temp = head->next;
        while(temp){
            insert(newHead, newTail, temp->val);
            if(temp->next == NULL) break;
            temp = temp->next->next;
        }
        return newHead;
    }
};