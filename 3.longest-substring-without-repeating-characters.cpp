/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;        // 返回最长无重复字符子串的长度
        int left = -1;         // 最长无重复字符子串的左边界
        int n = s.size();      // 字符串长度
        unordered_map<char, int> m;   // 建立字符串中字符和其位置的映射
        for (int i = 0; i < n; ++i)
        {
            // 如果当前字符在m中存在并且当前位置大于无重复字符子串的左边界，则更新左边界
            if (m.count(s[i]) && m[s[i]] > left)
            {
                left = m[s[i]];
            }
            m[s[i]] = i;  // 当前字符在m中不存在，简历字符和位置的映射
            result = max(result, i - left);
        }

        return result;
    }
};

