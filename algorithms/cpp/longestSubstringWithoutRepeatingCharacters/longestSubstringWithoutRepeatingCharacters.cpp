//
// Created on 2022/3/5.
//


/*****************************
 * 3. longestSubstringWithoutRepeatingCharacters
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 * Example:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *****************************/

#include "iostream"
#include "vector"

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int res = 0;

    vector<int> lastIndex(256, -1);

    int i = 0;

    for (int j = 0; j < n; j++) {

        i = max(i, lastIndex[s[j]] + 1);

        res = max(res, j - i + 1);

        lastIndex[s[j]] = j;
    }
    return res;
}

