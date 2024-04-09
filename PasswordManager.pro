QT += quick

HEADERS += $$files(src/*.hpp, true)
SOURCES += $$files(src/*.cpp, true)
SOURCES += main.cpp

RESOURCES += $$files(*.qrc)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
