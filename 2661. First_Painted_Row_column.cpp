#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    int n = arr.size();
    int total_row = mat.size();
    int total_col = mat[0].size();
    // pre proceccesed all the values of the matrix in the array
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < total_row; i++)
    {
        for (int j = 0; j < total_col; j++)
        {
            mp[mat[i][j]] = {i, j}; // storing the position of element with its value in matrix
        }
    }
    vector<int> row(total_row, 0); // will store the frequency of each row present in matrix;
    vector<int> col(total_col, 0); //  will store the frequency of each column present in matrix;
    // step-1 --> traversing the array
    for (int i = 0; i < n; i++)
    {
        // step-2 --> finding the position of element present in array in matrix
        int curr_row = mp[arr[i]].first;
        int curr_col = mp[arr[i]].second;
        // step-3 --> increasing frequency of that row and column in vector
        row[curr_row]++;
        col[curr_col]++;
        if (row[curr_row] == total_col)
            return i;
        if (col[curr_col] == total_row)
            return i;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 4, 5, 2, 6, 3};
    vector<vector<int>> mat = {{4, 3, 5}, {1, 2, 6}};
    cout << firstCompleteIndex(arr, mat);
}