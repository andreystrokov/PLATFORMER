#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include "Vulkan/VulkanModel.h"

#include "interfaceElements/wallpaper.h"
#include "interfaceElements/buttonmainmenu.h"


class MainMenuClass
{
public:
    MainMenuClass();

    friend class GameRenderer;

private:


    wallpaperMainMenu* wallpaper;
//    buttonMainMenu* newGameBtn;

    const std::vector<Vertex> verticesWallpaper = {
        {{-1.0f, -1.0f,0.99f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}},
        {{1.0f, -1.0f,0.99f}, {0.0f, 1.0f, 0.0f}, {1.0f, 0.0f}},
        {{1.0f, 1.0f,0.99f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}},
        {{-1.0f, 1.0f,0.99f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}
    };
    const std::vector<uint32_t> indicesWallpaper = {
        0, 1, 2, 2, 3, 0
    };

};

#endif // MAINMENU_H
