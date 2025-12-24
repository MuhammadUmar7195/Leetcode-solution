#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     // Brute Force Approach TC will be O(n*m) SC will be O(1)
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int k = 0; k < matrix[i].size(); k++)
//             {
//                 if (matrix[i][k] == target)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
    
// };

class Solution {
public:
    // Binary Search Approach with TC O(log(n*m)) SC will be O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
            return false;

        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            if(matrix[i][j] > target){
                j--;
            }else {
                i++;
            }
        }

        return false;
    }
};


int main()
{
    Solution solution;
    
    // Test case 1
    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    cout << "Test 1 - Target " << target1 << ": " << (solution.searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;
    
    // Test case 2
    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 13;
    cout << "Test 2 - Target " << target2 << ": " << (solution.searchMatrix(matrix2, target2) ? "Found" : "Not Found") << endl;
    
    return 0;
}