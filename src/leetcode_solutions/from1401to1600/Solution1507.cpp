#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

/**
 * 1507. 转变日期格式 | 难度：简单
 */
class Solution1507
{
    unordered_map<string, string> s2month = {
        {"Jan", "01"},
        {"Feb", "02"},
        {"Mar", "03"},
        {"Apr", "04"},
        {"May", "05"},
        {"Jun", "06"},
        {"Jul", "07"},
        {"Aug", "08"},
        {"Sep", "09"},
        {"Oct", "10"},
        {"Nov", "11"},
        {"Dec", "12"}};

public:
    /**
     * 官方题解
     *
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6.1 MB, 在所有 C++ 提交中击败了 25.60% 的用户
     * 通过测试用例：110 / 110
     */
    string reformatDate(string date)
    {
        stringstream ss(date);
        string year, month, day;
        ss >> day >> month >> year;
        month = s2month[month];
        day.pop_back();
        day.pop_back();
        if (day.size() == 1)
        {
            day = "0" + day;
        }
        return year + "-" + month + "-" + day;
    }
};