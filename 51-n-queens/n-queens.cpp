class Solution {
public:

    // void helper(int col,int n,vector<int>visited,vector<vector<int>>&ans)
    // {
    //     if(col==n-1)
    //     {
    //         ans.push_back(visited);
    //         return ;
    //     }
    //     //replenish the visited
    //          vector<int> row(n,-1);
    //         for(int j=0;j<n;j++){
    //             if(visited[j]!=-1)
    //             {
    //               row[visited[j]]=1;
    //               int difference=col-j;
    //               int firstrow=visited[j]-difference;
    //               int secondrow=visited[j]+difference;
    //               if(firstrow>=0&& firstrow<n) row[firstrow]=1;
    //               if(secondrow<n) row[secondrow]=1;
    //             }
    //         }
    //     for(int i=0;i<n;i++){
    //         if(row[i]==1)
    //         continue;
    //         visited[col]=i;
    //         helper(col+1,n,visited,ans);
    //         visited[col]=-1;
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<int>visited(n,-1);
    //     vector<vector<int>>ans;
    //     helper(0,n,visited,ans);
    //      vector<vector<string>> final;
    //      for(int i=0;i<ans.size();i++)
    //      {
    //          vector<string> solution;
    //          vector<int> v(n,0);
    //          for(int j=0;j<n;j++)
    //          {
    //                v[ans[i][j]]=j;
    //          }
    //          for(int p=0;p<n;p++)
    //          {
    //              string s;
    //              for(int k=0;k<n;k++)
    //              {
    //                   if(k==v[p])
    //                   {
    //                       s=s+"Q";
    //                   }
    //                   else{
    //                       s=s+".";
    //                   }
    //              }
    //              solution.push_back(s);
    //          }
    //          final.push_back(solution);
    //      }
    //      return final;

void helper(int row, int n, vector<int>& visited, vector<vector<string>>& ans) {
    if (row == n) {
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
            solution[i][visited[i]] = 'Q';
        ans.push_back(solution);
        return;
    }
    for (int col = 0; col < n; ++col) {
        bool can_place = true;
        for (int prev_row = 0; prev_row < row; ++prev_row) {
            if (visited[prev_row] == col || 
                visited[prev_row] - prev_row == col - row || 
                visited[prev_row] + prev_row == col + row) {
                can_place = false;
                break;
            }
        }
        if (can_place) {
            visited[row] = col;
            helper(row + 1, n, visited, ans);
            visited[row] = -1;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> visited(n, -1);
    vector<vector<string>> ans;
    helper(0, n, visited, ans);
    return ans;
}

};