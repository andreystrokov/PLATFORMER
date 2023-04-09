#include <iostream>
#include "renderer.h"
int main(int argc, char *argv[])
{
    renderer rnd;
    try {
           rnd.run();
       } catch (const std::exception& e) {
           std::cerr << e.what() << std::endl;
           return EXIT_FAILURE;
       }
    return 0;
}
