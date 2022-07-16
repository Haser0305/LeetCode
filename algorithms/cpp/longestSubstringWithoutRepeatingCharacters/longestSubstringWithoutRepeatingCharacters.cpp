//
// Created on 2022/3/5.
//


/*****************************
 * 3. longestSubstringWithoutRepeatingCharacters
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 * Example:
 *      Input: s = "abcabcbb"
 *      Output: 3
 *      Explanation: The answer is "abc", with the length of 3.
 *****************************/

#include "iostream"
#include "vector"

using namespace std;

int test(string s) {
    int n = s.size();
    int res = 0;

    vector<int> lastIndex(256, -1); // the size is 256, and all values are -1.

    int i = 0;

    for (int j = 0; j < n; j++) {

        i = max(i, lastIndex[s[j]] + 1); // 用以決定起頭位置，如果遇到重複的就會往右重複數

        res = max(res, j - i + 1); // 記錄當下字串的最長值，_Right:從左到右之間所有數的總和

        lastIndex[s[j]] = j;
    }
    return res;
}

