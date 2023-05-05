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

}

void controller::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        controller::Ref()->keyPressed.push_back(key);
    }
    if(action == GLFW_RELEASE)
    {
        auto it = std::find(controller::Ref()->keyPressed.begin(),controller::Ref()->keyPressed.end(),key);
        controller::Ref()->keyPressed.erase(it);
    }

}

void controller::mousePos_callback(GLFWwindow *window, double _x_pos, double _y_pos)
{
      int winHeight,winWidth;
      glfwGetWindowSize(window,&winWidth,&winHeight);
      double normalizedX = -1.0 + 2.0 * _x_pos / static_cast<double>(winWidth);
      double normalizedY = -1.0 + 2.0 * _y_pos / static_cast<double>(winHeight);

      controller::Ref()->windowCursor = MOUSE_CURSOR(normalizedX,normalizedY);
}

void controller::mouseBtn_callback(GLFWwindow *window, int button, int action, int mods)
{
//    qDebug() << button << ' ' << action;
}

