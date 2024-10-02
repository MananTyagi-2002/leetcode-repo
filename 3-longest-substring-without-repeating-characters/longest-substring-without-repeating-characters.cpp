class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mp; 
    int l = 0, mlength = 0;

    for (int r = 0; r < s.length(); ++r) {
        char current = s[r];
        if (mp.find(current) != mp.end()) {
            l = max(l, mp[current] + 1);
        }
                mp[current] = r;
        mlength = max(mlength, r - l + 1);
    }

    return mlength;

    }
};