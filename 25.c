// Reverse nodes in k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        for(int i = 0; i < k; ++i){
            if(!curr)
            return head;
            curr = curr -> next;
        }
        
        ListNode * new_curr = reverse(head, curr);
        head -> next = reverseKGroup(curr, k);
        return new_curr;
        
    }
    
    ListNode* reverse(ListNode* left, ListNode* right){
        ListNode* prev = right;
        while(left != right){
            ListNode* tmp = left -> next;
            left -> next = prev;
            prev = left;
            left = tmp;
        }
        return prev;
    }
};
