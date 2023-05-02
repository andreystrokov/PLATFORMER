#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "renderer.h"
#include <thread>
#include "mainActor.h"
#include "background.h"
#include <chrono>
#include "audio.h"
#include <QThread>

using namespace std::chrono_literals;

class GAME
{
public:
    GAME();

    void init();

    void GameLoop();
private:
    void initObjects();
    renderer rnd;
    controller* keyController;
    MainActor*  mainActor = nullptr;

    Background* background = nullptr;
    Background* farTrees = nullptr;
    Background* midTrees = nullptr;
    Background* closeTrees = nullptr;

    audio* audioModule = nullptr;
    QThread* audioThread = nullptr;

//    QApplication app(argc,argv);

    std::vector<VulkanObject*>*  objects = nullptr;
};

#endif // GAME_H
