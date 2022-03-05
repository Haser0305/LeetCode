//
// Created on 2022/3/5.
//


/*******************************
 *
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 *
 * Example 1:
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *******************************/

#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash_map;
    int temp;
    int index;
    for (int i = 0; i < nums.size(); i++) {
        temp = target - nums[i];
        index = hash_map.count(nums[i]);
        if (index != 0) {
            return {i, hash_map[nums[i]]};
        } else {
            hash_map[temp] = i;
        }
    }
    cout << endl << hash_map.count(2);
    return {0};
}






