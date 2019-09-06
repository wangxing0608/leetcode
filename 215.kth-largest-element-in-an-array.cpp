/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (49.55%)
 * Likes:    2353
 * Dislikes: 189
 * Total Accepted:    427K
 * Total Submissions: 861.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while (true)
        {
            // pos为数第pos+1大元素的最终位置
            int pos = partition(nums, left, right);
            if (pos == k - 1)
            {
                return nums[pos];
            }
            // 要求的数字在左半部分
            if (pos > k - 1)
            {
                right = pos - 1;
            }
            // 要求的数字在右半部分
            else 
            {
                left = pos + 1;
            }
        }
    }

    int partition(vector<int> &nums, int left, int right)
    {
        // 划分数组的主元
        int pivot = nums[left];
        int l = left + 1; 
        int r = right;
        while (l <= r)
        {
            if (nums[l] < pivot && nums[r] > pivot)
            {
                // 交换元素,使其满足排序的条件
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot)
            {
                ++l;  // 左边界向右移动
            }
            if (nums[r] <= pivot) 
            {
                --r;  // 右边界向左移动
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

