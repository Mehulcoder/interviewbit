/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* head){
	if (head == NULL || head->next == NULL) 
            return head; 
  
    /* reverse the rest list and put  
      the first element at the end */
    ListNode* rest = reverse(head->next); 
    head->next->next = head; 

    /* tricky step -- see the diagram */
    head->next = NULL; 

    /* fix the head pointer */
    return rest; 
	// return newhead;
} 

ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B==0){
        return A;
    }
    if(A==NULL || A->next==NULL){
        return A;
    }
    
    ListNode* head = A;
    ListNode* head2 = A;
    int temp = B;
    int forprev = B-1;
    while(temp--){
        head = head->next;
    }
    
    while(forprev--){
        head2 = head2->next;
    }
    head2->next = NULL;
    ListNode* temp3 = reverse(A);
    
    ListNode* temp2 = reverseList(head, B);

    A->next = temp2;
    
    return temp3;
}
