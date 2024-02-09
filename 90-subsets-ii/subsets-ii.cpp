class Solution {
public:
    void helper(vector<int>nums,int ind,int N,vector<int> ans, set<vector<int>> &set)
    {
       if(ind==N)
       {
           //base case 
           set.insert(ans);
           return;
       }

       //pick
       ans.push_back(nums[ind]);
       helper(nums,ind+1,N,ans,set);


       ans.pop_back();

       //notpick
       helper(nums,ind+1,N,ans,set);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> set;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        helper(nums,0,nums.size(),ans,set);
        vector<vector<int>> finalans;
        for(auto s: set)
        {
            finalans.push_back(s);
        }
        return finalans;
 
    }
};