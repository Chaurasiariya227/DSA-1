#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int columnCount = grid[0].size();

        // Iterate through each cell in the grid to calculate the minimum path sum
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < columnCount; ++col) {
                if (row == 0 && col == 0) {
                     continue; // Skip the starting cell as it is the beginning of the path
                  
                } 
                else if (row == 0) {
                    // If we are in the first row, the only way to reach this cell is from the left
                    grid[row][col] += grid[row][col - 1];
                } 
                else if (col == 0) {
                    // If we are in the first column, the only way to reach this cell is from above
                    grid[row][col] += grid[row - 1][col];
                } 
                else {
                    // For all other cells, choose the minimum path sum from either the cell above or the cell to the left
                    grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
                }
            }
        }

        // Return the value in the bottom-right cell, which represents the minimum path sum
        return grid[rowCount - 1][columnCount - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> exampleGrid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "The minimum path sum for the first grid is: " << solution.minPathSum(exampleGrid1) << endl; // Output=7
    return 0;
}
