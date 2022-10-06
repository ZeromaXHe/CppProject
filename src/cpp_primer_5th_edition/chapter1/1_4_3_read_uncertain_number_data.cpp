#include <iostream>

int main()
{
    int sum = 0, value = 0;
    // 从键盘向程序输入数据时，在 Windows 系统中，输入文件结束符的方法是输入 Ctrl + z，然后按 Enter 或 Return 键
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}