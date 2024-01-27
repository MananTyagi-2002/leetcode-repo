class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find break point 
        int bp=-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
              //nums[i]==breakpoint
              bp=i;
              break;
            }
        }
            if(bp==-1)
            {
                  reverse(nums.begin(),nums.end());
                  return ;
            }
        

        //find the just greater number
        int jg=-1;
          for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[bp])
            {
              //nums[i]==breakpoint
              jg=i;
              break;
            }
        }
        swap(nums[jg],nums[bp]);
        reverse(nums.begin()+bp+1,nums.end());
        return;

    }
};