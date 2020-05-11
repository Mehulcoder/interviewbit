
ListNode* Solution::subtract(ListNode* A) {
    ListNode* head = A;
    ListNode* last = A;
    int count = 1;
    vector<int> values;
    while(last->next != NULL){
        values.push_back(last->val);
        count++;
        last = last->next;
    }
 
    values.push_back(last->val);
    int n = values.size();
 
    for (int i = 0; i < count/2; ++i)
    {
        head->val = values[n-i-1]-values[i];
        head=head->next;
    }
 
    return A;
 
 
 
}