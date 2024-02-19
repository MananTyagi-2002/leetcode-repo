class Solution {
public:
    bool ispalindrome(int start,int end,string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                return false ;
            }
            start++;
            end--;
        }
        return true;
    }
    void helper(string s, int index,vector<vector<string>>&ans, vector<string>path )
    {
        if(index==s.size())
        {
            //base case at when there is a partition at last index
            ans.push_back(path);
            return;
        }
        for (int i=index;i<=s.size();i++)
        {
            if(ispalindrome(index,i,s))
            {
                path.push_back(s.substr(index,i-index+1));
                helper(s,i+1,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>path;
        helper(s,0,ans,path);
        return ans;
    }
};