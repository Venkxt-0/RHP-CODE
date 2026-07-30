#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string binaryStr = "1001110011";
    
    unordered_map<int, int> firstSeen;
    firstSeen[0] = -1;
    
    int balance = 0;
    int maxLen = 0;

    for (int idx = 0; idx < binaryStr.length(); idx++) {
        balance += (binaryStr[idx] == '1') ? 1 : -1;

        int match = firstSeen.find(balance);
        if (match != firstSeen.end()) {
            int currentLen = idx - match->second;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            firstSeen[balance] = idx;
        }
    }

    cout << maxLen << endl;

    return 0;
}
