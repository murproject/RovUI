INCLUDEPATH += "$$PWD\..\..\thirdpaty\qcustomplot\include"
INCLUDEPATH ~= s,/,\\,g


INCLUDEPATH += "$$PWD\..\..\thirdpaty\qcustomplot\include"
INCLUDEPATH ~= s,/,\\,g

CONFIG(release, debug | release) : {
    LIBS += -L"$$PWD\..\..\thirdpaty\qcustomplot\lib"
    LIBS += \
        -lqcustomplot2
    LIBS ~= s,/,\\,g
}

CONFIG(debug, debug | release) : {
    LIBS += -L"$$PWD\..\..\thirdpaty\qcustomplot\lib"
    LIBS += \
        -lqcustomplotd2
    LIBS ~= s,/,\\,g
}
