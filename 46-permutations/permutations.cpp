class Solution {
public:

    void helper(int ind,vector<int>nums,vector<int> ds,vector<vector<int>>&ans, vector<int>visited){
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==1)
            continue;
            ds.push_back(nums[i]);
            visited[i]=1;
            helper(i+1,nums,ds,ans,visited);
            visited[i]=0;
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<int> ds;
         vector<vector<int>>ans;
         vector<int>visited(nums.size(),0);
         helper(0,nums,ds,ans,visited);
         return ans;
    }
};