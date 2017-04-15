// Swap nodes in pairs
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        dummy.next = head;
        ListNode *pre = curr;
        curr = curr -> next;
        while(curr){
            if(curr -> next != NULL){
                ListNode *after = curr -> next -> next;
                pre -> next = curr -> next;
                curr -> next -> next = curr;
                pre = curr;
                curr = after;
            }else{
                break;
            }
        }
        pre -> next = curr;
        return dummy.next;
    }
};
