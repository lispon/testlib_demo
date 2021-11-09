#include "tst_form.h"

void Tst_form::initTestCase_data() {

}

void Tst_form::initTestCase() {

}

void Tst_form::cleanupTestCase() {

}

void Tst_form::init() {

}

void Tst_form::cleanup() {

}


void Tst_form::tstStringId() {
    QFETCH(QString, id_str);
    QFETCH(int, id_int);

    MainWindow m;

    m.setStringID(id_str);
    QCOMPARE(m.getIntID(), id_int);
}

void Tst_form::tstStringId_data() {
    QTest::addColumn<QString>("id_str");
    QTest::addColumn<int>("id_int");

    QTest::addRow("id is zero.") << "0" << 0;
    QTest::addRow("id is empty") << "" << 0;
    QTest::addRow("id is negative") << "-1" << -1;
    QTest::addRow("id is normal") << "123" << 123;
}


QTEST_MAIN(Tst_form)
#include "tst_form.moc"
