class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return buildBST(1, n);
    }
    private:
     vector<TreeNode*> buildBST(int start, int end){
        vector<TreeNode*> li;
        if(start > end){
            li.push_back(NULL);
            return li;
        }
        if(start == end){
            li.push_back(new TreeNode(start));
            return li;
        }
        for(int indx = start; indx<=end; indx++){
         vector<TreeNode*> leftNodeList = buildBST(start, indx-1);
         vector<TreeNode*> rightNodeList = buildBST(indx+1, end);
            for(TreeNode* leftSide : leftNodeList){
                for(TreeNode* rightSide : rightNodeList){
                    TreeNode* root = new TreeNode(indx);
                    root->left = leftSide;
                    root->right = rightSide;
                    li.push_back(root);
                }
            }
        }
        return li;
    }
};
