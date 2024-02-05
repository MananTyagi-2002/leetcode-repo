class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxcount=INT_MIN;
        for( char c: s)
        {
            maxcount=max(count,maxcount);
            if(c=='(') count++;
            if (c==')') count--;
        }
        return maxcount;

    }
};