class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int count=0;
        for( int i=0;i<matrix.size();i++)
        {
            for(int j=count;j<matrix[0].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
            count++;
        }
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return ;

    }
};