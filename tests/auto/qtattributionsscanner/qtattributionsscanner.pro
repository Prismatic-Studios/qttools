CONFIG += testcase
QT = core testlib

DISTFILES += \
    testdata/good/expected.json \
    testdata/good/expected.error \
    testdata/good/minimal/qt_attribution_test.json \
    testdata/good/minimal/expected.json \
    testdata/good/minimal/expected.error \
    testdata/good/complete/qt_attribution_test.json \
    testdata/good/complete/expected.json \
    testdata/good/complete/expected.error \
    testdata/warnings/incomplete/qt_attribution_test.json \
    testdata/warnings/incomplete/expected.json \
    testdata/warnings/incomplete/expected.error \
    testdata/warnings/unknown/qt_attribution_test.json \
    testdata/warnings/unknown/expected.json \
    testdata/warnings/unknown/expected.error

TARGET = tst_qtattributionsscanner

SOURCES += tst_qtattributionsscanner.cpp
