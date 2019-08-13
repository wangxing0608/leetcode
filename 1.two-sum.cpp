/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int, int> numsMap;
       vector<int> ans;
       // 建立数组中数值和位置的映射
       for (auto i = 0; i < nums.size(); ++i)
       {
           numsMap[nums[i]] = i;
       }

       for (int i = 0; i < nums.size(); ++i)
       {
           // 求得另外一个数值
           int v = target - nums[i];

           if (numsMap.count(v) && numsMap[v] != i)
           {
               ans.push_back(i);
               ans.push_back(numsMap[v]);
               return ans;
           }
       }
       return ans;
    }
};

