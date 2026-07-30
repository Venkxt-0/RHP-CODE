#include <iostream>
#include <vector>

using namespace std;

int main() {
    int height, width;
    cout << "Enter number of rows: ";
    cin >> height;
    cout << "Enter number of columns: ";
    cin >> width;

    vector<vector<int>> grid(height, vector<int>(width));
    cout << "Enter elements of matrix:\n";
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            cin >> grid[r][c];
        }
    }

    int targetRow, targetCol;
    cout << "Enter the input row and col index: ";
    cin >> targetRow >> targetCol;

    int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    int neighborSum = 0;
    for (int t = 0; t < 8; t++) {
        int nextR = targetRow + directions[t][0];
        int nextC = targetCol + directions[t][1];

        bool inBounds = (nextR >= 0 && nextR < height) && (nextC >= 0 && nextC < width);
        if (inBounds) {
            neighborSum += grid[nextR][nextC];
        }
    }

    cout << "AdjSum : " << neighborSum << endl;

    return 0;
}
