#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

class Display
{
public:
    Display(int width, int height, const char* title);

    virtual ~Display();
    void clear(Display display);
    GLFWwindow* main_window;
protected:
private:
    int main_width;
    int main_height;
    std::string main_name;
    void Swapbuffers(Display display);
    void pollevents() {glfwPollEvents();};
};

#endif // DISPLAY_H
