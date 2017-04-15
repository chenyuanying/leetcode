// Merge k sorted lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len == 0) return NULL;
        if(len == 1) return lists[0];
        else if(len == 2) return mergeTwoLists(lists[0], lists[1]);
        else{
            vector<ListNode*> leftLists(lists.begin(), lists.begin() + len / 2);
            vector<ListNode*> rightLists(lists.begin() + len / 2, lists.end());
            ListNode *left = mergeKLists(leftLists);
            ListNode *right = mergeKLists(rightLists);
            return mergeTwoLists(left, right);
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                curr -> next = l1;
                l1 = l1 -> next;
            }else{
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr -> next;
        }
        curr -> next = l1 ? l1 : l2;
        return dummy.next;
    }
    
};
