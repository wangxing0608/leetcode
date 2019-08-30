/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        // 如果整数列表为空或只有一个元素
        if (nums.size() <= 1)
        {
            return nums.empty() ? 0 : nums[0];
        }
        
        // 使用dp数组记录到各个位置的最大和
        // 基本情况dp[0] = nums[0], dp1 = max(nums[0], nums[1])
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size(); ++i)
        {
            dp.push_back(max(nums[i] + dp[i-2], dp[i-1]));
        }
        return dp.back();
    }
};

