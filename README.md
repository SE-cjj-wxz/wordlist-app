# 结对编程项目说明

## 模块介绍

- bin：可执行文件Wordlist.exe和所依赖的动态链接库

- guibin:  
  - bin：GUI.exe为可执行文件，其他文件为依赖所需的动态链接库

  - plugins：GUI.exe运行依赖的模块

- src：计算模块的核心代码

- test：所有单元测试代码和数据

- GUI：GUI实现的所有代码

## 特殊说明

- 用户界面实际依赖的计算模块动态链接库名为 `libcore.dll`。

- CLI执行过程：

1. 进入bin文件夹
2. 执行命令

```
.\WordList.exe -n input.txt
```

最终结果会输出到 `WordList.exe` 同级的 `solution.txt` 中（.\bin\solution.txt）。

如果遇到 `Wordlist.exe` 执行无反应的情况重新编译一遍即可（仓库中的 `Wordlist.exe` 是通过 `Mingw 8.1`编译得到的，理论上在测试环境（`Mingw 9.0`）中可以正常执行。）

- GUI执行过程：

1. 进入guibin文件夹
2. 执行命令

```
.\GUI.exe
```

