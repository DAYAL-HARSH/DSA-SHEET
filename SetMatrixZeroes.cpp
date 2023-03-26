// optimal approach taking two array in the matrix to store zeros in it according to the zeros in the matrix.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = rows-1; i >= 0; i--){
            for(int j = cols-1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};


// GFG question, this ques is a bit different from above instead of making both whole row and column we are doing  
/// in whole matrix when you find a zero, convert its upper, lower, left, and right value to zero and make that element 
// the sum of the upper, lower, left and right value.

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> temp = matrix;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(temp[i][j] == 0){
                    if(i+1 < rows){
                        matrix[i][j] += temp[i+1][j];
                        matrix[i+1][j] = 0;
                    }
                    if(i-1 >= 0){
                        matrix[i][j] += temp[i-1][j];
                        matrix[i-1][j] = 0;
                    }
                    if(j+1 < cols){
                        matrix[i][j] += temp[i][j+1];
                        matrix[i][j+1] = 0;
                    }
                    if(j-1 >= 0){
                        matrix[i][j] += temp[i][j-1];
                        matrix[i][j-1] = 0;
                    }
                }
            }
        }
    }
};
