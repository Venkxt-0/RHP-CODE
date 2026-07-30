#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string strA, strB;
    cout << "Enter string1: ";
    cin >> strA;
    cout << "Enter string2: ";
    cin >> strB;

    int lenA = strA.length();
    int lenB = strB.length();

    vector<vector<int>> grid(lenA + 1, vector<int>(lenB + 1, 0));
    
    int maxLen = 0;
    int endIdx = 0;

    for (int r = 1; r <= lenA; r++) {
        for (int c = 1; c <= lenB; c++) {
            if (strA[r - 1] == strB[c - 1]) {
                grid[r][c] = grid[r - 1][c - 1] + 1;
                
                if (grid[r][c] > maxLen) {
                    maxLen = grid[r][c];
                    endIdx = r;
                }
            }
        }
    }

    string lcs = strA.substr(endIdx - maxLen, maxLen);
    cout << "Longest Substring: '" << lcs << "'" << endl;

    return 0;
}
