/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (40.29%)
 * Likes:    261
 * Dislikes: 1297
 * Total Accepted:    118.6K
 * Total Submissions: 293.6K
 * Testcase Example:  '10\n6'
 *
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number is higher or
 * lower.
 * 
 * You call a pre-defined API guess(int num) which returns 3 possible results
 * (-1, 1, or 0):
 * 
 * 
 * -1 : My number is lower
 * ⁠1 : My number is higher
 * ⁠0 : Congrats! You got it!
 * 
 * 
 * Example :
 * 
 * 
 * 
 * Input: n = 10, pick = 6
 * Output: 6
 * 
 * 
 * 
 */
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0)
        {
            return n;
        }

        int left = 1;   // 左边界
        int right = n;  // 右边界
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int t = guess(mid);
            if (t == 0)
            {
                return mid;
            }
            if (t == 1)
            {
                left = mid + 1;
            }
            else 
            {
                right = mid;
            }
        }
        return left;
    }
};

