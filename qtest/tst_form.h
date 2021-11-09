#ifndef TST_FORM_H
#define TST_FORM_H

#include <mainwindow.h>

#include <QtTest/QtTest>

class Tst_form : public QObject {
    Q_OBJECT

private slots:
    ///
    /// \brief It will be called to create a global test data table.
    ///
    void initTestCase_data();

    ///
    /// \brief It will be called before the first test function is executed.
    ///
    void initTestCase();
    ///
    /// \brief It will be called after the last test function was executed.
    ///
    void cleanupTestCase();

    ///
    /// \brief It will be called before each test function is executed.
    ///
    void init();
    ///
    /// \brief It will be called after every test function.
    ///
    void cleanup();

private slots:
    void tstStringId();
    void tstStringId_data();
};

#endif // TST_FORM_H
