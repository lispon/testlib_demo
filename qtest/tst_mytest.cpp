#include "tst_mytest.h"

void TestQString::initTestCase_data() {
    qDebug() << "test::initTestCase_data" << QTime::currentTime();
}

void TestQString::initTestCase() {
    qDebug() << "test::initTestCase" << QTime::currentTime();
}

void TestQString::cleanupTestCase() {
    qDebug() << "test::cleanupTestCase" << QTime::currentTime();
}

void TestQString::init() {
    qDebug() << "test::init" << QTime::currentTime();
}

void TestQString::cleanup() {
    qDebug() << "test::cleanup" << QTime::currentTime();
}


void TestQString::toUpper() {
    QString str = "hello";
    QVERIFY2(str.toUpper() == "HELLO", "QString::toUpper.");

    QCOMPARE(str.toUpper(), QString("HELLO"));
}

void TestQString::toUpper2() {
    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

void TestQString::toUpper2_data() {
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("all lower1") << "hello" << "HELLO";
    QTest::newRow("mixed1")     << "Hello" << "HELLO";
    QTest::newRow("all upper1") << "HELLO" << "HELLO";
}

void TestQString::tstGui() {
    QLineEdit line_edit;

    QTest::keyClicks(&line_edit, "hello world");

    QCOMPARE(line_edit.text(), QString("hello world"));
}

void TestQString::tstGui2() {
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit line_edit;

    events.simulate(&line_edit);

    QCOMPARE(line_edit.text(), expected);

    if(expected.isEmpty()) {
        QSKIP("skip lineedit empty.");
    }
}

void TestQString::tstGui2_data() {
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";
}

void TestQString::tstBenchmark_simple() {
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    QCOMPARE(str1.localeAwareCompare(str2), 0);

    QBENCHMARK {
        str1.localeAwareCompare(str2);
    }
}

void TestQString::tstBenchmark_multi() {
    QFETCH(bool, useLocaleCompare);
    QString str1 = QLatin1String("This is a test string");
    QString str2 = QLatin1String("This is a test string");

    int result;
    if(useLocaleCompare) {
        QBENCHMARK {
            result = str1.localeAwareCompare(str2);
        }
    } else {
        QBENCHMARK {
            result = (str1 == str2);
        }
    }
    Q_UNUSED(result)
}

void TestQString::tstBenchmark_multi_data() {
    QTest::addColumn<bool>("useLocaleCompare");

    QTest::addRow("locale aware compare") << true;
    QTest::addRow("standard compare") << false;

    QSKIP("skip all benchmark _data.");
}

QTEST_MAIN(TestQString);
#include "tst_mytest.moc"
