/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* head, int length){
    if (head == NULL || head->next == NULL) 
            return head;
            
    if(length == 1 || length == 0){
        return head;
    }
    /* reverse the rest list and put  
      the first element at the end */
    ListNode* rest = reverse(head->next, length-1);
    ListNode* temp = head->next->next;
    head->next->next = head;
    head->next = temp;
    
    return rest;
    
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {

    int  a = 1;
    ListNode* head = A;
    ListNode* prev = NULL;
    while(a<B){
        prev = head;
        head = head-> next;
        a++;
    }
    
    if(prev==NULL){
        return reverse(head, C-B+1);
    }
    prev->next = reverse(head, C-B+1);
    
    return A;
    
}
