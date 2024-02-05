class Solution {
public:
    bool isAnagram(string s, string t) {
       int arr[27]={0};
       int p=0;

       for(char c:s)
       {
           p=toupper(c)-'A';
           arr[p]++;
       }
        int arr2[27]={0};
        p=0;

       for(char c:t)
       {
           p=toupper(c)-'A';
           arr2[p]++;
       }
       for(int i=0;i<27;i++)
       {
           if (arr[i]!=arr2[i])
           return false;
       }
       return true;
    }
};