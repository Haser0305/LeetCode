//
// Created on 2022/3/5.
//



/***************************
 * 4. Median of Two Sorted Arrays
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 * Example :
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 */

#include "vector"

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int isOdd = (nums1.size() + nums2.size()) % 2;
    int runtimes = (nums1.size() + nums2.size() - 1) / 2;
    int n1 = 0;
    int n2 = 0;
    int isEmpty = false;
    int result = 0;

    for (int i = 0; i < runtimes; i++) {
        if (n1 == nums1.size()) {
            isEmpty = true;
            n2 += runtimes - i;
            break;
        }
        if (n2 == nums2.size()) {
            isEmpty = true;
            n1 += runtimes - i;
            break;
        }

        if (nums1[n1] <= nums2[n2]) {
            n1++;
        } else {
            n2++;
        }

    }

    if (nums1.size() == n1 || nums2.size() == n2) {
        isEmpty = true;
    }

    if (isOdd) {
        if (isEmpty) {
            if (n1 == nums1.size()) {
                return nums2[n2];
            } else {
                return nums1[n1];
            }
        } else {
            if (nums1[n1] <= nums2[n2]) {
                return nums1[n1];
            } else {
                return nums2[n2];
            }
        }
    } else {
        if (isEmpty) {
            if (n1 == nums1.size()) {
                return (double) (nums2[n2] + nums2[n2 + 1]) / 2;
            } else {
                return (double) (nums1[n1] + nums1[n1 + 1]) / 2;
            }
        } else {
            for (int i = 0; i < 2; i++) {
                if (nums1[n1] <= nums2[n2]) {
                    result += nums1[n1];
                    n1++;
                    if (n1 == nums1.size() && i == 0) {
                        return (double) (result + nums2[n2]) / 2;
                    }
                } else {
                    result += nums2[n2];
                    n2++;
                    if (n2 == nums2.size() && i == 0) {
                        return (double) (result + nums1[n1]) / 2;
                    }
                }
            }

            return (double) result / 2;
        }
    }
}

