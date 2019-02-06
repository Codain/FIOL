!contains( INCLUDEPATH, $$PWD ) {
    INCLUDEPATH += $$PWD

    HEADERS += \
        $$PWD/include/fiol.h

    SOURCES += \
        $$PWD/src/fiolBReadBE.c \
        $$PWD/src/fiolBReadLE.c \
        $$PWD/src/fiolBReadUBE.c \
        $$PWD/src/fiolBReadULE.c \
        $$PWD/src/fiolSReadChar.c \
        $$PWD/src/fiolSReadInt.c \
        $$PWD/src/fiolSReadFloat.c \
        $$PWD/src/fiolSReadDouble.c \
        $$PWD/src/fiolSReadUInt.c \
        $$PWD/src/fiolSWriteChar.c \
        $$PWD/src/fiolSWriteInt.c \
        $$PWD/src/fiolSWriteFloat.c \
        $$PWD/src/fiolSWriteDouble.c \
        $$PWD/src/fiolSWriteUInt.c
}
