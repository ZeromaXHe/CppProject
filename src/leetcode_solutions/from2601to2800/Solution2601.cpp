#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 2611. 老鼠和奶酪 | 难度：中等
 */
class Solution2611
{
public:
    /**
     * 执行用时：192 ms, 在所有 C++ 提交中击败了 25.77% 的用户
     * 内存消耗：102.4 MB, 在所有 C++ 提交中击败了 63.78% 的用户
     * 通过测试用例：564 / 564
     */
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int n = reward1.size();
        int sum = 0;
        // 小顶堆
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; ++i)
        {
            sum += reward2[i];
            pq.push(reward1[i] - reward2[i]);
            while (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};