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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1 && head->next == NULL) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int pos = cnt-n;
        if(pos == 0) return head->next;
        temp = head;
        ListNode* prev = NULL;
        while(temp && pos != 0){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        if(temp->next == NULL) prev->next= NULL;
        else prev->next = temp->next;
        return head;
    }
};