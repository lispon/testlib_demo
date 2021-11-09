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

## 运行

推荐使用 Qt Creator 来运行测试程序, 使用 Qt Creator 最下方状态栏的第 9 项 **Test Results**, 可以查看测试结果.
