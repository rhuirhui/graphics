#include "display.h"
#include <iostream>
#include <GLFW/glfw3.h>

Display::Display(int width, int height, const char* title)
{
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  main_window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (main_window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
  }
  glfwMakeContextCurrent(main_window);
  int widthviewport, heightviewport;
  glfwGetFramebufferSize(main_window, &widthviewport, &heightviewport);
  glViewport(0, 0, widthviewport, heightviewport);
  glfwSetWindowPos(main_window, 0,50 );
}

Display::~Display()
{
  glfwTerminate();
}

void Display::clear(Display display)
{
 while (!glfwWindowShouldClose(display.main_window))
 {
  glfwPollEvents();
  glClearColor(0.0, 1.0, 0.5, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  glfwSwapBuffers(display.main_window);
 }
}

void Display::Swapbuffers(Display display)
{
 glfwSwapBuffers(display.main_window);
}
