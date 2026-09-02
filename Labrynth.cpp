#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int diff[] = {0, -1, 0, 1, 0};
const string dir = "LURD";

string getPath(int startRow, int startCol, int endRow, int endCol, const vector<vector<char>>& g) {
    string ans = "";
    int prow = endRow;
    int pcol = endCol;

    while (prow != startRow || pcol != startCol) {
        char ch = g[prow][pcol];
        ans += ch;
        
        if (ch == 'L') pcol++;
        else if (ch == 'R') pcol--;
        else if (ch == 'U') prow++;
        else if (ch == 'D') prow--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solution() {
    int R, C;
    if (!(cin >> R >> C)) return;

    vector<string> matrix(R);
    for (int i = 0; i < R; i++) {
        cin >> matrix[i];
    }

    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 'A') {
                startRow = i;
                startCol = j;
            } else if (matrix[i][j] == 'B') {
                endRow = i;
                endCol = j;
            }
        }
    }

    queue<pair<int, int>> Q;
    vector<vector<char>> g(R, vector<char>(C, ' '));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    Q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    bool found = false;

    while (!Q.empty()) {
        auto [row, col] = Q.front();
        Q.pop();

        if (row == endRow && col == endCol) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = row + diff[i];
            int ncol = col + diff[i + 1];

            if (nrow >= 0 && nrow < R && ncol >= 0 && ncol < C) {
                if (matrix[nrow][ncol] != '#' && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = true;
                    g[nrow][ncol] = dir[i]; 
                    Q.push({nrow, ncol});
                }
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string ans = getPath(startRow, startCol, endRow, endCol, g);
    cout << ans.length() << "\n";
    cout << ans << "\n";
}

	int main() {
	    ios::sync_with_stdio(false);
	    cin.tie(NULL);
	    solution();
	    return 0;
	}
