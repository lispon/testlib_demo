# qtest

using Qt test library.

## mytest

该项目根据 <qthelp://org.qt-project.qttest.5152/qttest/qtest-tutorial.html> 帮助文档来实现.

## testclass

该项目根据 <qthelp://org.qt-project.qttest.5152/qttest/qttest-module.html> 帮助文档来实现, 但是:

1. QAbstractItemModel 暂时未测试.

1. QTest::QTouchEventSequence 暂时未测试.

## testform

尝试 mytest 和 testclass 两个项目后, 测试现有界面程序, 只测试了一个简单函数.

## testfile

    不推荐使用该方法

与 testform 项目进行对比, 直接测试源文件.

## 运行

推荐使用 Qt Creator 来运行测试程序, 使用 Qt Creator 最下方状态栏的第 9 项 **Test Results**, 可以查看测试结果.

## testform 和 testfile对比总结

1. 添加 testfile 测试项目, mainwindow.cpp 会被两个项目进行引用, 使用 Qt Creator 打开该文件时, 会出现 `Note: Multiple parse contexts are available for this file. Choose the preferred one from the editor toolbar.` 的提示.

1. 在 testform 测试项目中, 不会出现该问题, 同时, 目标中包含的文件列表也比较清晰明白, 即使存在多个不同的测试项目, 也不会出现 testfile 项目中出现的警告.

1. 使用 testform, 个人认为, 更有利于低耦合代码的理解; 对于一些功能性比较独立的内容, 可以单独生成库(add_library).
