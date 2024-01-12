class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> mp;
        for(int i=0;i<n+1;i++)
        {
           mp[nums[i]]++;
           if(mp[nums[i]]>1)
           {
               return nums[i];
           }
        }
        return 0;
    }
};