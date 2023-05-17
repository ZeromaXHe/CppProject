#include <iostream>
#include <vector>

using namespace std;

/**
 * 2446. 判断两个事件是否存在冲突 | 难度：简单
 */
class Solution2446
{
public:
    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：11.3 MB, 在所有 C++ 提交中击败了 20.48% 的用户
     * 通过测试用例：129 / 129
     */
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        return ((event1[1] >= event2[0] && event1[0] <= event2[1]) ||
                (event2[1] >= event1[0] && event2[0] <= event1[1]));
    }
};