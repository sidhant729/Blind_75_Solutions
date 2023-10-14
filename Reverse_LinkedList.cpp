// Problem Link -> https://leetcode.com/problems/reverse-linked-list/description/


class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* curr = head;
        ListNode* tail = NULL;

        while(curr != NULL)
        {
            ListNode* nxt = curr->next;
            curr->next = tail;
            tail = curr;
            curr = nxt;
        }
        
        return tail;
    }
};

// T.C. - O(N)
// S.C. - O(1)