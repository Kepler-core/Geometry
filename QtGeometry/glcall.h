#pragma once
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include <GL/glew.h>

#ifdef _WIN32
#define ASSERT(x) if (!(x)) __debugbreak()
#else
#define ASSERT(x) if (!(x)) __builtin_trap()
#endif

#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);