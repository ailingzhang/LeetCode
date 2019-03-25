/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.43%)
 * Total Accepted:    298.5K
 * Total Submissions: 657.1K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

/**********
 * 方法一：双重for循环遍历搜索
 * 
 * 时间复杂度：O(n^2)
 *********/

// #include <vector>
// using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         for(int i = 0; i < nums.size() -1; i++)
//         {
//             for(int j = i+1; j < nums.size(); j++)
//             {
//                 if (nums[i] + nums[j] == target) {
//                     ans.push_back(i);
//                     ans.push_back(j);
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/***********
 * 方法二：循环一个数，map寻找另一个数
 * 
 * 时间复杂度：O(n)
 * ********/

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        map<int, int> my_map;

        for(int i = 0; i < nums.size(); i++)
        {
            my_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];

            if (my_map.find(need) != my_map.end() &&
                i != my_map[need]){
                ans.push_back(i);
                ans.push_back(my_map[need]);
                return ans;
            }

        }
        return ans;
    }
};

