/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int findLen(ListNode *temp){
     int l=0;
     while(temp!=NULL){
         l++;
         temp=temp->next;
     }
     return l;
 }
ListNode* Solution::rotateRight(ListNode* A, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l=findLen(A);
    if(k%l==0) return A;
    ListNode* temp=A;
    for(int i=0;i<l-k%l-1;i++){
        temp=temp->next;
    }
      ListNode* next=temp->next;
    temp->next=NULL;
    
    ListNode *last=next;
    while(last->next!=NULL)
     last=last->next;
     
    last->next=A;
    A=next;
    return A;
}