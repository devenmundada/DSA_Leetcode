class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int totalElement = m * n;

        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;

        int count = 0;
        while (count < totalElement) {
            // print Starting Row
            for (int i = startingCol; i <= endingCol && count < totalElement;
                 i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            // print Ending Col
            for (int i = startingRow; i <= endingRow && count < totalElement;
                 i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // print Ending Row
            for (int i = endingCol; i >= startingCol && count < totalElement;
                 i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // print Starting Col
            for (int i = endingRow; i >= startingRow && count < totalElement;
                 i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};