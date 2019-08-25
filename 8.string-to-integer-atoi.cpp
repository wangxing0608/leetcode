/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        // 如果字符串为空
        if (str.empty())
        {
            return 0;
        }

        int sign =1, base = 0, i = 0, n = str.size();
        
        // 跳过字符串中的空白字符
        while (i < n && str[i] == ' ')
        {
            ++i;
        }

        if (i < n && (str[i] == '+' || str[i] == '-'))
        {
            sign = (str[i++] == '+') ? 1 : -1;
        }

        while (i < n && str[i] >= '0' && str[i] <= '9')
        {
            // 超过了32整型值能表示的最大范围,返回INT_MAX或INT_MIN
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};

