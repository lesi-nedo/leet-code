#include <vector>
#include <iostream>

using namespace std;


void setZeroes(vector<vector<int>>& matrix) {
    const auto n_rows {matrix.size()};
    const auto n_cols  {matrix[0].size()};
    bool zero_first_row = false;
    bool zero_first_col = false;
    for (size_t ind_i = 0; ind_i < n_rows && !zero_first_col; ind_i++)
        if (matrix[ind_i][0] == 0)
            zero_first_col = true;
    for (size_t ind_j = 0; ind_j < n_cols && !zero_first_row; ind_j++)
        if(matrix[0][ind_j] == 0)
            zero_first_row = true;

    for (size_t ind_i = 1; ind_i < n_rows; ind_i++) {
        for (size_t ind_j = 1; ind_j < n_cols; ind_j++ ) {
            if (matrix[ind_i][ind_j] == 0) {
                matrix[0][ind_j] = 0;
                matrix[ind_i][0] = 0;
            }
        }
    }

    for (size_t ind = 1; ind < n_cols; ind++) {
        if (matrix[0][ind] == 0)
            for (size_t ind_i = 1; ind_i < n_rows; ind_i++)
                matrix[ind_i][ind] = 0;
    }
    for (size_t ind = 1; ind < n_rows; ind++)
        if (matrix[ind][0] == 0)
            for (size_t ind_j = 1; ind_j < n_cols; ind_j++)
                matrix[ind][ind_j] = 0;

    if (zero_first_row)
        for (size_t ind = 0; ind < n_cols; ind++)
            matrix[0][ind] = 0;
    if (zero_first_col)
        for (size_t ind = 0; ind < n_rows; ind++)
            matrix[ind][0] = 0;
}

int main() {
    vector<vector<vector<int>>> tests {
        // {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}},
        {{1,1,1}, {1,0,1}, {1,1,1}}
    };

    for (auto& test: tests) {
        setZeroes(test);

        for (const auto& row: test) {
            for (const auto& column: row) {
                cout << " " << column;
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    return 1;
}