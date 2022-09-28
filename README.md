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

    还是在打开 test.cpp 的前提下，菜单栏点击 “运行 -> 添加配置”，选择 `C++(GDB/LLDB)`。（网上说在弹出的下拉选项中，选择g++.exe - 生成和调试活动文件；这一步貌似实际操作中并没有）

    然后就可以使用快捷键 F5 或者菜单栏“运行 -> 启动调试”进行调试了

7. C/C++ 配置

    使用快捷键 `Ctrl + Shift + P` 打开命令面板，输入 `C/C++ 编辑配置(UI)`，将会弹出 C/C++ 配置页面

    配置完成后，点击资源管理器，可以看到在 `.vscode` 文件夹中自动生成了 `c_cpp_properties.json` 文件；