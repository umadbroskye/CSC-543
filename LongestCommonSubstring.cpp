#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Your program should take in 2 strings, you can assume for this assignment that they are identical in length.
string longestCommonSubstring(const string& s1, const string& s2) {
    int maxLength = 0;
    int endingIndexS1 = 0;
    int m = s1.length(), n = s2.length();

    // You should create a lookup table similar to the previous slide that shows the dynamically growing table that can ultimately be used to determine an answer
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endingIndexS1 = i;
                }
            }
        }
    }

    // your program’s output should be a 2D grid similar to what is shown in the previous slide along with the solution (solution in main())
    cout << "Lookup table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << "\n";
    }

    return s1.substr(endingIndexS1 - maxLength, maxLength);
}

int main() {
    string s1;
    string s2;
    
    cout << "First string: ";
    cin >> s1;
    cout << "Second string: ";
    cin >> s2;

    cout << "Inputs: \"" << s1 << "\" and \"" << s2 << "\"\n";

    string result = longestCommonSubstring(s1, s2);
    cout << "LCS: \"" << result << "\"\n";

    return 0;
}
