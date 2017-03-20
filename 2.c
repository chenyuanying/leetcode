// Add Two Numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carryFlag = 0;
    int firstFlag = 1;
    struct ListNode *oldPtrR = NULL;
    struct ListNode *currPtrR = NULL;
    struct ListNode *result = NULL;
    struct ListNode *currPtrl1 = l1;
    struct ListNode *currPtrl2 = l2;
    while(currPtrl1 != NULL || currPtrl2 != NULL){
        currPtrR = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(firstFlag != 1){
            oldPtrR -> next = currPtrR;
        }else{
            result = currPtrR;
            firstFlag = 0;
        }
        if(currPtrl1 == NULL){
            currPtrR -> val = (0 + currPtrl2 -> val + carryFlag) % 10;
            carryFlag = (0 + currPtrl2 -> val + carryFlag) / 10;
            currPtrl2 = currPtrl2 -> next;
        }else if(currPtrl2 == NULL){
            currPtrR -> val = (currPtrl1 -> val + 0 + carryFlag) % 10;
            carryFlag = (currPtrl1 -> val + 0 + carryFlag) / 10;
            currPtrl1 = currPtrl1 -> next;
        }else{
            currPtrR -> val = (currPtrl1 -> val + currPtrl2 -> val + carryFlag) % 10;
            carryFlag = (currPtrl1 -> val + currPtrl2 -> val + carryFlag) / 10;
            currPtrl1 = currPtrl1 -> next;
            currPtrl2 = currPtrl2 -> next;
        }
        currPtrR -> next = NULL;
        oldPtrR = currPtrR;
        currPtrR = currPtrR -> next;
    }
    if(carryFlag == 1){
        currPtrR = (struct ListNode*)malloc(sizeof(struct ListNode));
        oldPtrR -> next = currPtrR;
        currPtrR->val = 1;
        currPtrR -> next = NULL;
    }
    return result;
}
