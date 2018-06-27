# boost split can not split Chinese sentence #

```
std::regex regex("，|。|！|？");
std::string src = "使用boost split失败了，不知道什么原因。有人可以告诉我吗？谢谢！";

std::sregex_token_iterator iterator(src.begin(), src.end(), regex, -1);
std::sregex_token_iterator end;

for ( ; iterator != end; ++iterator) {
    std::string res = *iterator;
    std::cout << res << std::endl;
}
```
输出结果
```
使用boost split失败了
不知道什么原因
有人可以告诉我吗
谢谢
```
# error: #error "Compiler is not in a mode aware of C++11." #

<pre>
error: #error "Compiler is not in a mode aware of C++11."
https://stackoverflow.com/questions/47886400/cmake-configure-error-in-3-10-1-but-not-in-3-9-6 <br/>
Deprecated and Removed Features
Support for building CMake itself with C++98 compilers was dropped. CMake is now implemented using C++11.<br/>
This requires a capable compiler. The first version of GCC which is C++11 feature complete is GCC 4.8.1.<br/>
Gcc 4.4.5 is over 7 years old and more important, it doesn't support C++11 (from the error):<br/>
Cannot find a C++ compiler supporting C++11 on this system.
</pre>

# error:怎样让CMake 编译器使用gcc代替Clang? #
```
set(CMAKE_C_COMPILER "gcc") # 显示指定使用的C编译器
set(CMAKE_CXX_COMPILER "g++")# 显示指定使用的C++编译器
```

# error: no matching function for call to 'regex_replace #
<pre>
gcc需要安装4.9以上版本
</pre>

# CMakeLists.txt区分mac #

```
if (UNIX AND NOT APPLE)
    message(STATUS "ENTRY LINUX")
elseif(UNIX AND APPLE)
    message(STATUS "ENTRY MAC")
endif()
```

# error: boost link error #
<pre>
安装boost的时候，注意gcc版本(mac默认使用的是llvm，建议手动安装，并通过alias链接到指定的gcc上)
状况case：(发生时间:2018-06-13)boost安装的时候用root账号，然后gcc版本为4.8.1，编译应用的时候，
用work账号，这时候gcc版本为5.2.0，导致boost部分库编译的时候出现各种诡异情况！
</pre>

# c++ boost/filesystem.hpp linker command failed #
<pre>
CMakeLists.txt里添加 -lboost_system-mt
</pre>
[相关链接](https://stackoverflow.com/questions/25845154/boost-log-configuration-files)
# c++ split 使用宽字符切分乱码，是因为平台环境导致的。 #
<pre>
linux下临时：export LANG=zh_CN.UTF-8
可以也可以在~/.bash_profile中添加上面那一行
</pre>
