#ifndef CONTROLLER_H
#define CONTROLLER_H


//#include <QDebug>

#include <iostream>
#include <ncurses.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>

class controller
{
    explicit controller();
public:
    static controller* Ref() {static controller res; return &res; };
    controller(controller &r) = delete;
    void operator=(const controller& r) = delete;
    ~controller();
    void init();
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    std::vector<int>* getCurrentKeyPressed() { return &keyPressed; };
private:
    std::vector<int> keyPressed;
};

#endif // CONTROLLER_H
