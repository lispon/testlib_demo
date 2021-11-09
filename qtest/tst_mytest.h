#ifndef TST_MYTEST_H
#define TST_MYTEST_H

#include <QtWidgets>
#include <QtTest/QtTest>

class TestQString : public QObject {
    Q_OBJECT

private slots:
    ///
    /// brief It will be called to create a global test data table.
    ///
    void initTestCase_data();

    ///
    /// brief It will be called before the first test function is executed.
    ///
    void initTestCase();
    ///
    /// brief It will be called after the last test function was executed.
    ///
    void cleanupTestCase();

    ///
    /// brief It will be called before each test function is executed.
    ///
    void init();
    ///
    /// brief It will be called after every test function.
    ///
    void cleanup();

private slots:
    void toUpper();
    void toUpper2();
    void toUpper2_data();

    void tstGui();
    void tstGui2();
    void tstGui2_data();

    void tstBenchmark_simple();
    void tstBenchmark_multi();
    void tstBenchmark_multi_data();
};

#endif // TST_MYTEST_H
