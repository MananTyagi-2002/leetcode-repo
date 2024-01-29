class Solution {
public:
    void helper(vector<int>& candidates,int target, int ind,vector<int>ds,vector<vector<int>>&ans)
    {
        // if(ind==candidates.size())
        // { no need for this as we are using loop
            if(target==0)
            {
                ans.push_back(ds);
                return;
            }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            helper( candidates, target-candidates[i],i+1,ds,ans);
            ds.pop_back();
        }    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
            vector<int> ds;
            vector<vector<int>>ans;
            sort(candidates.begin(),candidates.end());
            helper( candidates, target,  0,ds,ans);
            return ans;

    }
};