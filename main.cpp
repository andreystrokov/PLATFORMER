#include <iostream>
#include "game.h"
//#include "QApplication"
#include "renderer.h"
#include <QThread>
#include "audio.h"

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    system("/home/andrey/GAME_PROJECT/PLATFORMER/GAME/shaders/compile.sh");
    std::this_thread::sleep_for(500ms);

   GAME g;
   g.init();
   g.GameLoop();
    return 0;
}
