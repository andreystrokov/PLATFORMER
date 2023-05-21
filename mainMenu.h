#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include "Vulkan/VulkanModel.h"

#include "interfaceElements/wallpaper.h"
#include "interfaceElements/buttonmainmenu.h"
#include "interfaceElements/text.h"

class MainMenuClass
{
public:
    MainMenuClass();

    friend class GameRenderer;
    friend class GAME;

private:

    bool isActive = true;

    wallpaperMainMenu* wallpaper;
    Text* nameGameText;
    buttonMainMenu* newGameBtn;
    buttonMainMenu* levelsBtn;
    buttonMainMenu* optionsBtn;
    buttonMainMenu* quitBtn;

    const std::vector<Vertex> verticesWallpaper = {
        {{-1.0f, -1.0f,0.99f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{1.0f, -1.0f,0.99f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{1.0f, 1.0f,0.99f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-1.0f, 1.0f,0.99f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
    };
    const std::vector<Vertex> verticesNewGameBtn = {
        {{0.3f, 0.0f,0.98f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{0.9f, 0.0f,0.98f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{0.9f, 0.2f,0.98f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{0.3f, 0.2f,0.98f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
    };
    const std::vector<Vertex> verticesOptionsBtn = {
        {{0.3f, 0.25f,0.98f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{0.9f, 0.25f,0.98f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{0.9f, 0.45f,0.98f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{0.3f, 0.45f,0.98f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
    };
    const std::vector<Vertex> verticesQuitBtn = {
        {{0.3f, 0.5f,0.98f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{0.9f, 0.5f,0.98f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{0.9f, 0.7f,0.98f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{0.3f, 0.7f,0.98f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
    };
    const std::vector<Vertex> verticesGameName = {
        {{-0.9f, -0.9f,0.98f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{-0.5f,-0.9f,0.98f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{-0.5f,- 0.7f,0.98f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-0.9f, -0.7f,0.98f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
    };
    const std::vector<uint32_t> indicesAllItems = {
        0, 1, 2, 2, 3, 0
    };

};

#endif // MAINMENU_H
