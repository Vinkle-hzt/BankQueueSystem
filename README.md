# BankQueueSystem

四川大学2020级软件工程2021年暑期实训项目。

## 项目介绍

模拟银行排队取号、等待、叫号和办理业务等功能，并提供 VIP 服务和银行信息查看的功能。

### 项目框架

![整体架构](doc\img\整体架构.svg)

### 项目ER图

![数据库er图](doc\img\数据库er图.svg)

## 如何编译运行此项目

### 编译运行环境

```
Cmake 3.0.0+
gcc 10.1.0
mingw-w64-7.0.0-r3
MySQL Community Server 8.0.20 
```

如果环境不同，不能保证编译一定通过。

### 编译运行步骤

-  在`MySQL`中创建 `bank_queue_system` 数据库，并运行 `bank_queue_system.sql` 文件中的 SQL 语句。
- 更改 `common.c` 中的相应全局变量
- 运用 `Cmake` 编译运行

## 项目文档
https://vinkle.top/BankQueueSystem
