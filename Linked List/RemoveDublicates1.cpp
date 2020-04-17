/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return A;
    }
    
    ListNode* rest = deleteDuplicates(A->next);
    ListNode* mover = rest;
    
    int data = A->val;
    if(rest->val == data){
        return rest;
    }
    
    A->next = rest;
    
    return A;
}
