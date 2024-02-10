class Solution {
public:
    void helper (vector<int>& candidates, int target, vector<vector<int>>& ans ,int ind, int N, vector<int> set)
    {
        if(ind==N)
        {
            if(target==0)
            ans.push_back(set);
            return;
        }
         if(candidates[ind]<=target){
         //pick
         set.push_back(candidates[ind]);
         helper(candidates,target-candidates[ind],ans,ind,N,set);

         //not pick
         set.pop_back();
         }
         helper(candidates,target,ans,ind+1,N,set);
         return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> set;
         helper(candidates,target,ans,0,candidates.size(),set);
         return ans;
    }
};