TEMPLATE = app

QT += qml quick sql

SOURCES += main.cpp \
    memomodel.cpp

RESOURCES += qml.qrc \
    tools.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = .

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    memomodel.h
