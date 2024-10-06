class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;  // Use char, not int, as the key
        int left = 0;
        int right = 0;
        int maxi = 0;  // Stores the maximum length of the window
        int maxFreq = 0;  // Stores the highest frequency of any character in the current window

        for (; right < s.length(); right++) {
            char curr = s[right];
            mp[curr]++;
            
            // Keep track of the character with the highest frequency in the current window
            maxFreq = max(maxFreq, mp[curr]);
            
            // Check if the number of replacements needed exceeds `k`
            if ((right - left + 1) - maxFreq > k) {
                // If replacements exceed k, shrink the window by moving the left pointer
                mp[s[left]]--;
                left++;
            }
            
            // Calculate the maximum window size
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};
