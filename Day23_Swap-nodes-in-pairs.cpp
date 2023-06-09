/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseInPairs(ListNode* head,int k){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        int count = 0;
        while(curr != NULL && count < k){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward != NULL){
            head -> next = reverseInPairs(forward,k);
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        int k = 2;
        ListNode *ans = reverseInPairs(head,k);
        return ans;
        

        
    }
};
