/*
 * @lc app=leetcode id=599 lang=cpp
 *
 * [599] Minimum Index Sum of Two Lists
 */
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;  // 保存结果的向量
        unordered_map<string, int> m;
        int mn = INT_MAX;     // 保存当前找到的下标和的最小值
        int n1 = list1.size();
        int n2 = list2.size();

        // 建立列表1中数据和它的坐标的映射
        for (int i = 0; i < n1; ++i)
        {
            m[list1[i]] = i;  
        }

        for (int i = 0; i < n2; ++i)
        {
            // 如果list2遍历到的词也在list1中出现
            if (m.count(list2[i]))
            {
                int sum = i + m[list2[i]];   // 找到下标和
                if (sum == mn)   // 如果下标和如果等于最小值，将该词加入到向量
                {
                    result.push_back(list2[i]);
                }
                else if (sum < mn) // 如果下标和小于最小值，更新向量和最小值
                {
                    mn = sum;
                    result = {list2[i]};
                }
            }
        }
        return result;
    }
};

