//
// Created on 2022/3/5.
//

/***********************
 * 5. Longest Palindromic Substring
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example:
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
************************/

#include "vector"
#include "iostream"

using namespace std;

string longestPalindrome(string s) {
    int stringSize = s.length();
    int maxBegin = 0;
    int maxLen = 1;

    vector<vector<bool>> dp(stringSize, vector<bool>(stringSize, false));

    for (int i = 0; i < stringSize; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < stringSize - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxBegin = i;
            maxLen = 2;
        }
    }
    for (int len = 3; len <= stringSize; len++) {
        for (int i = 0; i < stringSize - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                maxBegin = i;
                maxLen = len;
            }
        }
    }
    return s.substr(maxBegin, maxLen);
}