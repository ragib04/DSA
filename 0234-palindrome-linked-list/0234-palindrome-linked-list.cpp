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
void reverseLL(ListNode* &head, ListNode* temp){
    if(temp->next == NULL) {
        head = temp;
        return;
    }
    
    reverseLL(head,temp->next);
    temp->next->next = temp;
    temp->next = NULL;


}
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;
        ListNode* temp = head;
        while(temp){
            insert(newHead, newTail, temp->val);
            temp = temp->next;
        }
        reverseLL(newHead, newHead);

        temp = head;
        while(temp){
            if(temp->val != newHead->val) return false;
            temp = temp->next;
            newHead = newHead->next;
        }
        return true;
    }
};