class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j)
    {
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        vector<int> x = {-1, 0, 1, 0 , -1}  ;
        for(int k = 0; k < x.size() - 1; k++)
        {
            helper(grid, i + x[k], j + x[k + 1]);
        }  
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    helper(grid, i, j);
                }

            }
        }

        return ans;
    }
};
