/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        long result = 0;   // 保存翻转之后的值
        // 取余并求翻转之后的值
        while (x != 0)
        {
            result = 10 * result + x % 10;
            x /= 10;
        }
        
        //如果翻转之后的整数值超过int表示的界限, 返回0
        if (result < INT_MIN || result > INT_MAX)
        {
            return 0;
        }
        return result;
    }
};

