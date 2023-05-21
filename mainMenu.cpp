#include "mainMenu.h"

MainMenuClass::MainMenuClass()
{
    wallpaper = new wallpaperMainMenu(verticesWallpaper,indicesAllItems,
                                      "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/textures/interface/mainMenu/Wallpaper.png",
                                      "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_vert.spv",
                                      "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_frag.spv");

    newGameBtn = new buttonMainMenu(verticesNewGameBtn,indicesAllItems,
                                                    "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/textures/interface/mainMenu/newGameBtn.png",
                                                    "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_vert.spv",
                                                    "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_frag.spv");
    optionsBtn = new buttonMainMenu(verticesOptionsBtn,indicesAllItems,
                                    "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/textures/interface/mainMenu/optionsBtn.png",
                                    "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_vert.spv",
                                    "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_frag.spv");
    quitBtn = new buttonMainMenu(verticesQuitBtn,indicesAllItems,
                                 "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/textures/interface/mainMenu/quitBtn.png",
                                 "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_vert.spv",
                                 "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_frag.spv");
    nameGameText = new Text(verticesGameName,indicesAllItems,
                            "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/textures/interface/mainMenu/GameName.png",
                            "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_vert.spv",
                            "/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/interfaceShaders/wallpaper_frag.spv");

}
