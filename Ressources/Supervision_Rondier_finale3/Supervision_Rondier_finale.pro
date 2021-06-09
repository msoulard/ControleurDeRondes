QT       += core gui sql widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accesmysql.cpp \
    accessqlite.cpp \
    accesxml.cpp \
    agents.cpp \
    associationagentsrondes.cpp \
    chronologieanomalie.cpp \
    communicationadb.cpp \
    creationagent.cpp \
    creationlieu.cpp \
    creationpointeau.cpp \
    gestionsmartphones.cpp \
    gestionsqlite.cpp \
    historique.cpp \
    ihmagents.cpp \
    ihmassociation.cpp \
    ihmidentification.cpp \
    ihmlieux.cpp \
    ihmpointeaux.cpp \
    ihmrondes.cpp \
    ihmsynchronisation.cpp \
    lieu.cpp \
    main.cpp \
    message.cpp \
    modifagent.cpp \
    modiflieu.cpp \
    modifpointeau.cpp \
    parametre.cpp \
    pointeaux.cpp \
    qcheckboximage.cpp \
    qdevicewatcher.cpp \
    qdevicewatcher_linux.cpp \
    rondes.cpp \
    scanner.cpp \
    supervisionrondier.cpp \
    tempspointage.cpp

HEADERS += \
    accesmysql.h \
    accessqlite.h \
    accesxml.cpp.autosave \
    accesxml.h \
    agents.h \
    associationagentsrondes.h \
    chronologieanomalie.h \
    communicationadb.h \
    creationagent.h \
    creationlieu.h \
    creationpointeau.h \
    gestionsmartphones.h \
    gestionsqlite.h \
    historique.h \
    ihmagents.h \
    ihmassociation.h \
    ihmidentification.h \
    ihmlieux.h \
    ihmpointeaux.h \
    ihmrondes.h \
    ihmsynchronisation.h \
    lieu.h \
    message.h \
    modifagent.h \
    modiflieu.h \
    modifpointeau.h \
    parametre.h \
    pointeaux.h \
    qcheckboximage.h \
    qdevicewatcher.h \
    qdevicewatcher_p.h \
    rondes.h \
    scanner.h \
    supervisionrondier.h \
    tempspointage.h \
    ui_parametre.h

FORMS += \
    chronologieanomalie.ui \
    creationagent.ui \
    creationlieu.ui \
    creationpointeau.ui \
    historique.ui \
    ihmagents.ui \
    ihmassociation.ui \
    ihmidentification.ui \
    ihmlieux.ui \
    ihmpointeaux.ui \
    ihmrondes.ui \
    ihmsynchronisation.ui \
    ihmsynchronisation.ui \
    modifagent.ui \
    modiflieu.ui \
    modifpointeau.ui \
    supervisionrondier.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES += \
    configurations.xml \
    images/LogoTouchard.png \
    images/pdf-file.svg
