ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    if(A == NULL) return B;
    if(B == NULL) return A;
    
    if(A -> val < B -> val) {
        A->next = Solution::mergeTwoLists(A->next, B);
        return A;
    }
    else {
        B->next = Solution::mergeTwoLists(A, B->next);
        return B;
    }
}