/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (43.58%)
 * Total Accepted:    38.7K
 * Total Submissions: 88.7K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m < 0 || n < 0)
        {
            return;
        }

        nums1.resize(m + n);
        int i = m - 1;
        int j = n - 1;
        int t = m + n - 1;

        while (t >= 0)
        {
            if (i < 0)
            {
                nums1[t--] = nums2[j--];
            }
            else if (j < 0)
            {
                nums1[t--] = nums1[i--];
            }
            else if (nums1[i] > nums2[j])
            {
                nums1[t--] = nums1[i--];
            }
            else {
                nums1[t--] = nums2[j--];
            }
        }
    }
};

