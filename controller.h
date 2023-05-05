#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <QDebug>

#include <iostream>
#include <ncurses.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <algorithm>
#include <utility>

typedef std::pair<double,double> MOUSE_CURSOR;

struct key
{
    int key;
    int action;
};

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
    static void mousePos_callback(GLFWwindow* window, double _x_pos, double _y_pos);
    static void mouseBtn_callback(GLFWwindow* window, int button, int action, int mods);

    std::vector<int>* getCurrentKeyPressed() { return &keyPressed; };
    MOUSE_CURSOR getCursorPos() { return windowCursor; };

private:
    std::vector<int> keyPressed;
    MOUSE_CURSOR windowCursor;
};

#endif // CONTROLLER_H
