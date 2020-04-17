/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    int length = 0;
    ListNode* head = A;
    
    
    if(A==NULL || A->next == NULL){
        return A;
    }
    
    ListNode* temphead = swapPairs(A->next->next);
    ListNode* second = A->next;
    A->next = temphead;
    second->next = A;
    return second;
}
