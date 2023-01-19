#include <iostream>
#include <vector>

using namespace std;

/**
 * 1356. 根据数字二进制下 1 的数目排序 | 难度：简单
 */
class Solution1356
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 98.62% 的用户
     * 内存消耗：9.7 MB, 在所有 C++ 提交中击败了 99.45% 的用户
     * 通过测试用例：77 / 77
     */
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [&](const int &a, const int &b)
             { 
                int countA = bitCount(a);
                int countB = bitCount(b);
                return countA == countB ? a < b : countA < countB; });
        return arr;
    }

    int bitCount(int i)
    {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        i = (i + (i >> 4)) & 0x0f0f0f0f;
        i = i + (i >> 8);
        i = i + (i >> 16);
        return i & 0x3f;
    }
};
