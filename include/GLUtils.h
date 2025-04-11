#ifndef GLUTILS_H
#define GLUTILS_H
#include <GL/glew.h>
#include <iostream>

namespace GLUtils {
unsigned int generateShaders(const char *vertexShaderSource,
                             const char *fragmentShaderSource);

void genBuffers(float *vertices, uint8_t *indices);
unsigned int loadTextures();
} // namespace GLUtils
#endif // !SHADERS_H
