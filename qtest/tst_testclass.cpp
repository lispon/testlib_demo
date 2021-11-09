#include "tst_testclass.h"


void TstTestClass::initTestCase_data() {

}

void TstTestClass::initTestCase() {

}

void TstTestClass::cleanupTestCase() {

}

void TstTestClass::init() {

}

void TstTestClass::cleanup() {

}


void TstTestClass::tstSignalSpy() {
    QObject object;
    const QMetaObject* mo = object.metaObject();
    int signalIndex = mo->indexOfSignal("objectNameChanged(QString)");
    QMetaMethod signal = mo->method(signalIndex);

    QSignalSpy spy(&object, signal);
    object.setObjectName("A net object name");
    QCOMPARE(spy.count(), 1);
}

void TstTestClass::tstSignalSpy_data() {
    QTest::addColumn<int>("propertyIndex");
    // Collect all relevant perperties.
    static const auto mo = QWindow::staticMetaObject;
    for(int i = mo.propertyOffset(); i < mo.propertyCount(); ++i) {
        auto property = mo.property(i);

        // ...that have type int.
        if(QVariant::Int == property.type()) {
            static const QRegularExpression re("^minimum|maximum");
            const auto name = property.name();

            // ...and start with "minimum" or "maxmium"
            if(re.match(name).hasMatch()) {
                QTest::addRow("%s", name) << i;
            }
        }
    }
}

void TstTestClass::tstEventList() {
    QFETCH(QTestEventList, events);
    QFETCH(double, value);

    QLineEdit ledt;
    events.simulate(&ledt);

    QCOMPARE(ledt.text().toDouble(), value);
}

void TstTestClass::tstEventList_data() {
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<double>("value");

    QTestEventList list1;
    list1.addKeyClicks("1");
    QTest::newRow("int.") << list1 << 1.;

    list1.addKeyClicks(".2");
    list1.addKeyClick(Qt::Key_3);
    list1.addKeyClick('4');
    QTest::newRow("double.") << list1 << 1.234;
}

void TstTestClass::tstTouchEvent() {
}

void TstTestClass::tstTouchEvent_data() {
    QSKIP("not understand touchEvent, so skip all touchEvent.");
}

void TstTestClass::tstItemModel() {
}

void TstTestClass::tstItemModel_data() {
    QSKIP("not understand ItemModel, so skip all QAbstractItemModelTester.");
}


QTEST_MAIN(TstTestClass);
#include "tst_testclass.moc"
