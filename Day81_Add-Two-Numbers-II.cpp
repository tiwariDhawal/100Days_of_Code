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
private:

    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
    }
    return prev;
}
public:
    
    void insertAtTail(ListNode *&head,ListNode *&tail,int val){
        ListNode *temp = new ListNode(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    ListNode *add(ListNode *first,ListNode *second){
        int carry  = 0;
        ListNode *ansHead = NULL;
        ListNode *ansTail = NULL;
        while(first != NULL && second != NULL){
            int val1 = first -> val;
            int val2 = second -> val;
            int sum = val1 + val2 + carry ;
            int digit = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum / 10;
            first = first -> next;
            second = second -> next;
            
        }
        while(first != NULL){
            int val1 = first -> val;
            
            int sum = val1 +  carry ;
            int digit = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum / 10;
            first = first -> next;
        }
        while(second != NULL){
           
            int val2 = second -> val;
            int sum = val2 + carry ;
            int digit = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum / 10;
            second = second -> next;
        }
        while(carry != 0){
            int sum = carry;
            int digit  = sum % 10;
            insertAtTail(ansHead,ansTail,digit);
            carry = sum / 10;
        }
        return ansHead;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = reverse(l1);
        ListNode* second = reverse(l2);
        
        //add both the lists
        ListNode *ans = add(first,second);
        
        //reverse the ans
        ans = reverse(ans);
        return ans;
    }
};
