#include "tst_file.h"


void TstFile::tstFileFun() {
    QFETCH(QString, id_str);
    QFETCH(int, id_int);

    MainWindow mw;
    mw.setStringID(id_str);
    QCOMPARE(id_int, mw.getIntID());
}

void TstFile::tstFileFun_data() {
    QTest::addColumn<QString>("id_str");
    QTest::addColumn<int>("id_int");

    QTest::newRow("normal") << "123" << 123;
    QTest::newRow("zero") << "0" << 0;
    QTest::newRow("negative") << "-456" << -456;
}

QTEST_MAIN(TstFile);
#include "tst_file.moc"
