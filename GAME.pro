QT += core gui widgets multimedia

CONFIG += c++17 console
CONFIG -= app_bundle

system(sh $$PWD/shaders/compile.sh)
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        audio.cpp \
        background.cpp \
        controller.cpp \
        game.cpp \
        ground.cpp \
        main.cpp \
        mainActor.cpp \
        renderer.cpp

LIBS += -lvulkan -lglfw -lncurses -lmpg123 -lvlc -lao

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

HEADERS += \
    VulkanCharacterModel.h \
    VulkanModel.h \
    audio.h \
    background.h \
    controller.h \
    game.h \
    ground.h \
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

install_textures_background.path = $$OUT_PWD/textures/background/

install_textures_background.files += $$PWD/textures/background/groundNew.png \
                     $$PWD/textures/background/parallax-demon-woods-bg.png  \
                     $$PWD/textures/background/parallax-demon-woods-close-trees.png \
                     $$PWD/textures/background/parallax-demon-woods-far-trees.png \
                     $$PWD/textures/background/parallax-demon-woods-mid-trees.png

install_textures_character.path = $$OUT_PWD/textures/character/

install_textures_character.files += $$PWD/textures/character/Idle.png \
                     $$PWD/textures/character/Attacks.png  \
                     $$PWD/textures/character/Jump.png \
                     $$PWD/textures/character/Run.png \
                     $$PWD/textures/character/Death.png

install_music.path = $$OUT_PWD/music/

install_music.files += $$PWD/music/song.mp3

INSTALLS += install_res \
            install_textures_background \
            install_textures_character \
            install_music
