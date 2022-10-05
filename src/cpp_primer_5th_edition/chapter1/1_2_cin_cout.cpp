#include <iostream>

int main() {
    std::cout << "Enter two numbers" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
    // vscode 外部控制台一闪而过，getchar() 或者 system("pause") 没有效果，只能打断点
    return 0;
}