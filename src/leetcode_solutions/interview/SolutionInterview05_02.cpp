#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 面试题 05.02. 二进制数转字符串 | 难度：中等
 */
class SolutionInterview05_02
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 28.78% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 51.71% 的用户
     * 通过测试用例：33 / 33
     */
    string printBin(double num)
    {
        string res = "0.";
        double test = 1.0;
        int count = 0;
        while (num > 0)
        {
            test /= 2.0;
            if (num >= test)
            {
                res += "1";
                num -= test;
            }
            else
            {
                res += "0";
            }
            ++count;
            if (count >= 32)
            {
                return "ERROR";
            }
        }
        return res;
    }

    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：5.9 MB, 在所有 C++ 提交中击败了 44.88% 的用户
     * 通过测试用例：33 / 33
     */
    string printBin_multiply(double num)
    {
        string res = "0.";
        while (num > 0)
        {
            num *= 2.0;
            if (num >= 1)
            {
                res += "1";
                num -= 1;
            }
            else
            {
                res += "0";
            }
            if (res.size() >= 32)
            {
                return "ERROR";
            }
        }
        return res;
    }
};