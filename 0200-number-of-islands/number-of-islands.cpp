class Solution {
    int rows, cols;
    void sink(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        if (grid[r][c] != '1') return;
        grid[r][c] = '0';
        sink(grid, r+1, c); sink(grid, r-1, c);
        sink(grid, r, c+1); sink(grid, r, c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size(); cols = grid[0].size();
        int count = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == '1') { ++count; sink(grid, r, c); }
        return count;
    }
};