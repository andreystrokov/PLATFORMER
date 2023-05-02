#include "controller.h"



using namespace std;
controller::controller()
{

}

controller::~controller()
{

}

void controller::init()
{
    initscr(); // initialize ncurses
        cbreak(); // disable line buffering (read input immediately)
        noecho(); // do not display input characters
        keypad(stdscr, TRUE); // enable arrow keys and function keys
}

void controller::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{

    if(action == GLFW_PRESS)
    {
//        auto it = std::find(controller::Ref()->keyPressed.begin(),controller::Ref()->keyPressed.end(),key);
//        if(it != controller::Ref()->keyPressed.end())
            controller::Ref()->keyPressed.push_back(key);
            std::cout <<  controller::Ref()->keyPressed.size() << std::endl;
    }
    if(action == GLFW_RELEASE)
    {
        auto it = std::find(controller::Ref()->keyPressed.begin(),controller::Ref()->keyPressed.end(),key);
        controller::Ref()->keyPressed.erase(it);
    }

}

