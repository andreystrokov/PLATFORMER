#ifndef GAME_H
#define GAME_H

#include "controller.h"
#include "Vulkan/GameRenderer.h"
#include <thread>
#include "mainActor.h"
#include "mainMenu.h"
#include "background.h"
#include "ground.h"
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
    void drawPause();
private:
    void initObjects();


    MainMenuClass mainMenu;
    GameRenderer rnd;
    controller* keyController;
    MainActor*  mainActor = nullptr;

    Background* background = nullptr;
    Background* farTrees = nullptr;
    Background* midTrees = nullptr;
    Background* closeTrees = nullptr;
    Ground* ground = nullptr;
    audio* audioModule = nullptr;
    QThread* audioThread = nullptr;

    float levelGameXCoord = 0.0f;
//    QApplication app(argc,argv);
    bool isPaused = false;
    std::vector<VulkanObject*>*  objects = nullptr;
    std::vector<VulkanCharacterObject*>*  characters = nullptr;
};

#endif // GAME_H
