#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * 1694. 重新格式化电话号码 | 难度：简单
 */
class Solution1694
{
public:
    /**
     * 执行用时：4 ms, 在所有 C++ 提交中击败了 14.11% 的用户
     * 内存消耗：6.1 MB, 在所有 C++ 提交中击败了 38.59% 的用户
     * 通过测试用例：108 / 108
     */
    string reformatNumber(string number)
    {
        string digits;
        for (char ch : number)
        {
            if (isdigit(ch))
                digits.push_back(ch);
        }
        int ptr = 0;
        string res;
        // number = "12" 测试了一下，结果很迷惑。可能是 size() 返回的类型比较奇怪？
        // bool b = ptr < digits.size() - 4; // true
        // bool bo = 0 < digits.size() - 4; // true
        // bool boo = ptr < 2 - 4; // false
        // bool bool0 = 0 < 2 - 4; // false

        // bool b1 = false - 4; // true
        // int i1 = false - 4; // -4
        // int i2 = true - 4; // -3
        // int size = digits.size(); // 2

        // bool b2 = ptr < (digits.size() - 4); // true
        // bool bo2 = 0 < (digits.size() - 4); // true
        // bool boo2 = ptr < (2 - 4); // false
        // bool bool2 = 0 < (2 - 4); // false

        // bool b3 = (ptr < digits.size()) - 4; // true
        // bool bo3 = (0 < digits.size()) - 4; // true
        // bool boo3 = (ptr < 2) - 4; // true
        // bool bool3 = (0 < 2) - 4; // true

        // bool b4 = -4; // true

        // 不能写成 ptr < digits.size() - 4，原因见上面迷惑的结果
        int diff = digits.size() - 4;
        while (ptr < diff)
        {
            res += digits.substr(ptr, 3) + "-";
            ptr += 3;
        }
        if (ptr == digits.size() - 4)
        {
            res += digits.substr(ptr, 2) + "-" + digits.substr(ptr + 2, 2);
        }
        else
        {
            res += digits.substr(ptr, digits.size() - ptr);
        }
        return res;
    }

    /**
     * 执行用时：0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
     * 内存消耗：6 MB, 在所有 C++ 提交中击败了 65.15% 的用户
     * 通过测试用例：108 / 108
     * 
     * 提交记录里面看到的记录。C++ 直接在 string 上面的操作这么快的吗？
     */
    string reformatNumber2(string number)
    {
        if (number.size() == 2)
            return number;
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == ' ' || number[i] == '-')
            {
                number.erase(i, 1);
                i--;
            }
        }
        for (int i = number.size() - number.size() % 3; i > 0; i -= 3)
            number.insert(number.begin() + i, '-');
        if (number[number.size() - 1] == '-')
            number.erase(number.size() - 1, 1);
        if (number[number.size() - 2] == '-')
        {
            char tmp = number[number.size() - 2];
            number[number.size() - 2] = number[number.size() - 3];
            number[number.size() - 3] = tmp;
        }
        return number;
    }
};

int main(int argc, char *argv[])
{
    Solution1694 solution;
    std::cout << solution.reformatNumber("12") << std::endl;
    return 0;
}