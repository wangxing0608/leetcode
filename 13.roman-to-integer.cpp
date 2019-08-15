/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
public:
    // 将字符转换为对应的数字的辅助函数
    inline int c2n(char c)
    {
        switch (c)
        {
        case 'I' :
            return 1;
        case 'V' : 
            return 5;
        case 'X' :
            return 10;
        case 'L' : 
            return 50;
        case 'C' :
            return 100;
        case 'D' :
            return 500;
        case 'M' : 
            return 1000;    
        default:
            return 0;
        }
    }
    int romanToInt(string s) {
        int result = 0;  // 保存转换结果
        for (int i = 0; i < s.size(); ++i)
        {
            // 如果当前值比前一个值大,则该段的值应该是当前值减去上一个值:IV = 4 = 5 - 1
            if (i > 0 && c2n(s[i]) > c2n(s[i-1]))
            {
                result += (c2n(s[i]) - 2 * c2n(s[i-1]));
            }
            else 
            {
                result += c2n(s[i]);
            }
        }
        return result;
    }
};

