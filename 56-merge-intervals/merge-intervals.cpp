class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                // combine and delete the i+1 interval and adjust index accordingly
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + i + 1);
                n--; // Decrease the size after erasing an interval
                i--; // Adjust index after erasing an interval
            }
        }
        return intervals;
    }
};