#pragma once
#ifndef OPENGLFEATUREDESCRIPTOR_H
#define OPENGLFEATUREDESCRIPTOR_H

#include "vertexarray.h"
#include "vertexbuffer.h"
#include "indexbuffer.h"
#include "Geometry.h"

class OpenglFeatureDescriptor
{
public:
    OpenglFeatureDescriptor(int stride) : stride(stride) {}
    ~OpenglFeatureDescriptor();

    void offset(double xOffset, double yOffset);

    //void rotate();    // Just resend data to GPU

public:
    int stride;
    VertexBuffer* vbo = nullptr;
    VertexArray* vao = nullptr;
    std::vector<IndexBuffer*> ibos;
};

#endif // OPENGLFEATUREDESCRIPTOR_H
