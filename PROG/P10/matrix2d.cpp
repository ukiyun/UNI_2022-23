#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}

bool max_filter(vector<vector<int>>& v, int n) {
    // Check if n is odd
    if (n % 2 == 0) {
        return false; // Invalid parameter
    }

    // Check if the dimensions of the matrix are at least n
    int rows = v.size();
    int cols = v[0].size();
    if (rows < n || cols < n) {
        return false; // Invalid parameter
    }

    // Create a temporary matrix to store the filtered values
    vector<vector<int>> temp(rows, vector<int>(cols));

    // Apply the max filter to each element of the matrix
    for (int i = n/2; i < rows - n/2; i++) {
        for (int j = n/2; j < cols - n/2; j++) {
            // Find the maximum value in the neighbourhood
            int max_val = v[i][j];
            for (int ii = i - n/2; ii <= i + n/2; ii++) {
                for (int jj = j - n/2; jj <= j + n/2; jj++) {
                    if (v[ii][jj] > max_val) {
                        max_val = v[ii][jj];
                    }
                }
            }

            // Store the maximum value in the temporary matrix
            temp[i][j] = max_val;
        }
    }

    // Copy the filtered values back to the original matrix
    v = temp;

    return true; // Parameters are valid
}
