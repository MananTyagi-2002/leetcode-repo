class Solution {
public:
    void calculatingCombinationSum(vector<int>& candidates, int target,int ind, vector<vector<int>> &ans, vector<int>ds )
    {
        if(ind==candidates.size())
        {
            if(target==0)
         {
            ans.push_back(ds);
         }
            return;
        }

        if(candidates[ind]<=target)
        {
            //picked
          ds.push_back(candidates[ind]);
        calculatingCombinationSum( candidates, target-candidates[ind], ind, ans, ds );
        ds.pop_back();
        }
        //not picked
        calculatingCombinationSum( candidates, target, ind+1, ans, ds );
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        int ind=0;

        calculatingCombinationSum( candidates, target, ind, ans, ds );
        return ans;

    }
};