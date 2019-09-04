/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:

     // 求山脉数组的峰值
    int getHighest(int n, MountainArray &mountainArr)
    {
        int l = 0;
        int r = n - 1;
        while (l + 2 < r)
        {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            if (mountainArr.get(mid1) > mountainArr.get(mid2))
            {
                r = mid2;
            }
            else
            {
                l = mid1;
            }
        }
        if (l == r)
        {
            return l;
        } 
        else if (l + 1 == r)
        {
            if (mountainArr.get(l) > mountainArr.get(r))
            {
                return l;
            }
            else 
            {
                return r;
            }
        } 
        else 
        {
            int x = mountainArr.get(l);
            int y = mountainArr.get(l + 1);
            int z = mountainArr.get(l + 2);
            if (x > y && x > z)
            {
                return l;
            }
            else if (y > x && y > z)
            {
                return l + 1;
            }
            else
            {
                return l + 2;
            }
        }
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();  // 数组长度
        int hightest = getHighest(n, mountainArr);   // 求得数组的峰值位置
        int l = 0; 
        int r = hightest;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) < target)
            {
                l = mid + 1;
            }
            else 
            {
                r = mid;
            }
        }

        if (mountainArr.get(l) == target)
        {
            return l;
        } 
        l = hightest; 
        r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (mountainArr.get(mid) > target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        if (mountainArr.get(l) == target)
        {
            return l;
        }
        return -1;
    }
};

