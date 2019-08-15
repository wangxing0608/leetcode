/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.78%)
 * Likes:    1517
 * Dislikes: 1410
 * Total Accepted:    514.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       // 如果保存字符串的数组为空
       if (strs.empty())
       {
           return "";
       }
       // 保存最长公共前缀
       string result = "";
       for (int i = 0; i < strs[0].size(); ++i)
       {
           char c = strs[0][i]; 
           // 遍历字符串数组中的其他字符串,检查是否在相同位置的字符相等
           for (int j = 1; j < strs.size(); ++j)
           {
               // 如果当前最长公共前缀长度超过了字符串数组中较短的字符串长度
               // 或者相同位置的字符串不相同,则返回结果字符串
               if (i >= strs[j].size() || strs[j][i] != c)
               {
                   return result;
               }
           }
           result.push_back(c);
       }
       return result;
    }
};

