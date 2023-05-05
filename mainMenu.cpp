#include "mainMenu.h"

MainMenuClass::MainMenuClass()
{
    wallpaper = new wallpaperMainMenu(verticesWallpaper,indicesWallpaper,
                                      "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/textures/interface/mainMenu/Wallpaper.png",
                                      "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_vert.spv",
                                      "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_frag.spv");


}
