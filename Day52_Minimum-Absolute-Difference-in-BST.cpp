/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode *root,vector<int>&ans){
        if(root == NULL){
            return;
        }
        inorder(root -> left,ans);
        ans.push_back(root -> val);
        inorder(root -> right,ans);
        
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        if(ans.size() == 1){
            return ans[0];
        }
        if(ans.size() == 0){
            return 0;
        }
        int minDiff = 0;
        int mini = INT_MAX;
        int n = ans.size();
        for(int i = 0;i < n-1;i++){
            minDiff = abs(ans[i+1]-ans[i]);
            mini = min(minDiff,mini);
        }
        return mini;

    }
};
