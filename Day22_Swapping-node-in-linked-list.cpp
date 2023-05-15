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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *ans;
        int size = 0;
        while(temp != NULL){
            size = size + 1;
            if(size == k){
                ans = temp;
            }
            temp = temp -> next;
        }
        temp = head;
        for(int i = 0;i< (size - k);i++){
            temp = temp -> next;
            
        }
        swap(ans -> val, temp -> val);
        return head;
    }
};
