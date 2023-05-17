class Solution {
public:
    ListNode *getMid(ListNode *head){
        ListNode *fast = head -> next;
        ListNode *slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head){
        ListNode *forward = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if(head == NULL){
            return 0;
        }
        ListNode *mid = getMid(head);
        ListNode *left = head;
        ListNode *right = reverse(mid -> next);
        mid -> next = NULL;
        int sum = 0;
        int maxi = INT_MIN;
        vector<int>ans;
        while(left != NULL && right != NULL){
            sum = left -> val + right -> val;
            ans.push_back(sum);
            left = left -> next;
            right = right -> next;
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size() - 1];
    }
};
