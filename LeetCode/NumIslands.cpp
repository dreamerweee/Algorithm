/*
* 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
* 一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
*/

void DFS(vector<vector<char>> &grid, int row, int col, int grid_row, int grid_col)
{
    grid[row][col] = '0';
    if (row - 1 >= 0 && grid[row-1][col] == '1') {
        DFS(grid, row-1, col, grid_row, grid_col);
    }
    if (col + 1 < grid_col && grid[row][col+1] == '1') {
        DFS(grid, row, col+1, grid_row, grid_col);
    }
    if (row + 1 < grid_row && grid[row+1][col] == '1') {
        DFS(grid, row+1, col, grid_row, grid_col);
    }
    if (col - 1 >= 0 && grid[row][col-1] == '1') {
        DFS(grid, row, col-1, grid_row, grid_col);
    }
}

int NumIslands(vector<vector<char>>& grid)
{
    int grid_row = grid.size();
    if (grid_row == 0) {
        return 0;
    }
    int grid_col = grid[0].size();
    int num = 0;
    
    for (int row = 0; row < grid_row; ++row) {
        for (int col = 0; col < grid_col; ++col) {
            if (grid[row][col] == '1') {
                ++num;
                DFS(grid, row, col, grid_row, grid_col);
            }
        }
    }
    return num;
}