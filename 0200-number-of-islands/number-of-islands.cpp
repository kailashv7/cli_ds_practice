class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        function<void(int,int)> sink = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols) return;
            if (grid[r][c] != '1') return;
            grid[r][c] = '0';
            sink(r+1, c);
            sink(r-1, c);
            sink(r, c+1);
            sink(r, c-1);
        };

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == '1') { ++count; sink(r, c); }

        return count;
    }
};