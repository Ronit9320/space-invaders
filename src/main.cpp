#include "../include/shaders.h"
#include "../include/window.h"
#include <iostream>

int main() {
  std::cout << "starting window creation" << std::endl;
  createWindow();
  generateShaders();
  return 0;
}
