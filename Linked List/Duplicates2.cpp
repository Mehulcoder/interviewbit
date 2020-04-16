/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
typedef pair<int, int> pii;
#define all(x) (x).begin(), (x).end()
#define f first
#define s second


 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A->next == NULL || A==NULL){
        return A;
    }
    
    int next_val = A->next->val;
    
    ListNode* temp = deleteDuplicates(A->next);
    
    if(temp == NULL){
        if(next_val==A->val){
            return NULL;
        }
        A->next = NULL;
        return A;
    }
    
    if(temp->val == A->val){
        return temp->next;
    }
    
    if(next_val == A->val){
        return temp;
    }
    
    A->next = temp;
    return A;
}
