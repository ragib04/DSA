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
ListNode* reverseLL(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = NULL;
    while(temp){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
ListNode* getkthNode(ListNode* temp, int k){
    k -= 1;
    while(temp && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        while(temp){
            ListNode* kthNode = getkthNode(temp, k);

            if(kthNode == NULL){
                if(prevlast){
                    prevlast ->next = temp;

                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp ==head) head = kthNode;
            else{
                prevlast->next = kthNode;
            }
            prevlast = temp;
            temp = nextNode;

        }
        return head;
        
    }
};