class Solution {
public:
    void helper(int index , int n, int k,vector<int>&subset,vector<vector<int>>&ans){
        //dekhta ja k ka size kya h agar wo bada zero ho jata h to return    karde na utne hi to size ka subset chaiye
        if(k == 0){
            ans.push_back(subset);
            return ;
        }
        //more optimised in this line we have bounded upto which the subset is going to be
        if(k > n - index + 1) return ;
        
        if(index > n){
             
            return;
        }
        //take the ith element
        subset.push_back(index);
        helper(index+1,n,k-1,subset,ans);
        
        //skip the ith element 
        subset.pop_back();
        helper(index+1,n,k,subset,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        vector<vector<int>>ans;
        helper(1,n,k,subset,ans);
        return ans;
        
    }
};
