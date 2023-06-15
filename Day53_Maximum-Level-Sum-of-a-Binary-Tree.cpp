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
    int maxLevelSum(TreeNode* root) {
        vector<pair<int,int>>ans;
        int level = 1;
        int max_level = 0;
        queue<TreeNode*>q;
        q.push(root);
        int maxi = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0;i< size;i++){
                TreeNode *front = q.front();
                q.pop();

                sum = sum + front -> val;
                if(front -> left){
                    q.push(front -> left);
                }
                if(front -> right){
                    q.push(front -> right);
                } 
            }
            if (sum > maxi) {
                maxi = sum;
                max_level = level;
            }
            level++;
           
            
        }
        
        return max_level;
        
        
        
    }
};
