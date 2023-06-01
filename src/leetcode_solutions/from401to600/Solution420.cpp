#include <iostream>
#include <vector>

using namespace std;

/**
 * 420. 强密码检验器 | 难度：困难
 */
class Solution420
{
public:
    /**
     * 大于 20 的长度分析有点恶心，直接 copy 官方题解了
     *
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 48.05% 的用户
     * 通过测试用例：53 / 53
     */
    int strongPasswordChecker(string password)
    {
        int continueCount = 0;
        bool lower = false, upper = false, digit = false;
        char pre = '#';
        if (password.length() <= 20)
        {
            int breakContinue3 = 0;
            for (char ch : password)
            {
                if (islower(ch))
                    lower = true;
                else if (isupper(ch))
                    upper = true;
                else if (isdigit(ch))
                    digit = true;
                if (ch != pre)
                {
                    if (continueCount >= 3)
                        breakContinue3 += continueCount / 3;
                    continueCount = 1;
                    pre = ch;
                }
                else
                    ++continueCount;
            }
            if (continueCount >= 3)
                breakContinue3 += continueCount / 3;
            if (password.length() >= 6 && password.length() <= 20)
                return max(breakContinue3, 3 - lower - upper - digit);
            else
                return max(6 - (int)password.length(), 3 - lower - upper - digit);
        }
        else
        {
            int n = password.length();
            // 替换次数和删除次数
            int replace = 0, remove = n - 20;
            // k mod 3 = 1 的组数，即删除 2 个字符可以减少 1 次替换操作
            int rm2 = 0;
            int cnt = 0;
            char cur = '#';

            for (char ch : password)
            {
                if (islower(ch))
                    lower = true;
                else if (isupper(ch))
                    upper = true;
                else if (isdigit(ch))
                    digit = true;

                if (ch == cur)
                    ++cnt;
                else
                {
                    if (remove > 0 && cnt >= 3)
                    {
                        if (cnt % 3 == 0)
                        {
                            // 如果是 k % 3 = 0 的组，那么优先删除 1 个字符，减少 1 次替换操作
                            --remove;
                            --replace;
                        }
                        else if (cnt % 3 == 1)
                        {
                            // 如果是 k % 3 = 1 的组，那么存下来备用
                            ++rm2;
                        }
                        // k % 3 = 2 的组无需显式考虑
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            if (remove > 0 && cnt >= 3)
            {
                if (cnt % 3 == 0)
                {
                    --remove;
                    --replace;
                }
                else if (cnt % 3 == 1)
                    ++rm2;
            }
            replace += cnt / 3;

            // 使用 k % 3 = 1 的组的数量，由剩余的替换次数、组数和剩余的删除次数共同决定
            int use2 = min({replace, rm2, remove / 2});
            replace -= use2;
            remove -= use2 * 2;
            // 由于每有一次替换次数就一定有 3 个连续相同的字符（k / 3 决定），因此这里可以直接计算出使用 k % 3 = 2 的组的数量
            int use3 = min({replace, remove / 3});
            replace -= use3;
            remove -= use3 * 3;
            return (n - 20) + max(replace, 3 - lower - upper - digit);
        }
    }
};