class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        std::unordered_map<int, int> mp;  // To count occurrences of each type of fruit
        int left = 0;
        int maxi = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            // Add the current fruit (on the right) to the basket
            mp[fruits[right]]++;

            // If we have more than 2 distinct fruits, shrink the window from the left
            while (mp.size() > 2) {
                mp[fruits[left]]--;  // Decrease the count of the left fruit
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);  // Remove the fruit if its count becomes 0
                }
                left++;  // Move the left pointer to shrink the window
            }

            // Update the maximum number of fruits we can collect
            maxi = std::max(maxi, right - left + 1);
        }

        return maxi;
    }

};