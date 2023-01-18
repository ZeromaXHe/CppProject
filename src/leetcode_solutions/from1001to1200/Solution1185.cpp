#include <iostream>
#include <vector>

using namespace std;

/**
 * 1185. 一周中的第几天 | 难度：简单
 */
class Solution1185
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 22.08% 的用户
     * 内存消耗：5.8 MB, 在所有 C++ 提交中击败了 37.66% 的用户
     * 通过测试用例：43 / 43
     */
    string dayOfTheWeek(int day, int month, int year)
    {
        vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
        // 输入年份之前的年份的天数贡献
        int days = 365 * (year - 1971) + (year - 1969) / 4;
        // 输入年份中，输入月份之前的月份的天数贡献
        for (int i = 0; i < month - 1; ++i)
        {
            days += monthDays[i];
        }
        // 闰二月
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3)
        {
            days += 1;
        }
        // 输入月份中的天数贡献
        days += day;
        // 1970 年 12 月 31 日是星期四
        return week[(days + 3) % 7];
    }
};