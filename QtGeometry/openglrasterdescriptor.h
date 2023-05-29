#pragma once
#ifndef OPENGLRASTERDESCRIPTOR_H
#define OPENGLRASTERDESCRIPTOR_H

#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "texture.h"
#include <vector>


class OpenglRasterDescriptor
{
public:
    ~OpenglRasterDescriptor();

    VertexBuffer* vbo = nullptr;
    VertexArray* vao = nullptr;
    IndexBuffer* ibo = nullptr;
    std::vector<Texture*>  texs;
};

#endif // OPENGLRASTERDESCRIPTOR_H
