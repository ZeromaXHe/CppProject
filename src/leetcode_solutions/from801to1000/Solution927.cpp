#include <vector>

using namespace std;

/**
 * 927. 三等分 | 难度：困难
 */
class Solution
{
public:
    /**
     * 执行用时：36 ms, 在所有 C++ 提交中击败了 61.11% 的用户
     * 内存消耗：38.1 MB, 在所有 C++ 提交中击败了 39.58% 的用户
     * 通过测试用例：121 / 121
     */
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int count = 0;
        for (int i : arr)
            count += i;
        if (count % 3 != 0)
            return {-1, -1};
        if (count == 0)
            return {0, 2};
        int div = count / 3;
        int p1 = 0, p2 = 0, p3 = 0;
        count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
            {
                if (count == 0)
                    p1 = i;
                else if (count == div)
                    p2 = i;
                else if (count == 2 * div)
                    p3 = i;
                ++count;
            }
        }

        int len = (int)arr.size() - p3;
        if (p1 + len <= p2 && p2 + len <= p3)
        {
            for (int i = 0; i < arr.size() - p3; i++)
            {
                if (arr[p1 + i] != arr[p2 + i] || arr[p2 + i] != arr[p3 + i])
                    return {-1, -1};
            }
            return {p1 + len - 1, p2 + len};
        }
        return {-1, -1};
    }
};