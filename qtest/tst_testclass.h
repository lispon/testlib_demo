#ifndef TST_TESTCLASS_H
#define TST_TESTCLASS_H

#include <QtGui>
#include <QtTest/QtTest>
#include <QtWidgets/QtWidgets>

class TstTestClass : public QObject {
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
    //
    void tstSignalSpy();
    void tstSignalSpy_data();
    //
    void tstEventList();
    void tstEventList_data();
    //
    void tstTouchEvent();
    void tstTouchEvent_data();
    //
    void tstItemModel();
    void tstItemModel_data();
};

#endif // TST_TESTCLASS_H
