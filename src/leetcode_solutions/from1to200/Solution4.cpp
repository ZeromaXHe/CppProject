#include <iostream>
#include <vector>

using namespace std;

/**
 * 4. 寻找两个正序数组的中位数 | 难度：困难
 */
class Solution4
{
public:
    /**
     * lower_bound 的使用有点脱裤子放屁多此一举了
     *
     * 执行用时：32 ms, 在所有 C++ 提交中击败了 41.28% 的用户
     * 内存消耗：86.7 MB, 在所有 C++ 提交中击败了 82.24% 的用户
     * 通过测试用例：2094 / 2094
     */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = len1;
        auto iterL1 = nums1.begin();
        auto iterR1 = nums1.end();
        while (l < r)
        {
            int mid = (l + r) / 2;
            auto binaryResult1 = lower_bound(iterL1, iterR1, nums1[mid]);
            int leftCount1 = distance(nums1.begin(), binaryResult1);
            if (leftCount1 > (len1 + len2) / 2)
            {
                r = mid - 1;
                iterR1 = binaryResult1;
                continue;
            }
            int leftCount2 = (len1 + len2) / 2 - leftCount1;
            if (leftCount2 > len2)
            {
                l = mid + 1;
                iterL1 = next(binaryResult1);
                continue;
            }
            if (leftCount2 < len2 && leftCount1 > 0 && nums2[leftCount2] < nums1[leftCount1 - 1])
            {
                r = mid - 1;
                iterR1 = binaryResult1;
                continue;
            }
            if (leftCount2 > 0 && leftCount1 < len1 && nums1[leftCount1] < nums2[leftCount2 - 1])
            {
                l = mid + 1;
                iterL1 = next(binaryResult1);
                continue;
            }
            int rightMin = min(leftCount1 < len1 ? nums1[leftCount1] : INT32_MAX,
                               leftCount2 < len2 ? nums2[leftCount2] : INT32_MAX);
            if ((len1 + len2) % 2 == 1)
            {
                return rightMin;
            }
            else
            {
                int leftMax = max(leftCount1 > 0 ? nums1[leftCount1 - 1] : INT32_MIN,
                                  leftCount2 > 0 ? nums2[leftCount2 - 1] : INT32_MIN);
                return (rightMin + 0.0 + leftMax) / 2.0;
            }
        }
        int l2 = (len1 + len2) / 2 - l;
        int rightMin = min(l < len1 ? nums1[l] : INT32_MAX,
                           l2 < len2 ? nums2[l2] : INT32_MAX);
        if ((len1 + len2) % 2 == 1)
        {
            return rightMin;
        }
        else
        {
            int leftMax = max(l > 0 ? nums1[l - 1] : INT32_MIN,
                              l2 > 0 ? nums2[l2 - 1] : INT32_MIN);
            return (rightMin + 0.0 + leftMax) / 2.0;
        }
    }

    /**
     * 执行用时：20 ms, 在所有 C++ 提交中击败了 89.71% 的用户
     * 内存消耗：86.8 MB, 在所有 C++ 提交中击败了 63.48% 的用户
     * 通过测试用例：2094 / 2094
     */
    double findMedianSortedArrays_simple(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int r = len1;
        int mid1 = len1 / 2;
        int mid2 = len2 / 2;
        while (l < r)
        {
            mid1 = (l + r) / 2;
            mid2 = (len1 + len2) / 2 - mid1;
            if (mid1 > (len1 + len2) / 2)
                r = mid1 - 1;
            else if (mid2 > len2)
                l = mid1 + 1;
            else if (mid2 < len2 && mid1 > 0 && nums2[mid2] < nums1[mid1 - 1])
                r = mid1 - 1;
            else if (mid2 > 0 && mid1 < len1 && nums1[mid1] < nums2[mid2 - 1])
                l = mid1 + 1;
            else
                break;
        }
        // 不加下面两行的话，当 l == r 退出循环时会有 mid1 和实际不一致的 bug
        mid1 = (l + r) / 2;
        mid2 = (len1 + len2) / 2 - mid1;
        int rightMin = min(mid1 < len1 ? nums1[mid1] : INT32_MAX,
                           mid2 < len2 ? nums2[mid2] : INT32_MAX);
        if ((len1 + len2) % 2 == 1)
            return rightMin;
        else
        {
            int leftMax = max(mid1 > 0 ? nums1[mid1 - 1] : INT32_MIN,
                              mid2 > 0 ? nums2[mid2 - 1] : INT32_MIN);
            return (rightMin + 0.0 + leftMax) / 2.0;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution4 solution;
    vector<int> nums1 = {1};
    vector<int> nums2 = {2, 3};
    std::cout << solution.findMedianSortedArrays_simple(nums1, nums2) << std::endl; // 2.0000
    return 0;
}
