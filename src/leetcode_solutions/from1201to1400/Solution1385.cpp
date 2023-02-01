#include <iostream>
#include <vector>

using namespace std;

/**
 * 1385. 两个数组间的距离值 | 难度：简单
 */
class Solution1385
{
public:
    /**
     * 官方题解修改
     *
     * 执行用时：8 ms, 在所有 C++ 提交中击败了 88.97% 的用户
     * 内存消耗：12.7 MB, 在所有 C++ 提交中击败了 41.67% 的用户
     * 通过测试用例：103 / 103
     */
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int result = 0;
        for (int &x : arr1)
        {
            // 二分查找。两个迭代器相减就是索引 p
            unsigned p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size())
            {
                ok &= (arr2[p] - x > d);
            }
            // p - 1 <= arr2.size() 不能省略，p - 1 >= 0 可以省略（p 是 unsigned），对于以下测试用例：
            // [-8,-7]
            // [4,10,-4,5,2]
            // 55
            // 结果中 p = 0，会导致 p - 1 溢出为 4294967295
            // (其实直接写 p >= 1 就好了，官方题解非要搞得这么复杂)
            if (p - 1 <= arr2.size())
            {
                ok &= (x - arr2[p - 1] > d);
            }
            // 直接把 true 当 1 用
            result += ok;
        }
        return result;
    }
};
