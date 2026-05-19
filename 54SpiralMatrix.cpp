class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minRow = 0;
        int minCol = 0;
        int maxCol = matrix[0].size()-1;
        int maxRow = matrix.size()-1;
        vector<int> ans;
        while (minRow <= maxRow && minCol <= maxCol) {
            for (int j = minCol; j <= maxCol; j++) {
                ans.push_back(matrix[minRow][j]);
            }
            minRow++;
            for (int i = minRow; i <= maxRow; i++) {
                ans.push_back(matrix[i][maxCol]);
            }
            maxCol--;
            if (minRow <= maxRow) {
                for (int j = maxCol; j >= minCol; j--) {
                    ans.push_back(matrix[maxRow][j]);
                }
                maxRow--;
            }
            if (minCol<= maxCol) {
                for (int i = maxRow; i >= minRow; i--) {
                    ans.push_back(matrix[i][minCol]);
                }
                minCol++;
            }
        }
        return ans;
    }
};