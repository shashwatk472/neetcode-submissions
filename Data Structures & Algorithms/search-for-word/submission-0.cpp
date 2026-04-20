class Solution {
public:
    vector<int> dirs = {-1,0,1,0,-1};
    bool f(vector<vector<char>>& board, string word, int x, int y, vector<vector<bool>> visited, int idx)
    {
        if(idx == word.size())
            return true;
        
        int n = board.size(), m = board[0].size();
        if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == 1)
            return false;
        
        visited[x][y] = 1;
        return board[x][y] == word[idx] && (f(board, word, x + dirs[0], y + dirs[1], visited, idx + 1) || f(board, word, x + dirs[1], y + dirs[2], visited, idx + 1) || f(board, word, x + dirs[2], y + dirs[3], visited, idx + 1) || f(board, word, x + dirs[3], y + dirs[4], visited, idx + 1));
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                vector<vector<bool>> visited(n, vector<bool>(m, 0));
                if(f(board, word, i, j, visited, 0) == true)
                    return true;
            }
        }
        return false;
    }
};
