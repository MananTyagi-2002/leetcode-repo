class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    vector<int> col(matrix[0].size(), 1);
    vector<int> row(matrix.size(), 1);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (row[i] == 0) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < matrix[0].size(); i++) {
        if (col[i] == 0) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][i] = 0;
            }
        }
    }
    return;
}
};