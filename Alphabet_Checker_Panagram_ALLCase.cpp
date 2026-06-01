#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int lower_flag = 0;
    int upper_flag = 0;
    
    cout << "Enter a String: ";
    getline(cin, s); 
    
    for(char c : s) {
        if (c >= 'a' && c <= 'z') {
            lower_flag = lower_flag | (1 << (c - 'a'));
        }
        else if (c >= 'A' && c <= 'Z') {
            upper_flag = upper_flag | (1 << (c - 'A'));
        }
    }
    
    int target = (1 << 26) - 1;
    if (lower_flag == target && upper_flag == target) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
