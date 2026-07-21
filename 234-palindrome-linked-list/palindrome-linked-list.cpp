class Solution {
public:
     ListNode* reverse(ListNode* head) {
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
     }
    bool isPalindrome(ListNode* head) {
         if(head == NULL || head->next == NULL)
            return true;
             ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverse(slow);
        ListNode* firstHalf = head;
        while(secondHalf){
            if(firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};