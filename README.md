# 笔记

## Visual Studio Code 开发环境搭建

1. 下载安装 VS Code

2. 在 VS Code 扩展中安装 C/C++ Extension Pack

3. 安装 MinGW。
    1. [官网](https://osdn.net/projects/mingw/) 下载 mingw-get-setup.exe
    2. 正常安装流程
    3. 安装完后，点击 continue 会打开 “MinGW Installer Manager”，需要选择 mingw32-gcc-g++-bin 以编译 C++（mingw32-base-bin 支持编译 C 语言）。
    4. 选好后菜单栏中选择 Installation -> Apply Changes。点击 Apply，然后等待安装完成。（中间可能会有些下载失败，多执行几遍这一步就好。会安装之前失败的，下载也貌似是断点续传的，都是接着上次的下）
    5. 配置 PATH 环境变量。增加 MinGW 安装路径的 bin 文件夹，如 `D:\MinGW\bin`
    6. 如果全部正常，`win + r` 输入 `cmd` 打开命令行，输入 `gcc -v` 后可以正常看到 GCC 编译器的具体信息。

4. 在 VS Code 中创建 HelloWorld 工程。新建文件 `test.cpp`，内容如下
    ```c++
    #include <iostream>
    #include <vector>
    #include <string>
    
    int main(int argc, char *argv[])
    {
        std::cout << "Hello World" << std::endl;
        return 0;
    }
    ```

5. 编译 `test.cpp`。

    在打开 test.cpp 的前提下，菜单栏上点击 “终端 -> 配置默认生成任务”，弹出的选择框中选择 “c/c++：g++.exe生成活动文件”。将自动在 `.vscode` 目录下生成 `task.json`。（其中 args 的最后一个参数可以修改成 `"${fileDirname}\\build\\${fileBasenameNoExtension}.exe"`，中间的 build 目录是我自己加的，路径对应编译后的 exe 文件位置）

6. 调试 `test.cpp`。

    还是在打开 test.cpp 的前提下，菜单栏点击 “运行 -> 添加配置”，选择 `C++(GDB/LLDB)`。网上说在弹出的下拉选项中，选择g++.exe - 生成和调试活动文件；这一步貌似实际操作中并没有，需要使用 “(gdb) 启动” 来代替。需要把 program 和 miDebuggerPath 的内容略微改一下。externalConsole 改为 true 可以让调试控制台使用外部窗口，否则没办法进行输入，会报 “Unable to perform this action because the process is running.”

    目前 launch.json 的配置中括号中内容如下：

    ```json
    {
        "name": "(gdb) 启动",
        "type": "cppdbg",
        "request": "launch",
        "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${fileDirname}",
        "environment": [],
        "externalConsole": true,
        "MIMode": "gdb",
        "miDebuggerPath": "D:/MinGW/bin/gdb.exe",
        "setupCommands": [
            {
                "description": "为 gdb 启用整齐打印",
                "text": "-enable-pretty-printing",
                "ignoreFailures": true
            },
            {
                "description":  "将反汇编风格设置为 Intel",
                "text": "-gdb-set disassembly-flavor intel",
                "ignoreFailures": true
            }
        ],
        "preLaunchTask": "C/C++: g++.exe 生成活动文件"
    }
    ```

    然后就可以使用快捷键 F5 或者菜单栏“运行 -> 启动调试”进行调试了

7. C/C++ 配置

    使用快捷键 `Ctrl + Shift + P` 打开命令面板，输入 `C/C++ 编辑配置(UI)`，将会弹出 C/C++ 配置页面。

    需要配置编译器路径（我选的 `MinGW/bin/gcc.exe` 的路径），IntelliSense 模式（我用的 win，选的 “windows-gcc-x64”）

    配置完成后，点击资源管理器，可以看到在 `.vscode` 文件夹中自动生成了 `c_cpp_properties.json` 文件；

## VS Code Git 配置

需要在设置中搜索 gitpath 然后在 settings.json 中编辑，修改 `"git.path": "C:/Program Files/Git/cmd/git.exe"`。不然 push 不生效

## C++ 语言笔记

### 快速幂

```c++
const int MOD = 1337;

int pow(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (long)res * x % MOD;
        }
        x = (long)x * x % MOD;
        n /= 2;
    }
    return res;
}
```

除以 MOD 取余的操作根据题意可以进行修改或省略

### NULL 和 nullptr

在 C++98 标准和 C++03 标准中，还没有 `nullptr` ，只有 `NULL`。

**在 C++ 中，`NULL` 被定义为整形常量 0（而在 C 中，`NULL`被定义为无类型指针常量 (`void*`) 0 ）**

也就是说在 C++ 中，下面的这两行代码是完全等价的，没有区别。

```cpp
int* p1 = NULL;  
int* p2 = 0;
```

**C++11 标准增加了新的关键字 `nullptr`，保证在任何情况下都表示空指针**

因此，在 C++11 标准出来以后，不推荐使用 `NULL` 来代表空指针。为了提高代码的健壮性，建议以后表示指针空值时最好都使用 `nullptr` 。

### 数字转字符串

使用 `to_string()` 函数，唯一参数为数字

### 字符串转数字

使用 `stoi()` 函数

### 计算二进制 1 的个数

```c++
int bitCount(int i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i + (i >> 4)) & 0x0f0f0f0f;
    i = i + (i >> 8);
    i = i + (i >> 16);
    return i & 0x3f;
}
```

### algorithm

```c++
#include <algorithm>
```

最大值、最小值：`max()` 和 `min()`

二分查找：`lower_bound()`

### cstdlib

```c++
#include <cstdlib>
```

绝对值：`abs()` （`using namespace std;` 的话，可能需要前面加 `::`）

### numeric

```c++
#include <numeric>
```

最大公约数：`gcd()`

### unordered_map

```c++
#include <unordered_map>
```

使用 `count` 来判断存在



for 循环自动拆分键值——结构化绑定(c++ 17 特性)：

```c++
unordered_map<int, int> count;
for (auto [k, v] : count)
{
    // ...
}
```



### unordered_set

```c++
#include <unordered_set>
```

使用 `count` 来判断存在

### vector

```c++
#include <vector>
```

#### `emplace_back()` 和 `push_back()` 的区别

在于底层实现的机制不同。`push_back()` 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；而 `emplace_back()` 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。

显然完成同样的操作，`push_back()` 的底层实现过程比 `emplace_back()` 更繁琐，换句话说，`emplace_back()` 的执行效率比 `push_back()` 高。因此，在实际使用时，建议大家优先选用 `emplace_back()`。

> 由于 `emplace_back()` 是 C++ 11 标准新增加的，如果程序要兼顾之前的版本，还是应该使用 `push_back()`。

#### 排序

示例代码：

```c++
vector<vector<int>> &mat;
vector<int> sorting;
// []：定义匿名函数
// [&]：以引用形式捕获所有外部变量，也就是外部变量均可用
sort(sorting.begin(), sorting.end(), [&](const int &a, const int &b)
	{ return mat[a] == mat[b] ? a < b : mat[a] < mat[b]; });
```

