# 结对编程项目说明

## 模块介绍

- bin：可执行文件Wordlist.exe、GUI.exe和所依赖的动态链接库

- src：计算模块的核心代码

- test：所有单元测试代码和数据

- GUI：GUI实现的所有代码

## 特殊说明

- 用户界面采用 C++ 的 Qt 实现，使用前请确保以下环境：

1. Qt版本 >= 6.4.2
2. 编译器采用 Qt Tools 中的`MinGW 11.2.0 64-bit for C`

- 用户界面实际依赖的计算模块动态链接库名为 `libcore.dll`。

- CLI执行过程：

1. 进入bin文件夹
2. 执行命令

```
.\WordList.exe -n input.txt
```

最终结果会输出到 `WordList.exe` 同级的 `solution.txt` 中（.\bin\solution.txt）。