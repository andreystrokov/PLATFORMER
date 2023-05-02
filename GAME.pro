QT += core gui widgets multimedia

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        audio.cpp \
        background.cpp \
        controller.cpp \
        game.cpp \
        main.cpp \
        mainActor.cpp \
        renderer.cpp

LIBS += -lvulkan -lglfw -lncurses -lmpg123 -lvlc -lao

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

HEADERS += \
    VulkanModel.h \
    audio.h \
    background.h \
    controller.h \
    game.h \
    mainActor.h \
    renderer.h \
    shaderLoader.h

DISTFILES += \
    shaders/background.frag \
    shaders/background.vert \
    shaders/mainActor.frag \
    shaders/mainActor.vert

TARGET = GAME

install_res.path = $$OUT_PWD/shaders/

install_res.files += $$PWD/shaders/mainActor_vert.spv \
                     $$PWD/shaders/mainActor_frag.spv  \
                     $$PWD/shaders/background_vert.spv \
                     $$PWD/shaders/background_frag.spv



INSTALLS += install_res
