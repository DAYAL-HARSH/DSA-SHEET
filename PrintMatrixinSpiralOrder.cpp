//optimal approach

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (res.size() < m * n) {
            for (int j = left; j <= right && res.size() < m * n; j++) {
                res.push_back(matrix[top][j]);
            }
            top++;
        
            for (int i = top; i <= bottom && res.size() < m * n; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            for (int j = right; j >= left && res.size() < m * n; j--) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
        
            for (int i = bottom; i >= top && res.size() < m * n; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
