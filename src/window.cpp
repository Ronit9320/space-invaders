#include "../include/data.h"
#include "../include/file_io.h"
#include "../include/shaders.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

void createWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "START", NULL, NULL);
  glfwMakeContextCurrent(window);
  glewInit();
  std::string vertexShader = readFromFile("../shaders/shader.vert");
  std::string fragmentShader = readFromFile("../shaders/shader.frag");

  const char *vertex = vertexShader.c_str();
  const char *fragment = fragmentShader.c_str();

  std::vector<float> vertices = getData();

  unsigned int shaderProgram = shaderUtils::generateShaders(vertex, fragment);
  shaderUtils::attributeHandler(vertices.data(), vertices.size());

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.0f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}
