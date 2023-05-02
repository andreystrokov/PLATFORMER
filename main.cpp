#include <iostream>
#include "game.h"
//#include "QApplication"
#include "renderer.h"
#include <QThread>
#include "audio.h"

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
   GAME g;
   g.init();
   g.GameLoop();
    return 0;
}
